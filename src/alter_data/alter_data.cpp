/*
    File: alter_data.cpp

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This program modifies genotype data by introducing missing values based on parameters 
    specified in an input file `parameters.txt`. The modified data is saved in a new CSV file.

    Key Features:
    - Reading a percentage of missing data to introduce from a parameters file.
    - Reading genotype data from a CSV file.
    - Introducing missing data into the genotype matrix.
    - Writing the altered genotype data to a new CSV file.

    Output: A new CSV file `<genotypes>_altered.csv` containing the modified genotype data.

    Preconditions:
    - `parameters.txt` must specify the percentage of missing data (as a float).
    - `genotypes.csv` must contain a valid genotype matrix.
    - Ensure proper file paths and directory permissions.
*/
#include <iostream>
#include <vector>
#include <string>
#include "read_parameters.h"
#include "read_genotypes.h"
#include "introduce_missing_data.h"
#include "write_genotypes.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./alter_data <parameters.txt> <genotypes.csv>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string parametersFile = argv[1];
    std::string genotypesFile = argv[2];
    std::string outputFile = genotypesFile.substr(0, genotypesFile.find_last_of('.')) + "_altered.csv";

    float percentMiss = 0.0f;
    readParameters(parametersFile, percentMiss);

    std::vector<std::vector<int>> genotypes;
    readGenotypes(genotypesFile, genotypes);

    introduceMissingData(genotypes, percentMiss);

    writeGenotypes(outputFile, genotypes);

    std::cout << "Fichier de génotypes altéré écrit dans " << outputFile << std::endl;

    return 0;
}
