#include <math.h>
#include "project.h"

int generate_ca_code(int prn, int code[GPS_CODE_LENGTH])
{
    int g1[10], g2[10];

    if (prn != 1)
        return 0;

    for (int i = 0; i < 10; i++)
    {
        g1[i] = 1;
        g2[i] = 1;
    }

    for (int i = 0; i < GPS_CODE_LENGTH; i++)
    {
        int g1_out = g1[9];
        int g2_out = g2[1] ^ g2[5];

        int feedback1 = g1[2] ^ g1[9];
        int feedback2 = g2[1] ^ g2[2] ^
                        g2[5] ^ g2[7] ^
                        g2[8] ^ g2[9];

        code[i] = (g1_out ^ g2_out) ? -1 : 1;

        for (int j = 9; j > 0; j--)
        {
            g1[j] = g1[j - 1];
            g2[j] = g2[j - 1];
        }

        g1[0] = feedback1;
        g2[0] = feedback2;
    }

    return 1;
}

void generate_signal(const GpsConfig *cfg, GpsSignal *signal)
{
    const double PI = 3.141592653589793;

    for (int i = 0; i < GPS_CODE_LENGTH; i++)
    {
        int chip = signal->ca_code[
            (i + cfg->code_phase) % GPS_CODE_LENGTH
        ];

        double phase = 2.0 * PI *
                       cfg->doppler_hz * i /
                       cfg->sample_rate_hz;

        signal->i_samples[i] = chip * cos(phase);
        signal->q_samples[i] = chip * sin(phase);
    }
}

void acquire_signal(const GpsConfig *cfg,
                    const GpsSignal *signal,
                    AcquisitionResult *result)
{
    double best_power = -1.0;

    int best_phase = 0;
    int best_doppler = 0;

    for (int doppler = cfg->doppler_min_hz;
         doppler <= cfg->doppler_max_hz;
         doppler += cfg->doppler_step_hz)
    {
        for (int phase = 0;
             phase < GPS_CODE_LENGTH;
             phase++)
        {
            double sum_i = 0.0;
            double sum_q = 0.0;

            for (int n = 0; n < GPS_CODE_LENGTH; n++)
            {
                double angle = 2.0 * 3.141592653589793 *
                               doppler * n /
                               cfg->sample_rate_hz;

                double c = cos(angle);
                double s = sin(angle);

                double wi = signal->i_samples[n] * c +
                            signal->q_samples[n] * s;

                double wq = signal->q_samples[n] * c -
                            signal->i_samples[n] * s;

                int local_code = signal->ca_code[
                    (n + phase) % GPS_CODE_LENGTH
                ];

                sum_i += wi * local_code;
                sum_q += wq * local_code;
            }

            double power = sum_i * sum_i +
                           sum_q * sum_q;

            if (power > best_power)
            {
                best_power = power;
                best_phase = phase;
                best_doppler = doppler;
            }
        }
    }

    result->code_phase = best_phase;
    result->doppler_hz = best_doppler;
    result->correlation_power = best_power;
    result->detected = (best_power > 1000.0);
}
