#ifndef IMPUTE_MISSING_DATA_KNN_H
#define IMPUTE_MISSING_DATA_KNN_H

#include <vector>
#include <algorithm>
#include <utility>
#include "hamming_distance.h"

inline void imputeMissingData(std::vector<int> &target, const std::vector<std::vector<int>> &genotypes, int k) {
    std::vector<std::pair<int, int>> distances; // {distance, index}

    for (size_t i = 0; i < genotypes.size(); ++i) {
        int distance = hammingDistance(target, genotypes[i]);
        distances.emplace_back(distance, i);
    }
    // Trier par distance croissante
    std::sort(distances.begin(), distances.end());

    // Parcourir chaque locus pour imputer
    for (size_t i = 0; i < target.size(); ++i) {
        if (target[i] == -1) { // Si la donnée est manquante
            std::vector<int> values; // Valeurs pour imputer
            for (int j = 0; j < k && j < distances.size(); ++j) {
                int neighbor_index = distances[j].second;
                if (genotypes[neighbor_index][i] != -1) { // Ne prendre que les données valides
                    values.push_back(genotypes[neighbor_index][i]);
                }
            }
            if (!values.empty()) {
                // Imputer avec la valeur majoritaire
                int ones = std::count(values.begin(), values.end(), 1);
                int zeros = std::count(values.begin(), values.end(), 0);
                target[i] = (ones >= zeros) ? 1 : 0;
            }
        }
    }
}

#endif
