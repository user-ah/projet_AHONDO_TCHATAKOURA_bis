#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * Calcul de la distance de Hamming entre deux haplotypes.
 * La distance de Hamming correspond au nombre de positions où deux vecteurs diffèrent.
 *
 * @param haplo1 Premier haplotype (vecteur d'entiers)
 * @param haplo2 Deuxième haplotype (vecteur d'entiers)
 * @return Distance de Hamming (entier)
 */
inline int calculateHammingDistance(const std::vector<int>& haplo1, const std::vector<int>& haplo2) {
    // Vérification que les deux haplotypes ont la même taille
    if (haplo1.size() != haplo2.size()) {
        std::cerr << "Erreur : Les haplotypes ont des dimensions différentes." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Calcul de la distance en comparant chaque position
    int distance = 0;
    for (size_t i = 0; i < haplo1.size(); ++i) {
        if (haplo1[i] != haplo2[i]) {
            distance++;
        }
    }
    return distance;
}