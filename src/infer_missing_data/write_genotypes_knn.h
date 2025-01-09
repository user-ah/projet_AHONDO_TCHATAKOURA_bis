/*
    File: write_genotypes_knn.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to write the genotypes to a CSV file after imputation.
    The function will handle missing data represented by `-1` and replace it with "NA" in the output file.

    Key Features:
    - Writes the genotypes to a CSV file.
    - Replaces missing values (`-1`) with "NA" in the output file.
    - Writes each genotype row on a new line in the CSV file.

    Output:
    - The function writes the genotypes to the specified output file in CSV format.

    Preconditions:
    - The `genotypes` vector must contain the imputed genotype data.
    - The `output_file` should be a valid path where the output will be saved.
*/

#ifndef WRITE_GENOTYPES_KNN_H
#define WRITE_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

inline bool writeGenotypes(const std::string &output_file, const std::vector<std::vector<int>> &genotypes) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open " << output_file << std::endl;
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
