#ifndef EXPLAIN_GENOTYPE_H
#define EXPLAIN_GENOTYPE_H

#include <vector>
#include <new>
#include <stddef.h>

/**
 * Vérifie si une paire de haplotypes explique un génotype donné.
 *
 * @param h1 Premier haplotype.
 * @param h2 Deuxième haplotype.
 * @param genotype Génotype à vérifier.
 * @return true si (h1, h2) explique le génotype, false sinon.
 */

inline bool isValid(int haplo1, int haplo2, int genotype) {
    int haplo_sum = haplo1 + haplo2;
    if (haplo_sum == 0) return genotype == 0;
    if (haplo_sum == 1) return genotype == 2;
    if (haplo_sum == 2) return genotype == 1;
    return false; // Pour tout autre cas inattendu
}
 inline bool explainGenotype(const std::vector<int>& h1, const std::vector<int>& h2, const std::vector<int>& genotype) {
    for (size_t i = 0; i < genotype.size(); ++i) {
        if (!isValid(h1[i], h2[i], genotype[i])) {
            return false;
        }
    }
    return true;
}

#endif // EXPLAIN_GENOTYPE_H
