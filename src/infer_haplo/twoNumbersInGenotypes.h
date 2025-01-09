/*
    File: twoNumbersInGenotypes.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This file contains a function to count the total number of `2`s present in a genotypes CSV file. 
    Each line in the file represents a genotype, and the function will read through the file, 
    count how many `2`s appear in the entire dataset, and return that total count.

    Key Features:
    - Reads through a genotypes file.
    - Counts the occurrences of the value `2` in the file.

    Output:
    - The function returns the total count of `2`s found in the genotypes file.

    Preconditions:
    - The genotypes file must be in CSV format, where each line contains genotype values separated by commas.
    - The genotypes file must be accessible and readable.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * Counts the total number of `2`s in a genotypes file.
 * Each line in the file represents a genotype.
 *
 * @param genotypesFile Name of the CSV file containing the genotypes.
 * @return Total count of `2`s in the file.
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
