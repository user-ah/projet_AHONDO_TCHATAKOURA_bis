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
