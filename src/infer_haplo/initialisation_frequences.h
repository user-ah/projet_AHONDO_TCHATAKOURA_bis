#ifndef INITIALISATION_FREQUENCES_H
#define INITIALISATION_FREQUENCES_H

#include <unordered_map>
#include <vector>
#include "vector_hash.h"
/**
 * Initialise les fréquences des haplotypes.
 *
 * Chaque haplotype a une probabilité initiale uniforme de 1 / (nombre total d'haplotypes).
 *
 * @param haplotypes Ensemble des haplotypes distincts.
 * @param frequencies Carte pour stocker les fréquences des haplotypes.
 */
inline void initialisation_frequences_haplotypes(
    const std::vector<std::vector<int>>& haplotypes, 
    std::unordered_map<std::vector<int>, double, VectorHash>& frequencies) {
    double p = 1.0 / haplotypes.size();
    for (const auto& haplotype : haplotypes) {
        frequencies[haplotype] = p;
    }
}

#endif // INITIALISATION_FREQUENCES_H
