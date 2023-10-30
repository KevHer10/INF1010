#include "Film.h"

// Constructeurs
/// @brief Constructeur par défaut de la classe Film.
Film::Film() : Media(), duree_(0), dureeVisionne_(0) {}

/// @brief Constructeur de la classe Film avec des paramètres.
/// @param titre Le titre du film.
/// @param anneeDeSortie L'année de sortie du film.
/// @param categorie La catégorie du film.
/// @param duree La durée du film en minutes.
Film::Film(string titre, int anneeDeSortie, Categorie categorie, int duree) {}  // TODO


// Methodes virtuelles surchargees
/// @brief Calcule la progression de la lecture du film.
/// @return Une chaîne de caractères représentant la progression de lecture.
string Film::progression() const { return ""; }  // TODO

/// @brief Affiche les informations du film.
/// @param os Le flux de sortie où afficher les informations.
void Film::afficher(ostream& os) const { }  // TODO