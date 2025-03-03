/**
 * @file twoNumbersInGenotypes.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Counts the total occurrences of the value `2` in a genotypes CSV file.
 * 
 * @details
 * This header file defines a function that scans a genotypes CSV file and counts the total number 
 * of occurrences of the value `2`. Each line in the file represents a genotype, and the function 
 * reads through the entire file to determine how frequently the value `2` appears in the dataset.
 * 
 * @section Features Key Features
 * - Reads through a genotypes CSV file.
 * - Counts occurrences of the allele `2` in the dataset.
 * - Returns the total count of `2`s found in the genotypes file.
 * 
 * @section Preconditions Preconditions
 * - The `genotypesFile` must be a valid and properly formatted CSV file.
 * - Each line in the file must contain genotype values separated by commas.
 * - The file must be accessible and readable.
 * 
 * @section Output Output
 * - The function returns the total count of occurrences of `2` in the genotypes dataset.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * @brief Counts the total number of occurrences of `2` in a genotypes file.
 * 
 * @details
 * This function reads through a genotypes CSV file and counts how many times the value `2` appears 
 * across the entire dataset. It ensures that the file is properly formatted and accessible before processing.
 * 
 * @param genotypesFile The name of the CSV file containing the genotypes.
 * 
 * @throws std::runtime_error If the file cannot be opened or read.
 * 
 * @return The total count of `2`s found in the genotypes file.
 * 
 * @section Example Example Usage
 * @code
 * size_t countTwos = countTwosInGenotypes("data/genotypes.csv");
 * std::cout << "Total number of `2`s in the dataset: " << countTwos << std::endl;
 * @endcode
 * 
 * @see readGenotypes()
 * @see estimation_esperance()
 */

inline size_t countTwosInGenotypes(const std::string& genotypesFile) {
    std::ifstream file(genotypesFile);
    if (!file) {
        std::cerr << "Error: Unable to open file " << genotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    size_t countTwos = 0; 
    std::string line;
    char delimiter = ','; 
    while (std::getline(file, line)) {
        if (line.empty()) continue; 

        std::istringstream stream(line);
        std::string valueStr;

        while (std::getline(stream, valueStr, delimiter)) {
            int value = std::stoi(valueStr); 
            if (value == 2) {
                countTwos++; 
            }
        }
    }

    return countTwos; 
}
