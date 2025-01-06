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

