#include "Film.h"
#include <iostream>
#include <iomanip>

// Constructeurs
Film::Film() : titre_(""), anneeDeSortie_(0), realisateur_(""), categorie_(Categorie::ACTION), duree_(0) {}

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree)
	: titre_(titre), anneeDeSortie_(anneeDeSortie), realisateur_(realisateur), categorie_(categorie), duree_(duree) {}

Film::Film(const Film& film) { }							// TODO

Film& Film::operator=(const Film& film) { return *this; }	// TODO

// Getters
string Film::getTitre() const { return titre_; }

string Film::getRealisateur() const { return realisateur_; }

int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

Categorie Film::getCategorie() const { return categorie_; }

int Film::getDuree() const { return duree_; }

vector<shared_ptr<Acteur>> Film::getActeurs() const { return {}; }	// TODO

vector<unique_ptr<Critique>> Film::getCritiques() const { return {}; }			// TODO

int Film::getNbActeurs() const { return (int) acteurs_.size(); }

int Film::getNbCritiques() const { return (int) critiques_.size(); }

// Setters
void Film::setTitre(string titre) { this->titre_ = titre; }

void Film::setRealisateur(string realisateur) { this->realisateur_ = realisateur; }

void Film::setAnneeDeSortie(int anneeDeSortie) { this->anneeDeSortie_ = anneeDeSortie; }

void Film::setCategorie(Categorie categorie) { this->categorie_ = categorie; }

void Film::setDuree(int duree) { this->duree_ = duree; }

void Film::setActeurs(vector<shared_ptr<Acteur>> acteurs) { this->acteurs_ = acteurs; }

void Film::setCritiques(vector<Critique*> critiquesVec) { }					// TODO

// Méthodes fonctionnelles
shared_ptr<Acteur> Film::trouverActeur(const string nom) const { return nullptr; }		// TODO

unique_ptr<Critique> Film::trouverCritique(const string nom) const { return nullptr; }	// TODO

bool Film::isActeurPresent(string nomActeur) const { return false; }		// TODO

bool Film::isCritiquePresent(string nomCritique) const { return false; }	// TODO

float Film::obtenirNoteMoyenne() const { return 0.0; }						// TODO

// Opérateurs
bool Film::operator+=(shared_ptr<Acteur>& acteur) {	return false; }	// TODO

bool Film::operator+=(Critique* critique) {	return false; }			// TODO

bool Film::operator==(const Film& film) const { return false; }		// TODO

bool Film::operator!=(const Film& film) const { return false; }		// TODO


bool Film::operator-=(shared_ptr<Acteur>& acteur) {	return false; }	// TODO

bool Film::operator-=(Critique* critique) {	return false; }			// TODO


// Méthode d'affichage
ostream& operator<<(ostream& os, const Film& film) { return os; }	// TODO
