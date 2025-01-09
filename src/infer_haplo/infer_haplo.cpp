/*
    File: main.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines the main function of an Expectation-Maximization (EM) algorithm used for 
    haplotype inference from genotype data. The program reads genotype and haplotype data, performs 
    EM iterations to maximize the likelihood, and outputs the results, including the ordered haplotypes 
    and log files.

    Key Features:
    - Reads genotype and haplotype data from CSV files.
    - Runs the Expectation-Maximization algorithm for haplotype inference.
    - Outputs the ordered haplotypes and log details, including execution time and convergence information.
    - Calculates the Hamming distance between inferred haplotypes and ground truth for accuracy assessment.

    Output:
    - Writes the ordered haplotypes to a CSV file.
    - Logs the execution details (iterations, time, convergence) to a log file.
    - Calculates and outputs the average Hamming distance between inferred and ground truth haplotypes.

    Preconditions:
    - The input files for genotypes, ground truth haplotypes, and output haplotypes must be properly formatted CSV files.
    - The number of genotypes and haplotypes must align with the provided data.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <string>
#include <limits>
#include "genotype_reader.h"
#include "generate_haplotypes.h"
#include "initialisation_frequences.h"
#include "calcul_proba_genotypes.h"
#include "maximisation.h"
#include "estimation_esperance.h"
#include "sort_haplotypes.h"
#include "assign_haplotypes.h"
#include "vector_hash.h"
#include "distinct_haplotypes.h"
#include "haplotype_reordering.h"
#include "calculAverageHammingDistance.h"
#include "twoNumbersInGenotypes.h"
#include "haplotype_reader.h"
#include "log_writer.h"

const int NB_ETAPES_MAXIMUM = 100; 
const double SEUIL = 0.001;        

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0]
                  << " <genotypes_csv> <haplo_ground_truth.csv> <haplotypes_csv> <log_file>" 
                  << std::endl;
        return EXIT_FAILURE;
    }

    const std::string genotypesFile = argv[1]; 
    const std::string groundTruthFile = argv[2];
    const std::string haplotypesFile = argv[3]; 
    const std::string logFile = argv[4]; 
    std::cout << "EM parameters: Maximum steps = " << NB_ETAPES_MAXIMUM 
              << ", Convergence threshold = " << SEUIL << std::endl;

    
    std::vector<std::vector<int>> genotypes;
    int n_ind = 0, n_loci = 0;
    readGenotypes(genotypesFile, genotypes, n_ind, n_loci);

    
    std::vector<std::vector<int>> haplotypes = generateAndFilterUniqueHaplotypes(genotypes);

    
    std::unordered_map<std::vector<int>, double, VectorHash> frequencies;
    initialisation_frequences_haplotypes(haplotypes, frequencies);

    
    std::unordered_map<std::vector<int>, double, VectorHash> probabilities;
    int nb_iterations = 0;
    double loglikelihood_prec = -std::numeric_limits<double>::infinity();
    bool convergence = false;

    
    auto start = std::chrono::high_resolution_clock::now();

    
    while (!convergence && nb_iterations < NB_ETAPES_MAXIMUM) {
        ++nb_iterations;
        std::cout << "\n--- Starting iteration " << nb_iterations << " ---" << std::endl;

        
        calcul_proba_genotypes(genotypes, haplotypes, frequencies, probabilities);

        
        maximisation(genotypes, haplotypes, frequencies, probabilities, n_ind);

        
        double loglikelihood = estimation_esperance(genotypes, haplotypes, frequencies);
        std::cout << "Log-likelihood after iteration " << nb_iterations << " : " << loglikelihood << std::endl;
        
        
        double delta = std::abs(loglikelihood_prec - loglikelihood) / std::abs(loglikelihood_prec);
        std::cout << "Delta: " << delta << " (Threshold: " << SEUIL << ")" << std::endl;        
        
        if (delta < SEUIL) {
            convergence = true;
        }
        loglikelihood_prec = loglikelihood;
    }

    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> executionTime = end - start;

    
    std::vector<std::pair<std::vector<int>, double>> sortedHaplotypes = sortHaplotypesByFrequency(frequencies);

    
    std::unordered_map<std::vector<int>, std::pair<std::vector<int>, std::vector<int>>, VectorHash> genotypeToHaplotypes =
        assignHaplotypesOptimized(genotypes, sortedHaplotypes, haplotypesFile);
    reorganizeHaplotypesAndWriteToFile(genotypes, genotypeToHaplotypes, haplotypesFile);

    
    size_t countTwos = countTwosInGenotypes(genotypesFile);
    auto groundTruthHaplotypes = readHaplotypes(groundTruthFile);
    auto inferredHaplotypes = readHaplotypes(haplotypesFile);

    size_t n_distinct_ground_truth_haplotypes = 0;
    size_t n_distinct_inferred_haplotypes = 0;

    
    DistinctHaplotypesFromFile(groundTruthFile, n_distinct_ground_truth_haplotypes);
    DistinctHaplotypesFromFile(haplotypesFile, n_distinct_inferred_haplotypes);

    
    double averageDistance = calculateAverageHammingDistance(inferredHaplotypes, groundTruthHaplotypes, n_loci);

    
    writeLog(logFile, n_ind, n_loci, nb_iterations, executionTime.count(), countTwos,
             n_distinct_ground_truth_haplotypes, n_distinct_inferred_haplotypes, averageDistance);

    return EXIT_SUCCESS;
}
