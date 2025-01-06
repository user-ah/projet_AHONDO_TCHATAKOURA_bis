#ifndef HAPLOTYPE_REORDERING_H
#define HAPLOTYPE_REORDERING_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include "vector_hash.h"

/**
 * Réorganise les haplotypes pour correspondre à l'ordre des génotypes et les écrit dans un fichier.
 *
 * @param genotypes Liste des génotypes.
 * @param genotypeToHaplotypes Map associant chaque génotype à sa paire d'haplotypes.
 * @param haplotypesFile Nom du fichier de sortie pour les haplotypes réorganisés.
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
            std::cerr << "Erreur : Aucun haplotype trouvé pour le génotype suivant : ";
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
        std::cerr << "Erreur : Impossible d'écrire dans le fichier des haplotypes " << haplotypesFile << std::endl;
    }
}

#endif // HAPLOTYPE_REORDERING_H
