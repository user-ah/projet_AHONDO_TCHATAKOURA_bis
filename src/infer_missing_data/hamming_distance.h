#ifndef HAMMING_DISTANCE_KNN_H
#define HAMMING_DISTANCE_KNN_H

#include <vector>
#include <string>

inline int hammingDistance(const std::vector<int> &a, const std::vector<int> &b) {
    int distance = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != -1 && b[i] != -1 && a[i] != b[i]) {
            ++distance;
        }
    }
    return distance;
}

#endif
