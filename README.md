
# GPS Signal Processing Simulator

## Description
The GPS Signal Processing Simulator is a C-based project designed to simulate the basic operations of a GPS receiver. It demonstrates GPS C/A code generation, signal generation, Doppler frequency estimation, code phase detection, and correlation-based signal acquisition.

## Features
- GPS C/A code generation.
- PRN sequence generation.
- GPS baseband signal simulation.
- Doppler frequency estimation.
- Code phase detection.
- Correlation-based signal acquisition.
- Displays signal acquisition results.
- Saves simulation results in an output file.

## Project Structure

```text
gps-signal-processing-simulator/
│
├── src/
│   ├── main.c
│   ├── algorithm.c
│   └── utilities.c
│
├── include/
│   └── project.h
│
├── tests/
│   └── test.c
│
├── data/
│   └── sample_input.txt
│
├── output/
│   └── sample_output.txt
│
├── docs/
│   └── working_principle.md
│
├── Makefile
├── README.md
└── LICENSE
```

## Requirements
- C Programming Language
- GCC Compiler
- Make utility
- Basic knowledge of GPS and Digital Signal Processing

## Working Principle
1. Read GPS configuration parameters from the input file.
2. Generate the GPS C/A code using a PRN sequence.
3. Simulate a GPS baseband signal.
4. Perform signal acquisition using correlation.
5. Estimate Doppler frequency and code phase.
6. Display and save the acquisition results.

## Example
- Input: PRN = 1, Doppler Frequency = 500 Hz, Code Phase = 17 chips.
- Output: GPS signal acquired successfully with estimated Doppler frequency of 500 Hz and code phase of 17 chips.

## How to Compile and Run

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/gps-signal-processing-simulator.git
```

### Step 2: Open the Project Directory

```bash
cd gps-signal-processing-simulator
```

### Step 3: Compile the Program

```bash
make
```

### Step 4: Run the Simulator

```bash
make run
```

### Step 5: Run Test Cases

```bash
make test
```

## Scope
- Demonstrates basic GPS signal generation and acquisition techniques.
- Helps understand PRN codes, Doppler frequency, and code phase estimation.
- Provides a foundation for learning GPS receiver design and digital signal processing.
- Can be extended with noise simulation, multiple PRN codes, and navigation data processing.

## Applications
- GPS receiver algorithm education.
- Satellite communication studies.
- Digital signal processing experiments.
- Navigation system research and learning.

## Limitations
- Supports PRN 1 only in the current implementation.
- Uses a simplified noiseless baseband signal model.
- Does not perform actual satellite tracking or position calculation.

## Author
SaiAbhilekha Reddy

## Language
C programming language

## Domain
Electronics and Communication Engineering (ECE)

## License
Released under the MIT License.see LICENSE
