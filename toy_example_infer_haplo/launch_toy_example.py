"""
    File: run_infer_haplo.py

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This script compiles and runs a C++ program for haplotype inference.
    It first compiles the C++ source code, and if successful, it executes the compiled program with input and output files for genotypes, ground truth haplotypes, inferred haplotypes, and logs.

    Key Features:
    - Compiles the C++ source code using `g++` with C++17 standard.
    - Executes the compiled program with input files: genotypes, ground truth haplotypes, and a specified output log file.
    - Handles compilation and execution errors with appropriate error messages.
    - Assumes that the C++ source code and necessary input files exist at specified paths.

    Output:
    - The script runs the compiled executable, generating a log file with the results of the haplotype inference.

    Preconditions:
    - The C++ source file (`infer_haplo.cpp`) must be written correctly and located at the specified path.
    - The input files (`genotypes.csv`, `haplotypes.csv`) and the output log file must be specified and used correctly.
"""

import os
import sys
import subprocess

# Variables pour les fichiers et paramètres
genotypes_file = "../data/Dataset_1/genotypes.csv"
groundtruth_file = "../data/Dataset_1/haplotypes.csv"
InferedHaplotypes_file = "../data/Dataset_1//infered_haplo.csv"
log_file = "../data/Dataset_1/log.txt"
cpp_file = "../src/infer_haplo/infer_haplo.cpp"  


executable = "../src/infer_haplo/infer_haplo_1"


compile_command = f"g++ -std=c++17 -o {executable} {cpp_file}"


cmd = f"{executable} {genotypes_file} {groundtruth_file} {InferedHaplotypes_file} {log_file}"

try:
    print(f"Compilation de {cpp_file}...")
    subprocess.run(compile_command, shell=True, check=True)
    print("Compilation réussie.")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Erreur lors de la compilation du fichier C++ : {cpp_file}\n{e}\n")
    sys.exit(1)


print(f"Exécution de la commande : {cmd}")


try:
    subprocess.run(cmd, shell=True, check=True)
    print("Exécution réussie.")
    print(f"Fichier généré :\n - {log_file}\n ")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Erreur lors de l'exécution de la commande : {cmd}\n{e}\n")
    sys.exit(1)