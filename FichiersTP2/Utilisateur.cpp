#include "Utilisateur.h"

Utilisateur::Utilisateur(const string& nom, const string& mdp) : nomUtilisateur(nom), motDePasse(mdp) {}

string Utilisateur::getNomUtilisateur() const { return nomUtilisateur; }

vector<shared_ptr<Film>> Utilisateur::getFilmsVus() const { return filmsVus; }

void Utilisateur::setNomUtilisateur(const string& nom) { nomUtilisateur = nom; }

void Utilisateur::setMotDePasse(const string& mdp) { motDePasse = mdp; }

void Utilisateur::ajouterFilm(shared_ptr<Film> film) { } // TODO

bool Utilisateur::verifierConnexion(const string& mdp) const { return false; } // TODO
