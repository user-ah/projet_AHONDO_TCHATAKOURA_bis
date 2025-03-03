/**
 * @file create_geno_haplo_data.cpp
 * @authors Ahamed TCHATAKOURA & Mawuéna AHONDO
 * 
 * @brief This program generates genotypic and haplotypic data based on the parameters specified 
 * in an input file `parameters.txt`. The results are saved in two CSV files: `genotypes.csv` 
 * and `haplotypes.csv`.
 * 
 * @details
 * Key Features:
 * - Reading parameters from a text file (number of individuals, loci, distinct haplotypes).
 * - Random generation of haplotypes and genotypes.
 * - Saving the generated data to CSV files.
 * 
 * @output CSV files `genotypes.csv` and `haplotypes.csv`.
 * 
 * @pre Properly configured directories and files.
 * @pre `parameters.txt` file containing n_ind, n_loci, n_distinct_haplo.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "read_parameters.h"
#include "generate_haplotypes.h"
#include "generate_genotypes.h"
#include "save_csv.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./create_geno_haplo_data <chemin parameters.txt> <chemin genotypes.csv> <chemin haplotypes.csv>\n";
        return 1;
    }

    std::string param_file = argv[1];
    std::string geno_file = argv[2];
    std::string haplo_file = argv[3];

    srand(time(0));  // Initialize random number generator

    int n_ind, n_loci, n_distinct_haplo;
    read_parameters(param_file, n_ind, n_loci, n_distinct_haplo);

    auto haplotypes = generate_haplotypes(n_ind, n_loci, n_distinct_haplo);
    auto genotypes = generate_genotypes(haplotypes, n_loci);

    save_csv(haplo_file, haplotypes);
    save_csv(geno_file, genotypes);

    std::cout << "Fichiers '" << geno_file << "' et '" << haplo_file << "' générés avec succès.\n";

    return 0;
}
