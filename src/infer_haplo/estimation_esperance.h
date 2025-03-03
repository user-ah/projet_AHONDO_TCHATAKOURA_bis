/**
 * @file estimation_esperance.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Computes the log-likelihood from genotype probabilities.
 * 
 * @details
 * This header file declares the function `estimation_esperance`, which calculates the 
 * log-likelihood value based on haplotype frequencies and observed genotypes. The function 
 * iterates over all genotypes and sums the logarithm of their probabilities to determine 
 * the overall likelihood of the observed data.
 * 
 * @section Features Key Features
 * - Computes the log-likelihood for a given set of genotypes and haplotype frequencies.
 * - Supports a vector-based representation of genotypes and haplotypes.
 * - Uses logarithmic scaling to improve numerical stability.
 * 
 * @section Preconditions Preconditions
 * - The `genotypes` matrix must be provided as a vector of vectors of integers.
 * - The `haplotypes` set must be a vector of vectors of integers representing all candidate haplotypes.
 * - The `frequencies` map must contain valid frequency values for all haplotypes.
 * 
 * @param genotypes A vector of vectors of integers representing the genotype matrix.
 * @param haplotypes A vector of vectors of integers representing the haplotypes.
 * @param frequencies An unordered map with vectors of integers as keys and doubles as values, 
 * representing the frequencies corresponding to each haplotype.
 * 
 * @throws std::invalid_argument If the input data is empty or incorrectly formatted.
 * @throws std::out_of_range If an expected haplotype is not found in the frequency map.
 * 
 * @return The computed log-likelihood value based on the provided genotype data and haplotype frequencies.
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes = {{0,1,2}, {1,0,1}};
 * std::vector<std::vector<int>> haplotypes = {{0,1,1}, {1,0,1}};
 * std::unordered_map<std::vector<int>, double, VectorHash> frequencies = {
 *     {{0,1,1}, 0.6}, {{1,0,1}, 0.4}
 * };
 * double logLikelihood = estimation_esperance(genotypes, haplotypes, frequencies);
 * std::cout << "Log-likelihood: " << logLikelihood << std::endl;
 * @endcode
 * 
 * @see calcul_proba_genotypes()
 * @see maximisation()
 */


#ifndef ESTIMATION_ESPERANCE_H
#define ESTIMATION_ESPERANCE_H

#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include "vector_hash.h"
#include "explain_genotype.h"

inline double estimation_esperance(
    const std::vector<std::vector<int>>& genotypes,
    const std::vector<std::vector<int>>& haplotypes,
    const std::unordered_map<std::vector<int>, double, VectorHash>& frequencies) {

    double loglikelihood = 0.0;

    for (const auto& genotype : genotypes) {
        double proba_g = 0.0;

        for (const auto& h1 : haplotypes) {
            for (const auto& h2 : haplotypes) {
                if (explainGenotype(h1, h2, genotype)) {
                    double p1 = frequencies.at(h1);
                    double p2 = frequencies.at(h2);
                    proba_g += (h1 == h2) ? p1 * p1 : 2 * p1 * p2;
                }
            }
        }

        if (proba_g > 0) {
            loglikelihood += std::log(proba_g);
        }
    }

    std::cout << "Log-likelihood : " << loglikelihood << std::endl;

    return loglikelihood;
}

#endif 
