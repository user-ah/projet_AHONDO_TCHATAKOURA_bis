/*
    File: estimationEsperance.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to calculate the log-likelihood from the genotype probabilities. 
    The function computes the log-likelihood based on the given frequencies of haplotypes and the 
    genotypes. It sums the log of genotype probabilities over all provided genotypes.

    Key Features:
    - Calculates the log-likelihood from genotype and haplotype probabilities.
    - Supports a vector-based representation of genotypes and haplotypes.
    - Uses logarithmic scaling to compute the log-likelihood.

    Output:
    - Returns the log-likelihood value of the provided genotypes based on the haplotype frequencies.

    Preconditions:
    - The input genotype matrix must be provided as a vector of vectors of integers.
    - The haplotype frequency map must be provided, with frequencies corresponding to each haplotype.
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
