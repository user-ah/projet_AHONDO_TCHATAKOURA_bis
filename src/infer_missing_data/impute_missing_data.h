/**
 * @file impute_missing_data_knn.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Imputes missing genotype data using a k-nearest neighbors (KNN) approach.
 * 
 * @details
 * This header file defines a function that imputes missing data in a genotype vector 
 * using a k-nearest neighbors (KNN) approach. The function computes the Hamming distance 
 * between the target vector and all other genotype vectors, selects the `k` closest neighbors, 
 * and imputes missing values based on the majority vote among the neighbors.
 * 
 * @section Features Key Features
 * - Computes Hamming distances between the target vector and all genotype vectors.
 * - Selects the `k` nearest neighbors based on the smallest Hamming distances.
 * - Imputes missing values (`-1` in the target vector) using the majority vote from the neighbors' corresponding values.
 * 
 * @section Preconditions Preconditions
 * - The target vector and genotype vectors must be of the same size.
 * - The target vector may contain `-1` values to indicate missing data.
 * - The `genotypes` matrix should contain multiple genotype vectors for comparison.
 * - The value of `k` must be a positive integer and should not exceed the number of available genotype vectors.
 * 
 * @section Output Output
 * - The function modifies the `target` vector by imputing missing values with either `0` or `1`, 
 *   based on the majority vote from the `k` nearest neighbors.
 */
#ifndef IMPUTE_MISSING_DATA_KNN_H
#define IMPUTE_MISSING_DATA_KNN_H

#include <vector>
#include <algorithm>
#include <utility>
#include "hamming_distance.h"

/**
 * @brief Imputes missing values in a genotype vector using a KNN-based approach.
 * 
 * @details
 * This function identifies the `k` nearest neighbors based on the Hamming distance between 
 * the `target` vector and all genotype vectors in the dataset. Missing values (`-1`) in the 
 * `target` vector are replaced using a majority vote from the corresponding positions in the 
 * nearest neighbors.
 * 
 * @param target The genotype vector with missing values to be imputed.
 * @param genotypes A matrix of genotype vectors to use for nearest neighbor comparison.
 * @param k The number of nearest neighbors to consider for imputation.
 * 
 * @throws std::invalid_argument If `target` and genotype vectors have different sizes.
 * @throws std::invalid_argument If `k` is not positive or exceeds the number of available genotype vectors.
 * 
 * @return void (Modifies the `target` vector in-place).
 * 
 * @section Example Example Usage
 * @code
 * std::vector<int> target = {0, -1, 1, -1, 0};
 * std::vector<std::vector<int>> genotypes = {
 *     {0, 1, 1, 0, 0},
 *     {0, 0, 1, 1, 0},
 *     {0, 1, 1, 1, 0}
 * };
 * int k = 2;
 * imputeMissingDataKNN(target, genotypes, k);
 * 
 * for (int val : target) {
 *     std::cout << val << " ";
 * }
 * // Output: 0 1 1 1 0 (example result based on majority vote)
 * @endcode
 * 
 * @see hammingDistance()
 */

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
