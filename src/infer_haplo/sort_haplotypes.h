/*
    File: sort_haplotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to sort haplotypes by their frequency in descending order.
    The function takes a map of haplotype frequencies and returns a vector of haplotypes sorted based on their frequency.

    Key Features:
    - Sorts haplotypes based on their frequency.
    - Returns a vector of haplotypes sorted in descending order of frequency.

    Output:
    - The function returns a vector of pairs, where each pair contains a haplotype and its frequency,
      sorted by frequency in descending order.

    Preconditions:
    - The `frequencies` map must contain valid haplotypes and their corresponding frequencies.
*/

#ifndef SORT_HAPLOTYPES_H
#define SORT_HAPLOTYPES_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "vector_hash.h"

/**
 * Trie les haplotypes par fréquence décroissante.
 *
 * @param frequencies Carte des fréquences des haplotypes.
 * @return Un vecteur contenant les haplotypes triés par fréquence décroissante.
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

