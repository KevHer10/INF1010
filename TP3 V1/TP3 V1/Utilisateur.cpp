#include "Utilisateur.h"

/// @brief Constructeur de la classe Utilisateur avec param�tres.
/// @param nom Le nom d'utilisateur de l'utilisateur.
/// @param mdp Le mot de passe de l'utilisateur.
Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

/// @brief Obtient le nom d'utilisateur de l'utilisateur.
/// @return Le nom d'utilisateur de l'utilisateur.
string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

/// @brief Obtient la liste des m�dias visionn�s par l'utilisateur.
/// @return Un vecteur de pointeurs partag�s vers les m�dias visionn�s par l'utilisateur.
vector<shared_ptr<Media>> Utilisateur::getMediaVus() const { return mediaVus; }

/// @brief D�finit le nom d'utilisateur de l'utilisateur.
/// @param nom Le nouveau nom d'utilisateur � d�finir.
void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

/// @brief D�finit le mot de passe de l'utilisateur.
/// @param mdp Le nouveau mot de passe � d�finir.
void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

/// @brief Ajoute un m�dia visionn� � la liste des m�dias de l'utilisateur.
/// @param media Un pointeur partag� vers le m�dia visionn� � ajouter.
void Utilisateur::ajouterMedia(shared_ptr<Media> media) {
	mediaVus.push_back(media);
}  // TODO

/// @brief V�rifie la connexion de l'utilisateur en comparant le mot de passe fourni.
/// @param mdp Le mot de passe � v�rifier.
/// @return true si le mot de passe fourni correspond au mot de passe de l'utilisateur, false sinon.
bool Utilisateur::verifierConnexion(const string& mdp) const { return motDePasse == mdp; }
