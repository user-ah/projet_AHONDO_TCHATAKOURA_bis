/**
 * @file log_writer.h
 * @author Ahamed TCHATAKOURA
 * @author Mawuéna AHONDO
 * @date 2025-03-03
 * @version 1.0
 * 
 * @brief Writes log information to a specified log file.
 * 
 * @details
 * This header file defines a function that writes log details to a specified file. The log contains 
 * information about the execution of the Expectation-Maximization (EM) algorithm, including:
 * - The number of individuals and loci.
 * - The number of iterations and execution time.
 * - The number of distinct haplotypes found.
 * - Other relevant statistics for debugging and analysis.
 * 
 * @section Features Key Features
 * - Records key execution details into a log file.
 * - Logs information about the number of individuals, loci, and distinct haplotypes.
 * - Records execution time, EM iterations, and other relevant statistics.
 * - Provides feedback on the success or failure of writing to the log file.
 * 
 * @section Preconditions Preconditions
 * - The `log_file` parameter must be a valid file path and writable.
 * - The `frequencies`, `genotypes`, and `haplotypes` data must be properly initialized before calling the function.
 * 
 * @section Output Output
 * - Writes structured log data to a file specified by `log_file`.
 * - Provides success/failure feedback for log writing operations.
 */


#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief Writes execution details to a log file.
 * 
 * @details
 * This function records key execution details into a log file for debugging and analysis. 
 * It captures information such as:
 * - The number of individuals and loci.
 * - The number of EM iterations performed.
 * - Execution time in seconds.
 * - The number of distinct haplotypes identified.
 * - The computed average Hamming distance.
 * 
 * @param log_file The path to the log file where execution details will be written.
 * @param n_ind The number of individuals in the dataset.
 * @param n_loci The number of loci in the dataset.
 * @param nb_iterations The number of EM iterations performed.
 * @param execution_time The total execution time in seconds.
 * @param count_twos The number of occurrences of the allele `2` in the dataset.
 * @param n_distinct_ground_truth_haplotypes The number of distinct haplotypes in the ground truth data.
 * @param n_distinct_inferred_haplotypes The number of distinct haplotypes inferred by the algorithm.
 * @param average_distance The computed average Hamming distance.
 * 
 * @throws std::runtime_error If the log file cannot be opened or written to.
 * 
 * @return void
 * 
 * @section Example Example Usage
 * @code
 * writeLog("results/log.txt", 100, 50, 20, 1.23, 150, 30, 28, 0.05);
 * @endcode
 * 
 * @see estimation_esperance()
 * @see calculAverageHammingDistance()
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
