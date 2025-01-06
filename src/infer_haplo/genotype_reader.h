#ifndef GENOTYPE_READER_H
#define GENOTYPE_READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * @brief Lit un fichier de génotypes CSV et extrait les génotypes, le nombre d'individus et de loci.
 * 
 * @param filename Nom du fichier CSV contenant les génotypes.
 * @param genotypes Vecteur de vecteurs où chaque vecteur représente un génotype.
 * @param n_ind Référence pour stocker le nombre d'individus (lignes).
 * @param n_loci Référence pour stocker le nombre de loci (colonnes).
 */
inline void readGenotypes(const std::string& filename, 
                          std::vector<std::vector<int>>& genotypes, 
                          int& n_ind, int& n_loci) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    n_ind = 0;  
    n_loci = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::vector<int> genotype;
        std::string value;

        while (std::getline(ss, value, ',')) {
            try {
                genotype.push_back(std::stoi(value));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erreur : Valeur non valide '" << value 
                          << "' dans le fichier " << filename 
                          << ", ligne " << n_ind + 1 << "." << std::endl;
                exit(EXIT_FAILURE);
            } catch (const std::out_of_range& e) {
                std::cerr << "Erreur : Valeur hors limites '" << value 
                          << "' dans le fichier " << filename 
                          << ", ligne " << n_ind + 1 << "." << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        if (n_loci == 0) {
            n_loci = genotype.size(); 
        } else if (genotype.size() != n_loci) {
            std::cerr << "Erreur : Ligne " << n_ind + 1 
                      << " du fichier " << filename 
                      << " ne correspond pas au nombre attendu de loci (" << n_loci << ")." << std::endl;
            exit(EXIT_FAILURE);
        }

        genotypes.push_back(genotype);
        ++n_ind;
    }

    file.close();
}

#endif 
