#include "Acteur.h"

// Constructeurs

/// @brief Constructeur par d�faut de la classe Acteur.
Acteur::Acteur() :Cast(), agence_("") {} //TODO


/// @brief Constructeur de la classe Acteur avec des param�tres.
/// @param nom Le nom de l'acteur.
/// @param anneeNaissance L'ann�e de naissance de l'acteur.
/// @param biographie La biographie de l'acteur.
/// @param salaire Le salaire de l'acteur.
/// @param agence Le nom de l'agence � laquelle l'acteur est affili�.
Acteur::Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence): Cast(nom, anneeNaissance, biographie, salaire), agence_(agence) {}  //TODO

/// @brief Constructeur de copie de la classe Acteur.
/// @param acteur L'acteur � copier.
Acteur::Acteur(const Acteur& acteur) : Cast(acteur), agence_(acteur.agence_), rolesJoues_(acteur.rolesJoues_) {}  //TODO.

// Methodes virtuelles surchargees

/// @brief M�thode virtuelle permettant � l'acteur d'accepter un r�le dans un casting.
/// @param role Une paire d'identifiant de r�le et de pointeur vers un objet Cast.
/// @return true si l'acteur accepte le r�le, false sinon.

bool Acteur::accepterRole(const pair<int, Cast*>& role) const { 
	
	//const Acteur* acteur{};
	if (role.first >= salaire_ && dynamic_cast<Acteur*>(role.second))
		return true;

	return false;
}  //TODO 

/// @brief Calcule la popularit� de l'acteur.
/// @return Le niveau de c�l�brit� de l'acteur.
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

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un r�le � l'acteur.
/// @param role Le nom du r�le � ajouter.
/// @return Une r�f�rence � l'acteur modifi�.
Acteur& Acteur::operator+=(const string& role) { 
	this->ajouterRole(role);
	return *this;
}  //TODO

// Methode d'affichage

/// @brief Affiche les r�les de l'acteur.
void Acteur::afficherRoles() const {
	cout << "Roles Joues: \n";
	for (auto& roles : rolesJoues_)
		cout << roles << "\n";
} //TODO

/// @brief Affiche les informations de l'acteur.
/// @param os Le flux de sortie o� afficher les informations.
void Acteur::afficher(ostream& os) const {
	Cast::afficher(os);
	cout << "Agence: " << agence_<<"\n\n"; 
} //TODO