#include "Film.h"
#include <iostream>
#include <iomanip>

// TODO: Implémenter les méthodes de la classe Film ici.

// Constructeurs et destructeur
Film::Film() {}

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) {
    titre_ = titre;
    anneeDeSortie_ = anneeDeSortie;
    realisateur_ = realisateur;
    categorie_ = categorie;
    duree_ = duree;
}

Film::~Film() { }

// Getters
string Film::getTitre() const { return ""; }

string Film::getRealisateur() const { return ""; }

int Film::getAnneeDeSortie() const { return 0; }

Categorie Film::getCategorie() const { return Categorie::HORREUR; }

int Film::getDuree() const { return 0; }

vector<Acteur*> Film::getActeurs() const { return {acteurs_}; }

vector<Critique*> Film::getCritiques() const { return {critiques_}; }

int Film::getNbActeurs() const { return acteurs_.size(); }

int Film::getNbCritiques() const { return critiques_.size(); }

// Setters
void Film::setTitre(string titre) { titre_ = titre; }

void Film::setRealisateur(string realisateur) { realisateur_ = realisateur; }

void Film::setAnneeDeSortie(int anneeDeSortie) { anneeDeSortie_ = anneeDeSortie; }

void Film::setCategorie(Categorie categorie) { categorie_ = categorie; }

void Film::setDuree(int duree) { duree_ = duree; }

void Film::setActeurs(vector<Acteur*> acteurs) {}

void Film::setCritiques(vector<Critique*> critiquesVec) {}

// Méthodes fonctionnelles
Acteur* Film::trouverActeur(const string nom) const {
    for (auto& acteur : acteurs_) 
        if (acteur->getNom() == nom)
            return acteur;

    return nullptr;
}

Critique* Film::trouverCritique(const string nom) const {
    for (auto& critique : critiques_) 
        if (critique->getAuteur() == nom)
            return critique;
       
    return nullptr;
}

bool Film::isActeurPresent(string nomActeur) const {
    
    if (trouverActeur(nomActeur) != nullptr)
            return true;
        
    return false;
}

bool Film::isCritiquePresent(string nomCritique) const {
    
    if (trouverCritique(nomCritique) != nullptr)
        return true;
    
    return false;
}

bool Film::ajouterActeur(string nom, int anneeNaissance, string biographie) {
    
    acteurs_.push_back(new Acteur(nom,anneeNaissance,biographie));
    
    return true;
}

bool Film::ajouterCritique(string nom, string commentaire, int note) {
    
    critiques_.push_back(new Critique(nom, commentaire, note));

    return true;
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
