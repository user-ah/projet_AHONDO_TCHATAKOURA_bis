"""
@file run_infer_missing_data.py
@authors Ahamed TCHATAKOURA & Mawuéna AHONDO
@date 2025-03-03
@version 1.0

@brief Compiles and executes a C++ program to impute missing genotype data.

@details
This script automates the compilation and execution of a C++ program (`infer_missing_data.cpp`) 
that imputes missing values in genotype data. It first compiles the C++ source file using `g++ -std=c++11`,
and upon successful compilation, executes the compiled program with the required input files: 
parameters and altered genotypes. The program generates an output file containing the imputed genotypes.

The script performs the following steps:
1. Compiles the C++ source file (`infer_missing_data.cpp`).
2. Runs the compiled executable with input parameters and genotype data.
3. Generates an output file containing the imputed genotype dataset.
4. Handles errors during compilation and execution, displaying appropriate error messages.

@section Features Key Features
- Compiles the C++ source code using `g++` with the C++11 standard.
- Executes the compiled program with input files: `parameters_3_1.txt` and `genotypes_alteres.csv`.
- Produces an output file: `imputed_genotypes.csv` containing imputed genotypes.
- Handles compilation and execution errors, displaying meaningful messages in case of failure.
- Assumes that the C++ source code and necessary input files exist at the specified paths.

@section Preconditions Preconditions
- The C++ source file (`infer_missing_data.cpp`) must be correctly written and located in `../src/infer_missing_data/`.
- The input files (`parameters_3_1.txt`, `genotypes_alteres.csv`) must exist and be properly formatted.
- The output file for imputed genotypes (`imputed_genotypes.csv`) must be correctly specified.
- The script must have execution permissions and necessary dependencies installed.

@section Output Output
- If successful, the script compiles and runs the C++ program, generating:
  - `imputed_genotypes.csv` (file with imputed genotypes).
- If an error occurs during compilation or execution, an appropriate error message is displayed.

@section Example Example Usage
@code
python run_infer_missing_data.py
@endcode
"""

import os
import sys

# Paths to required files
parameters_file = "../parameters/parameters_3_1.txt"
genotypes_file = "../data/Dataset_8/alt_20/genotypes_alteres.csv"
output_genotypes_file = "../data/Dataset_8/alt_20/k_1/imputed_genotypes.csv"

executable = "../src/infer_missing_data/infer_missing_data"
source_file = "../src/infer_missing_data/infer_missing_data.cpp"

# Compilation command
compile_cmd = f"g++ -o {executable} {source_file} -std=c++11"
print(f"Compiling executable: {compile_cmd}")

compile_exit_code = os.system(compile_cmd)
if compile_exit_code != 0:
    sys.stderr.write("Error during compilation of the C++ program.\n")
    sys.exit(1)
else:
    print("Compilation successful.")

# Execution command
cmd = f"{executable} {parameters_file} {genotypes_file} {output_genotypes_file}"
print(f"Executing command: {cmd}")

exit_code = os.system(cmd)
if exit_code != 0:
    sys.stderr.write(f"Error during execution of {cmd}\n")
    sys.exit(1)
else:
    print(f"Execution successful. Imputed genotypes saved in {output_genotypes_file}")
