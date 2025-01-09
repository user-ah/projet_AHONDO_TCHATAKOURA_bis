/*
    File: genotypeReader.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to read genotypes from a CSV file. 
    The function extracts the genotypes, the number of individuals, and the number of loci from the input file. 
    It handles errors such as invalid or out-of-range values in the CSV file and ensures the data conforms to expected dimensions.

    Key Features:
    - Reads genotypes from a CSV file into a vector of vectors.
    - Handles errors in the input file, including invalid values and inconsistent row sizes.
    - Extracts the number of individuals (rows) and loci (columns) from the CSV.

    Output:
    - Populates the `genotypes` vector with the genotypic data.
    - Updates the `n_ind` and `n_loci` with the number of individuals and loci, respectively.

    Preconditions:
    - The input file must be a valid CSV file containing genotypic data.
    - Each row must represent a genotype, and each column corresponds to a locus.

*/

#ifndef GENOTYPE_READER_H
#define GENOTYPE_READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * @brief Reads a CSV genotype file and extracts genotypes, number of individuals, and loci.
 * 
 * @param filename The CSV file name containing the genotypes.
 * @param genotypes A vector of vectors where each vector represents a genotype.
 * @param n_ind Reference to store the number of individuals (rows).
 * @param n_loci Reference to store the number of loci (columns).
 */
inline void readGenotypes(const std::string& filename, 
                          std::vector<std::vector<int>>& genotypes, 
                          int& n_ind, int& n_loci) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    n_ind = 0;  
    n_loci = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::vector<int> genotype;
        std::string value;

        while (std::getline(ss, value, ',')) {
            try {
                genotype.push_back(std::stoi(value));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid value '" << value 
                          << "' in file " << filename 
                          << ", line " << n_ind + 1 << "." << std::endl;
                exit(EXIT_FAILURE);
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Out-of-range value '" << value 
                          << "' in file " << filename 
                          << ", line " << n_ind + 1 << "." << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        if (n_loci == 0) {
            n_loci = genotype.size(); 
        } else if (genotype.size() != n_loci) {
            std::cerr << "Error: Line " << n_ind + 1 
                      << " in file " << filename 
                      << " does not match the expected number of loci (" << n_loci << ")." << std::endl;
            exit(EXIT_FAILURE);
        }

        genotypes.push_back(genotype);
        ++n_ind;
    }

    file.close();
}

#endif
