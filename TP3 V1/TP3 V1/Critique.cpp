#include "Critique.h"

// Constructeurs
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

Critique::Critique(std::string auteur, std::string contenu, int note)
    : auteur_(auteur), commentaire_(contenu), note_(note) {}

Critique::Critique(const Critique& critique) : auteur_(critique.auteur_), commentaire_(critique.commentaire_), note_(critique.note_) { }  // TODO

Critique& Critique::operator=(const Critique& critique) { 
    
    if (this == &critique)
    {
        return *this;
    }
    
}  // TODO

// Methode vituelle surchargee
float Critique::obtenirEvaluation() const { return static_cast<float>(note_); }  // TODO

// Operators
bool Critique::operator==(const Critique& critique) const { 
    if (auteur_ == critique.auteur_
        && commentaire_ == critique.commentaire_
        && note_ == critique.note_
        )
        return true;

    return false;
}  // TODO

bool Critique::operator!=(const Critique& critique) const { 
    if (auteur_ != critique.auteur_
        || commentaire_ != critique.commentaire_
        || note_ != critique.note_
        )
        return true;

    return false;
}  // TODO

// Methodes pour l'affichage
ostream& operator<<(ostream& os, const Critique& critique) { return os; }  // TODO