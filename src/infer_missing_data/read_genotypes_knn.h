/*
    File: read_genotypes_knn.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to read genotype data from a CSV file. The data is read into a 2D vector, where each row
    represents a genotype and each column represents a locus. Missing values are represented by "NA" in the input file and are 
    stored as `-1` in the vector.

    Key Features:
    - Reads genotype data from a CSV file.
    - Handles missing values represented by "NA" and stores them as `-1`.
    - Catches and reports errors in case of invalid or out-of-range values in the input file.

    Output:
    - The function modifies the `genotypes` vector by adding the data from the CSV file.

    Preconditions:
    - The input CSV file should contain genotypes, with each genotype on a new line and loci separated by commas.
    - Missing values should be represented by "NA".
*/

#ifndef READ_GENOTYPES_KNN_H
#define READ_GENOTYPES_KNN_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

inline bool readGenotypes(const std::string &genotypes_file, std::vector<std::vector<int>> &genotypes) {
    std::ifstream file(genotypes_file);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open " << genotypes_file << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        
        while (std::getline(ss, cell, ',')) {
            try {
                if (cell == "NA") {  
                    row.push_back(-1);
                } else {
                    row.push_back(std::stoi(cell)); 
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error: Invalid cell '" << cell << "' in file " << genotypes_file << std::endl;
                return false;
            } catch (const std::out_of_range &e) {
                std::cerr << "Error: Out of range value in cell '" << cell << "' in file " << genotypes_file << std::endl;
                return false;
            }
        }

        
        genotypes.push_back(row);
    }

    file.close();
    return true;
}

#endif
