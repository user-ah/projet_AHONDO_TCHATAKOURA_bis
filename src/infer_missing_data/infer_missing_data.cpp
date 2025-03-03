/**
 * @file infer_missing_data.cpp
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Implements the main function for genotype imputation using the k-nearest neighbors (KNN) approach.
 * 
 * @details
 * This program performs genotype imputation using a k-nearest neighbors (KNN) approach. It reads configuration 
 * parameters from a file, loads genotype data (which may contain missing values), imputes missing values using 
 * KNN imputation, and writes the fully imputed genotype data to an output CSV file.
 * 
 * The imputation process involves:
 * 1. Reading parameters, including the value of `k` (number of neighbors), from a configuration file.
 * 2. Reading genotype data from a CSV file where missing values are represented by `-1`.
 * 3. Computing Hamming distances to find the `k` nearest genotypes for imputation.
 * 4. Imputing missing genotype values using majority voting from the `k` nearest neighbors.
 * 5. Saving the imputed genotype data to an output CSV file.
 * 
 * @section Features Key Features
 * - Reads parameters, including the value of `k`, from a configuration file.
 * - Reads genotype data (with potential missing values) from a CSV file.
 * - Imputes missing genotype values using KNN imputation.
 * - Saves the imputed genotype data to an output CSV file.
 * 
 * @section Preconditions Preconditions
 * - The `parameters.txt` file must contain a valid `k` value.
 * - The `genotypes.csv` file must contain properly formatted genotype data, with missing values represented by `-1`.
 * - The output file path must be correctly specified to store the imputed genotypes.
 * 
 * @section Output Output
 * - The imputed genotype data is saved in a CSV file specified by the user.
 */

#include <iostream>
#include <vector>
#include <string>
#include "read_parameters_knn.h"
#include "read_genotypes_knn.h"
#include "impute_missing_data.h"
#include "write_genotypes_knn.h"

/**
 * @brief Main function for genotype imputation using KNN.
 * 
 * @details
 * This function reads parameters from a configuration file, loads genotype data, 
 * applies KNN-based imputation to fill in missing values, and writes the imputed 
 * genotype data to an output CSV file.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The list of command-line arguments:
 *  - `argv[1]` : Path to the `parameters.txt` file containing the value of `k`.
 *  - `argv[2]` : Path to the `genotypes.csv` file containing genotype data with missing values.
 *  - `argv[3]` : Path to the output CSV file where the imputed genotypes will be saved.
 * 
 * @throws std::runtime_error If the parameter file or genotype file cannot be opened.
 * @throws std::invalid_argument If the `k` value is missing or invalid.
 * 
 * @return `EXIT_SUCCESS` if execution is successful, `EXIT_FAILURE` otherwise.
 * 
 * @section Example Example Usage
 * @code
 * ./infer_missing_data config/parameters.txt data/genotypes.csv results/imputed_genotypes.csv
 * @endcode
 * 
 * @see imputeMissingDataKNN()
 * @see hammingDistance()
 */

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <parameters.txt> <genotypes.csv> <output_genotypes.csv>" << std::endl;
        return 1;
    }

    std::string parameters_file = argv[1];
    std::string genotypes_file = argv[2];
    std::string output_file = argv[3];

    
    int k = 0;
    if (!readParameters(parameters_file, k)) {
        return 1;
    }
    std::cout << "Value of k: " << k << std::endl;

    
    std::vector<std::vector<int>> genotypes;
    if (!readGenotypes(genotypes_file, genotypes)) {
        return 1;
    }

    
    for (auto &row : genotypes) {
        imputeMissingData(row, genotypes, k);
    }

    
    if (!writeGenotypes(output_file, genotypes)) {
        return 1;
    }

    std::cout << "Imputation completed. File saved as: " << output_file << std::endl;
    return 0;
}
