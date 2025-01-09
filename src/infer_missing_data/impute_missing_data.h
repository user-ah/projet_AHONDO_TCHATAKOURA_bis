/*
    File: impute_missing_data_knn.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to impute missing data in a genotype vector using a k-nearest neighbors (KNN) approach. 
    The function calculates the Hamming distance between the target vector and all other genotype vectors, identifies the `k` closest neighbors, 
    and imputes missing values based on the majority value among the neighbors.

    Key Features:
    - Computes Hamming distances between the target vector and all genotype vectors.
    - Selects the `k` nearest neighbors based on the smallest Hamming distance.
    - Imputes missing values (`-1` in the target vector) using the majority vote from the neighbors' corresponding values.

    Output:
    - The function modifies the `target` vector by imputing missing values with either `0` or `1`, based on the majority vote from the closest neighbors.

    Preconditions:
    - The target vector and genotype vectors must be of the same size.
    - The target vector may contain `-1` values to indicate missing data.
    - The `genotypes` matrix should contain multiple genotype vectors to compare against.
*/

#ifndef IMPUTE_MISSING_DATA_KNN_H
#define IMPUTE_MISSING_DATA_KNN_H

#include <vector>
#include <algorithm>
#include <utility>
#include "hamming_distance.h"

inline void imputeMissingData(std::vector<int> &target, const std::vector<std::vector<int>> &genotypes, int k) {
    std::vector<std::pair<int, int>> distances; 

    for (size_t i = 0; i < genotypes.size(); ++i) {
        int distance = hammingDistance(target, genotypes[i]);
        distances.emplace_back(distance, i);
    }
    
    std::sort(distances.begin(), distances.end());

    
    for (size_t i = 0; i < target.size(); ++i) {
        if (target[i] == -1) { 
            std::vector<int> values; 
            for (int j = 0; j < k && j < distances.size(); ++j) {
                int neighbor_index = distances[j].second;
                if (genotypes[neighbor_index][i] != -1) { 
                    values.push_back(genotypes[neighbor_index][i]);
                }
            }
            if (!values.empty()) {
                
                int ones = std::count(values.begin(), values.end(), 1);
                int zeros = std::count(values.begin(), values.end(), 0);
                target[i] = (ones >= zeros) ? 1 : 0;
            }
        }
    }
}

#endif
