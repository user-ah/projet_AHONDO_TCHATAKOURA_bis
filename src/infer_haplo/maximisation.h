#ifndef MAXIMISATION_H
#define MAXIMISATION_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include "vector_hash.h"


#include "explain_genotype.h"

/**
 * Met à jour les fréquences des haplotypes en fonction des génotypes et de leurs probabilités.
 *
 * @param genotypes Liste des génotypes.
 * @param haplotypes Liste des haplotypes possibles.
 * @param frequencies Fréquences actuelles des haplotypes à mettre à jour.
 * @param probabilities Probabilités des génotypes calculées.
 * @param n_ind Nombre total d'individus.
 */
inline void maximisation(
    const std::vector<std::vector<int>>& genotypes,
    const std::vector<std::vector<int>>& haplotypes,
    std::unordered_map<std::vector<int>, double, VectorHash>& frequencies,
    const std::unordered_map<std::vector<int>, double, VectorHash>& probabilities,
    int n_ind) {

    std::unordered_map<std::vector<int>, double, VectorHash> new_frequencies;

    for (const auto& h1 : haplotypes) {
        double freq = 0.0;

        for (const auto& genotype : genotypes) {
            double proba_g = probabilities.at(genotype);

            for (const auto& h2 : haplotypes) {
                if (explainGenotype(h1, h2, genotype)) {
                    double contrib = (h1 == h2) ?
                                     (2 * frequencies.at(h1) * frequencies.at(h1)) / proba_g :
                                     (2 * frequencies.at(h1) * frequencies.at(h2)) / proba_g;
                    freq += contrib / n_ind;
                }
            }
        }

        new_frequencies[h1] = freq / 2;
    }

    frequencies = new_frequencies;

}

#endif // MAXIMISATION_H
