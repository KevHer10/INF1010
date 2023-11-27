/*
Fichier: Media.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Media.
*/
#include "Media.h"

// Constructeur
/// @brief Constructeur par d�faut de la classe Media.
Media::Media() : titre_(""), anneeDeSortie_(0), categorie_(Categorie::ACTION) {}

/// @brief Constructeur de la classe Media avec des param�tres.
/// @param titre Le titre du m�dia.
/// @param anneeDeSortie L'ann�e de sortie du m�dia.
/// @param categorie La cat�gorie du m�dia.
Media::Media(string titre, int anneeDeSortie, Categorie categorie)
    : titre_(titre), anneeDeSortie_(anneeDeSortie), categorie_(categorie) {}

// Methodes virtuelles surchargees

/// @brief Obtient l'�valuation du m�dia.
/// @return L'�valuation du m�dia.
float Media::obtenirEvaluation() const { 
    float moyenne = 0;
    
    for (auto& critique : critiques_) {

        moyenne += critique.obtenirEvaluation();
    }
    
    return moyenne/critiques_.size();

}  // TODO

// Opeators
/// @brief Ajoute un membre du casting au m�dia.
/// @param cast Un pointeur partag� vers un objet Cast � ajouter au m�dia.
void Media::operator+=(shared_ptr<Cast> cast) {
    casts_.push_back(cast);
}  // TODO

/// @brief Ajoute une critique au m�dia.
/// @param critique La critique � ajouter au m�dia.
void Media::operator+=(Critique critique) {
    critiques_.push_back(critique);
}  // TODO

// Methodes d'affichage
/// @brief Affiche les informations du m�dia.
/// @param os Le flux de sortie o� afficher les informations.
void Media::afficher(ostream& os) const {
    os << titre_ << ", " << anneeDeSortie_ << ", ";

    switch (categorie_)
    {
    case Categorie::ACTION: os << "Action\n";   break;
    case Categorie::COMEDIE: os << "Comedie\n"; break;
    case Categorie::DRAME: os << "Drame\n";  break;
    case Categorie::HORREUR: os << "Horreur\n"; break;
    default: os << "Inconnu\n";
    }

    os << "Casting: \n";
    for (auto& cast : casts_) {
        os << *cast;
    }

    os << "Critiques: \n";
    for (auto& critiques : critiques_) {
        os << critiques;
    }
        

}  // TODO

/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations du m�dia.
/// @param os Le flux de sortie.
/// @param media Le m�dia � afficher.
/// @return Le flux de sortie mis � jour.
ostream& operator<<(ostream& os, const Media& media) { 
    media.afficher(os);
    return os;
}  // TODO
