/**
 * @file calculHammingDistance.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Computes the Hamming distance between two haplotypes.
 * 
 * @details
 * This header file declares the function `calculateHammingDistance`, which computes the 
 * Hamming distance between two haplotypes represented as vectors of integers. The Hamming 
 * distance is the number of positions where the corresponding elements of the two vectors differ.
 * 
 * The function ensures that both input haplotypes have the same length before performing the 
 * calculation. If they have different lengths, an exception is thrown.
 * 
 * @section Features Key Features
 * - Computes the Hamming distance between two haplotypes.
 * - Validates that both input vectors have the same size.
 * - Returns an integer representing the number of differing positions.
 * 
 * @section Preconditions Preconditions
 * - The two input haplotypes must have the same size (number of loci).
 * 
 * @param haplo1 The first haplotype, represented as a vector of integers.
 * @param haplo2 The second haplotype, represented as a vector of integers.
 * 
 * @throws std::invalid_argument If the two haplotypes have different sizes.
 * 
 * @return The Hamming distance (integer) between the two haplotypes.
 * 
 * @section Example Usage Example
 * @code
 * std::vector<int> haplo1 = {1, 0, 1, 1};
 * std::vector<int> haplo2 = {1, 1, 0, 1};
 * int distance = calculateHammingDistance(haplo1, haplo2);
 * std::cout << "Hamming Distance: " << distance << std::endl; // Output: Hamming Distance: 2
 * @endcode
 * 
 * @see calculateAverageHammingDistance()
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

inline int calculateHammingDistance(const std::vector<int>& haplo1, const std::vector<int>& haplo2) {
    if (haplo1.size() != haplo2.size()) {
        std::cerr << "Error: The haplotypes have different dimensions." << std::endl;
        exit(EXIT_FAILURE);
    }

    int distance = 0;
    for (size_t i = 0; i < haplo1.size(); ++i) {
        if (haplo1[i] != haplo2[i]) {
            distance++;
        }
    }
    return distance;
}
