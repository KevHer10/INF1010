#include "Realisateur.h"

// Constructeurs
Realisateur::Realisateur() {}  // TODO

Realisateur::Realisateur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& studioAssocie) {}  // TODO

Realisateur::Realisateur(const Realisateur& realisateur) {}  // TODO

// Getter et setter
vector<pair<int, string>> Realisateur::getPrix() const { return {}; }  // TODO

void Realisateur::ajouterPrix(int annee, const string& nomPrix) { }  // TODO

// Methodes virtuelles surchargees
bool Realisateur::accepterRole(const pair<int, Cast*>& role) const { return false; }  // TODO

ClasseCelebrite Realisateur::calculerPopularite() const { return ClasseCelebrite::B_CELEBRITY; }  // TODO

// Operator
Realisateur& Realisateur::operator+=(const pair<int, string>& prix) { return *this; }  // TODO

// Methodes d'affichage
void Realisateur::afficherPrix() const { }  // TODO

void Realisateur::afficher(ostream& os) const { }  // TODO
