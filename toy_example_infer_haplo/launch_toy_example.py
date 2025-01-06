import os
import sys
import subprocess

# Variables pour les fichiers et paramètres
genotypes_file = "../src/infer_haplo/genotypes.csv"
groundtruth_file = "../src/infer_haplo/haplotypes.csv"
InferedHaplotypes_file = "../src/infer_haplo/infered_haplo.csv"
log_file = "../src/infer_haplo/log.txt"
cpp_file = "../src/infer_haplo/infer_haplo.cpp"  # Fichier source C++

# Nom de l'exécutable
executable = "../src/infer_haplo/infer_haplo"

# Commande de compilation pour le fichier C++
compile_command = f"g++ -o {executable} {cpp_file}"

# Création de la commande
cmd = f"{executable} {genotypes_file} {groundtruth_file} {InferedHaplotypes_file} {log_file}"

# Vérification de la compilation
try:
    print(f"Compilation de {cpp_file}...")
    subprocess.run(compile_command, shell=True, check=True)
    print("Compilation réussie.")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Erreur lors de la compilation du fichier C++ : {cpp_file}\n{e}\n")
    sys.exit(1)

# Affichage de la commande pour validation
print(f"Exécution de la commande : {cmd}")

# Exécution de la commande
try:
    subprocess.run(cmd, shell=True, check=True)
    print("Exécution réussie.")
    print(f"Fichier généré :\n - {log_file}\n ")
except subprocess.CalledProcessError as e:
    sys.stderr.write(f"Erreur lors de l'exécution de la commande : {cmd}\n{e}\n")
    sys.exit(1)