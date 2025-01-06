#ifndef WRITE_GENOTYPES_H
#define WRITE_GENOTYPES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

inline void writeGenotypes(const std::string& outputFile, const std::vector<std::vector<int>>& genotypes) {
    std::ofstream file(outputFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'écrire dans le fichier " << outputFile << std::endl;
        exit(EXIT_FAILURE);
    }

    for (const auto& row : genotypes) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (row[i] == -1) {
                file << "NA";
            } else {
                file << row[i];
            }
            if (i < row.size() - 1) {
                file << " ";
            }
        }
        file << "\n";
    }
    file.close();
}

#endif
