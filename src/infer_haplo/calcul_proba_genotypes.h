/**
 * @file calcul_proba_genotypes.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Calculates the probabilities of genotypes based on haplotype frequencies.
 * 
 * @details 
 * This header file declares the function `calcul_proba_genotypes`, which computes the probability of 
 * each genotype by iterating over all possible haplotype pairs that could produce it. The calculation 
 * considers the frequencies of these haplotypes and updates a probability map accordingly.
 * 
 * @section Features Key Features
 * - Computes genotype probabilities using haplotype frequencies.
 * - Uses a vector-based representation for genotypes and haplotypes.
 * - Employs a hash map to efficiently store haplotype frequencies and genotype probabilities.
 * - Ensures the `probabilities` map is cleared before updating it with new values.
 * 
 * @section Preconditions Preconditions
 * - The input `genotypes` and `haplotypes` must be **non-empty** and correctly formatted.
 * - The `frequencies` map must contain **valid probability values** for all involved haplotypes.
 * - The sum of all haplotype frequencies should be close to 1 for accurate probability calculations.
 * 
 * @param genotypes A list of genotypes represented as vectors of integers.
 * @param haplotypes A list of possible haplotypes.
 * @param frequencies A hash map storing the current frequencies of each haplotype.
 * @param probabilities A hash map to store the calculated probabilities for each genotype.
 * 
 * @throws std::invalid_argument If the input data is empty or incorrectly formatted.
 * @throws std::out_of_range If an unexpected haplotype is not found in the frequency map.
 * 
 * @note The function **clears** the `probabilities` map before updating it with new values.
 * 
 * @return void
 * 
 * @see estimation_esperance()
 * @see maximisation()
 */

#ifndef CALCUL_PROBA_GENOTYPES_H
#define CALCUL_PROBA_GENOTYPES_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include "vector_hash.h"
#include "explain_genotype.h"

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
