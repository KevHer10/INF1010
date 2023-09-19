#include "Film.h"
#include <iostream>
#include <iomanip>

// TODO: Implémenter les méthodes de la classe Film ici.

// Constructeurs et destructeur
Film::Film() { }

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) { }

Film::~Film() { }

// Getters
string Film::getTitre() const { return ""; }

string Film::getRealisateur() const { return ""; }

int Film::getAnneeDeSortie() const { return 0; }

Categorie Film::getCategorie() const { return Categorie::HORREUR; }

int Film::getDuree() const { return 0; }

vector<Acteur*> Film::getActeurs() const { return {}; }

vector<Critique*> Film::getCritiques() const { return {}; }

int Film::getNbActeurs() const { return 0; }

int Film::getNbCritiques() const { return 0; }

// Setters
void Film::setTitre(string titre) { }

void Film::setRealisateur(string realisateur) { }

void Film::setAnneeDeSortie(int anneeDeSortie) { }

void Film::setCategorie(Categorie categorie) { }

void Film::setDuree(int duree) { }

void Film::setActeurs(vector<Acteur*> acteurs) { }

void Film::setCritiques(vector<Critique*> critiquesVec) { }

// Méthodes fonctionnelles
Acteur* Film::trouverActeur(const string nom) const {
    return nullptr;
}

Critique* Film::trouverCritique(const string nom) const {
    return nullptr;
}

bool Film::isActeurPresent(string nomActeur) const {
    return false;
}

bool Film::isCritiquePresent(string nomCritique) const {
    return false;
}

bool Film::ajouterActeur(string nom, int anneeNaissance, string biographie) {
    return false;
}

bool Film::ajouterCritique(string nom, string commentaire, int note) {
    return false;
}

bool Film::retirerActeur(const string nom) {
    return false;
}

bool Film::retirerCritique(const string nom) {
    return false;
}

float Film::obtenirNoteMoyenne() const {
    return 0;
}

// Méthodes d'affichage
void Film::afficher() const { }
