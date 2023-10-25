#include "Cast.h"

// Constructeurs
Cast::Cast()
    : nom_(""), anneeNaissance_(0), biographie_("") {}

Cast::Cast(const string& nom, int anneeNaissance, const string& biographie, int salaire)
    : nom_(nom), anneeNaissance_(anneeNaissance), biographie_(biographie), salaire_(salaire) {}

Cast::Cast(const Cast& cast)
    : nom_(cast.nom_), anneeNaissance_(cast.anneeNaissance_), biographie_(cast.biographie_) {}

// Destructeur
Cast::~Cast() {}  // TODO (si necessaire)

// Operators
bool Cast::operator==(const Cast& cast) const { 
    if (nom_ == cast.nom_
        && anneeNaissance_ == cast.anneeNaissance_
        && biographie_ == cast.biographie_)
        return true;

    return false;
}  // TODO

bool Cast::operator!=(const Cast& cast) const { 
    
    if (nom_ != cast.nom_
        || anneeNaissance_ != cast.anneeNaissance_
        || biographie_ != cast.biographie_)
        return true;
    
    return false;
}  // TODO

// Methodes d'affichage
void Cast::afficher(ostream& os) const {
    os << nom_ << anneeNaissance_ << biographie_;
}  // TODO

ostream& operator<<(ostream& os, const Cast& cast) { 
    cast.afficher(os);
    return os;
}  // TODO
