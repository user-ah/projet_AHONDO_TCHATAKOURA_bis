/*
    File: introduce_missing_data.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to introduce missing data into a genotype matrix. 
    The percentage of missing data is specified as a parameter, and the function randomly 
    replaces elements in the matrix with a sentinel value (-1) to represent missing data.

    Key Features:
    - Supports input genotype matrices of any size.
    - Randomly introduces missing data based on the specified percentage.
    - Utilizes standard library functions for randomness.

    Output: The modified genotype matrix with missing data represented by -1.

    Preconditions:
    - The input genotype matrix must be non-empty and rectangular.
    - The percentage of missing data should be between 0 and 100.
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
