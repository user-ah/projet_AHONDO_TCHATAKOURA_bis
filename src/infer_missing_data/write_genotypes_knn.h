#ifndef WRITE_GENOTYPES_KNN_H
#define WRITE_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

inline bool writeGenotypes(const std::string &output_file, const std::vector<std::vector<int>> &genotypes) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir " << output_file << std::endl;
        return false;
    }
    for (const auto &row : genotypes) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (row[i] == -1) {
                file << "NA";
            } else {
                file << row[i];
            }
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }
    file.close();
    return true;
}

#endif
