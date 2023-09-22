#include "Critique.h"

// Constructeurs
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

Critique::Critique(std::string auteur, std::string contenu, int note)
	: auteur_(auteur), commentaire_(contenu), note_(note) {}

Critique::Critique(const Critique& critique) { }							// TODO

Critique& Critique::operator=(const Critique& critique) { return *this; }	// TODO

// Getters
string Critique::getAuteur() const { return auteur_; }

string Critique::getCommentaire() const { return commentaire_; }

int Critique::getNote() const { return note_; }

// Setters
void Critique::setAuteur(string auteur) { this->auteur_ = auteur; }

void Critique::setCommentaire(string contenu) { this->commentaire_ = contenu; }

void Critique::setNote(int note) { this->note_ = note; }

// Opérateurs
bool Critique::operator==(const Critique& critique) const { return false; } // TODO
bool Critique::operator!=(const Critique& critique) const { return false; }	// TODO

// Méthodes pour l'affichage
ostream& operator<<(ostream& os, const Critique& critique) { return os; }	// TODO