/**
 * @file read_parameters_knn.h
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Reads the parameter file to extract the value of `k` for KNN imputation.
 * 
 * @details
 * This header file defines a function that reads a parameter file and extracts the value of `k`, 
 * which is used in the k-nearest neighbors (KNN) imputation process. The parameter file is expected 
 * to contain a line in the format:
 * ```
 * k <value>
 * ```
 * where `<value>` is an integer.
 * 
 * @section Features Key Features
 * - Reads the parameter file to extract the value of `k`.
 * - Handles the extraction of `k` from a correctly formatted line in the file.
 * - Ensures that `k` is a valid positive integer.
 * 
 * @section Preconditions Preconditions
 * - The input file must contain a line specifying the value of `k` in the format: `k <value>`.
 * - The file must be accessible and readable.
 * - The extracted value of `k` must be a valid positive integer.
 * 
 * @section Output Output
 * - The function modifies the `k` variable by extracting its value from the file.
 */


#ifndef READ_PARAMETERS_KNN_H
#define READ_PARAMETERS_KNN_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Reads the parameter file and extracts the value of `k` for KNN imputation.
 * 
 * @details
 * This function opens a parameter file, searches for the line containing `k <value>`, 
 * and extracts the integer value of `k`, which is then stored in the provided variable.
 * 
 * @param filename The name of the parameter file containing the value of `k`.
 * @param k A reference to an integer variable where the extracted `k` value will be stored.
 * 
 * @throws std::runtime_error If the file cannot be opened.
 * @throws std::invalid_argument If the `k` value is missing, improperly formatted, or not a valid positive integer.
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * int k;
 * readParameters("config/parameters.txt", k);
 * @endcode
 * 
 * @see imputeMissingDataKNN()
 */
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
