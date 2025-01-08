#ifndef READ_GENOTYPES_KNN_H
#define READ_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

inline bool readGenotypes(const std::string &genotypes_file, std::vector<std::vector<int>> &genotypes) {
    std::ifstream file(genotypes_file);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir " << genotypes_file << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        // Lire chaque cellule séparée par une virgule
        while (std::getline(ss, cell, ',')) {
            try {
                if (cell == "NA") {  // Valeur manquante
                    row.push_back(-1);
                } else {
                    row.push_back(std::stoi(cell));  // Convertir la cellule en entier
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Erreur : Cellule invalide '" << cell << "' dans le fichier " << genotypes_file << std::endl;
                return false;
            } catch (const std::out_of_range &e) {
                std::cerr << "Erreur : Valeur hors plage dans la cellule '" << cell << "' dans le fichier " << genotypes_file << std::endl;
                return false;
            }
        }

        // Ajouter la ligne lue aux génotypes
        genotypes.push_back(row);
    }

    file.close();
    return true;
}

#endif
