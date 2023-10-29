#include "Acteur.h"

// Constructeurs
Acteur::Acteur() :Cast(), agence_("") {} //TODO

Acteur::Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence): Cast(nom, anneeNaissance, biographie, salaire), agence_(agence) {}  //TODO

Acteur::Acteur(const Acteur& acteur) : Cast(acteur), agence_(acteur.agence_), rolesJoues_(acteur.rolesJoues_) {}  //TODO.

// Methodes virtuelles surchargees
bool Acteur::accepterRole(const pair<int, Cast*>& role) const { 
	
	const Acteur* acteur{};
	if (role.first >= salaire_ && dynamic_cast<const Acteur*>(role.second) == acteur)
		return true;

	return false;
}  //TODO 

ClasseCelebrite Acteur::calculerPopularite() const { 
	int roles = static_cast<int>(rolesJoues_.size());

	if(roles > SEUIL_A)
		return ClasseCelebrite::A_CELEBRITY;
	else if (roles >= SEUIL_B && roles <= SEUIL_A )
		return ClasseCelebrite::B_CELEBRITY;
	else if (roles < SEUIL_B)
		return ClasseCelebrite::C_CELEBRITY;
	
}  //TODO

// Operator
Acteur& Acteur::operator+=(const string& role) { 
	this->ajouterRole(role);
	return *this;
}  //TODO

// Methode d'affichage
void Acteur::afficherRoles() const { } //TODO

void Acteur::afficher(ostream& os) const { } //TODO