# Projet AHONDO & TCHATAKOURA

##  Introduction
Ce projet est réalisé dans le cadre du **Master de Bioinformatique** de **Nantes Université** (2024-2025) dans l'enseignement *Advanced Algorithmics and Programming for Biologists / Models, Methods and Algorithms for Bioinformatics* sous l'encadrement de **C. Sinoquet**.

L'objectif principal est d'implémenter un ensemble d'algorithmes en **C++**, avec des scripts complémentaires en **Python**, permettant de :
- Générer des données génotypiques et haplotypiques.
- Réaliser une **inférence d'haplotypes** à partir des génotypes en utilisant l'algorithme Expectation-Maximization (EM).
- **Altérer les données** pour simuler des valeurs manquantes.
- **Imputer les données manquantes** via l'algorithme des k plus proches voisins (**KNN**).
- Analyser l'impact du pourcentage de données manquantes sur la parcimonie de l'inférence d'haplotypes.

Ce projet suit des conventions strictes et est évalué sur plusieurs critères, notamment la **correction des algorithmes, la lisibilité et modularité du code, ainsi que la qualité des tests et résultats produits**.

##  Structure du Projet
Le projet est organisé comme suit :

```
projet_AHONDO_TCHATAKOURA_bis/
│── data/                 # Contient les jeux de données
│── docs/                 # Documentation générée par Doxygen
│── parameters/           # Fichiers de configuration et paramètres
│── script/               # Scripts pour la génération de génotypes et haplotypes
│   ├── create_geno_haplo_data.cpp
│   ├── generate_genotypes.h
│   ├── generate_haplotypes.h
│   ├── read_parameters.h
│   ├── save_csv.h
│── src/                  # Code source principal en C++
│   ├── alter_data/       # Code pour modifier les données de génotypes
│   │   ├── alter_data.cpp
│   │   ├── introduce_missing_data.h
│   │   ├── read_genotypes.h
│   │   ├── read_parameters.h
│   │   ├── write_genotypes.h
│   ├── infer_haplo/      # Code pour l'inférence des haplotypes
│   │   ├── assign_haplotypes.h
│   │   ├── calcul_proba_genotypes.h
│   │   ├── calculAverageHammingDistance.h
│   │   ├── calculHammingDistance.h
│   │   ├── distinct_haplotypes.h
│   │   ├── estimation_esperance.h
│   │   ├── explain_genotype.h
│   │   ├── generate_haplotypes.h
│   │   ├── genotype_reader.h
│   │   ├── haplotype_reader.h
│   │   ├── haplotype_reordering.h
│   │   ├── infer_haplo_1
│   │   ├── infer_haplo.cpp
│   │   ├── initialisation_frequences.h
│   │   ├── log_writer.h
│   │   ├── maximisation.h
│   │   ├── sort_haplotypes.h
│   │   ├── twoNumbersInGenotypes.h
│   │   ├── vector_hash.h
│── toy_example_alter_data/      # Exemples de test pour la modification des données
│   ├── launch_toy_example.py
│── toy_example_create_geno_haplo/ # Exemples de test pour la création de données
│   ├── launch_toy_example.py
│── toy_example_infer_haplo/     # Exemples de test pour l'inférence des haplotypes
│   ├── launch_toy_example.py
│── toy_example_infer_missing_data/ # Exemples de test pour l'imputation des données manquantes
│   ├── launch_toy_example.py
│── Doxyfile               # Fichier de configuration Doxygen
│── README.md              # Documentation du projet
```

##  Installation et Utilisation

### 1️⃣ **Installation de Doxygen**
Si Doxygen n'est pas encore installé, vous pouvez l'installer avec la commande suivante :
```bash
# Sous Linux (Debian/Ubuntu)
sudo apt install doxygen

# Sous macOS
brew install doxygen

# Sous Windows (via Chocolatey)
choco install doxygen
```

### 2️⃣ **Exécution des Scripts de Test**
Tous les tests et exécutions du projet sont automatisés à l'aide des fichiers `launch_toy_example.py` présents dans les sous-dossiers `toy_example_*`. Pour chaque module, il suffit de lancer le script correspondant :

```bash
# Génération des données génotypiques et haplotypiques
python toy_example_create_geno_haplo/launch_toy_example.py

# Inférence des haplotypes
python toy_example_infer_haplo/launch_toy_example.py

# Altération des données (ajout de valeurs manquantes)
python toy_example_alter_data/launch_toy_example.py

# Imputation des données manquantes avec KNN
python toy_example_infer_missing_data/launch_toy_example.py
```

Ces scripts lancent automatiquement les programmes C++ avec les bons paramètres et fichiers.

##  Documentation

La documentation technique est générée automatiquement avec **Doxygen**.

###  **Générer la documentation**
Si elle n’est pas encore générée, exécutez :
```bash
doxygen Doxyfile
```

###  **Accéder à la documentation**
Ouvrez le fichier **index.html** dans le dossier `docs/html/` :
```bash
open docs/html/index.html  # macOS
xdg-open docs/html/index.html  # Linux
```

##  Auteurs
- **Ahamed TCHATAKOURA**
- **Mawuéna AHONDO**

