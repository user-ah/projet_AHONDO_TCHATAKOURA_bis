/*
    File: haplotypeReordering.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to reorder haplotypes to match the order of genotypes 
    and write them to a file. The function takes a list of genotypes and a mapping from genotypes 
    to haplotypes, and writes the ordered haplotypes to the specified output file.

    Key Features:
    - Reorders haplotypes to match the order of genotypes.
    - Writes the ordered haplotypes to a CSV file.
    - Handles cases where no matching haplotype is found for a genotype by outputting an error message.

    Output:
    - Writes the ordered haplotypes to the specified file.

    Preconditions:
    - The input `genotypes` is a list of genotypes, and `genotypeToHaplotypes` is a map that 
      associates each genotype with a corresponding pair of haplotypes.
    - The output file (`haplotypesFile`) must be writable.
*/

#ifndef HAPLOTYPE_REORDERING_H
#define HAPLOTYPE_REORDERING_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include "vector_hash.h"

/**
 * Reorders haplotypes to match the order of genotypes and writes them to a file.
 *
 * @param genotypes List of genotypes.
 * @param genotypeToHaplotypes Map associating each genotype with its corresponding haplotype pair.
 * @param haplotypesFile Output file name for the reordered haplotypes.
 */
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
