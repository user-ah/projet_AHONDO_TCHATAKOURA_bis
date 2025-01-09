/*
    File: calcul_proba_genotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to calculate the probabilities of genotypes 
    based on the frequencies of haplotypes. The function iterates over a list of genotypes 
    and calculates their probabilities by considering all possible pairs of haplotypes 
    that could give rise to the genotype. The calculation incorporates the frequencies 
    of the haplotypes involved.

    Key Features:
    - Calculates genotype probabilities using haplotype frequencies.
    - Handles genotype and haplotype data represented as vectors of integers.
    - Uses a hash map to store the haplotype frequencies and genotype probabilities.

    Output: Updates the `probabilities` map with calculated probabilities for each genotype.

    Preconditions:
    - The input `genotypes` and `haplotypes` must be non-empty and correctly formatted.
    - The `frequencies` map should contain valid data for all haplotypes involved.
*/
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

#endif 
