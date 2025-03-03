/**
 * @file haplotypeReader.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Reads haplotypes from a CSV file and stores them in a structured format.
 * 
 * @details
 * This header file defines a function to read haplotypes from a CSV file and store them in a vector. 
 * Each pair of haplotypes corresponds to two consecutive lines in the file. The function assumes that 
 * alleles are separated by commas and that the file contains an even number of rows, each representing 
 * a haplotype.
 * 
 * @section Features Key Features
 * - Reads haplotypes from a CSV file where each row represents a haplotype.
 * - Each pair of haplotypes is stored as a pair of vectors of integers.
 * - Assumes the file uses a comma as the delimiter between alleles.
 * - Ensures that haplotypes are properly paired for further processing.
 * 
 * @section Preconditions Preconditions
 * - The input file must be a valid CSV file containing haplotypes.
 * - Each pair of consecutive rows in the file represents one haplotype pair.
 * - The number of rows must be even to form complete haplotype pairs.
 * 
 * @section Output Output
 * - Returns a vector of pairs of haplotypes, each represented as a vector of integers.
 */

/**
 * @brief Reads haplotypes from a CSV file and stores them in a vector.
 * 
 * @details
 * This function reads a haplotype dataset from a CSV file where each row represents a haplotype.
 * It processes the data and stores haplotypes as pairs of vectors of integers.
 * 
 * @param filename The name of the CSV file containing haplotype data.
 * 
 * @throws std::runtime_error If the file cannot be opened.
 * @throws std::invalid_argument If the file format is invalid (e.g., uneven number of rows).
 * 
 * @return A vector of pairs of haplotypes, each represented as a vector of integers.
 * 
 * @section Example Example Usage
 * @code
 * std::vector<std::pair<std::vector<int>, std::vector<int>>> haplotypes = readHaplotypes("haplotypes.csv");
 * for (const auto& pair : haplotypes) {
 *     std::cout << "Haplotype 1: ";
 *     for (int allele : pair.first) std::cout << allele << " ";
 *     std::cout << "\nHaplotype 2: ";
 *     for (int allele : pair.second) std::cout << allele << " ";
 *     std::cout << std::endl;
 * }
 * @endcode
 * 
 * @see generateHaplotypePairs()
 * @see assignHaplotypesOptimized()
 */


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * Reads haplotypes from a CSV file and stores them in a vector.
 * Each pair of haplotypes corresponds to two consecutive lines in the file.
 *
 * @param filename The CSV file containing the haplotypes.
 * @return A vector of haplotype pairs (each is a vector of integers).
 */
inline std::vector<std::pair<std::vector<int>, std::vector<int>>> readHaplotypes(const std::string& filename) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> haplotypes;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    char delimiter = ','; 
    std::vector<int> haplo1, haplo2;

    while (std::getline(file, line)) {
        std::vector<int> haplo;
        std::istringstream stream(line);
        std::string alleleStr;

        
        while (std::getline(stream, alleleStr, delimiter)) {
            haplo.push_back(std::stoi(alleleStr));
        }

        if (haplo1.empty()) {
            haplo1 = haplo; 
        } else {
            haplo2 = haplo; 
            haplotypes.emplace_back(haplo1, haplo2); 
            haplo1.clear(); 
        }
    }

    return haplotypes;
}
