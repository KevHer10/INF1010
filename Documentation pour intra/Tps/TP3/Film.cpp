/*
Fichier: Film.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Film.
*/
#include "Film.h"

// Constructeurs

/// @brief Constructeur par d�faut de la classe Film.
Film::Film() : Media(), duree_(0), dureeVisionne_(0) {}

/// @brief Constructeur de la classe Film avec des param�tres.
/// @param titre Le titre du film.
/// @param anneeDeSortie L'ann�e de sortie du film.
/// @param categorie La cat�gorie du film.
/// @param duree La dur�e du film en minutes.
Film::Film(string titre, int anneeDeSortie, Categorie categorie, int duree): Media(titre,anneeDeSortie,categorie), duree_(duree) {}  // TODO


// Methodes virtuelles surchargees

/// @brief Calcule la progression de la lecture du film.
/// @return Une cha�ne de caract�res repr�sentant la progression de lecture.
string Film::progression() const { return "Temps ecoule: " + to_string(dureeVisionne_) + "/" +
to_string(duree_) + " minutes\n"; }  // TODO

/// @brief Affiche les informations du film.
/// @param os Le flux de sortie o� afficher les informations.
void Film::afficher(ostream& os) const {

	Media::afficher(os);
	cout << "Duree: " << duree_ << " minutes\n\n";

}  // TODO