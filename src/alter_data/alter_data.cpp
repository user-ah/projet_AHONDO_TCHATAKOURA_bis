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
