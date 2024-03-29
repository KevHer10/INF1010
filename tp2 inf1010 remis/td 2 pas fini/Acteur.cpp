#include "Acteur.h"

// Constructeurs
Acteur::Acteur() : nom_(""), anneeNaissance_(0), biographie_("") {}

Acteur::Acteur(std::string nom, int anneeNaissance, std::string biographie)
    : nom_(nom), anneeNaissance_(anneeNaissance), biographie_(biographie) {}

Acteur::Acteur(const Acteur& acteur) 
{
    nom_ = acteur.nom_;
    anneeNaissance_ = acteur.anneeNaissance_;
    biographie_ = acteur.biographie_;
}	                        // TODO

Acteur& Acteur::operator=(const Acteur& acteur) 
{ 
    if (this != &acteur) 
    {
        nom_ = acteur.nom_;
        anneeNaissance_ = acteur.anneeNaissance_;
        biographie_ = acteur.biographie_;
    }

    
    return *this;
}	// TODO

// Getters
string Acteur::getNom() const { return nom_; }

int Acteur::getAnneeNaissance() const { return anneeNaissance_; }

string Acteur::getBiographie() const { return biographie_; }

// Setters
void Acteur::setNom(const std::string nom) { this->nom_ = nom; }

void Acteur::setAnneeNaissance(int anneeNaissance) { this->anneeNaissance_ = anneeNaissance; }

void Acteur::setBiographie(const std::string bio) { this->biographie_ = bio; }


// Opérateur
bool Acteur::operator==(const Acteur& acteur) const {
    
    if (nom_ == acteur.getNom() && anneeNaissance_ == acteur.getAnneeNaissance() && biographie_ == acteur.getBiographie()) 
    {
        return true;
    }

    return false;

}	// TODO

bool Acteur::operator!=(const Acteur& acteur) const {
    if (nom_ != acteur.getNom() && anneeNaissance_ != acteur.getAnneeNaissance() && biographie_ != acteur.getBiographie())
    {
        return true;
    }

    return false;
  
}	// TODO

// Méthodes pour l'affichage
ostream& operator<<(ostream& os, const Acteur& acteur) 
{ 
    
    os << acteur.nom_ << endl;
    os << SEPARATEUR_SIMPLE << endl;
    os << "\tDate de naissance: " << acteur.anneeNaissance_ << endl;
    os << "\tBiographie: " << acteur.biographie_ << endl;
    os << SEPARATEUR_SIMPLE << endl;
    return os;
        
        
        

}	// TODO