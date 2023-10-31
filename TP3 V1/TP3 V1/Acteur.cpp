#include "Acteur.h"

// Constructeurs

/// @brief Constructeur par défaut de la classe Acteur.
Acteur::Acteur() :Cast(), agence_("") {} //TODO


/// @brief Constructeur de la classe Acteur avec des paramètres.
/// @param nom Le nom de l'acteur.
/// @param anneeNaissance L'année de naissance de l'acteur.
/// @param biographie La biographie de l'acteur.
/// @param salaire Le salaire de l'acteur.
/// @param agence Le nom de l'agence à laquelle l'acteur est affilié.
Acteur::Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence): Cast(nom, anneeNaissance, biographie, salaire), agence_(agence) {}  //TODO

/// @brief Constructeur de copie de la classe Acteur.
/// @param acteur L'acteur à copier.
Acteur::Acteur(const Acteur& acteur) : Cast(acteur), agence_(acteur.agence_), rolesJoues_(acteur.rolesJoues_) {}  //TODO.

// Methodes virtuelles surchargees

/// @brief Méthode virtuelle permettant à l'acteur d'accepter un rôle dans un casting.
/// @param role Une paire d'identifiant de rôle et de pointeur vers un objet Cast.
/// @return true si l'acteur accepte le rôle, false sinon.

bool Acteur::accepterRole(const pair<int, Cast*>& role) const { 
	
	//const Acteur* acteur{};
	if (role.first >= salaire_ && dynamic_cast<Acteur*>(role.second))
		return true;

	return false;
}  //TODO 

/// @brief Calcule la popularité de l'acteur.
/// @return Le niveau de célébrité de l'acteur.
ClasseCelebrite Acteur::calculerPopularite() const { 
	int roles = static_cast<int>(rolesJoues_.size());

	if(roles > SEUIL_A)
		return ClasseCelebrite::A_CELEBRITY;
	else if (roles >= SEUIL_B && roles <= SEUIL_A )
		return ClasseCelebrite::B_CELEBRITY;
	else 
		return ClasseCelebrite::C_CELEBRITY;
	
}  //TODO

// Operator

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un rôle à l'acteur.
/// @param role Le nom du rôle à ajouter.
/// @return Une référence à l'acteur modifié.
Acteur& Acteur::operator+=(const string& role) { 
	this->ajouterRole(role);
	return *this;
}  //TODO

// Methode d'affichage

/// @brief Affiche les rôles de l'acteur.
void Acteur::afficherRoles() const {
	cout << "Roles Joues: \n";
	for (auto& roles : rolesJoues_)
		cout << roles << "\n";
} //TODO

/// @brief Affiche les informations de l'acteur.
/// @param os Le flux de sortie où afficher les informations.
void Acteur::afficher(ostream& os) const {
	Cast::afficher(os);
	cout << "Agence: " << agence_<<"\n\n"; 
} //TODO