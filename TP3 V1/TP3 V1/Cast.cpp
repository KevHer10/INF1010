/*
Fichier: Cast.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Cast.
*/
#include "Cast.h"

// Constructeurs

/// @brief Constructeur par d�faut de la classe Cast.
Cast::Cast()
    : nom_(""), anneeNaissance_(0), biographie_("") {}


/// @brief Constructeur de la classe Cast avec des param�tres.
/// @param nom Le nom du membre du casting.
/// @param anneeNaissance L'ann�e de naissance du membre du casting.
/// @param biographie La biographie du membre du casting.
/// @param salaire Le salaire du membre du casting.
Cast::Cast(const string& nom, int anneeNaissance, const string& biographie, int salaire)
    : nom_(nom), anneeNaissance_(anneeNaissance), biographie_(biographie), salaire_(salaire) {}

/// @brief Constructeur de copie de la classe Cast.
/// @param cast Le membre du casting � copier.
Cast::Cast(const Cast& cast)
    : nom_(cast.nom_), anneeNaissance_(cast.anneeNaissance_), biographie_(cast.biographie_) {}

// Destructeur
/// @brief Destructeur de la classe Cast.

Cast::~Cast() {}  // TODO (si necessaire)

// Operators

/// @brief Surcharge de l'op�rateur d'�galit�.
/// @param cast L'autre membre du casting � comparer.
/// @return true si les membres du casting sont �gaux, false sinon.
bool Cast::operator==(const Cast& cast) const { 
    if (nom_ == cast.nom_
        && anneeNaissance_ == cast.anneeNaissance_
        && biographie_ == cast.biographie_)
        return true;

    return false;
}  // TODO

/// @brief Surcharge de l'op�rateur de diff�rence.
/// @param cast L'autre membre du casting � comparer.
/// @return true si les membres du casting sont diff�rents, false sinon.
bool Cast::operator!=(const Cast& cast) const { 
    
    if (nom_ != cast.nom_
        || anneeNaissance_ != cast.anneeNaissance_
        || biographie_ != cast.biographie_)
        return true;
    
    return false;
}  // TODO

// Methodes d'affichage

/// @brief Affiche les informations du membre du casting.
/// @param os Le flux de sortie o� afficher les informations.
void Cast::afficher(ostream& os) const {
   
        os << "------------------------------------------------\n"
        << "Nom: " << nom_
        << "\nAnn�e de naissance: " << anneeNaissance_
        << "\nBiographie: " << biographie_ << "\n";

}  // TODO


/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations du membre du casting.
/// @param os Le flux de sortie.
/// @param cast Le membre du casting � afficher.
/// @return Le flux de sortie mis � jour.
ostream& operator<<(ostream& os, const Cast& cast) { 
    //os << "Casting:\n";
    cast.afficher(os);
    return os;
}  // TODO
