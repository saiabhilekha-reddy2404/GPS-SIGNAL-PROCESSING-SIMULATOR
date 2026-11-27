# Working Principle

The GPS Signal Processing Simulator demonstrates
the basic operation of a simplified GPS receiver
using C programming language.

## 1. Input Configuration

The simulator reads PRN number, sampling frequency,
Doppler frequency, code phase and Doppler search
range from the sample input file.

## 2. PRN Code Generation

The program generates a 1023-chip GPS L1 C/A code
using two 10-stage shift registers.

## 3. Signal Generation

The generated PRN code is used to create a
simulated complex baseband GPS signal.

The signal contains:
- In-phase component
- Quadrature component
- Doppler frequency shift
- Code phase offset

## 4. Signal Acquisition

The acquisition algorithm searches different
Doppler frequency values and code phases.

It uses correlation processing to identify
the matching satellite code sequence.

## 5. Doppler Estimation

The simulator identifies the Doppler frequency
that produces the highest correlation power.

## 6. Code Phase Detection

The algorithm estimates the code phase by
finding the maximum correlation value.

## 7. Output Generation

The estimated Doppler frequency, code phase,
PRN number and correlation power are stored
in the sample output file.

## Scope

This project demonstrates GPS C/A code generation,
baseband signal simulation and correlation-based
signal acquisition using C programming.

It provides an educational foundation for
understanding GPS receiver processing and
digital signal processing concepts.

## Limitations

- Supports PRN 1 only.
- Uses a simplified noiseless signal model.
- Does not decode navigation messages.
- Does not calculate geographical position.
- Does not model real-world RF propagation.
