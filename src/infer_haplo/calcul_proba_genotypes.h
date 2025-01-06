#ifndef CALCUL_PROBA_GENOTYPES_H
#define CALCUL_PROBA_GENOTYPES_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include "vector_hash.h"
#include "explain_genotype.h"
/**
 * Calcule les probabilités des génotypes en fonction des fréquences des haplotypes.
 *
 * @param genotypes Liste des génotypes.
 * @param haplotypes Liste des haplotypes possibles.
 * @param frequencies Fréquences actuelles des haplotypes.
 * @param probabilities Probabilités des génotypes à mettre à jour.
 */
inline void calcul_proba_genotypes(
    const std::vector<std::vector<int>>& genotypes,
    const std::vector<std::vector<int>>& haplotypes,
    const std::unordered_map<std::vector<int>, double, VectorHash>& frequencies,
    std::unordered_map<std::vector<int>, double, VectorHash>& probabilities) {

    probabilities.clear();

    for (const auto& genotype : genotypes) {
        double proba = 0.0;

        for (const auto& h1 : haplotypes) {
            for (const auto& h2 : haplotypes) {
                if (explainGenotype(h1, h2, genotype)) {
                    double p1 = frequencies.at(h1);
                    double p2 = frequencies.at(h2);
                    double contrib = (h1 == h2) ? p1 * p1 : 2 * p1 * p2;
                    proba += contrib;
                }
            }
        }

        probabilities[genotype] = proba;
    }
}

#endif // CALCUL_PROBA_GENOTYPES_H
