
/**
 * @file vector_hash.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Custom hash function for `std::vector<int>` to be used in hash-based containers.
 * 
 * @details
 * This header file defines a custom hash function for `std::vector<int>`, allowing it to be 
 * used as a key in hash-based containers like `std::unordered_map` and `std::unordered_set`. 
 * The hash function iterates through the elements of the vector and applies a combination 
 * of hash operations to generate a unique hash code for each vector.
 * 
 * @section Features Key Features
 * - Implements a custom hash function for vectors of integers.
 * - Ensures compatibility of `std::vector<int>` with unordered containers.
 * - Provides a simple and efficient hashing mechanism.
 * 
 * @section Preconditions Preconditions
 * - The elements of the vector should be of type `int`.
 * - The hashing mechanism assumes the vector has a deterministic ordering.
 * 
 * @section Output Output
 * - Provides the `VectorHash` structure that can be used as a custom hash function in `std::unordered_map` and `std::unordered_set`.
 */

#ifndef VECTOR_HASH_H
#define VECTOR_HASH_H

#include <vector>
#include <functional>
#include <new>
#include <stddef.h>

/**
 * @brief Custom hash function for `std::vector<int>`.
 * 
 * @details
 * This structure defines a custom hashing mechanism for `std::vector<int>`. It computes a hash 
 * value by iterating through the vector elements and applying bitwise operations to ensure 
 * a unique and well-distributed hash.
 * 
 * @tparam T The type of elements in the vector (assumed to be `int`).
 * 
 * @return A hash value representing the vector.
 * 
 * @section Example Example Usage
 * @code
 * std::unordered_map<std::vector<int>, double, VectorHash> frequencies;
 * frequencies[std::vector<int>{0, 1, 1}] = 0.5;
 * frequencies[std::vector<int>{1, 0, 1}] = 0.3;
 * 
 * for (const auto& pair : frequencies) {
 *     std::cout << "Haplotype: ";
 *     for (int allele : pair.first) std::cout << allele << " ";
 *     std::cout << " -> Frequency: " << pair.second << std::endl;
 * }
 * @endcode
 */

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
