#include "Critique.h"

// Constructeurs
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

Critique::Critique(std::string auteur, std::string contenu, int note)
    : auteur_(auteur), commentaire_(contenu), note_(note) {}

Critique::Critique(const Critique& critique) {
	*this = critique;
}

Critique& Critique::operator=(const Critique& critique) {
    this->auteur_ = critique.auteur_;
	this->commentaire_ = critique.commentaire_;
	this->note_ = critique.note_;
	return *this;
}

// Methode vituelle surchargee
float Critique::obtenirEvaluation() const {
    return static_cast<float>(getNote());
}

// Operators
bool Critique::operator==(const Critique& critique) const {
	return this->auteur_ == critique.auteur_ && this->commentaire_ == critique.commentaire_ && this->note_ == critique.note_;
}

bool Critique::operator!=(const Critique& critique) const {
    return !(*this == critique);
}

// Methodes pour l'affichage
ostream& operator<<(ostream& os, const Critique& critique) {
    os << "\t" << critique.auteur_ << ": " << critique.commentaire_ << " - Note : " << critique.note_;
	return os;
}