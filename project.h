#ifndef PROJECT_H
#define PROJECT_H

#define GPS_CODE_LENGTH 1023

typedef struct
{
    int prn;
    double sample_rate_hz;
    int doppler_hz;
    int code_phase;
    int doppler_min_hz;
    int doppler_max_hz;
    int doppler_step_hz;

} GpsConfig;

typedef struct
{
    int ca_code[GPS_CODE_LENGTH];

    double i_samples[GPS_CODE_LENGTH];
    double q_samples[GPS_CODE_LENGTH];

} GpsSignal;

typedef struct
{
    int code_phase;
    double doppler_hz;
    double correlation_power;
    int detected;

} AcquisitionResult;

int read_config(const char *filename, GpsConfig *cfg);

int generate_ca_code(int prn,
                     int code[GPS_CODE_LENGTH]);

void generate_signal(const GpsConfig *cfg,
                     GpsSignal *signal);

void acquire_signal(const GpsConfig *cfg,
                    const GpsSignal *signal,
                    AcquisitionResult *result);

void print_result(const GpsConfig *cfg,
                  const AcquisitionResult *result,
                  const char *filename);

#endif
