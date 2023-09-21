#include "Acteur.h"

// TODO: Impl�menter les m�thodes de la classe Acteur ici.

// Constructeurs
Acteur::Acteur() {
	nom_ = "";
	anneeNaissance_ = 0;
	biographie_ = "";

}

Acteur::Acteur(std::string nom, int anneeNaissance, std::string biographie) {
	nom_ = nom;
	anneeNaissance_ = anneeNaissance;
	biographie_ = biographie;

}

// Getters
string Acteur::getNom() const {
	return nom_;
}

int Acteur::getAnneeNaissance() const {
	return anneeNaissance_;
}

string Acteur::getBiographie() const {
	return biographie_;
}

// Setters
void Acteur::setNom(const std::string nom) {
	nom_ = nom;
}

void Acteur::setAnneeNaissance(int anneeNaissance) {
	anneeNaissance_ = anneeNaissance;
}

void Acteur::setBiographie(const std::string bio) {
	biographie_ = bio;
}

// M�thode d'affichage
void Acteur::afficher() const {
	

	cout << nom_ << "\n";
	cout << SEPARATEUR_SIMPLE;
	cout << "\n\tDate de naissance: " << anneeNaissance_;
	cout << "\n\tBiographie: " << biographie_ << "\n";
	cout << SEPARATEUR_SIMPLE << "\n";

}
