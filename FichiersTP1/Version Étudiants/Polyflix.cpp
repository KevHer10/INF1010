#include "Polyflix.h"

string SEPARATEUR = "======================================================================================\n";

// TODO: Impl�menter les m�thodes de la classe Polyflix ici.

// Constructeurs et destructeur
Polyflix::Polyflix() { }

Polyflix::Polyflix(string nomUtilisateur, string motDePasse) { }

Polyflix::~Polyflix() { }

// getters
string Polyflix::getUtilisateur() const { return ""; }

// setters
void Polyflix::setUtilisateur(string utilisateur) { }

void Polyflix::setMotDePasse(string motDePasse) { }

// M�thodes pour la connexion
bool Polyflix::connecter(string utilisateur, string motDePasse) { return false; }

// M�thodes pour g�rer les films
bool Polyflix::ajouterFilm(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) { return false; }

bool Polyflix::retirerFilm(string titre, int anneeDeSortie) { return false; }

// M�thodes pour la recherche
Film* Polyflix::chercherFilmParTitre(const string& titre) const { return nullptr; }

vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { return {}; }

// M�thodes pour obtenir des statistiques
int Polyflix::getNombreTotalFilms() const { return 0; }

int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { return 0; }

Film* Polyflix::obtenirFilmAvecLaPlusHauteNote() const { return nullptr; }

Film* Polyflix::obtenirFilmAvecLaPlusBasseNote() const { return nullptr; }

Film* Polyflix::obtenirFilmPlusRecent() const { return nullptr; }

// M�thodes pour l'affichage
void Polyflix::afficherListeFilms() const { }

void Polyflix::afficherFilmsParCategorie(Categorie categorie) const { }