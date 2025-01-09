/*
    File: vector_hash.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a custom hash function for `std::vector<int>`, which is used in 
    hash-based containers like `std::unordered_map`. It computes a hash value for a vector of integers 
    by iterating through its elements and applying a combination of hash operations to produce a unique 
    hash code for each vector.

    Key Features:
    - Defines a custom hash function for vectors of integers.
    - Ensures that `std::vector<int>` can be used as a key in unordered containers like `std::unordered_map`.

    Output:
    - This file provides the `VectorHash` structure that can be used with hash-based containers.

    Preconditions:
    - The elements of the vector should be of type `int`.
*/

#ifndef VECTOR_HASH_H
#define VECTOR_HASH_H

#include <vector>
#include <functional>
#include <new>
#include <stddef.h>

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

#endif // VECTOR_HASH_H
