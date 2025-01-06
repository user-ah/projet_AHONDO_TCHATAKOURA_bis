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

    // Copier les fréquences dans un vecteur pour le tri
    std::vector<std::pair<std::vector<int>, double>> sortedHaplotypes(frequencies.begin(), frequencies.end());

    // Trier par fréquence décroissante
    std::sort(sortedHaplotypes.begin(), sortedHaplotypes.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    return sortedHaplotypes;
}

#endif // SORT_HAPLOTYPES_H

