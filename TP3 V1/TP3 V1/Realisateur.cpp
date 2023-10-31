/*
Fichier: Realisateur.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Realisateur.
*/
#include "Realisateur.h"

// Constructeurs

/// @brief Constructeur par d�faut de la classe Realisateur.
Realisateur::Realisateur(): Cast(), studio_("") {}  // TODO

/// @brief Constructeur de la classe Realisateur avec des param�tres.
/// @param nom Le nom du r�alisateur.
/// @param anneeNaissance L'ann�e de naissance du r�alisateur.
/// @param biographie La biographie du r�alisateur.
/// @param salaire Le salaire du r�alisateur.
/// @param studioAssocie Le nom du studio associ� au r�alisateur.
Realisateur::Realisateur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& studioAssocie) 
	: Cast(nom, anneeNaissance, biographie, salaire), studio_(studioAssocie) {}  // TODO

/// @brief Constructeur de copie de la classe Realisateur.
/// @param realisateur Le r�alisateur � copier.
Realisateur::Realisateur(const Realisateur& realisateur) : Cast(realisateur), studio_(realisateur.studio_), prix_(realisateur.prix_) {}  // TODO

// Getter et setter

/// @brief Obtient la liste des prix remport�s par le r�alisateur.
/// @return Un vecteur de paires (ann�e, nom du prix).
vector<pair<int, string>> Realisateur::getPrix() const { 
	
	return prix_;
}  // TODO

/// @brief Ajoute un prix � la liste des prix du r�alisateur.
/// @param annee L'ann�e du prix.
/// @param nomPrix Le nom du prix � ajouter.
void Realisateur::ajouterPrix(int annee, const string& nomPrix) {
	prix_.push_back(make_pair(annee, nomPrix));
}  // TODO

// Methodes virtuelles surchargees

/// @brief M�thode virtuelle permettant au r�alisateur d'accepter un r�le dans un casting.
/// @param role Une paire d'identifiant de r�le et de pointeur vers un objet Cast.
/// @return true si le r�alisateur accepte le r�le, false sinon.
bool Realisateur::accepterRole(const pair<int, Cast*>& role) const { 
	//const Realisateur* realisateur{};
	if (role.first >= salaire_ && dynamic_cast<const Realisateur*>(role.second))
		return true;

	return false;
}  // TODO

/// @brief Calcule la popularit� du r�alisateur.
/// @return Le niveau de c�l�brit� du r�alisateur.
ClasseCelebrite Realisateur::calculerPopularite() const { 
	int prix = static_cast<const int>(prix_.size());

	if (prix > SEUIL_A)
		return ClasseCelebrite::A_CELEBRITY;
	else if (prix >= SEUIL_B && prix <= SEUIL_A)
		return ClasseCelebrite::B_CELEBRITY;
	else
		return ClasseCelebrite::C_CELEBRITY;
	


	}  // TODO

// Operator

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un prix au r�alisateur.
/// @param prix Une paire (ann�e, nom du prix) � ajouter.
/// @return Une r�f�rence au r�alisateur modifi�.
Realisateur& Realisateur::operator+=(const pair<int, string>& prix) { 
	ajouterPrix(prix.first, prix.second);
	return *this;

}  // TODO

// Methodes d'affichage
/// @brief Affiche la liste des prix remport�s par le r�alisateur.
void Realisateur::afficherPrix() const {
	cout << "Prix re�us: \n";
	for (const pair<int,string> prixRecus : prix_) {
		cout << "- " << prixRecus.second << " (" << prixRecus.first<<")\n";
	}


}  // TODO

/// @brief Affiche les informations du r�alisateur.
/// @param os Le flux de sortie o� afficher les informations.
void Realisateur::afficher(ostream& os) const {
	Cast::afficher(os);
	cout << "Studio associ�: " << studio_<<"\n\n";
}  // TODO
