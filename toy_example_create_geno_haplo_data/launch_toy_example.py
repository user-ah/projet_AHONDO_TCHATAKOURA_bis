"""
@file run_create_geno_haplo_data.py
@authors Ahamed TCHATAKOURA & Mawuéna AHONDO
@date 2025-03-03
@version 1.0

@brief Compiles and executes a C++ program to generate genotype and haplotype data.

@details
This script automates the compilation and execution of a C++ program (`create_geno_haplo_data.cpp`)
that generates genotype and haplotype data. It first compiles the C++ source code using `g++`,
and upon successful compilation, executes the compiled program to generate the necessary output files.

The script performs the following steps:
1. Compiles the C++ source file (`create_geno_haplo_data.cpp`).
2. Runs the compiled executable with input parameters (`parameters.txt`).
3. Generates `genotypes.csv` and `haplotypes.csv` files based on the execution logic.
4. Handles errors during compilation and execution, displaying appropriate error messages.

@section Features Key Features
- Compiles the C++ source code using `g++`.
- Executes the compiled program with necessary input files (`parameters.txt`).
- Generates the output genotype (`genotypes.csv`) and haplotype (`haplotypes.csv`) files.
- Handles errors gracefully, displaying relevant messages in case of failures.
- Assumes the C++ source file and necessary files exist in the specified paths.

@section Preconditions Preconditions
- The C++ source file (`create_geno_haplo_data.cpp`) must be correctly written and located in `../script/`.
- The `parameters.txt` file must exist and contain the necessary configuration for the program.
- The script must have execution permissions and the required dependencies installed.

@section Output Output
- If successful, the script compiles and runs the C++ program, generating:
  - `genotypes.csv`
  - `haplotypes.csv`
- If an error occurs during compilation or execution, an appropriate error message is displayed.

@section Example Example Usage
@code
python run_create_geno_haplo_data.py
@endcode
"""

import os
import sys
import subprocess

# Paths to required files
parameters_file = "../script/parameters.txt"
genotypes_file = "../data/genotypes.csv"
haplotypes_file = "../data/haplotypes.csv"
cpp_file = "../script/create_geno_haplo_data.cpp"
executable = "../script/create_geno_haplo_data"

# Compilation command
compile_command = f"g++ -o {executable} {cpp_file}"

try:
    print(f"Compiling {cpp_file}...")
    subprocess.run(compile_command, shell=True, check=True)
    print("Compilation successful.")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Error during compilation of C++ file: {cpp_file}\n{e}\n")
    sys.exit(1)

# Execution command
cmd = f"{executable} {parameters_file} {genotypes_file} {haplotypes_file}"

print(f"Executing command: {cmd}")

try:
    subprocess.run(cmd, shell=True, check=True)
    print("Execution successful.")
    print(f"Generated files:\n - {genotypes_file}\n - {haplotypes_file}")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Error during execution of command: {cmd}\n{e}\n")
    sys.exit(1)
