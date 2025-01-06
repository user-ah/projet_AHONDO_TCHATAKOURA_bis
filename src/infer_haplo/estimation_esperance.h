#ifndef ESTIMATION_ESPERANCE_H
#define ESTIMATION_ESPERANCE_H

#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include "vector_hash.h"
#include "explain_genotype.h"




/**
 * Calcule le log-likelihood à partir des probabilités des génotypes.
 *
 * @param genotypes Liste des génotypes.
 * @param haplotypes Liste des haplotypes possibles.
 * @param frequencies Fréquences des haplotypes actuelles.
 * @return Log-likelihood.
 */
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

#endif // ESTIMATION_ESPERANCE_H
