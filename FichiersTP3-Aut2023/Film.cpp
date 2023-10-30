#include "Film.h"

// Constructeurs
/// @brief Constructeur par d�faut de la classe Film.
Film::Film() : Media(), duree_(0), dureeVisionne_(0) {}

/// @brief Constructeur de la classe Film avec des param�tres.
/// @param titre Le titre du film.
/// @param anneeDeSortie L'ann�e de sortie du film.
/// @param categorie La cat�gorie du film.
/// @param duree La dur�e du film en minutes.
Film::Film(string titre, int anneeDeSortie, Categorie categorie, int duree) {}  // TODO


// Methodes virtuelles surchargees
/// @brief Calcule la progression de la lecture du film.
/// @return Une cha�ne de caract�res repr�sentant la progression de lecture.
string Film::progression() const { return ""; }  // TODO

/// @brief Affiche les informations du film.
/// @param os Le flux de sortie o� afficher les informations.
void Film::afficher(ostream& os) const { }  // TODO