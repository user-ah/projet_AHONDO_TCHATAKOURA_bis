/**
 * @file read_genotypes_knn.h
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Reads genotype data from a CSV file, handling missing values.
 * 
 * @details
 * This header file defines a function that reads genotype data from a CSV file and stores it in 
 * a 2D vector, where each row represents a genotype and each column represents a locus. 
 * Missing values in the CSV file, represented as `"NA"`, are converted to `-1` in the output vector.
 * 
 * @section Features Key Features
 * - Reads genotype data from a CSV file.
 * - Handles missing values by replacing `"NA"` with `-1`.
 * - Detects and reports errors for invalid or out-of-range values in the input file.
 * 
 * @section Preconditions Preconditions
 * - The input CSV file must contain genotype data, where each row represents an individual and 
 *   loci are separated by commas.
 * - Missing values must be represented by `"NA"` in the input file.
 * 
 * @section Output Output
 * - The function populates the `genotypes` vector with parsed data from the CSV file.
 */

#ifndef READ_GENOTYPES_KNN_H
#define READ_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

/**
 * @brief Reads genotype data from a CSV file and stores it in a 2D vector.
 * 
 * @details
 * This function reads a genotype dataset from a CSV file and stores it in a vector of vectors.
 * Each row in the file represents a genotype, and missing values (`"NA"`) are replaced by `-1` 
 * for easier processing in subsequent analyses.
 * 
 * @param filename The name of the CSV file containing genotype data.
 * @param genotypes A reference to a 2D vector that will store the parsed genotype data.
 * 
 * @throws std::runtime_error If the file cannot be opened.
 * @throws std::invalid_argument If the file contains invalid characters or missing values that are not `"NA"`.
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes;
 * readGenotypesKNN("data/genotypes.csv", genotypes);
 * 
 * for (const auto& genotype : genotypes) {
 *     for (int allele : genotype) {
 *         std::cout << allele << " ";
 *     }
 *     std::cout << std::endl;
 * }
 * @endcode
 * 
 * @see imputeMissingDataKNN()
 */
inline bool readGenotypes(const std::string &genotypes_file, std::vector<std::vector<int>> &genotypes) {
    std::ifstream file(genotypes_file);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open " << genotypes_file << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        
        while (std::getline(ss, cell, ',')) {
            try {
                if (cell == "NA") {  
                    row.push_back(-1);
                } else {
                    row.push_back(std::stoi(cell)); 
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error: Invalid cell '" << cell << "' in file " << genotypes_file << std::endl;
                return false;
            } catch (const std::out_of_range &e) {
                std::cerr << "Error: Out of range value in cell '" << cell << "' in file " << genotypes_file << std::endl;
                return false;
            }
        }

        
        genotypes.push_back(row);
    }

    file.close();
    return true;
}

#endif
