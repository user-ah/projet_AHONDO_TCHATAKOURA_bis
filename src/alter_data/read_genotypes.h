/**
    @file read_genotypes.h

     @brief This header file defines a function to read genotype data from a text file. 
     The genotype data is stored in a 2D vector of integers. Each row in the file 
     corresponds to a row in the matrix, and non-numeric characters are ignored.

     @authors 
     Ahamed TCHATAKOURA 
     Mawuéna AHONDO

     @details
     Key Features:
     - Reads a genotype matrix from a text file.
     - Parses numeric characters and ignores other characters.
     - Supports matrices of arbitrary dimensions.

     @param genotypesFile The path to the genotype text file.
     @param genotypes A 2D vector to store the genotype data.

     @return void

     @pre The input file must be in a readable format (one genotype per cell, rows separated by newlines).
     @pre Non-numeric characters are ignored during parsing.

     @exception std::ifstream::failure If the file cannot be opened.
 */
#ifndef READ_GENOTYPES_H
#define READ_GENOTYPES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

inline void readGenotypes(const std::string& genotypesFile, std::vector<std::vector<int>>& genotypes) {
    std::ifstream file(genotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << genotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (std::isdigit(c)) {
                row.push_back(c - '0');
            }
        }
        genotypes.push_back(row);
    }
    file.close();
}

#endif
