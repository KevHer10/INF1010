#include "Realisateur.h"

// Constructeurs
Realisateur::Realisateur(): Cast(), studio_("") {}  // TODO

Realisateur::Realisateur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& studioAssocie) 
	: Cast(nom, anneeNaissance, biographie, salaire), studio_(studioAssocie) {}  // TODO

Realisateur::Realisateur(const Realisateur& realisateur) : Cast(realisateur), studio_(realisateur.studio_), prix_(realisateur.prix_) {}  // TODO

// Getter et setter
vector<pair<int, string>> Realisateur::getPrix() const { 
	
	return prix_;
}  // TODO

void Realisateur::ajouterPrix(int annee, const string& nomPrix) {
	prix_.push_back(make_pair(annee, nomPrix));
}  // TODO

// Methodes virtuelles surchargees
bool Realisateur::accepterRole(const pair<int, Cast*>& role) const { 
	const Realisateur* realisateur{};
	if (role.first >= salaire_ && dynamic_cast<const Realisateur*>(role.second) == realisateur)
		return true;

	return false;
}  // TODO

ClasseCelebrite Realisateur::calculerPopularite() const { 
	int prix = static_cast<int>(prix_.size());

	if (prix > SEUIL_A)
		return ClasseCelebrite::A_CELEBRITY;
	else if (prix >= SEUIL_B && prix <= SEUIL_A)
		return ClasseCelebrite::B_CELEBRITY;
	else if (prix < SEUIL_B)
		return ClasseCelebrite::C_CELEBRITY;


}  // TODO

// Operator
Realisateur& Realisateur::operator+=(const pair<int, string>& prix) { 
	ajouterPrix(prix.first, prix.second);
	return *this;

}  // TODO

// Methodes d'affichage
void Realisateur::afficherPrix() const { }  // TODO

void Realisateur::afficher(ostream& os) const { }  // TODO
