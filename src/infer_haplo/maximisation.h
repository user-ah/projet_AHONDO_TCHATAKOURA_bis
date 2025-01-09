/*
    File: maximisation.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to update the frequencies of haplotypes based on the genotypes and their probabilities. 
    The maximization step of an Expectation-Maximization (EM) algorithm is implemented here, where the frequencies of haplotypes are adjusted according to the observed data.

    Key Features:
    - Updates haplotype frequencies based on genotype-probability pairs.
    - Iterates over all possible haplotype pairs to calculate their contributions.
    - Modifies the `frequencies` map to reflect the updated haplotype frequencies.

    Output:
    - The function updates the `frequencies` map to reflect the newly calculated haplotype frequencies.

    Preconditions:
    - The `genotypes` and `haplotypes` vectors must contain valid sequences.
    - The `probabilities` map must contain valid genotype probabilities.
    - The `frequencies` map must contain the current haplotype frequencies.
    - The `n_ind` parameter must represent the total number of individuals.
*/

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
