/*
    File: read_parameters.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to read simulation parameters from a text file. 
    Specifically, it extracts the percentage of missing data (percent_miss) specified 
    in the file and assigns it to a variable.

    Key Features:
    - Parses a text file to find a specific parameter (`percent_miss`).
    - Extracts the value associated with the parameter and converts it to a float.
    - Handles errors if the file cannot be opened or the parameter is missing.

    Output: A float value representing the percentage of missing data.

    Preconditions:
    - The input file must include a line specifying `percent_miss` in the format: `percent_miss=<value>`.
*/

#ifndef READ_PARAMETERS_H
#define READ_PARAMETERS_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

inline void readParameters(const std::string& parametersFile, float& percentMiss) {
    std::ifstream file(parametersFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << parametersFile << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("percent_miss") != std::string::npos) {
            percentMiss = std::stof(line.substr(line.find('<') + 1));
            break;
        }
    }
    file.close();
}

#endif
