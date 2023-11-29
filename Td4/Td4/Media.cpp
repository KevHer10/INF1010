/*
Fichier: Media.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation de la classe Media.
*/
#include "Media.h"

// Constructeur
Media::Media() : titre_(""), anneeDeSortie_(0), categorie_(Categorie::ACTION) {}

Media::Media(string titre, int anneeDeSortie, Categorie categorie)
    : titre_(titre), anneeDeSortie_(anneeDeSortie), categorie_(categorie) {}

// TODO
/// @brief Obtient l'�valuation moyenne du m�dia bas�e sur les critiques.
/// @return La note moyenne du m�dia.
float Media::obtenirEvaluation() const {
    float noteTotale = 0;
    for (auto& critique : critiques_) {
        noteTotale += critique->getNote();
    }
    float nbElements = static_cast<float>(critiques_.obtenirNbElements());
    return (noteTotale / nbElements);
}

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un acteur au casting du m�dia.
/// @param cast L'acteur � ajouter au casting.
void Media::operator+=(Cast cast) { casts_ += cast; }

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter une critique au m�dia.
/// @param critique La critique � ajouter au m�dia.
void Media::operator+=(Critique critique) { critiques_ += critique; }

/// @brief Affiche les informations du m�dia sur le flux de sortie.
/// @param os Le flux de sortie o� afficher les informations.
void Media::afficher(ostream& os) const {
    os << SEPARATEUR_DOUBLE << endl;
    // Afficher les informations de base du m�dia
    os << titre_ << ", " << anneeDeSortie_ << ", ";
    switch (categorie_) {
    case Categorie::ACTION: os << "Action" << endl; break;
    case Categorie::COMEDIE: os << "Com�die" << endl; break;
    case Categorie::DRAME: os << "Drame" << endl; break;
    case Categorie::HORREUR: os << "Horreur" << endl; break;
    }
    os << SEPARATEUR_DOUBLE << endl;

    // Afficher le casting du m�dia
    os << "Casting: " << endl;
    os << casts_;
    os << SEPARATEUR_SIMPLE << endl;

    // Afficher les critiques du m�dia
    os << "Critiques: " << endl;
    os << critiques_;
}

/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations du m�dia.
/// @param os Le flux de sortie.
/// @param media Le m�dia � afficher.
/// @return Le flux de sortie mis � jour.
ostream& operator<<(ostream& os, const Media& media) {
    media.afficher(os);
    return os;
}

