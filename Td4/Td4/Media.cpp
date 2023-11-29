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
/// @brief Obtient l'évaluation moyenne du média basée sur les critiques.
/// @return La note moyenne du média.
float Media::obtenirEvaluation() const {
    float noteTotale = 0;
    for (auto& critique : critiques_) {
        noteTotale += critique->getNote();
    }
    float nbElements = static_cast<float>(critiques_.obtenirNbElements());
    return (noteTotale / nbElements);
}

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un acteur au casting du média.
/// @param cast L'acteur à ajouter au casting.
void Media::operator+=(Cast cast) { casts_ += cast; }

/// @brief Surcharge de l'opérateur d'ajout pour ajouter une critique au média.
/// @param critique La critique à ajouter au média.
void Media::operator+=(Critique critique) { critiques_ += critique; }

/// @brief Affiche les informations du média sur le flux de sortie.
/// @param os Le flux de sortie où afficher les informations.
void Media::afficher(ostream& os) const {
    os << SEPARATEUR_DOUBLE << endl;
    // Afficher les informations de base du média
    os << titre_ << ", " << anneeDeSortie_ << ", ";
    switch (categorie_) {
    case Categorie::ACTION: os << "Action" << endl; break;
    case Categorie::COMEDIE: os << "Comédie" << endl; break;
    case Categorie::DRAME: os << "Drame" << endl; break;
    case Categorie::HORREUR: os << "Horreur" << endl; break;
    }
    os << SEPARATEUR_DOUBLE << endl;

    // Afficher le casting du média
    os << "Casting: " << endl;
    os << casts_;
    os << SEPARATEUR_SIMPLE << endl;

    // Afficher les critiques du média
    os << "Critiques: " << endl;
    os << critiques_;
}

/// @brief Surcharge de l'opérateur de sortie pour afficher les informations du média.
/// @param os Le flux de sortie.
/// @param media Le média à afficher.
/// @return Le flux de sortie mis à jour.
ostream& operator<<(ostream& os, const Media& media) {
    media.afficher(os);
    return os;
}

