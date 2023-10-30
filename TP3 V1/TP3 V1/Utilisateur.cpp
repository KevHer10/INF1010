#include "Utilisateur.h"

/// @brief Constructeur de la classe Utilisateur avec paramètres.
/// @param nom Le nom d'utilisateur de l'utilisateur.
/// @param mdp Le mot de passe de l'utilisateur.
Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

/// @brief Obtient le nom d'utilisateur de l'utilisateur.
/// @return Le nom d'utilisateur de l'utilisateur.
string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

/// @brief Obtient la liste des médias visionnés par l'utilisateur.
/// @return Un vecteur de pointeurs partagés vers les médias visionnés par l'utilisateur.
vector<shared_ptr<Media>> Utilisateur::getMediaVus() const { return mediaVus; }

/// @brief Définit le nom d'utilisateur de l'utilisateur.
/// @param nom Le nouveau nom d'utilisateur à définir.
void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

/// @brief Définit le mot de passe de l'utilisateur.
/// @param mdp Le nouveau mot de passe à définir.
void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

/// @brief Ajoute un média visionné à la liste des médias de l'utilisateur.
/// @param media Un pointeur partagé vers le média visionné à ajouter.
void Utilisateur::ajouterMedia(shared_ptr<Media> media) {
	mediaVus.push_back(media);
}  // TODO

/// @brief Vérifie la connexion de l'utilisateur en comparant le mot de passe fourni.
/// @param mdp Le mot de passe à vérifier.
/// @return true si le mot de passe fourni correspond au mot de passe de l'utilisateur, false sinon.
bool Utilisateur::verifierConnexion(const string& mdp) const { return motDePasse == mdp; }
