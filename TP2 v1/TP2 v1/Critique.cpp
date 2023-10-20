/*
Fichier: Critique.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez 
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: Implementation de la classe Critique.
*/
#include "Critique.h"

// Constructeurs

/// @brief Constructeur par defaut de la classe Critique
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

/// @brief Constructeur par paramètres de la classe Critique.
/// @param auteur: Auteur de la critique du film.
/// @param contenu: Commentaire du film.
/// @param note: Note du film.
Critique::Critique(std::string auteur, std::string contenu, int note)
	: auteur_(auteur), commentaire_(contenu), note_(note) {}

/// @brief Constructeur par copie de la classe Critique
/// @param acteur variable de type Critique avec tout l'information necessaire
Critique::Critique(const Critique& critique): auteur_(critique.auteur_), commentaire_(critique.commentaire_), note_(critique.note_) { }		//TODO

/// @brief definition de la surcharge de l'operateur = qui copie un obejet de type Critiqur dans une autre abjet du meme type
/// @param acteur variable de type Critique avec tout l'information necessaire
/// @return un objet de type Critique
Critique& Critique::operator=(const Critique& critique) {
	if (this != &critique) {
		auteur_ = critique.auteur_;
		commentaire_ = critique.commentaire_;
		note_ = critique.note_;
	}

	return *this;
}	// TODO

// Getters

/// @brief Retourne le nom de l'Auteur
/// @return nom auteur.
string Critique::getAuteur() const { return auteur_; }

/// @brief Retourne le commentaire de l'Auteur. 
/// @return commentaire de l'auteur.
string Critique::getCommentaire() const { return commentaire_; }

/// @brief Retourne la note de la critique.
/// @return note critique.
int Critique::getNote() const { return note_; }

// Setters
/// @brief Modifie le nom de l'Auteur. 
/// @param auteur: nom de l'Auteur. 
void Critique::setAuteur(string auteur) { this->auteur_ = auteur; }

/// @brief Modifie le commentaire de l'auteur.
/// @param contenu: commentaire de l'auteur.
void Critique::setCommentaire(string contenu) { this->commentaire_ = contenu; }

/// @brief Modifie la note de la critique.
/// @param note: note de la critique.
void Critique::setNote(int note) { this->note_ = note; }

// Opérateurs

/// @brief definition de la surcharge de l'operateur == qui compare 2 objets de type Critique pour savoir s'ils ont le meme contenu.
/// @param acteur variable de type Critique avec tout l'information necessaire
/// @return true si les objets sont pareils et false sinon
bool Critique::operator==(const Critique& critique) const {
	if (auteur_ == critique.auteur_ && commentaire_ == critique.commentaire_ && note_ == critique.note_)
		return true;

	return false;
} // TODO

/// @brief definition de la surcharge de l'operateur != qui compare 2 objets de type Critique pour savoir s'ils n'ont pas le meme contenu.
/// @param acteur variable de type Critique avec tout l'information necessaire
/// @return true si les objets ne sont pas pareils et false sinon
bool Critique::operator!=(const Critique& critique) const {
	if (auteur_ != critique.auteur_ || commentaire_ != critique.commentaire_ || note_ != critique.note_)
		return true;
	return false;
}	// TODO

// Méthodes pour l'affichage

/// @brief Affiche toutes les informations d'une suele critique.
/// @param os extraction operator 
/// @param acteur variable de type Critique contenant toute l'information de l'objet 
/// @return affichage de l'objet
ostream& operator<<(ostream& os, const Critique& critique) { 
	return os << critique.auteur_ << ": " << critique.commentaire_ << " - Note: " << critique.note_ << "\n";
}	// TODO