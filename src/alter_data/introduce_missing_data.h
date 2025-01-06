#ifndef INTRODUCE_MISSING_DATA_H
#define INTRODUCE_MISSING_DATA_H

#include <vector>
#include <cstdlib>
#include <ctime>

inline void introduceMissingData(std::vector<std::vector<int>>& genotypes, float percentMiss) {
    int totalElements = genotypes.size() * genotypes[0].size();
    int missingCount = static_cast<int>(percentMiss * totalElements / 100);

    std::srand(std::time(nullptr));
    while (missingCount > 0) {
        int i = std::rand() % genotypes.size();
        int j = std::rand() % genotypes[0].size();

        if (genotypes[i][j] != -1) { // -1 indicates missing data
            genotypes[i][j] = -1;
            --missingCount;
        }
    }
}

#endif
