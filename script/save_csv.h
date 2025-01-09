/*
    File: save_csv.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines the function `save_csv`, which saves a 2D vector of integers into a CSV file. 
    The function takes the filename and the data as input, writes the data to the specified CSV file, 
    and ensures that the values are separated by commas and rows are separated by newline characters.

    Key Functionality:
    - The function opens the specified file for writing.
    - It iterates through each row of the 2D vector and writes the values to the file, 
      adding commas between the values in a row.
    - After writing each row, a newline character is added to separate rows.
    - The file is closed after writing all the data.

    Parameters:
    - `filename`: The name of the file where the data will be saved.
    - `data`: A 2D vector of integers containing the data to be written to the file.

    Output:
    - The function writes the 2D vector `data` into a CSV file with the specified filename.
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
