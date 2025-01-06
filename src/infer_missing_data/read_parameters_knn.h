#ifndef READ_PARAMETERS_KNN_H
#define READ_PARAMETERS_KNN_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

inline bool readParameters(const std::string &parameters_file, int &k) {
    std::ifstream file(parameters_file);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir " << parameters_file << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("k") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            iss >> key >> k;
        }
    }
    file.close();
    return true;
}

#endif
