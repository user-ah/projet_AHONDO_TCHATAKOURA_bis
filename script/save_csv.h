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
