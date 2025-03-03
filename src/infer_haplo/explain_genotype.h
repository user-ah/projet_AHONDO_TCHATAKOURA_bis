/**
 * @file explain_genotype.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Checks whether a pair of haplotypes can explain a given genotype.
 * 
 * @details
 * This header file provides functions to verify if two haplotypes can explain a given genotype
 * based on Mendelian inheritance rules. The main function, `explainGenotype`, ensures that each 
 * allele in the genotype can be derived from the corresponding alleles in the haplotype pair.
 * 
 * A helper function, `isValid`, is used to check individual allele compatibility, ensuring that
 * the inheritance constraints are met.
 * 
 * @section Features Key Features
 * - Determines whether two haplotypes are consistent with a given genotype.
 * - Uses a helper function to validate allele compatibility.
 * - Works with a vector-based representation of haplotypes and genotypes.
 * 
 * @section Preconditions Preconditions
 * - The input `h1`, `h2`, and `genotype` must be vectors of the same size.
 * - Each vector should represent a sequence of alleles for a particular individual.
 * - Allele values should be within the expected range (typically 0, 1, or 2).
 * 
 * @param h1 A vector of integers representing the first haplotype.
 * @param h2 A vector of integers representing the second haplotype.
 * @param genotype A vector of integers representing the genotype.
 * 
 * @throws std::invalid_argument If the input vectors have different sizes or contain invalid allele values.
 * 
 * @return `true` if the haplotypes (`h1`, `h2`) can explain the genotype, `false` otherwise.
 * 
 * @section Example Example Usage
 * @code
 * std::vector<int> haplo1 = {0, 1, 1};
 * std::vector<int> haplo2 = {1, 0, 1};
 * std::vector<int> genotype = {1, 1, 2};
 * bool result = explainGenotype(haplo1, haplo2, genotype);
 * std::cout << "Genotype is explained: " << std::boolalpha << result << std::endl;
 * @endcode
 * 
 * @see calcul_proba_genotypes()
 * @see estimation_esperance()
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
