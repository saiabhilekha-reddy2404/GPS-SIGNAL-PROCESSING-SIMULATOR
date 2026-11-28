# GPS Signal Processing Simulator

## Description
The GPS Signal Processing Simulator is a C-based project designed to demonstrate the fundamental operations of GPS signal processing. It simulates GPS L1 C/A code generation, baseband signal generation, Doppler frequency estimation, code phase detection, and correlation-based signal acquisition.

## Features
- GPS L1 C/A code generation
- PRN sequence generation
- GPS baseband signal simulation
- Doppler frequency estimation
- Code phase detection
- Correlation-based signal acquisition
- Sample input and output generation
- Automated test cases

## Technologies Used
- **Programming Language:** C
- **Concepts:** Digital Signal Processing, GPS Signal Processing
- **Compiler:** GCC
- **Build Tool:** Makefile

## Repository Structure

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

## Working Principle

1. **Input Configuration:** Reads PRN number, sampling frequency, Doppler frequency, and code phase.
2. **PRN Generation:** Generates a 1023-chip GPS C/A code sequence.
3. **Signal Generation:** Creates a simulated complex baseband GPS signal.
4. **Signal Acquisition:** Performs correlation between the generated signal and local PRN code.
5. **Doppler Estimation:** Identifies the Doppler frequency with the highest correlation.
6. **Code Phase Detection:** Estimates the code phase using correlation results.
7. **Output Generation:** Saves the acquisition results in a text file.

## Sample Input

```text
1 1023000 500 17 -1000 1000 250
```

## Sample Output

```text
GPS Signal Processing Simulator
--------------------------------
PRN: 1
Detection: ACQUIRED
Estimated Code Phase: 17 chips
Estimated Doppler: 500 Hz
Correlation Power: 1046529.00
```

*This is the expected output for the supplied sample configuration.*

## Compilation and Execution

### Compile the project

```bash
make
```

### Run the simulator

```bash
make run
```

### Execute test cases

```bash
make test
```

### Clean generated files

```bash
make clean
```

## Applications
- Understanding GPS receiver fundamentals
- Learning satellite signal acquisition
- Studying digital signal processing
- Exploring PRN code generation
- Understanding Doppler frequency estimation

## Scope
- Demonstrates basic GPS signal generation and acquisition techniques
- Helps understand PRN codes,Doppler frequency,and code phase estimation
- Provides a foundation for learning GPS receiver design and digital signal processing
- Can be extended with noise simulation,multiple PRN codes,and navigation data processing
  
## Limitations
- Supports PRN 1 only.
- Uses a simplified noiseless signal model.
- Does not decode navigation messages.
- Does not calculate geographical position.
- Does not simulate real-world RF propagation.

## Author
SaiAbhilekha Reddy

## Language
C programming language

## Domain
Electronics and Communication Enigineering(ECE)

## License
Released under the MIT License.see LICENSE
