/*
    File: log_writer.h

    Authors: Ahamed TCHATAKOURA & Mawuéna AHONDO

    Description:
    This header file defines a function to write log information to a specified log file. 
    The function records details such as the number of individuals, loci, EM iterations, execution time,
    and several statistics related to the genotypes and haplotypes.

    Key Features:
    - Records important information into a log file for analysis and debugging.
    - Provides details on the number of individuals, loci, and distinct haplotypes.
    - Records execution time and other relevant statistics.

    Output:
    - Writes the log data to a file, as specified by the `log_file` parameter.
    - Provides feedback on the success or failure of writing to the log file.

    Preconditions:
    - The `log_file` parameter must be a valid file path.
    - The `frequencies`, `genotypes`, and `haplotypes` data must be properly prepared before calling the function.
*/

#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * Writes log information to a file.
 *
 * @param log_file The path to the log file.
 * @param n_ind Number of individuals.
 * @param n_loci Number of loci.
 * @param nb_iterations Number of EM iterations used.
 * @param executionTime Total execution time (in seconds).
 * @param countTwos Total count of "2"s in the genotypes file.
 * @param n_distinct_ground_truth Number of distinct haplotypes in the reference set.
 * @param n_distinct_inferred Number of distinct haplotypes in the inferred dataset.
 * @param averageDistance Average normalized Hamming distance.
 */
inline void writeLog(const std::string& log_file,
                     int n_ind,
                     int n_loci,
                     int nb_iterations,
                     double executionTime,
                     size_t countTwos,
                     size_t n_distinct_ground_truth,
                     size_t n_distinct_inferred,
                     double averageDistance) {
    std::ofstream log(log_file);
    if (log.is_open()) {
        log << "Number of individuals (n_ind): " << n_ind << "\n";
        log << "Number of loci (n_loci): " << n_loci << "\n";
        log << "Number of iterations used: " << nb_iterations << "\n";
        log << "Execution time: " << executionTime << " seconds\n";
        log << "Total count of `2`s in the genotypes file: " << countTwos << "\n";
        log << "Number of distinct haplotypes (ground truth): " << n_distinct_ground_truth << "\n";
        log << "Number of distinct haplotypes (inferred): " << n_distinct_inferred << "\n";
        log << "Average normalized Hamming distance: " << averageDistance << "\n";
        log.close();
        std::cout << "Log written to: " << log_file << std::endl;
    } else {
        std::cerr << "Error: Unable to open the log file: " << log_file << std::endl;
    }
}

#endif // LOG_WRITER_H
