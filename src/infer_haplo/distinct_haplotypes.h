
#ifndef CALCULATE_HAPLOTYPES_H
#define CALCULATE_HAPLOTYPES_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <fstream>
#include "vector_hash.h"

/**
 * @file calculateHaplotypes.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Provides functions for handling haplotype data.
 * 
 * @details
 * This header file defines several functions for processing haplotype information from CSV files. 
 * It includes functions to parse CSV lines, load haplotypes into an unordered set, and compute 
 * the number of distinct haplotypes.
 * 
 * @section Features Key Features
 * - Parses CSV lines into vectors of integers representing haplotypes.
 * - Loads haplotypes from a CSV file and stores them in an unordered set to eliminate duplicates.
 * - Computes the number of distinct haplotypes in a file.
 * 
 * @section Output Output
 * - Functions return sets of haplotypes or update the count of distinct haplotypes.
 * 
 * @section Preconditions Preconditions
 * - The CSV file must contain haplotypes represented as comma-separated integers.
 * - The input file must be accessible and formatted correctly.
 * 
 * @section Functions Available Functions
 * 
 * @brief Parses a CSV line into a vector of integers.
 * @param line The CSV line to parse.
 * @param delimiter The delimiter used in the CSV line (default is comma).
 * @return A vector of integers representing the haplotype.
 */

inline std::vector<int> parseCSVLine(const std::string& line, char delimiter = ',') {
    std::vector<int> haplotype;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        haplotype.push_back(std::stoi(token));
    }
    return haplotype;
}


/**
 * @brief Loads haplotypes from a CSV file and stores them in an unordered set.
 * 
 * @details This function reads a CSV file containing haplotypes, parses them into vectors of integers, 
 *          and stores them in an unordered set to remove duplicates.
 * 
 * @param haplotypesFile The path to the CSV file containing haplotypes.
 * @return An unordered set of vectors of integers representing the distinct haplotypes.
 * 
 * @throws std::runtime_error If the file cannot be opened or read.
 */
inline std::unordered_set<std::vector<int>, VectorHash> loadHaplotypesFromFile(const std::string& haplotypesFile) {
    std::ifstream file(haplotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << haplotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::unordered_set<std::vector<int>, VectorHash> haplotypes;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue; 
        haplotypes.insert(parseCSVLine(line));
    }

    return haplotypes;
}


/**
 * @brief Computes the number of distinct haplotypes from a CSV file.
 * 
 * @details This function reads haplotypes from a file and determines the count of unique haplotypes.
 * 
 * @param haplotypesFile The path to the CSV file containing haplotypes.
 * @param n_distinct_haplotypes A reference to a size_t variable to store the number of distinct haplotypes.
 * 
 * @throws std::runtime_error If the file cannot be opened or read.
 */

inline void DistinctHaplotypesFromFile(const std::string& haplotypesFile, size_t& n_distinct_haplotypes) {
    auto distinctHaplotypes = loadHaplotypesFromFile(haplotypesFile);
    n_distinct_haplotypes = distinctHaplotypes.size();
}

#endif
