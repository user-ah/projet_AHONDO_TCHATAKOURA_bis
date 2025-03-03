/**
 * @file read_parameters.h
 * @brief Defines the function `read_parameters` to read configuration parameters from a specified text file.
 * 
 * This header file defines the function `read_parameters`, which reads configuration parameters 
 * from a specified text file. The function extracts the values for the number of individuals (`n_ind`), 
 * the number of loci (`n_loci`), and the number of distinct haplotypes (`n_distinct_haplo`) 
 * from the file and assigns them to the respective variables.
 * 
 * @authors 
 * Ahamed TCHATAKOURA & Mawuéna AHONDO
 * 
 * @details
 * - The function opens the input file and checks for successful opening.
 * - It reads each line of the file and extracts the values of `n_ind`, `n_loci`, and `n_distinct_haplo`.
 * - If the file cannot be opened, an error message is displayed, and the program terminates.
 * 
 * @param filepath The path to the input parameters file.
 * @param n_ind Output parameter to store the number of individuals.
 * @param n_loci Output parameter to store the number of loci.
 * @param n_distinct_haplo Output parameter to store the number of distinct haplotypes.
 * 
 * @pre The parameters file must be correctly formatted, containing `n_ind`, `n_loci`, and `n_distinct_haplo`.
 * 
 * @post The function modifies the `n_ind`, `n_loci`, and `n_distinct_haplo` variables with the values 
 * read from the file.
 */

#ifndef READ_PARAMETERS_H
#define READ_PARAMETERS_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

inline void read_parameters(const std::string& filepath, int& n_ind, int& n_loci, int& n_distinct_haplo) {
    std::ifstream infile(filepath);
    if (!infile) {
        std::cerr << "Erreur d'ouverture du fichier de paramètres.\n";
        exit(1);
    }
    std::string line;
    while (infile >> line) {
        if (line == "n_ind") {
            infile >> n_ind;
        } else if (line == "n_loci") {
            infile >> n_loci;
        } else if (line == "n_distinct_haplo") {
            infile >> n_distinct_haplo;
        }
    }
    infile.close();
}

#endif

