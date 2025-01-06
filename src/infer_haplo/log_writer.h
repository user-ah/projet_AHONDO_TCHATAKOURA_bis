#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * Écrit les informations de log dans un fichier.
 *
 * @param log_file Le chemin vers le fichier de log.
 * @param n_ind Nombre d'individus.
 * @param n_loci Nombre de loci.
 * @param nb_iterations Nombre d'itérations EM utilisées.
 * @param executionTime Durée totale d'exécution (en secondes).
 * @param countTwos Nombre total de "2" dans le fichier des génotypes.
 * @param n_distinct_ground_truth Nombre d'haplotypes distincts dans la référence.
 * @param n_distinct_inferred Nombre d'haplotypes distincts dans les inférences.
 * @param averageDistance Distance moyenne de Hamming (normalisée).
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
        log << "Nombre d'individus (n_ind) : " << n_ind << "\n";
        log << "Nombre de loci (n_loci) : " << n_loci << "\n";
        log << "Nombre d'itérations utilisées : " << nb_iterations << "\n";
        log << "Durée d'exécution : " << executionTime << " secondes\n";
        log << "Nombre total de `2` dans le fichier des génotypes : " << countTwos << "\n";
        log << "Nombre d'haplotypes distincts (ground truth) : " << n_distinct_ground_truth << "\n";
        log << "Nombre d'haplotypes distincts (inférés) : " << n_distinct_inferred << "\n";
        log << "Distance moyenne de Hamming (normalisée) : " << averageDistance << "\n";
        log.close();
        std::cout << "Log écrit dans : " << log_file << std::endl;
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier de log : " << log_file << std::endl;
    }
}

#endif // LOG_WRITER_H
