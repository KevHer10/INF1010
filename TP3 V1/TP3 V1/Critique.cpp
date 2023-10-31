/*
Fichier: Critique.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Critique.
*/
#include "Critique.h"

// Constructeurs

/// @brief Constructeur par d�faut de la classe Critique.
Critique::Critique() : auteur_(""), commentaire_(""), note_(0) {}

/// @brief Constructeur de la classe Critique avec des param�tres.
/// @param auteur L'auteur de la critique.
/// @param commentaire Le commentaire de la critique.
/// @param note La note attribu�e dans la critique.
Critique::Critique(std::string auteur, std::string contenu, int note)
    : auteur_(auteur), commentaire_(contenu), note_(note) {}

/// @brief Constructeur de copie de la classe Critique.
/// @param critique La critique � copier.
Critique::Critique(const Critique& critique) : auteur_(critique.auteur_), commentaire_(critique.commentaire_), note_(critique.note_) { }  // TODO

/// @brief Surcharge de l'op�rateur d'assignation pour la classe Critique.
/// @param critique La critique � copier.
/// @return Une r�f�rence � la critique modifi�e.
Critique& Critique::operator=(const Critique& critique) { 
    
    if (this == &critique)
    {
        return *this;
    }
          
    
}  // TODO

// Methode vituelle surchargee

/// @brief Calcule l'�valuation de la critique.
/// @return L'�valuation de la critique.
float Critique::obtenirEvaluation() const { return static_cast<float>(note_); }  // TODO

// Operators

/// @brief Surcharge de l'op�rateur d'�galit� pour comparer les critiques.
/// @param critique La critique � comparer.
/// @return true si les critiques sont �gales, false sinon.
bool Critique::operator==(const Critique& critique) const { 
    if (auteur_ == critique.auteur_
        && commentaire_ == critique.commentaire_
        && note_ == critique.note_
        )
        return true;

    return false;
}  // TODO

/// @brief Surcharge de l'op�rateur de diff�rence pour comparer les critiques.
/// @param critique La critique � comparer.
/// @return true si les critiques sont diff�rentes, false sinon.
bool Critique::operator!=(const Critique& critique) const { 
    if (auteur_ != critique.auteur_
        || commentaire_ != critique.commentaire_
        || note_ != critique.note_
        )
        return true;

    return false;
}  // TODO

// Methodes pour l'affichage

/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations de la critique.
/// @param os Le flux de sortie.
/// @param critique La critique � afficher.
/// @return Le flux de sortie mis � jour.
ostream& operator<<(ostream& os, const Critique& critique) { 
    return os<<"------------------------------------------------\n" 
        << critique.auteur_ << ": " << critique.commentaire_ << " - Note: " << critique.note_ << "\n\n";
}	// TODO
    
    
    