#include "Cast.h"

// Constructeurs
Cast::Cast()
    : nom_(""), anneeNaissance_(0), biographie_("") {}

Cast::Cast(const string& nom, int anneeNaissance, const string& biographie, int salaire)
    : nom_(nom), anneeNaissance_(anneeNaissance), biographie_(biographie), salaire_(salaire) {}

Cast::Cast(const Cast& cast)
    : nom_(cast.nom_), anneeNaissance_(cast.anneeNaissance_), biographie_(cast.biographie_) {}

// Destructeur
Cast::~Cast() {}

// Operators
bool Cast::operator==(const Cast& cast) const {
    return nom_ == cast.nom_ &&
        anneeNaissance_ == cast.anneeNaissance_ &&
        biographie_ == cast.biographie_;
}

bool Cast::operator!=(const Cast& cast) const {
    return !(*this == cast);
}

// Methodes d'affichage
void Cast::afficher(ostream& os) const {
    os << "\tNom: " << nom_ << endl;
    os << "\tAnnee de naissance: " << anneeNaissance_ << endl;
    os << "\tBiographie: " << biographie_ << endl;
}

ostream& operator<<(ostream& os, const Cast& cast) {
    cast.afficher(os);
    return os;
}
