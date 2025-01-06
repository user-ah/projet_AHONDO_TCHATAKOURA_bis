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
 * Assigne les haplotypes aux génotypes en fonction du produit des fréquences.
 *
 * @param genotypes Liste des génotypes à expliquer.
 * @param sortedHaplotypes Liste triée des haplotypes avec leurs fréquences.
 * @param outputFilename Nom du fichier où écrire les haplotypes utilisés.
 * @return Une carte associant chaque génotype à une paire d’haplotypes.
 */
inline std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash>
assignHaplotypesOptimized(
    const std::vector<std::vector<int>>& genotypes,
    const std::vector<std::pair<std::vector<int>, double>>& sortedHaplotypes,
    const std::string& outputFilename) {

    // Stocker les associations génotypes -> paires d'haplotypes
    std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash> genotypeToHaplotypes;

    // Pour chaque génotype
    for (const auto& genotype : genotypes) {
        double maxScore = -1.0;
        std::pair<std::vector<int>, std::vector<int>> bestPair;

        // Parcourir toutes les paires d'haplotypes
        for (size_t i = 0; i < sortedHaplotypes.size(); ++i) {
            const auto& haplo1 = sortedHaplotypes[i].first;
            double freq1 = sortedHaplotypes[i].second;

            for (size_t j = i; j < sortedHaplotypes.size(); ++j) {
                const auto& haplo2 = sortedHaplotypes[j].first;
                double freq2 = sortedHaplotypes[j].second;

                // Vérifier si la paire (haplo1, haplo2) explique le génotype
                if (explainGenotype(haplo1, haplo2, genotype)) {
                    double score = freq1 * freq2;

                    // Mise à jour si on trouve une meilleure paire
                    if (score > maxScore) {
                        maxScore = score;
                        bestPair = {haplo1, haplo2};
                    }
                }
            }
        }

        // Vérification finale
        if (maxScore > -1.0) {
            genotypeToHaplotypes[genotype] = bestPair;
        } else {
            std::cerr << "Erreur : Aucun haplotype trouvé pour le génotype suivant : ";
            for (int allele : genotype) std::cerr << allele << " ";
            std::cerr << std::endl;
        }
    }

    // Écrire les haplotypes associés dans un fichier CSV
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
#endif // ASSIGN_HAPLOTYPES_SEQUENTIAL_H
