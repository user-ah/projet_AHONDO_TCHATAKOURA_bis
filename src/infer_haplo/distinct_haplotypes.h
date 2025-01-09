/*
    File: calculateHaplotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines several functions to handle haplotype data. It provides methods to 
    parse CSV files containing haplotype information, load haplotypes into an unordered set, 
    and calculate the number of distinct haplotypes.

    Key Features:
    - Parses CSV lines into vectors of integers to represent haplotypes.
    - Loads haplotypes from a CSV file and stores them in an unordered set to remove duplicates.
    - Computes the number of distinct haplotypes from a file.

    Output:
    - The functions return sets of haplotypes or update the count of distinct haplotypes.

    Preconditions:
    - The CSV file must have haplotypes represented as comma-separated integers.
    - The input file must be accessible for reading.
*/
#ifndef CALCULATE_HAPLOTYPES_H
#define CALCULATE_HAPLOTYPES_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <fstream>
#include "vector_hash.h"


inline std::vector<int> parseCSVLine(const std::string& line, char delimiter = ',') {
    std::vector<int> haplotype;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        haplotype.push_back(std::stoi(token));
    }
    return haplotype;
}


inline std::unordered_set<std::vector<int>, VectorHash> loadHaplotypesFromFile(const std::string& haplotypesFile) {
    std::ifstream file(haplotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << haplotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::unordered_set<std::vector<int>, VectorHash> haplotypes;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue; 
        haplotypes.insert(parseCSVLine(line));
    }

    return haplotypes;
}


inline void DistinctHaplotypesFromFile(const std::string& haplotypesFile, size_t& n_distinct_haplotypes) {
    auto distinctHaplotypes = loadHaplotypesFromFile(haplotypesFile);
    n_distinct_haplotypes = distinctHaplotypes.size();
}

#endif
