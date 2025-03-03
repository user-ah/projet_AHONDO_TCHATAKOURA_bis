/**
 * @file read_parameters.h
 * @brief Defines a function to read simulation parameters from a text file.
 * 
 * This header file contains the declaration of a function that reads the percentage 
 * of missing data (`percent_miss`) from a specified text file and assigns it to a variable.
 * 
 * @authors
 * Ahamed TCHATAKOURA & Mawuéna AHONDO
 * 
 * @details
 * The function parses a text file to find a specific parameter (`percent_miss`), 
 * extracts the value associated with the parameter, converts it to a float, and 
 * assigns it to the provided variable. It also handles errors if the file cannot 
 * be opened or if the parameter is missing.
 * 
 * @param parametersFile The path to the text file containing the simulation parameters.
 * @param percentMiss A reference to a float variable where the percentage of missing data will be stored.
 * 
 * @pre The input file must include a line specifying `percent_miss` in the format: `percent_miss=<value>`.
 * 
 * @throws std::runtime_error if the file cannot be opened.
 * 
 * @note The function exits the program with a failure status if the file cannot be opened.
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
