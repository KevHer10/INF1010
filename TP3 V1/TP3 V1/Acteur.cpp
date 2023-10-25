#include "Acteur.h"

// Constructeurs
Acteur::Acteur() :Cast() {} //TODO

Acteur::Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence): Cast(nom, anneeNaissance, biographie, salaire), agence_(agence) {}  //TODO

Acteur::Acteur(const Acteur& acteur) : Cast(acteur.nom_, acteur.anneeNaissance_, acteur.biographie_, acteur.salaire_), agence_(acteur.agence_), rolesJoues_(acteur.rolesJoues_) {}  //TODO.

// Methodes virtuelles surchargees
bool Acteur::accepterRole(const pair<int, Cast*>& role) const { 
	
	//if(role.first>= salaire_ && )
	return false;
}  //TODO

ClasseCelebrite Acteur::calculerPopularite() const { return ClasseCelebrite::B_CELEBRITY; }  //TODO

// Operator
Acteur& Acteur::operator+=(const string& role) { return *this;}  //TODO

// Methode d'affichage
void Acteur::afficherRoles() const { } //TODO

void Acteur::afficher(ostream& os) const { } //TODO