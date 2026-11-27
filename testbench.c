#include <stdio.h>
#include <assert.h>
#include "project.h"

int main()
{
    GpsConfig cfg = {
        1,
        1023000.0,
        500,
        17,
        -1000,
        1000,
        250
    };

    GpsSignal signal;
    AcquisitionResult result;

    // Test PRN code generation
    assert(generate_ca_code(1, signal.ca_code) == 1);

    // Unsupported PRN test
    assert(generate_ca_code(2, signal.ca_code) == 0);

    // Test signal generation
    generate_signal(&cfg, &signal);

    // Test signal acquisition
    acquire_signal(&cfg, &signal, &result);

    // Verify acquisition
    assert(result.detected == 1);

    // Verify estimated code phase
    assert(result.code_phase == cfg.code_phase);

    // Verify Doppler estimation
    assert(result.doppler_hz == cfg.doppler_hz);

    printf("All GPS simulator tests passed.\n");

    return 0;
}
