/**
 * @file assign_haplotypes_bis.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Assigns haplotypes to genotypes based on haplotype frequency product.
 * 
 * @details 
 * This header file defines the `assignHaplotypesOptimized` function, which finds the best pair of haplotypes 
 * explaining each genotype. The function evaluates haplotype pairs based on their frequencies, checks their 
 * compatibility with the genotype using `explainGenotype`, and writes the results to an output CSV file.
 * 
 * @section Features Key Features
 * - Maps genotypes to their most likely haplotype pairs using frequency-based scoring.
 * - Uses `explainGenotype` to verify if a haplotype pair can explain a given genotype.
 * - Outputs assigned haplotypes to a CSV file.
 * - Optimized for performance with pre-sorted haplotype lists.
 * 
 * @section Output Generated Output
 * - A map associating each genotype with its best haplotype pair.
 * - A CSV file storing the assigned haplotypes.
 * 
 * @section Preconditions Preconditions
 * - The input genotypes and haplotypes must be valid and correctly formatted.
 * - The function `explainGenotype` must be implemented to verify genotype compatibility.
 * - The output file path must be writable.
 * 
 * @param genotypes A list of genotypes to process.
 * @param sortedHaplotypes A sorted list of haplotypes with their associated frequencies.
 * @param outputFilename The name of the output file where assigned haplotypes will be written.
 * 
 * @throws std::runtime_error If the output file cannot be opened.
 * @throws std::invalid_argument If the input data is incorrectly formatted.
 * 
 * @return A map associating each genotype with its corresponding haplotype pair.
 * 
 * @see explainGenotype()
 * @see sortHaplotypesByFrequency()
 */


#ifndef ASSIGN_HAPLOTYPES_BIS_H
#define ASSIGN_HAPLOTYPES_BIS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <fstream>
#include "vector_hash.h"
#include "explain_genotype.h"


inline std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash>
assignHaplotypesOptimized(
    const std::vector<std::vector<int>>& genotypes,
    const std::vector<std::pair<std::vector<int>, double>>& sortedHaplotypes,
    const std::string& outputFilename) {
    std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash> genotypeToHaplotypes;
    for (const auto& genotype : genotypes) {
        double maxScore = -1.0;
        std::pair<std::vector<int>, std::vector<int>> bestPair;

        for (size_t i = 0; i < sortedHaplotypes.size(); ++i) {
            const auto& haplo1 = sortedHaplotypes[i].first;
            double freq1 = sortedHaplotypes[i].second;

            for (size_t j = i; j < sortedHaplotypes.size(); ++j) {
                const auto& haplo2 = sortedHaplotypes[j].first;
                double freq2 = sortedHaplotypes[j].second;

                if (explainGenotype(haplo1, haplo2, genotype)) {
                    double score = freq1 * freq2;

                    if (score > maxScore) {
                        maxScore = score;
                        bestPair = {haplo1, haplo2};
                    }
                }
            }
        }

        if (maxScore > -1.0) {
            genotypeToHaplotypes[genotype] = bestPair;
        } else {
            std::cerr << "Erreur : Aucun haplotype trouvé pour le génotype suivant : ";
            for (int allele : genotype) std::cerr << allele << " ";
            std::cerr << std::endl;
        }
    }

std::ofstream outFile(outputFilename);
if (outFile) {
    for (const auto& [genotype, haplos] : genotypeToHaplotypes) {
        const auto& haplo1 = haplos.first;
        const auto& haplo2 = haplos.second;

        for (size_t i = 0; i < haplo1.size(); ++i) {
            outFile << haplo1[i];
            if (i < haplo1.size() - 1) outFile << ","; 
        }
        outFile << "\n";

        for (size_t i = 0; i < haplo2.size(); ++i) {
            outFile << haplo2[i];
            if (i < haplo2.size() - 1) outFile << ",";
        }
        outFile << "\n";
    }
    outFile.close();
    std::cout << "Haplotypes écrits dans le fichier : " << outputFilename << std::endl;
} else {
    std::cerr << "Erreur : Impossible d'écrire dans le fichier des haplotypes " << outputFilename << std::endl;
}

    return genotypeToHaplotypes;
}
#endif