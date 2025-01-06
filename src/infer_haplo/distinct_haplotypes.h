#ifndef CALCULATE_HAPLOTYPES_H
#define CALCULATE_HAPLOTYPES_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <fstream>
#include "vector_hash.h"

// Parse une ligne CSV en un vecteur d'entiers
inline std::vector<int> parseCSVLine(const std::string& line, char delimiter = ',') {
    std::vector<int> haplotype;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        haplotype.push_back(std::stoi(token));
    }
    return haplotype;
}

// Charge tous les haplotypes depuis un fichier CSV
inline std::unordered_set<std::vector<int>, VectorHash> loadHaplotypesFromFile(const std::string& haplotypesFile) {
    std::ifstream file(haplotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << haplotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::unordered_set<std::vector<int>, VectorHash> haplotypes;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Ignore les lignes vides
        haplotypes.insert(parseCSVLine(line));
    }

    return haplotypes;
}

// Calcule le nombre d'haplotypes distincts à partir d'un fichier CSV
inline void DistinctHaplotypesFromFile(const std::string& haplotypesFile, size_t& n_distinct_haplotypes) {
    auto distinctHaplotypes = loadHaplotypesFromFile(haplotypesFile);
    n_distinct_haplotypes = distinctHaplotypes.size();
}

#endif 
