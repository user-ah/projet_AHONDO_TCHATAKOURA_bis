/**
 * @file hamming_distance_knn.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Computes the Hamming distance between two vectors of integers, ignoring missing values.
 * 
 * @details
 * This header file defines a function to compute the Hamming distance between two vectors of integers.
 * The Hamming distance is calculated as the number of differing positions between two vectors, while 
 * ignoring positions where the elements are marked as `-1`, which may represent missing or undefined data.
 * 
 * @section Features Key Features
 * - Computes the Hamming distance between two vectors of integers.
 * - Ignores positions with a value of `-1`, which may represent missing or undefined data.
 * - Designed for use in classification tasks such as K-Nearest Neighbors (KNN).
 * 
 * @section Preconditions Preconditions
 * - The vectors `a` and `b` must be of the same size.
 * - The vectors may contain integer values, with `-1` indicating missing or undefined values.
 * 
 * @section Output Output
 * - Returns an integer representing the Hamming distance between the two vectors.
 */
#ifndef HAMMING_DISTANCE_KNN_H
#define HAMMING_DISTANCE_KNN_H

#include <vector>
#include <string>
/**
 * @brief Computes the Hamming distance between two vectors, ignoring missing values (`-1`).
 * 
 * @details
 * This function calculates the Hamming distance by counting the number of differing positions between
 * two integer vectors while ignoring positions where either vector contains `-1`. This allows for 
 * flexibility in handling missing data.
 * 
 * @param a The first vector of integers.
 * @param b The second vector of integers.
 * 
 * @throws std::invalid_argument If the input vectors are not of the same size.
 * 
 * @return The computed Hamming distance between the two vectors.
 * 
 * @section Example Example Usage
 * @code
 * std::vector<int> vec1 = {0, 1, -1, 1, 0};
 * std::vector<int> vec2 = {0, -1, 1, 1, 1};
 * int distance = hammingDistance(vec1, vec2);
 * std::cout << "Hamming Distance: " << distance << std::endl; // Output: 2
 * @endcode
 * 
 * @see calculateAverageHammingDistance()
 */

inline int hammingDistance(const std::vector<int> &a, const std::vector<int> &b) {
    int distance = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != -1 && b[i] != -1 && a[i] != b[i]) {
            ++distance;
        }
    }
    return distance;
}

#endif
