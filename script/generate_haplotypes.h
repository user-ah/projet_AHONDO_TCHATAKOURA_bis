#ifndef GENERATE_HAPLOTYPES_H
#define GENERATE_HAPLOTYPES_H

#include <vector>
#include <cstdlib>

inline std::vector<std::vector<int>> generate_haplotypes(int n_ind, int n_loci, int n_distinct_haplo) {
    std::vector<std::vector<int>> distinct_haplotypes;

    // Generate random distinct haplotypes
    for (int i = 0; i < n_distinct_haplo; ++i) {
        std::vector<int> haplotype;
        for (int j = 0; j < n_loci; ++j) {
            haplotype.push_back(rand() % 2);  // 0 or 1 randomly
        }
        distinct_haplotypes.push_back(haplotype);
    }

    std::vector<std::vector<int>> haplotypes;

    // Generate haplotype pairs
    for (int i = 0; i < n_ind; ++i) {
        int haplo1_idx = rand() % n_distinct_haplo;
        int haplo2_idx = rand() % n_distinct_haplo;

        haplotypes.push_back(distinct_haplotypes[haplo1_idx]);
        haplotypes.push_back(distinct_haplotypes[haplo2_idx]);
    }

    return haplotypes;
}

#endif
