#ifndef READ_GENOTYPES_H
#define READ_GENOTYPES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

inline void readGenotypes(const std::string& genotypesFile, std::vector<std::vector<int>>& genotypes) {
    std::ifstream file(genotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << genotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (std::isdigit(c)) {
                row.push_back(c - '0');
            }
        }
        genotypes.push_back(row);
    }
    file.close();
}

#endif
