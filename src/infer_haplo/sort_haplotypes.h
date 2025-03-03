/**
 * @file sort_haplotypes.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Sorts haplotypes by their frequency in descending order.
 * 
 * @details
 * This header file defines a function that sorts haplotypes based on their frequency in descending order.
 * It takes an unordered map of haplotype frequencies as input and returns a vector of haplotype-frequency pairs 
 * sorted by frequency.
 * 
 * @section Features Key Features
 * - Sorts haplotypes based on their frequency.
 * - Returns a vector of haplotypes sorted in descending order of frequency.
 * 
 * @section Preconditions Preconditions
 * - The `frequencies` map must contain valid haplotypes and their corresponding frequencies.
 * - The map must not be empty.
 * 
 * @section Output Output
 * - The function returns a vector of pairs, where each pair consists of a haplotype and its frequency, 
 *   sorted by frequency in descending order.
 */

#ifndef SORT_HAPLOTYPES_H
#define SORT_HAPLOTYPES_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "vector_hash.h"

/**
 * @brief Sorts haplotypes by frequency in descending order.
 * 
 * @details
 * This function sorts haplotypes based on their frequency in descending order.
 * It takes a map of haplotype frequencies and returns a vector of haplotype-frequency pairs,
 * ensuring that the most frequent haplotypes appear first.
 * 
 * @param frequencies An unordered map where keys are haplotypes (represented as vectors of integers) 
 *        and values are their corresponding frequencies.
 * 
 * @throws std::invalid_argument If the input frequency map is empty.
 * 
 * @return A vector of pairs, where each pair contains a haplotype and its frequency, sorted in descending order.
 * 
 * @section Example Example Usage
 * @code
 * std::unordered_map<std::vector<int>, double, VectorHash> frequencies = {
 *     {{0,1,1}, 0.5}, {{1,0,1}, 0.3}, {{1,1,0}, 0.2}
 * };
 * std::vector<std::pair<std::vector<int>, double>> sortedHaplotypes = sortHaplotypesByFrequency(frequencies);
 * for (const auto& pair : sortedHaplotypes) {
 *     std::cout << "Haplotype: ";
 *     for (int allele : pair.first) std::cout << allele << " ";
 *     std::cout << " -> Frequency: " << pair.second << std::endl;
 * }
 * @endcode
 * 
 * @see assignHaplotypesOptimized()
 * @see initialisation_frequences_haplotypes()
 */

inline std::vector<std::pair<std::vector<int>, double>> sortHaplotypesByFrequency(
    const std::unordered_map<std::vector<int>, double, VectorHash>& frequencies) {

    std::vector<std::pair<std::vector<int>, double>> sortedHaplotypes(frequencies.begin(), frequencies.end());

    std::sort(sortedHaplotypes.begin(), sortedHaplotypes.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    return sortedHaplotypes;
}

#endif // SORT_HAPLOTYPES_H

