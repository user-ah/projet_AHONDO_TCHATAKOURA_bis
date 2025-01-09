/*
    File: infer_missing_data.cpp

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This file implements the main function for a genotype imputation program. The program reads parameters from a file, 
    reads genotype data from a CSV file, imputes missing values in the genotypes using a k-nearest neighbors (KNN) approach, 
    and writes the imputed genotype data to an output CSV file.

    Key Features:
    - Reads parameters, including the value of `k` (number of neighbors), from a file.
    - Reads genotype data (with potential missing values) from a CSV file.
    - Imputes missing genotype values using KNN imputation, where the `k` closest genotypes are used to determine the imputed values.
    - Writes the imputed genotype data to an output CSV file.

    Output:
    - The imputed genotype data is saved in a CSV file specified by the user.

    Preconditions:
    - The `parameters.txt` file must contain a valid `k` value.
    - The `genotypes.csv` file must contain genotype data, with missing values represented by `-1`.
    - The output file path must be provided to save the imputed genotypes.
*/

#include <iostream>
#include <vector>
#include <string>
#include "read_parameters_knn.h"
#include "read_genotypes_knn.h"
#include "impute_missing_data.h"
#include "write_genotypes_knn.h"

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
