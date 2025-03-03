/**
 * @file haplotypeReordering.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Reorders haplotypes to match the order of genotypes and writes them to a file.
 * 
 * @details
 * This header file defines a function that reorders haplotypes to align with the order of genotypes 
 * and writes them to a specified CSV file. The function takes a list of genotypes and a mapping from 
 * genotypes to haplotypes, ensuring that each genotype is associated with its corresponding haplotype pair.
 * 
 * @section Features Key Features
 * - Reorders haplotypes to match the order of genotypes.
 * - Writes the ordered haplotypes to a CSV file.
 * - Handles cases where no matching haplotype is found for a genotype by outputting an error message.
 * 
 * @section Preconditions Preconditions
 * - The input `genotypes` must be a list of valid genotypes.
 * - The `genotypeToHaplotypes` map must associate each genotype with a valid pair of haplotypes.
 * - The output file (`haplotypesFile`) must be writable.
 * 
 * @section Output Output
 * - Writes the ordered haplotypes to the specified file.
 */

/**
 * @brief Reorders haplotypes to match the order of genotypes and writes them to a file.
 * 
 * @details
 * This function ensures that haplotypes are reordered to align with the corresponding genotypes and 
 * then writes them to a CSV file for further processing.
 * 
 * @param genotypes A list of genotypes, each represented as a vector of integers.
 * @param genotypeToHaplotypes A map associating each genotype with its corresponding haplotype pair.
 * @param haplotypesFile The name of the output CSV file where the reordered haplotypes will be written.
 * 
 * @throws std::runtime_error If the output file cannot be opened for writing.
 * @throws std::invalid_argument If the input data is improperly formatted or missing expected entries.
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes = {{0,1,1}, {1,0,1}};
 * std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash> genotypeToHaplotypes;
 * genotypeToHaplotypes[genotypes[0]] = {{0,1,0}, {1,1,1}};
 * genotypeToHaplotypes[genotypes[1]] = {{1,0,1}, {0,1,1}};
 * 
 * reorganizeHaplotypesAndWriteToFile(genotypes, genotypeToHaplotypes, "ordered_haplotypes.csv");
 * @endcode
 * 
 * @see assignHaplotypesOptimized()
 * @see generateHaplotypePairs()
 */

#ifndef HAPLOTYPE_REORDERING_H
#define HAPLOTYPE_REORDERING_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include "vector_hash.h"


inline void reorganizeHaplotypesAndWriteToFile(
    const std::vector<std::vector<int>>& genotypes,
    const std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash>& genotypeToHaplotypes,
    const std::string& haplotypesFile) {

    std::vector<std::pair<std::vector<int>, std::vector<int>>> orderedHaplotypes;

    for (const auto& genotype : genotypes) {
        if (genotypeToHaplotypes.find(genotype) != genotypeToHaplotypes.end()) {
            orderedHaplotypes.push_back(genotypeToHaplotypes.at(genotype));
        } else {
            std::cerr << "Error: No haplotype found for the following genotype: ";
            for (int allele : genotype) std::cerr << allele << " ";
            std::cerr << std::endl;
        }
    }

    std::ofstream haploFile(haplotypesFile);
    if (haploFile) {
        for (const auto& [haplo1, haplo2] : orderedHaplotypes) {
            for (size_t i = 0; i < haplo1.size(); ++i) {
                haploFile << haplo1[i];
                if (i < haplo1.size() - 1) haploFile << ",";
            }
            haploFile << "\n";
            for (size_t i = 0; i < haplo2.size(); ++i) {
                haploFile << haplo2[i];
                if (i < haplo2.size() - 1) haploFile << ",";
            }
            haploFile << "\n";
        }
        haploFile.close();
    } else {
        std::cerr << "Error: Unable to write to haplotype file " << haplotypesFile << std::endl;
    }
}

#endif // HAPLOTYPE_REORDERING_H
