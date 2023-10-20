#include "Polyflix.h"
#include <algorithm>

string SEPARATEUR = "======================================================================================\n";

// Constructeur
Polyflix::Polyflix() {}

// Copy Constructor
Polyflix::Polyflix(const Polyflix& poyflix) { } // TODO

// Méthodes pour la recherche
Film* Polyflix::chercherFilmParTitre(const string& titre) const { return nullptr; }		// TODO

Utilisateur* Polyflix::chercherUtilisateur(const string& nomUtilisateur) { return nullptr; }	// TODO

// Méthodes liées aux utilisateurs
int Polyflix::getNombreUtilisateurs() const { return (int) utilisateurs_.size(); }

bool Polyflix::utilisateurExiste(const string& nomUtilisateur) { return false; }					// TODO

bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) { return false; }		// TODO

bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) { return false; }		// TODO

bool Polyflix::visionnerFilm(string nomUtilisateur, string titreFilm) { return false; }				// TODO

// Méthodes pour obtenir des statistiques
int Polyflix::getNombreTotalFilms() const { return (int) films_.size(); }

int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { return 0; }						// TODO

int Polyflix::getNombreTotalFilmsVisionnes() const { return 0; }										// TODO

int Polyflix::getNombreUtilisateursAyantVisionne(const string& titreFilm) const { return 0; }			// TODO

unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusHauteNote() const { return nullptr; }								// TODO

unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusBasseNote() const { return nullptr; }								// TODO

unique_ptr<Film> Polyflix::obtenirFilmPlusRecent() const { return nullptr; }										// TODO

vector<unique_ptr<Film>> Polyflix::listerFilmsParCategorie(Categorie categorie) const { return {}; }				// TODO

vector<shared_ptr<Film>> Polyflix::listerFilmsVisionnesParUtilisateur(const string& nomUtilisateur) { return {}; }	// TODO

// Opérateurs
bool Polyflix::operator+=(Utilisateur utilisateur) { return false; }	// TODO

bool Polyflix::operator+=(Film* film) { return false; }			// TODO

bool Polyflix::operator-=(string titre) { return false; }		// TODO

Film* Polyflix::operator[](string titre) { return nullptr; }	// TODO

// Méthodes pour l'affichage
ostream& operator<<(ostream& os, const Polyflix& polyflix) { return os; } // TODO
