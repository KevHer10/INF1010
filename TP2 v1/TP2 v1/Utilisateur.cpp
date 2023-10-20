/*
Fichier: Utilisateur.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: Implementation de la classe Utilisateur.
*/
#include "Utilisateur.h"
   
/// @brief constructeur par parametres de la classe Utilisateur.
   /// @param nom nom de l'utilisateur
   /// @param mdp mot de passe de l'utilisateur
Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

/// @brief retourne le nom de l'utilisateur
/// @return le nom de l'utilisateur de type string.
string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

/// @brief retourne dans le vecteur de type vector<shared_ptr<Film>> les films visionnes par l'utilisateur
/// @return un vector<shared_ptr<Film>> avec les films visionnes par l'utilisateur
vector<shared_ptr<Film>> Utilisateur::getFilmsVus() const { return filmsVus; }

/// @brief modifie le nom de l'utilisateur
/// @param nom le nom de l'utilisateur de type string
void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

/// @brief modifie le mot de passe de l'utilisateur
/// @param mdp mot de passe de l'utilisateur de type string
void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

/// @brief ajoute un film au vecteur vector<shared_ptr<Film>> filmsVus
/// @param film un shared_ptr de type Film
void Utilisateur::ajouterFilm(shared_ptr<Film> film) { filmsVus.push_back(film); } // TODO

/// @brief Verifie le mot de passe de l'utilisateur
/// @param mdp mot de passe de l'utilisateur
/// @return true si le mot de passe correspond a l'utilisateur et false sinon
bool Utilisateur::verifierConnexion(const string& mdp) const {
	if (motDePasse == mdp)
		return true;

	return false;
} // TODO
