"""
@file run_infer_haplo.py
@authors Ahamed TCHATAKOURA & Mawuéna AHONDO
@date 2025-03-03
@version 1.0

@brief Compiles and executes a C++ program for haplotype inference.

@details
This script automates the compilation and execution of a C++ program (`infer_haplo.cpp`) that performs haplotype inference.
It first compiles the C++ source file using `g++ -std=c++17`, and upon successful compilation, executes the compiled program 
with the required input files: genotypes, ground truth haplotypes, inferred haplotypes, and a log file.

The script performs the following steps:
1. Compiles the C++ source file (`infer_haplo.cpp`).
2. Runs the compiled executable with the input genotype and haplotype files.
3. Generates an output file containing inferred haplotypes and a log file recording execution details.
4. Handles errors during compilation and execution, displaying appropriate error messages.

@section Features Key Features
- Compiles the C++ source code using `g++` with the C++17 standard.
- Executes the compiled program with input files: `genotypes.csv`, `haplotypes.csv`, and a specified log file.
- Handles compilation and execution errors, displaying meaningful error messages.
- Assumes that the C++ source code and necessary input files exist at the specified paths.

@section Preconditions Preconditions
- The C++ source file (`infer_haplo.cpp`) must be correctly written and located in `../src/infer_haplo/`.
- The input files (`genotypes.csv`, `haplotypes.csv`) must exist and be properly formatted.
- The output file for inferred haplotypes (`infered_haplo.csv`) and the log file (`log.txt`) must be correctly specified.
- The script must have execution permissions and necessary dependencies installed.

@section Output Output
- If successful, the script compiles and runs the C++ program, generating:
  - `infered_haplo.csv` (file with inferred haplotypes).
  - `log.txt` (execution log file).
- If an error occurs during compilation or execution, an appropriate error message is displayed.

@section Example Example Usage
@code
python run_infer_haplo.py
@endcode
"""

import os
import sys
import subprocess

# Paths to required files
genotypes_file = "../data/Dataset_1/genotypes.csv"
groundtruth_file = "../data/Dataset_1/haplotypes.csv"
infered_haplotypes_file = "../data/Dataset_1/infered_haplo.csv"
log_file = "../data/Dataset_1/log.txt"
cpp_file = "../src/infer_haplo/infer_haplo.cpp"
executable = "../src/infer_haplo/infer_haplo_1"

# Compilation command
compile_command = f"g++ -std=c++17 -o {executable} {cpp_file}"

try:
    print(f"Compiling {cpp_file}...")
    subprocess.run(compile_command, shell=True, check=True)
    print("Compilation successful.")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Error during compilation of C++ file: {cpp_file}\n{e}\n")
    sys.exit(1)

# Execution command
cmd = f"{executable} {genotypes_file} {groundtruth_file} {infered_haplotypes_file} {log_file}"

print(f"Executing command: {cmd}")

try:
    subprocess.run(cmd, shell=True, check=True)
    print("Execution successful.")
    print(f"Generated files:\n - {log_file}\n - {infered_haplotypes_file}\n")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Error during execution of command: {cmd}\n{e}\n")
    sys.exit(1)
