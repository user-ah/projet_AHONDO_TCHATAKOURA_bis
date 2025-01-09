/*
    File: assign_haplotypes_bis.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to assign haplotypes to genotypes based on the product of haplotype frequencies. 
    The function identifies the best pair of haplotypes that explains each genotype using a scoring mechanism, and 
    writes the associated haplotypes to an output file.

    Key Features:
    - Maps genotypes to their best haplotype pairs using a frequency-based scoring system.
    - Checks if a pair of haplotypes explains a genotype using an external function.
    - Outputs the assigned haplotypes to a CSV file.

    Output: 
    - A map associating each genotype with a pair of haplotypes.
    - A CSV file containing the haplotypes used.

    Preconditions:
    - The input genotypes and haplotypes must be valid and formatted correctly.
    - The `explainGenotype` function must be implemented to verify genotype explanation.
    - The output file path must be writable.
    
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

/**
 * Assign haplotypes to genotypes based on the product of haplotype frequencies.
 *
 * @param genotypes List of genotypes to explain.
 * @param sortedHaplotypes Sorted list of haplotypes with their frequencies.
 * @param outputFilename Name of the file to write the assigned haplotypes.
 * @return A map associating each genotype with a pair of haplotypes.
 */
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