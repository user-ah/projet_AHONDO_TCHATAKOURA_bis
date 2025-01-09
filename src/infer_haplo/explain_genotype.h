/*
    File: explainGenotype.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to check if a pair of haplotypes can explain a given genotype.
    The function checks if each corresponding allele in the haplotypes matches the genotype according 
    to the expected inheritance rules, using a helper function to validate individual alleles.

    Key Features:
    - Verifies if two haplotypes can explain a given genotype.
    - Utilizes a helper function to validate the compatibility of allele pairs with the genotype.
    - Works on a vector-based representation of haplotypes and genotypes.

    Output:
    - Returns `true` if the haplotypes (h1, h2) explain the genotype, and `false` otherwise.

    Preconditions:
    - The input haplotypes and genotypes are provided as vectors of integers, with each vector
      representing a sequence of alleles for a particular individual.
*/
#ifndef EXPLAIN_GENOTYPE_H
#define EXPLAIN_GENOTYPE_H

#include <vector>
#include <new>
#include <stddef.h>

inline bool isValid(int haplo1, int haplo2, int genotype) {
    int haplo_sum = haplo1 + haplo2;
    if (haplo_sum == 0) return genotype == 0;
    if (haplo_sum == 1) return genotype == 2;
    if (haplo_sum == 2) return genotype == 1;
    return false; 
}

inline bool explainGenotype(const std::vector<int>& h1, const std::vector<int>& h2, const std::vector<int>& genotype) {
    for (size_t i = 0; i < genotype.size(); ++i) {
        if (!isValid(h1[i], h2[i], genotype[i])) {
            return false;
        }
    }
    return true;
}

#endif 
