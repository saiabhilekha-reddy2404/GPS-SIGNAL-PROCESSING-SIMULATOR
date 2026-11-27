
#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main(void)
{
    GpsConfig config;
    GpsSignal signal;
    AcquisitionResult result;

    // Read GPS configuration
    if (!read_config("data/sample_input.txt", &config))
    {
        printf("Error: Unable to read input file.\n");
        return EXIT_FAILURE;
    }

    // Generate GPS C/A code
    if (!generate_ca_code(config.prn, signal.ca_code))
    {
        printf("Error: Unsupported GPS PRN number.\n");
        return EXIT_FAILURE;
    }

    // Generate simulated GPS signal
    generate_signal(&config, &signal);

    // Perform GPS signal acquisition
    acquire_signal(&config, &signal, &result);

    // Display results
    printf("\nGPS Signal Processing Simulator\n");
    printf("--------------------------------\n");

    printf("PRN Number: %d\n", config.prn);

    if (result.detected)
    {
        printf("Signal Status: Acquired\n");
        printf("Estimated Code Phase: %d chips\n",
               result.code_phase);
        printf("Estimated Doppler Frequency: %.0f Hz\n",
               result.doppler_hz);
        printf("Correlation Power: %.2f\n",
               result.correlation_power);
    }
    else
    {
        printf("Signal Status: Not Acquired\n");
    }

    // Save results to output file
    print_result(&config, &result,
                 "output/sample_output.txt");

    printf("\nSimulation completed successfully.\n");
    printf("Results saved in output/sample_output.txt\n");

    return EXIT_SUCCESS;
}
