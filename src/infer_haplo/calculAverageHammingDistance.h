/*
    File: calculHammingDistance.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to calculate the normalized average Hamming distance 
    between two sets of haplotypes. The function computes the Hamming distance for each pair of 
    inferred haplotypes compared to a reference set (ground truth), and returns the average normalized 
    distance across all individuals.

    Key Features:
    - Computes Hamming distances between haplotype pairs.
    - Normalizes the distances by the number of loci.
    - Supports comparing inferred haplotypes with a ground truth reference.

    Output: Returns the average normalized Hamming distance across all individuals.

    Preconditions:
    - The number of inferred and ground truth haplotype pairs must be the same.
    - Each haplotype must have the correct number of loci (i.e., vector size must match `nLoci`).
*/

#include "calculHammingDistance.h"

inline double calculateAverageHammingDistance(
    const std::vector<std::pair<std::vector<int>, std::vector<int>>>& inferredHaplotypes,
    const std::vector<std::pair<std::vector<int>, std::vector<int>>>& groundTruthHaplotypes,
    int nLoci) {

    if (inferredHaplotypes.size() != groundTruthHaplotypes.size()) {
        std::cerr << "Error: The number of haplotype pairs does not match." << std::endl;
        exit(EXIT_FAILURE);
    }

    double totalDistance = 0.0;
    size_t nInd = inferredHaplotypes.size();

    for (size_t i = 0; i < nInd; ++i) {
        const auto& [h1, h2] = inferredHaplotypes[i];
        const auto& [g1, g2] = groundTruthHaplotypes[i];

        if (h1.size() != nLoci || h2.size() != nLoci || g1.size() != nLoci || g2.size() != nLoci) {
            std::cerr << "Error: Incorrect dimensions for individual " << i << std::endl;
            exit(EXIT_FAILURE);
        }

        int d1 = calculateHammingDistance(h1, g1) + calculateHammingDistance(h2, g2);
        int d2 = calculateHammingDistance(h1, g2) + calculateHammingDistance(h2, g1);

        totalDistance += std::min(d1, d2) / static_cast<double>(2 * nLoci);
    }

    return totalDistance / static_cast<double>(nInd);
}
