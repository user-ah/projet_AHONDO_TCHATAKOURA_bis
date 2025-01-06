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