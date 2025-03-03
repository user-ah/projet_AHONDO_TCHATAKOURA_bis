/**
 * @file generate_haplotypes.h
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * @brief This header file defines the function `generate_haplotypes`, which generates random haplotypes 
 * for a given population of individuals.
 *
 * The function creates a set of distinct haplotypes, then pairs them randomly to generate haplotypes 
 * for each individual.
 *
 * @details
 * - First, the function generates `n_distinct_haplo` distinct haplotypes, each having `n_loci` loci, 
 *   with each locus being randomly assigned a value of 0 or 1.
 * - Then, it randomly selects pairs of haplotypes from the distinct haplotypes and assigns them to individuals.
 *
 * @param n_ind The number of individuals (i.e., the number of haplotype pairs to generate).
 * @param n_loci The number of loci (genetic markers) in each haplotype.
 * @param n_distinct_haplo The number of distinct haplotypes to generate.
 *
 * @return A 2D vector representing the haplotypes for all individuals. Each individual has two 
 * associated haplotypes.
 */


#ifndef GENERATE_HAPLOTYPES_H
#define GENERATE_HAPLOTYPES_H

#include <vector>
#include <cstdlib>

inline std::vector<std::vector<int>> generate_haplotypes(int n_ind, int n_loci, int n_distinct_haplo) {
    std::vector<std::vector<int>> distinct_haplotypes;

    for (int i = 0; i < n_distinct_haplo; ++i) {
        std::vector<int> haplotype;
        for (int j = 0; j < n_loci; ++j) {
            haplotype.push_back(rand() % 2);
        }
        distinct_haplotypes.push_back(haplotype);
    }

    std::vector<std::vector<int>> haplotypes;

    for (int i = 0; i < n_ind; ++i) {
        int haplo1_idx = rand() % n_distinct_haplo;
        int haplo2_idx = rand() % n_distinct_haplo;

        haplotypes.push_back(distinct_haplotypes[haplo1_idx]);
        haplotypes.push_back(distinct_haplotypes[haplo2_idx]);
    }

    return haplotypes;
}

#endif
