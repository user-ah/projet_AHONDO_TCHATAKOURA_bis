/*
    File: generate_genotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines the function `generate_genotypes`, which takes pairs of haplotypes 
    as input and generates corresponding genotypes based on these haplotypes. The genotypes are 
    returned as a 2D vector, where each genotype corresponds to the alleles inherited from 
    both haplotypes.

    Key Functionality:
    - The function loops over pairs of haplotypes and constructs genotypes by combining the 
      alleles at each locus. 
    - If both haplotypes have the same allele (0 or 1), the genotype will reflect that allele; 
      otherwise, the genotype will be set to 2 (heterozygous).

    Parameters:
    - `haplotypes`: A 2D vector representing pairs of haplotypes.
    - `n_loci`: The number of loci (genetic markers) in each haplotype.

    Output:
    - Returns a 2D vector containing the genotypes for all pairs of haplotypes.
*/


#ifndef GENERATE_GENOTYPES_H
#define GENERATE_GENOTYPES_H

#include <vector>
#include <string>

inline std::vector<std::vector<int>> generate_genotypes(const std::vector<std::vector<int>>& haplotypes, int n_loci) {
    std::vector<std::vector<int>> genotypes;

    for (size_t i = 0; i < haplotypes.size(); i += 2) {
        std::vector<int> genotype;
        const auto& haplo1 = haplotypes[i];
        const auto& haplo2 = haplotypes[i + 1];

        for (int j = 0; j < n_loci; ++j) {
            if (haplo1[j] == 0 && haplo2[j] == 0) {
                genotype.push_back(0);
            } else if (haplo1[j] == 1 && haplo2[j] == 1) {
                genotype.push_back(1);
            } else {
                genotype.push_back(2);
            }
        }
        genotypes.push_back(genotype);
    }

    return genotypes;
}

#endif
