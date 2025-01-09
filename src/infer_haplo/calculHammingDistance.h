/*
    File: calculHammingDistance.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to calculate the Hamming distance between two haplotypes.
    The Hamming distance is the number of positions at which two vectors differ, and it is used 
    to measure how similar or different two haplotypes are.

    Key Features:
    - Computes the Hamming distance between two haplotypes (vectors of integers).
    - Ensures that both haplotypes have the same length before performing the calculation.

    Output: Returns the Hamming distance (integer) between two haplotypes.

    Preconditions:
    - The two input haplotypes must have the same size (length).
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

inline int calculateHammingDistance(const std::vector<int>& haplo1, const std::vector<int>& haplo2) {
    if (haplo1.size() != haplo2.size()) {
        std::cerr << "Error: The haplotypes have different dimensions." << std::endl;
        exit(EXIT_FAILURE);
    }

    int distance = 0;
    for (size_t i = 0; i < haplo1.size(); ++i) {
        if (haplo1[i] != haplo2[i]) {
            distance++;
        }
    }
    return distance;
}
