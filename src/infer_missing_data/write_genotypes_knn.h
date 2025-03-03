/**
 * @file write_genotypes_knn.h
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Writes the imputed genotype data to a CSV file, handling missing values.
 * 
 * @details
 * This header file defines a function that writes genotype data to a CSV file after imputation. 
 * The function ensures that missing values (represented by `-1`) are converted into `"NA"` in the output file, 
 * maintaining compatibility with standard genotype data formats.
 * 
 * @section Features Key Features
 * - Writes imputed genotype data to a CSV file.
 * - Replaces missing values (`-1`) with `"NA"` in the output file.
 * - Ensures each genotype row is correctly formatted in the CSV file.
 * 
 * @section Preconditions Preconditions
 * - The `genotypes` vector must contain valid imputed genotype data.
 * - The `output_file` must be a valid writable file path.
 * 
 * @section Output Output
 * - The function writes the genotype data to the specified output CSV file.
 * - Each genotype row is saved on a new line.
 */

#ifndef WRITE_GENOTYPES_KNN_H
#define WRITE_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
/**
 * @brief Writes the imputed genotype data to a CSV file, converting missing values to `"NA"`.
 * 
 * @details
 * This function takes a 2D vector of genotypes and writes it to a CSV file. Missing values (represented 
 * as `-1` in the vector) are replaced with `"NA"` in the output file to maintain standard formatting.
 * Each row of the matrix is written as a line in the CSV file.
 * 
 * @param output_file The path to the output CSV file where the genotypes will be saved.
 * @param genotypes A 2D vector containing the imputed genotype data.
 * 
 * @throws std::runtime_error If the output file cannot be opened for writing.
 * 
 * @return `true` if the file is successfully written, `false` otherwise.
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes = {
 *     {0, 1, -1, 1, 0},
 *     {1, 0, 1, -1, 1}
 * };
 * 
 * bool success = writeGenotypes("output/imputed_genotypes.csv", genotypes);
 * if (success) {
 *     std::cout << "File successfully written." << std::endl;
 * } else {
 *     std::cerr << "Error writing file." << std::endl;
 * }
 * @endcode
 * 
 * @see readGenotypesKNN()
 * @see imputeMissingDataKNN()
 */
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
