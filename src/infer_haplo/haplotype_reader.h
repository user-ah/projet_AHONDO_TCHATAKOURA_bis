#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * Lecture des haplotypes à partir d'un fichier CSV et stockage dans un vecteur.
 * Chaque paire d'haplotypes correspond à deux lignes consécutives dans le fichier.
 *
 * @param filename Nom du fichier CSV contenant les haplotypes
 * @return Vecteur de paires d'haplotypes (chacun étant un vecteur d'entiers)
 */
inline std::vector<std::pair<std::vector<int>, std::vector<int>>> readHaplotypes(const std::string& filename) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> haplotypes;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    char delimiter = ','; // Supposons que le séparateur est une virgule
    std::vector<int> haplo1, haplo2;

    while (std::getline(file, line)) {
        std::vector<int> haplo;
        std::istringstream stream(line);
        std::string alleleStr;

        // Lire chaque valeur entière séparée par des virgules
        while (std::getline(stream, alleleStr, delimiter)) {
            haplo.push_back(std::stoi(alleleStr));
        }

        if (haplo1.empty()) {
            haplo1 = haplo; // Premier haplotype de la paire
        } else {
            haplo2 = haplo; // Deuxième haplotype de la paire
            haplotypes.emplace_back(haplo1, haplo2); // Stocker la paire
            haplo1.clear(); // Réinitialiser pour la prochaine paire
        }
    }

    return haplotypes;
}