#include "Acteur.h"

// Constructeurs
Acteur::Acteur() {} //TODO

Acteur::Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence) {}  //TODO

Acteur::Acteur(const Acteur& acteur) {}  //TODO

// Methodes virtuelles surchargees
bool Acteur::accepterRole(const pair<int, Cast*>& role) const { return false; }  //TODO

ClasseCelebrite Acteur::calculerPopularite() const { return ClasseCelebrite::B_CELEBRITY; }  //TODO

// Operator
Acteur& Acteur::operator+=(const string& role) { return *this;}  //TODO

// Methode d'affichage
void Acteur::afficherRoles() const { } //TODO

void Acteur::afficher(ostream& os) const { } //TODO