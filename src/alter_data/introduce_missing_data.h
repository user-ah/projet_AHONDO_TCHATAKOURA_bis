/**
 * @file introduce_missing_data.h
 * @brief Defines a function to introduce missing data into a genotype matrix.
 * 
 * This header file contains the declaration of a function that introduces missing data into a genotype matrix.
 * The percentage of missing data is specified as a parameter, and the function randomly replaces elements in the matrix 
 * with a sentinel value (-1) to represent missing data.
 * 
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * 
 * @details
 * - Supports input genotype matrices of any size.
 * - Randomly introduces missing data based on the specified percentage.
 * - Utilizes standard library functions for randomness.
 * 
 * @pre
 * - The input genotype matrix must be non-empty and rectangular.
 * - The percentage of missing data should be between 0 and 100.
 * 
 * @param genotypes A reference to a 2D vector representing the genotype matrix.
 * @param percentMiss A float representing the percentage of missing data to introduce.
 * 
 * @return The modified genotype matrix with missing data represented by -1.
 */

#ifndef INTRODUCE_MISSING_DATA_H
#define INTRODUCE_MISSING_DATA_H

#include <vector>
#include <cstdlib>
#include <ctime>

inline void introduceMissingData(std::vector<std::vector<int>>& genotypes, float percentMiss) {
    int totalElements = genotypes.size() * genotypes[0].size();
    int missingCount = static_cast<int>(percentMiss * totalElements / 100);

    std::srand(std::time(nullptr));
    while (missingCount > 0) {
        int i = std::rand() % genotypes.size();
        int j = std::rand() % genotypes[0].size();

        if (genotypes[i][j] != -1) { // -1 indicates missing data
            genotypes[i][j] = -1;
            --missingCount;
        }
    }
}

#endif
