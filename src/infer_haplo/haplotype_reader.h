/*
    File: haplotypeReader.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to read haplotypes from a CSV file and store them in a vector. 
    Each pair of haplotypes corresponds to two consecutive lines in the file.

    Key Features:
    - Reads haplotypes from a CSV file, where each row represents a haplotype.
    - Each pair of haplotypes is stored as a pair of vectors of integers.
    - Assumes the file uses a comma as the delimiter between alleles.

    Output:
    - Returns a vector of pairs of haplotypes, each represented as a vector of integers.

    Preconditions:
    - The input file must be a valid CSV file containing pairs of haplotypes.
    - Each pair of consecutive rows in the file represents one haplotype pair.

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
