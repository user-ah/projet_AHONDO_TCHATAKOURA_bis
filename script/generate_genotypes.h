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
