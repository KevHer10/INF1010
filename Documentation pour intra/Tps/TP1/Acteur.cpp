/*
Fichier: Acteur.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Implementation de la classe Acteur.
*/
#include "Acteur.h"


// TODO: Implémenter les méthodes de la classe Acteur ici.

// Constructeurs

/// @brief constructeur par défaut de la classe Acteur.
Acteur::Acteur() {
	nom_ = "";
	anneeNaissance_ = 0;
	biographie_ = "";

}
/// @brief constructeur par défaut de la classe Acteur.
/// @param nom: nom acteur
/// @param anneeNaissance: anee de naissance de l'acteur. 
/// @param biographie: biographie de l'acteur.
Acteur::Acteur(std::string nom, int anneeNaissance, std::string biographie) {
	nom_ = nom;
	anneeNaissance_ = anneeNaissance;
	biographie_ = biographie;

}

// Getters

/// @brief retourne le nom de l'acteur.
/// @return nom acteur  
string Acteur::getNom() const {
	return nom_;
}
/// @brief retourne anee de naissance de l'acteur.
/// @return anee de naissance
int Acteur::getAnneeNaissance() const {
	return anneeNaissance_;
}
/// @brief retourne la biographie de l'acteur.
/// @return biographie de l'acteur.
string Acteur::getBiographie() const {
	return biographie_;
}

// Setters

/// @brief modifie le nom de l'acteur.
/// @param nom: nom de l'acteur
void Acteur::setNom(const std::string nom) {
	nom_ = nom;
}
/// @brief modifie l'anee de naissance de l'acteur. 
/// @param anneeNaissance: anee de naissance de l'acteur. 
void Acteur::setAnneeNaissance(int anneeNaissance) {
	anneeNaissance_ = anneeNaissance;
}
/// @brief modifie la Biographie de l'acteur.
/// @param bio: Biographie de l'acteur.
void Acteur::setBiographie(const std::string bio) {
	biographie_ = bio;
}

// Méthode d'affichage

/// @brief Affiche un suel acteur.
void Acteur::afficher() const {
	

	cout << nom_ << "\n";
	cout << SEPARATEUR_SIMPLE;
	cout << "\n\tDate de naissance: " << anneeNaissance_;
	cout << "\n\tBiographie: " << biographie_ << "\n";
	cout << SEPARATEUR_SIMPLE << "\n";

}
