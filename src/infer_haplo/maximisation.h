/**
 * @file maximisation.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Updates haplotype frequencies in the maximization step of the Expectation-Maximization (EM) algorithm.
 * 
 * @details
 * This header file defines a function that updates haplotype frequencies based on observed genotypes 
 * and their probabilities. The function implements the maximization step of the Expectation-Maximization (EM) algorithm, 
 * adjusting haplotype frequencies according to the likelihood contributions from genotype-probability pairs.
 * 
 * The key steps in this function include:
 * - Iterating over all possible haplotype pairs.
 * - Computing their contribution to the observed genotypes.
 * - Updating the frequencies accordingly.
 * 
 * @section Features Key Features
 * - Updates haplotype frequencies based on genotype-probability pairs.
 * - Iterates over all possible haplotype pairs to calculate their contributions.
 * - Modifies the `frequencies` map to reflect the updated haplotype frequencies.
 * 
 * @section Preconditions Preconditions
 * - The `genotypes` and `haplotypes` vectors must contain valid sequences.
 * - The `probabilities` map must contain valid genotype probabilities.
 * - The `frequencies` map must contain the current haplotype frequencies.
 * - The `n_ind` parameter must represent the total number of individuals.
 * 
 * @section Output Output
 * - The function updates the `frequencies` map with the newly calculated haplotype frequencies.
 */


#ifndef MAXIMISATION_H
#define MAXIMISATION_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include "vector_hash.h"
#include "explain_genotype.h"

/**
 * @brief Updates haplotype frequencies based on observed genotypes and their probabilities.
 * 
 * @details
 * This function performs the maximization step in the Expectation-Maximization (EM) algorithm by adjusting 
 * the haplotype frequencies. It computes the contributions of each haplotype pair to the genotype probabilities 
 * and updates the frequency map accordingly.
 * 
 * @param genotypes A vector of vectors representing the observed genotypes.
 * @param haplotypes A vector of vectors representing the possible haplotypes.
 * @param frequencies An unordered map containing the current frequencies of haplotypes.
 * @param probabilities An unordered map storing the computed probabilities for each genotype.
 * @param n_ind The total number of individuals in the dataset.
 * 
 * @throws std::invalid_argument If any input vector is empty or improperly formatted.
 * @throws std::runtime_error If an unexpected issue occurs during frequency calculation.
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes = {{0,1,1}, {1,0,1}};
 * std::vector<std::vector<int>> haplotypes = {{0,1,1}, {1,0,1}};
 * std::unordered_map<std::vector<int>, double, VectorHash> frequencies = {
 *     {{0,1,1}, 0.5}, {{1,0,1}, 0.5}
 * };
 * std::unordered_map<std::vector<int>, double, VectorHash> probabilities = {
 *     {{0,1,1}, 0.7}, {{1,0,1}, 0.3}
 * };
 * maximisation(genotypes, haplotypes, frequencies, probabilities, 100);
 * @endcode
 * 
 * @see estimation_esperance()
 * @see calcul_proba_genotypes()
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
