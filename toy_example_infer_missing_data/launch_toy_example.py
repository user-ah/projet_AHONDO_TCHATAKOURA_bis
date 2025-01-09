"""
    File: run_infer_missing_data.py

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This script compiles and runs a C++ program that imputes missing data in genotypes. 
    It first compiles the C++ source code, and if the compilation is successful, it runs the compiled program with the specified input and output files for genotypes and parameters.

    Key Features:
    - Compiles the C++ source code using `g++` with C++11 standard.
    - Executes the compiled program with input files for parameters and genotypes, and produces an output file for imputed genotypes.
    - Handles compilation and execution errors, providing appropriate messages in case of failure.
    - Assumes that the C++ source file and necessary input files exist at the given paths.

    Output:
    - The script runs the compiled executable, which processes the input genotypes and parameters to generate a file with imputed genotypes.

    Preconditions:
    - The C++ source file (`infer_missing_data.cpp`) must be written correctly and located at the specified path.
    - The input files (`parameters_3_1.txt`, `genotypes_alteres.csv`) and the output file (`imputed_genotypes.csv`) must be correctly specified and available.
"""

import os
import sys

parameters_file = "../parameters/parameters_3_1.txt"
genotypes_file = "../data/Dataset_8/alt_20/genotypes_alteres.csv"
output_genotypes_file = "../data/Dataset_8/alt_20/k_1/imputed_genotypes.csv"

executable = "../src/infer_missing_data/infer_missing_data"
source_file = "../src/infer_missing_data/infer_missing_data.cpp"

compile_cmd = f"g++ -o {executable} {source_file} -std=c++11"
print(f"Compilation de l'exécutable : {compile_cmd}")
compile_exit_code = os.system(compile_cmd)

if compile_exit_code != 0:
    sys.stderr.write("Erreur lors de la compilation du programme C++.\n")
    sys.exit(1)
else:
    print("Compilation réussie.")


cmd = f"{executable} {parameters_file} {genotypes_file} {output_genotypes_file}"
print(f"Exécution de la commande : {cmd}")


exit_code = os.system(cmd)


if exit_code != 0:
    sys.stderr.write(f"Erreur lors de l'exécution de {cmd}\n")
    sys.exit(1)
else:
    print(f"Exécution réussie. Fichier des génotypes imputés enregistré dans {output_genotypes_file}")
