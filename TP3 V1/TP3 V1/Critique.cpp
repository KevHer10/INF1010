#include "Critique.h"

// Constructeurs
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

Critique::Critique(std::string auteur, std::string contenu, int note)
    : auteur_(auteur), commentaire_(contenu), note_(note) {}

Critique::Critique(const Critique& critique) { }  // TODO

Critique& Critique::operator=(const Critique& critique) { return *this; }  // TODO

// Methode vituelle surchargee
float Critique::obtenirEvaluation() const { return 0.0; }  // TODO

// Operators
bool Critique::operator==(const Critique& critique) const { return false;}  // TODO

bool Critique::operator!=(const Critique& critique) const { return false;}  // TODO

// Methodes pour l'affichage
ostream& operator<<(ostream& os, const Critique& critique) { return os; }  // TODO