
/**
 * @file initialisation_frequences.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Initializes the frequencies of distinct haplotypes.
 * 
 * @details
 * This header file defines a function to initialize the frequencies of distinct haplotypes. 
 * The frequencies are assigned an equal probability, calculated as \( 1 / N \), where \( N \) 
 * is the total number of distinct haplotypes.
 * 
 * @section Features Key Features
 * - Initializes haplotype frequencies with an equal probability value.
 * - Stores haplotype frequencies in a hash map for fast retrieval.
 * - Ensures that all haplotypes have a valid initial frequency.
 * 
 * @section Preconditions Preconditions
 * - The `haplotypes` vector must contain distinct haplotype sequences.
 * - The `frequencies` map must be empty at the start and will be populated by this function.
 * - The number of haplotypes must be greater than zero to avoid division by zero.
 * 
 * @section Output Output
 * - The function populates the `frequencies` map, assigning an equal probability to each haplotype.
 */

/**
 * @brief Initializes the frequencies of distinct haplotypes with an equal probability.
 * 
 * @details
 * This function assigns an equal probability to each unique haplotype present in the input list. 
 * The probabilities are stored in a hash map for efficient lookup.
 * 
 * @param haplotypes A vector containing distinct haplotypes.
 * @param frequencies An unordered map to store the haplotype frequencies.
 * 
 * @throws std::invalid_argument If the haplotype vector is empty (to avoid division by zero).
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> haplotypes = {{0,1,1}, {1,0,1}, {1,1,0}};
 * std::unordered_map<std::vector<int>, double, VectorHash> frequencies;
 * initialisation_frequences_haplotypes(haplotypes, frequencies);
 * 
 * for (const auto& pair : frequencies) {
 *     std::cout << "Haplotype: ";
 *     for (int allele : pair.first) std::cout << allele << " ";
 *     std::cout << " -> Frequency: " << pair.second << std::endl;
 * }
 * @endcode
 * 
 * @see estimation_esperance()
 * @see calcul_proba_genotypes()
 */

#ifndef INITIALISATION_FREQUENCES_H
#define INITIALISATION_FREQUENCES_H

#include <unordered_map>
#include <vector>
#include "vector_hash.h"

/**
 * Initializes the frequencies of the haplotypes.
 *
 * Each haplotype is assigned an equal initial probability of 1 / (total number of haplotypes).
 *
 * @param haplotypes A collection of distinct haplotypes.
 * @param frequencies A map to store the haplotype frequencies.
 */
inline void initialisation_frequences_haplotypes(
    const std::vector<std::vector<int>>& haplotypes, 
    std::unordered_map<std::vector<int>, double, VectorHash>& frequencies) {
    double p = 1.0 / haplotypes.size();
    for (const auto& haplotype : haplotypes) {
        frequencies[haplotype] = p; 
    }
}

#endif 
