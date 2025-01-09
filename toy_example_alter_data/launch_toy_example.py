"""
    File: run_alter_data.py

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This script compiles and runs a C++ program that modifies genotype data.
    It first compiles the C++ source code, and if successful, it executes the compiled program to alter the genotype data.

    Key Features:
    - Compiles the C++ source code using `g++` with the C++11 standard.
    - Executes the compiled program with input and output files for parameters and genotypes.
    - Handles errors during both compilation and execution, displaying appropriate error messages.
    - Assumes that the C++ source code is located at a specified path and the necessary input/output files exist.

    Output:
    - The script runs the compiled executable, modifying the `genotypes.csv` file based on the given parameters.

    Preconditions:
    - The C++ source file (`alter_data.cpp`) must be correctly written and located at the specified path.
    - The `parameters.txt` file must contain the necessary configuration for the program.
    - The `genotypes.csv` file will be modified by the C++ program based on the execution logic.
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
