#ifndef GENERATE_HAPLOTYPES_H
#define GENERATE_HAPLOTYPES_H

#include <iostream>
#include <vector>
#include <set>
#include <functional>

// Type alias pour simplifier
using Haplotype = std::vector<int>;
using HaploPair = std::pair<Haplotype, Haplotype>;
using HaploList = std::vector<HaploPair>;

// Générer toutes les paires d'haplotypes possibles pour un génotype donné
inline HaploList generateHaplotypePairs(const std::vector<int>& genotype) {
    HaploList result;
    std::function<void(size_t, Haplotype, Haplotype)> backtrack =
        [&](size_t index, Haplotype h1, Haplotype h2) {
            if (index == genotype.size()) {
                result.emplace_back(h1, h2);
                return;
            }
            if (genotype[index] == 0) {
                h1.push_back(0);
                h2.push_back(0);
                backtrack(index + 1, h1, h2);
            } else if (genotype[index] == 1) {
                h1.push_back(1);
                h2.push_back(1);
                backtrack(index + 1, h1, h2);
            } else if (genotype[index] == 2) {
                Haplotype h1_copy = h1, h2_copy = h2;
                h1.push_back(0);
                h2.push_back(1);
                backtrack(index + 1, h1, h2);
                h1_copy.push_back(1);
                h2_copy.push_back(0);
                backtrack(index + 1, h1_copy, h2_copy);
            }
        };
    backtrack(0, {}, {});
    return result;
}
inline std::vector<std::vector<int>> generateAndFilterUniqueHaplotypes(const std::vector<std::vector<int>>& genotypes) {
    std::set<Haplotype> allUniqueHaplotypes;

    for (const auto& genotype : genotypes) {
        HaploList pairs = generateHaplotypePairs(genotype);

        for (const auto& pair : pairs) {
            allUniqueHaplotypes.insert(pair.first);
            allUniqueHaplotypes.insert(pair.second);
        }
    }
    return std::vector<std::vector<int>>(allUniqueHaplotypes.begin(), allUniqueHaplotypes.end());
}

#endif // GENERATE_HAPLOTYPES_H
