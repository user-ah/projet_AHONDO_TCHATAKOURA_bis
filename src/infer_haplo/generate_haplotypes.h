
#ifndef GENERATE_HAPLOTYPES_H
#define GENERATE_HAPLOTYPES_H

#include <iostream>
#include <vector>
#include <set>
#include <functional>
/**
 * @file generate_haplotypes.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Generates possible haplotype pairs for a given genotype and filters unique haplotypes.
 * 
 * @details
 * This header file declares functions used to generate all possible haplotype pairs for a given 
 * genotype using a recursive backtracking approach. It also includes functionality to filter 
 * out unique haplotypes across all individuals based on the input genotypes.
 * 
 * @section Features Key Features
 * - Generates all possible haplotype pairs for a given genotype.
 * - Filters out unique haplotypes across all individuals.
 * - Uses a recursive backtracking method for haplotype generation.
 * 
 * @section Preconditions Preconditions
 * - The input `genotypes` must be provided as a vector of integer vectors, where each vector 
 *   represents the genotype of an individual.
 * - The genotypic data must be properly formatted and consistent.
 * 
 * @param genotype A vector of integers representing a single genotype.
 * @return A list of possible haplotype pairs for the given genotype.
 * 
 * @throws std::invalid_argument If the input genotype contains invalid values.
 * 
 * @section Output Output
 * - Returns a list of unique haplotypes.
 * 
 * @section Functions Available Functions
 */

/**
 * @brief Generates all possible haplotype pairs for a given genotype.
 * 
 * @details This function uses a recursive backtracking method to generate all possible haplotype 
 *          pairs that can explain a given genotype.
 * 
 * @param genotype A vector of integers representing a single genotype.
 * @return A list of haplotype pairs that are compatible with the given genotype.
 * 
 * @throws std::invalid_argument If the input genotype contains invalid values.
 * 
 * @see generateAndFilterUniqueHaplotypes()
 */

using Haplotype = std::vector<int>;
using HaploPair = std::pair<Haplotype, Haplotype>;
using HaploList = std::vector<HaploPair>;

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



/**
 * @brief Generates and filters unique haplotypes across all individuals.
 * 
 * @details This function iterates through all genotypes, generates possible haplotype pairs, and 
 *          stores only unique haplotypes across all individuals.
 * 
 * @param genotypes A vector of vectors, where each vector represents the genotype of an individual.
 * @return A vector of vectors containing unique haplotypes.
 * 
 * @see generateHaplotypePairs()
 */

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
