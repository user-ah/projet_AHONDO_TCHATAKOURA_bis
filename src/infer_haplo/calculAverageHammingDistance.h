/**
 * @file calculAverageHammingDistance.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Computes the normalized average Hamming distance between two sets of haplotypes.
 * 
 * @details
 * This header file declares the function `calculateAverageHammingDistance`, which computes the 
 * Hamming distance for each pair of inferred haplotypes compared to a reference set (ground truth). 
 * The function returns the average normalized Hamming distance across all individuals.
 * 
 * @section Features Key Features
 * - Computes Hamming distances between haplotype pairs.
 * - Normalizes distances by the number of loci.
 * - Supports direct comparison of inferred haplotypes against a ground truth reference.
 * 
 * @section Preconditions Preconditions
 * - The number of inferred haplotype pairs must match the number of ground truth pairs.
 * - Each haplotype must have the correct number of loci (i.e., vector size must match `nLoci`).
 * 
 * @param inferredHaplotypes A vector of pairs of vectors representing the inferred haplotypes.
 * @param groundTruthHaplotypes A vector of pairs of vectors representing the ground truth haplotypes.
 * @param nLoci The number of loci in each haplotype.
 * 
 * @throws std::runtime_error If the number of haplotype pairs does not match or if the dimensions of the haplotypes are incorrect.
 * 
 * @return The average normalized Hamming distance across all individuals.
 * 
 * @see assignHaplotypesOptimized()
 * @see estimation_esperance()
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
