"""
@file run_alter_data.py
@authors Ahamed TCHATAKOURA & Mawuéna AHONDO
@date 2025-03-03
@version 1.0

@brief Compiles and executes a C++ program to modify genotype data.

@details
This script automates the compilation and execution of a C++ program (`alter_data.cpp`) that modifies genotype data.
It first compiles the C++ source file using `g++`, and upon successful compilation, executes the compiled program with
the required input parameters.

The script performs the following steps:
1. Compiles the C++ source file (`alter_data.cpp`) using `g++ -std=c++11`.
2. Runs the compiled executable with input parameters (`parameters.txt` and `genotypes.csv`).
3. Handles errors during compilation and execution, displaying appropriate messages.

@section Features Key Features
- Compiles the C++ source code using `g++` with the C++11 standard.
- Executes the compiled program with necessary input files (`parameters.txt` and `genotypes.csv`).
- Handles errors gracefully, outputting messages in case of failures.
- Assumes the C++ source file is located in `../src/` and input files exist in the expected locations.

@section Preconditions Preconditions
- The C++ source file (`alter_data.cpp`) must be correctly written and located in `../src/`.
- The `parameters.txt` file must exist and contain the necessary configuration for the program.
- The `genotypes.csv` file must exist and will be modified by the C++ program based on the execution logic.
- The script must have execution permissions and the required dependencies installed.

@section Output Output
- If successful, the script compiles and runs the C++ program, modifying the `genotypes.csv` file accordingly.
- If an error occurs during compilation or execution, an appropriate error message is displayed.

@section Example Example Usage
@code
python run_alter_data.py
@endcode
"""
import os
import sys
import subprocess

parameters_file = "../src/parameters.txt"
genotypes_file = "../data/genotypes.csv"
cpp_file = "../src/alter_data.cpp"


executable = "../src/alter_data"  

compile_command = f"g++ -std=c++11 -o {executable} {cpp_file}"

try:
    print(f"Compilation de {cpp_file}...")
    subprocess.run(compile_command, shell=True, check=True)
    print("Compilation réussie.")
except subprocess.CalledProcessError:
    sys.stderr.write(f"Erreur lors de la compilation du fichier C++ : {cpp_file}\n")
    sys.exit(1)


cmd = f"{executable} {parameters_file} {genotypes_file}"


print(f"Exécution de la commande : {cmd}")


try:
    subprocess.run(cmd, shell=True, check=True)
    print("Exécution réussie.")
except subprocess.CalledProcessError:
    sys.stderr.write(f"Erreur lors de l'exécution de la commande : {cmd}\n")
    sys.exit(1)
