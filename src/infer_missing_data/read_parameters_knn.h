/*
    File: read_parameters_knn.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to read the parameter file and extract the value of `k` used in the KNN imputation process.
    The parameter file is expected to contain the value of `k` on a line in the format: `k <value>`, where `<value>` is an integer.

    Key Features:
    - Reads the parameter file to extract the value of `k`.
    - Handles the extraction of `k` from a formatted line in the file.

    Output:
    - The function modifies the `k` variable by extracting its value from the file.

    Preconditions:
    - The input file must contain a line specifying the value of `k` in the format: `k <value>`.
*/

#ifndef READ_PARAMETERS_KNN_H
#define READ_PARAMETERS_KNN_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

inline bool readParameters(const std::string &parameters_file, int &k) {
    std::ifstream file(parameters_file);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open " << parameters_file << std::endl;
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
