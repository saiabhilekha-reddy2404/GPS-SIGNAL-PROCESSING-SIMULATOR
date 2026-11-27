#include <stdio.h>
#include "project.h"

int read_config(const char *filename, GpsConfig *cfg)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        return 0;

    int result = fscanf(fp, "%d %lf %d %d %d %d",
                        &cfg->prn,
                        &cfg->sample_rate_hz,
                        &cfg->doppler_hz,
                        &cfg->code_phase,
                        &cfg->doppler_min_hz,
                        &cfg->doppler_max_hz);

    if (result == 6)
        result = fscanf(fp, "%d", &cfg->doppler_step_hz);
    else
        result = 0;

    fclose(fp);

    return result == 1 &&
           cfg->sample_rate_hz > 0 &&
           cfg->code_phase >= 0 &&
           cfg->code_phase < GPS_CODE_LENGTH &&
           cfg->doppler_step_hz > 0 &&
           cfg->doppler_min_hz <= cfg->doppler_max_hz;
}

void print_result(const GpsConfig *cfg,
                  const AcquisitionResult *r,
                  const char *filename)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Unable to create output file.\n");
        return;
    }

    fprintf(fp, "GPS Signal Processing Simulator\n");
    fprintf(fp, "--------------------------------\n");

    fprintf(fp, "PRN: %d\n", cfg->prn);

    fprintf(fp, "Detection: %s\n",
            r->detected ? "ACQUIRED" : "NOT ACQUIRED");

    fprintf(fp, "Estimated Code Phase: %d chips\n",
            r->code_phase);

    fprintf(fp, "Estimated Doppler: %.0f Hz\n",
            r->doppler_hz);

    fprintf(fp, "Correlation Power: %.2f\n",
            r->correlation_power);

    fprintf(fp, "\nEducational GPS simulation model.\n");

    fclose(fp);
}
