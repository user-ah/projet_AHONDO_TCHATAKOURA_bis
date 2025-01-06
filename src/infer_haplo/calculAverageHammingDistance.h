#include "calculHammingDistance.h"

/**
 * Calcul de la distance moyenne de Hamming normalisée entre deux ensembles d'haplotypes.
 *
 * @param inferredHaplotypes Haplotypes inférés (vecteur de paires de vecteurs)
 * @param groundTruthHaplotypes Haplotypes de référence (vecteur de paires de vecteurs)
 * @param nLoci Nombre de loci (longueur des haplotypes)
 * @return Distance moyenne de Hamming normalisée (double)
 */
inline double calculateAverageHammingDistance(
    const std::vector<std::pair<std::vector<int>, std::vector<int>>>& inferredHaplotypes,
    const std::vector<std::pair<std::vector<int>, std::vector<int>>>& groundTruthHaplotypes,
    int nLoci) {

    // Vérification que les deux ensembles ont le même nombre d'individus
    if (inferredHaplotypes.size() != groundTruthHaplotypes.size()) {
        std::cerr << "Erreur : Le nombre de paires de haplotypes ne correspond pas." << std::endl;
        exit(EXIT_FAILURE);
    }

    double totalDistance = 0.0; // Somme des distances normalisées
    size_t nInd = inferredHaplotypes.size(); // Nombre d'individus (paires de haplotypes)

    for (size_t i = 0; i < nInd; ++i) {
        const auto& [h1, h2] = inferredHaplotypes[i];
        const auto& [g1, g2] = groundTruthHaplotypes[i];

        // Vérification des dimensions de chaque haplotype
        if (h1.size() != nLoci || h2.size() != nLoci || g1.size() != nLoci || g2.size() != nLoci) {
            std::cerr << "Erreur : Dimensions incorrectes pour l'individu " << i << std::endl;
            exit(EXIT_FAILURE);
        }

        // Calcul des distances entre haplotypes dans les deux configurations possibles
        int d1 = calculateHammingDistance(h1, g1) + calculateHammingDistance(h2, g2);
        int d2 = calculateHammingDistance(h1, g2) + calculateHammingDistance(h2, g1);

        // Ajout de la distance minimale, normalisée par 2 * nLoci
        totalDistance += std::min(d1, d2) / static_cast<double>(2 * nLoci);
    }

    // Retourne la distance moyenne sur tous les individus
    return totalDistance / static_cast<double>(nInd);
}
