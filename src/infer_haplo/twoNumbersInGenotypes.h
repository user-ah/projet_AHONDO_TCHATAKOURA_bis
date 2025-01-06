#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * Compte le nombre total de `2` dans un fichier de génotypes.
 * Chaque ligne du fichier représente un génotype.
 *
 * @param genotypesFile Nom du fichier CSV contenant les génotypes
 * @return Nombre total de `2` dans le fichier
 */
inline size_t countTwosInGenotypes(const std::string& genotypesFile) {
    std::ifstream file(genotypesFile);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << genotypesFile << std::endl;
        exit(EXIT_FAILURE);
    }

    size_t countTwos = 0; // Compteur pour le nombre de `2`
    std::string line;
    char delimiter = ','; 
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Ignorer les lignes vides

        std::istringstream stream(line);
        std::string valueStr;

        // Lecture de chaque valeur sur une ligne
        while (std::getline(stream, valueStr, delimiter)) {
            int value = std::stoi(valueStr); // Conversion en entier
            if (value == 2) {
                countTwos++; // Incrémenter le compteur si la valeur est `2`
            }
        }
    }

    return countTwos; // Retourner le total
}