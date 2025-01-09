/*
    File: write_genotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to write genotype data to a specified output file. 
    The function formats the genotype matrix, replacing missing values (-1) with "NA", 
    and saves the data in a space-separated format.

    Key Features:
    - Writes a 2D vector of genotypes to a file.
    - Handles missing data by writing "NA" for values marked as -1.
    - Ensures the output format is consistent with a space-separated structure.

    Output: A text file containing the genotype matrix in a space-separated format.

    Preconditions:
    - The output file must be writable.
    - The genotype matrix must be properly formatted with integers or -1 for missing values.
*/
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
