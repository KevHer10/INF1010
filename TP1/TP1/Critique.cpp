#include "Critique.h"

// TODO: Implémenter les méthodes de la classe Critique ici.

// Constructeurs
Critique::Critique() { 
	auteur_ = "";
	commentaire_ = "";
	note_ = 0;
}

Critique::Critique(std::string auteur, std::string contenu, int note) {
	auteur_ = auteur;
	commentaire_ = contenu;
	note_ = note;
}

// Getters
string Critique::getAuteur() const { return auteur_; }

string Critique::getCommentaire() const { return commentaire_; }

int Critique::getNote() const { return note_; }

// Setters
void Critique::setAuteur(string auteur) {
	auteur_ = auteur;
}

void Critique::setCommentaire(string contenu) {
	commentaire_ = contenu;
}

void Critique::setNote(int note) {
	note_ = note;
}

// Méthode d'affichage
void Critique::afficher() const {

	cout << auteur_ << ": " << commentaire_ << " - Note: " << note_ << "\n";
}
