/*
    File: hamming_distance_knn.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to compute the Hamming distance between two vectors of integers. 
    The Hamming distance is the number of positions at which the corresponding elements in two vectors 
    are different, while ignoring positions where the elements are marked as -1.

    Key Features:
    - Computes the Hamming distance between two vectors of integers.
    - Ignores positions with a value of `-1`, which may represent missing or undefined data.
    
    Output:
    - The function `hammingDistance` returns the Hamming distance between the two input vectors.

    Preconditions:
    - The vectors `a` and `b` must be of the same size.
    - The vectors may contain integer values, with `-1` indicating missing or undefined values.
*/

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
