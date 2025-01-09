/*
    File: initialisation_frequences.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to initialize the frequencies of distinct haplotypes. 
    The frequencies are set to an equal probability value, which is 1 divided by the total number of distinct haplotypes.

    Key Features:
    - Initializes haplotype frequencies with an equal value.
    - Stores haplotype frequencies in a map.
    
    Output: 
    - The function modifies the `frequencies` map to assign an equal probability to each haplotype.

    Preconditions:
    - The `haplotypes` vector must contain distinct haplotype sequences.
    - The `frequencies` map is assumed to be empty at the start and will be populated by this function.
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
