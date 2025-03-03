/**
 * @file genotype_reader.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Provides functionality for reading genotypes from a CSV file.
 * 
 * @details
 * This header file defines a function to extract genotype data from a CSV file. The function 
 * reads the genotypic data, determines the number of individuals (rows) and loci (columns), 
 * and ensures that the data conforms to the expected format. It also handles errors such as 
 * invalid values or inconsistent row sizes in the input file.
 * 
 * @section Features Key Features
 * - Reads genotypes from a CSV file into a vector of vectors.
 * - Validates the input format and ensures consistent row sizes.
 * - Extracts the number of individuals (rows) and loci (columns).
 * - Handles errors, including invalid values and out-of-range data.
 * 
 * @section Preconditions Preconditions
 * - The input file must be a valid CSV file containing only genotypic data.
 * - Each row must represent a genotype (an individual).
 * - Each column must correspond to a locus.
 * - The CSV file must be properly formatted with no missing values.
 * 
 * @section Output Output
 * - Populates the `genotypes` vector with the extracted genotypic data.
 * - Updates `n_ind` with the number of individuals.
 * - Updates `n_loci` with the number of loci.
 */

/**
 * @brief Reads a CSV file containing genotypic data and extracts relevant information.
 * 
 * @details
 * This function reads a genotype dataset from a CSV file and stores the extracted data in a vector of vectors. 
 * It also counts the number of individuals (rows) and loci (columns), ensuring that the dataset is properly formatted.
 * 
 * @param filename The name of the CSV file containing genotype data.
 * @param genotypes A reference to a vector of vectors storing the extracted genotypic data.
 * @param n_ind Reference to an integer storing the number of individuals (rows).
 * @param n_loci Reference to an integer storing the number of loci (columns).
 * 
 * @throws std::runtime_error If the file cannot be opened.
 * @throws std::invalid_argument If the file format is invalid (e.g., missing values, incorrect delimiters).
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::vector<int>> genotypes;
 * int n_ind = 0, n_loci = 0;
 * readGenotypes("genotypes.csv", genotypes, n_ind, n_loci);
 * std::cout << "Number of individuals: " << n_ind << ", Number of loci: " << n_loci << std::endl;
 * @endcode
 * 
 * @see initialisation_frequences_haplotypes()
 * @see estimation_esperance()
 */


#ifndef GENOTYPE_READER_H
#define GENOTYPE_READER_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

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
