#include "Utilisateur.h"

Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

vector<shared_ptr<Media>> Utilisateur::getMediaVus() const { return mediaVus; }

void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

void Utilisateur::ajouterMedia(shared_ptr<Media> media) {
	mediaVus.push_back(media);
}  // TODO

bool Utilisateur::verifierConnexion(const string& mdp) const { return motDePasse == mdp; }
