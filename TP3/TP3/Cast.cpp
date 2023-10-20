#include "Cast.h"
//Salut

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
bool Cast::operator==(const Cast& cast) const { return false; }  // TODO

bool Cast::operator!=(const Cast& cast) const { return false; }  // TODO

// Methodes d'affichage
void Cast::afficher(ostream& os) const { }  // TODO

ostream& operator<<(ostream& os, const Cast& cast) { return os; }  // TODO
