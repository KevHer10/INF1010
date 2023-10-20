/*
Fichier: Acteur.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez 
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: Implementation de la classe Acteur.
*/

#include "Acteur.h"

// Constructeurs

/// @brief Constructeur par defaut de la classe Acteur
Acteur::Acteur() : nom_(""), anneeNaissance_(0), biographie_("") {}

/// @brief constructeur par défaut de la classe Acteur.
/// @param nom: nom acteur
/// @param anneeNaissance: anee de naissance de l'acteur. 
/// @param biographie: biographie de l'acteur.
Acteur::Acteur(std::string nom, int anneeNaissance, std::string biographie)
    : nom_(nom), anneeNaissance_(anneeNaissance), biographie_(biographie) {}

/// @brief Constructeur par copie de la classe Acteur
/// @param acteur variable de type acteur avec tout l'information necessaire
Acteur::Acteur(const Acteur& acteur) : nom_(acteur.nom_), anneeNaissance_(acteur.anneeNaissance_), biographie_(acteur.biographie_) { }	                        // TODO

/// @brief definition de la surcharge de l'operateur = qui copie un obejet de type Acteur dans une autre abjet du meme type
/// @param acteur variable de type acteur avec tout l'information necessaire
/// @return un objet de type Acteur
Acteur& Acteur::operator=(const Acteur& acteur) {
    if (*this != acteur) {
        nom_ = acteur.nom_;
        anneeNaissance_ = acteur.anneeNaissance_;
        biographie_ = acteur.biographie_;
    }

    return *this;
}	// TODO

// Getters

/// @brief retourne le nom de l'acteur.
/// @return nom acteur 
string Acteur::getNom() const { return nom_; }

/// @brief retourne anee de naissance de l'acteur.
/// @return anee de naissance
int Acteur::getAnneeNaissance() const { return anneeNaissance_; }

/// @brief retourne la biographie de l'acteur.
/// @return biographie de l'acteur.
string Acteur::getBiographie() const { return biographie_; }

// Setters

/// @brief modifie le nom de l'acteur.
/// @param nom: nom de l'acteur
void Acteur::setNom(const std::string nom) { this->nom_ = nom; }

/// @brief modifie l'anee de naissance de l'acteur. 
/// @param anneeNaissance: anee de naissance de l'acteur.
void Acteur::setAnneeNaissance(int anneeNaissance) { this->anneeNaissance_ = anneeNaissance; }

/// @brief modifie la Biographie de l'acteur.
/// @param bio: Biographie de l'acteur.
void Acteur::setBiographie(const std::string bio) { this->biographie_ = bio; }


// Opérateur

/// @brief definition de la surcharge de l'operateur == qui compare 2 objets de type Acteur pour savoir s'ils ont le meme contenu.
/// @param acteur variable de type acteur avec tout l'information necessaire
/// @return true si les objets sont pareils et false sinon
bool Acteur::operator==(const Acteur& acteur) const {
    if (nom_ == acteur.nom_ && anneeNaissance_ == acteur.anneeNaissance_ && biographie_ == acteur.biographie_) {

        return true;
    }


    return false;
}	// TODO

/// @brief definition de la surcharge de l'operateur != qui compare 2 objets de type Acteur pour savoir s'ils n'ont pas le meme contenu.
/// @param acteur variable de type acteur avec tout l'information necessaire
/// @return true si les objets ne sont pas pareils et false sinon
bool Acteur::operator!=(const Acteur& acteur) const {
    if (nom_ != acteur.nom_ || anneeNaissance_ != acteur.anneeNaissance_ || biographie_ != acteur.biographie_)
        return true;

    return false;
}	// TODO

// Méthodes pour l'affichage

/// @brief Affiche toutes les informations d'un suel acteur.
/// @param os extraction operator 
/// @param acteur variable de type Acteur contenant toute l'information de l'objet 
/// @return affichage de l'objet
ostream& operator<<(ostream& os, const Acteur& acteur) {
    return os << acteur.nom_ << "\n"
        << SEPARATEUR_SIMPLE
        << "\n\tDate de naissance: " << acteur.anneeNaissance_
        << "\n\tBiographie: " << acteur.biographie_ << "\n"
        << SEPARATEUR_SIMPLE << "\n";
}	// TODO