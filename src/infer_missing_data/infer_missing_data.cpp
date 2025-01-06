#include <iostream>
#include <vector>
#include <string>
#include "read_parameters_knn.h"
#include "read_genotypes_knn.h"
#include "impute_missing_data.h"
#include "write_genotypes_knn.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <parameters.txt> <genotypes.csv> <output_genotypes.csv>" << std::endl;
        return 1;
    }

    std::string parameters_file = argv[1];
    std::string genotypes_file = argv[2];
    std::string output_file = argv[3];

    // Lire les paramètres
    int k = 0;
    if (!readParameters(parameters_file, k)) {
        return 1;
    }
    std::cout << "Valeur de k : " << k << std::endl;

    // Lire les génotypes
    std::vector<std::vector<int>> genotypes;
    if (!readGenotypes(genotypes_file, genotypes)) {
        return 1;
    }

    // Imputer les données manquantes pour chaque ligne
    for (auto &row : genotypes) {
        imputeMissingData(row, genotypes, k);
    }

    // Enregistrer le fichier avec les données imputées
    if (!writeGenotypes(output_file, genotypes)) {
        return 1;
    }

    std::cout << "Imputation terminée. Fichier enregistré : " << output_file << std::endl;
    return 0;
}
