/**
 * @file save_csv.h
 * @brief Defines the function `save_csv` for saving a 2D vector of integers into a CSV file.
 * 
 * This header file contains the declaration of the `save_csv` function, which writes a 2D vector of integers
 * to a CSV file. The function ensures that values are separated by commas and rows are separated by newline characters.
 * 
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * 
 * @details
 * The `save_csv` function performs the following operations:
 * - Opens the specified file for writing.
 * - Iterates through each row of the 2D vector and writes the values to the file, adding commas between the values in a row.
 * - Adds a newline character after writing each row to separate rows.
 * - Closes the file after writing all the data.
 * 
 * @param filename The name of the file where the data will be saved.
 * @param data A 2D vector of integers containing the data to be written to the file.
 * 
 * @return void
 */

#ifndef SAVE_CSV_H
#define SAVE_CSV_H

#include <vector>
#include <string>
#include <fstream>

inline void save_csv(const std::string& filename, const std::vector<std::vector<int>>& data) {
    std::ofstream file(filename);

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
}

#endif
