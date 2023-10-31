/*
Fichier: Realisateur.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Realisateur.
*/
#include "Realisateur.h"

// Constructeurs

/// @brief Constructeur par défaut de la classe Realisateur.
Realisateur::Realisateur(): Cast(), studio_("") {}  // TODO

/// @brief Constructeur de la classe Realisateur avec des paramètres.
/// @param nom Le nom du réalisateur.
/// @param anneeNaissance L'année de naissance du réalisateur.
/// @param biographie La biographie du réalisateur.
/// @param salaire Le salaire du réalisateur.
/// @param studioAssocie Le nom du studio associé au réalisateur.
Realisateur::Realisateur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& studioAssocie) 
	: Cast(nom, anneeNaissance, biographie, salaire), studio_(studioAssocie) {}  // TODO

/// @brief Constructeur de copie de la classe Realisateur.
/// @param realisateur Le réalisateur à copier.
Realisateur::Realisateur(const Realisateur& realisateur) : Cast(realisateur), studio_(realisateur.studio_), prix_(realisateur.prix_) {}  // TODO

// Getter et setter

/// @brief Obtient la liste des prix remportés par le réalisateur.
/// @return Un vecteur de paires (année, nom du prix).
vector<pair<int, string>> Realisateur::getPrix() const { 
	
	return prix_;
}  // TODO

/// @brief Ajoute un prix à la liste des prix du réalisateur.
/// @param annee L'année du prix.
/// @param nomPrix Le nom du prix à ajouter.
void Realisateur::ajouterPrix(int annee, const string& nomPrix) {
	prix_.push_back(make_pair(annee, nomPrix));
}  // TODO

// Methodes virtuelles surchargees

/// @brief Méthode virtuelle permettant au réalisateur d'accepter un rôle dans un casting.
/// @param role Une paire d'identifiant de rôle et de pointeur vers un objet Cast.
/// @return true si le réalisateur accepte le rôle, false sinon.
bool Realisateur::accepterRole(const pair<int, Cast*>& role) const { 
	//const Realisateur* realisateur{};
	if (role.first >= salaire_ && dynamic_cast<const Realisateur*>(role.second))
		return true;

	return false;
}  // TODO

/// @brief Calcule la popularité du réalisateur.
/// @return Le niveau de célébrité du réalisateur.
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

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un prix au réalisateur.
/// @param prix Une paire (année, nom du prix) à ajouter.
/// @return Une référence au réalisateur modifié.
Realisateur& Realisateur::operator+=(const pair<int, string>& prix) { 
	ajouterPrix(prix.first, prix.second);
	return *this;

}  // TODO

// Methodes d'affichage
/// @brief Affiche la liste des prix remportés par le réalisateur.
void Realisateur::afficherPrix() const {
	cout << "Prix reçus: \n";
	for (const pair<int,string> prixRecus : prix_) {
		cout << "- " << prixRecus.second << " (" << prixRecus.first<<")\n";
	}


}  // TODO

/// @brief Affiche les informations du réalisateur.
/// @param os Le flux de sortie où afficher les informations.
void Realisateur::afficher(ostream& os) const {
	Cast::afficher(os);
	cout << "Studio associé: " << studio_<<"\n\n";
}  // TODO
