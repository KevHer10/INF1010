#include "Utilisateur.h"

Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

bool Utilisateur::verifierConnexion(const string& mdp) const { return motDePasse == mdp; }
