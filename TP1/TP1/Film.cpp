#include "Film.h"
#include <iostream>
#include <iomanip>

// TODO: Implémenter les méthodes de la classe Film ici.

// Constructeurs et destructeur
Film::Film(){
    titre_ = "";
    anneeDeSortie_ = 0;
    realisateur_ = "";
    categorie_ = Categorie::ACTION;
    duree_ = 0;

} 

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) {
    titre_ = titre;
    anneeDeSortie_ = anneeDeSortie;
    realisateur_ = realisateur;
    categorie_ = categorie;
    duree_ = duree;
}

Film::~Film() {}

// Getters
string Film::getTitre() const { return titre_; }

string Film::getRealisateur() const { return realisateur_; }

int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

Categorie Film::getCategorie() const { return categorie_; }

int Film::getDuree() const { return duree_; }

vector<Acteur*> Film::getActeurs() const { return {acteurs_}; } //ici

vector<Critique*> Film::getCritiques() const { return {critiques_}; } //ici

int Film::getNbActeurs() const { return acteurs_.size(); }//ici

int Film::getNbCritiques() const { return critiques_.size(); }//ici

// Setters
void Film::setTitre(string titre) { titre_ = titre; }

void Film::setRealisateur(string realisateur) { realisateur_ = realisateur; }

void Film::setAnneeDeSortie(int anneeDeSortie) { anneeDeSortie_ = anneeDeSortie; }

void Film::setCategorie(Categorie categorie) { categorie_ = categorie; }

void Film::setDuree(int duree) { duree_ = duree; }

void Film::setActeurs(vector<Acteur*>& acteurs) {
    for (auto& acteur : acteurs_) {
        delete acteur;
        acteur = nullptr;
    }
   
    acteurs_ = acteurs;
}//ici

void Film::setCritiques(vector<Critique*> critiquesVec) {

    for (auto&& critique : critiques_) {
        delete critique;
        critique = nullptr;
    }
}//ici

// Méthodes fonctionnelles
Acteur* Film::trouverActeur(const string nom) const {
    for (auto& acteur : acteurs_) {
        if (acteur->getNom() == nom)
            return acteur;
    }
    
    return nullptr;
}

Critique* Film::trouverCritique(const string nom) const {
    for (auto&& critique : critiques_)
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
    
    for (auto&& acteur : acteurs_) {
        if (acteur->getNom() == nom)
            acteur = acteurs_.back();
        acteurs_.pop_back();
        return true;
        //break;
    }

    return false;
}

bool Film::retirerCritique(const string nom) {
    for (auto&& critique : critiques_) {
        if (critique->getAuteur() == nom)
            critique = critiques_.back();
        critiques_.pop_back();
        return true;
        //break;
    }

    return false;
}

float Film::obtenirNoteMoyenne() const {
    float moyenne = 0;
    for (auto&& critique : critiques_) {
        moyenne += critique->getNote();
    }
    moyenne = moyenne / critiques_.size();

    return moyenne;
}

// Méthodes d'affichage
void Film::afficher() const {
    Categorie categorie = getCategorie();
    
    cout << getTitre() << " (" << getAnneeDeSortie() << ") " << "de " << getRealisateur() << "\n";
    cout << "Duree: " << getDuree() << " minutes" << "\n";
    
    cout << "Categorie: ";
    switch (categorie)
    {
    case Categorie::ACTION: std::cout << "Action\n";   break;
    case Categorie::COMEDIE: std::cout << "Comedie\n"; break;
    case Categorie::DRAME: std::cout << "Drame\n";  break;
    case Categorie::HORREUR: std::cout << "Horreur\n"; break;
    }

     cout << "Acteurs:" << "\n";

     for (auto&& acteur : acteurs_)
         acteur->afficher();

     cout << "Critiques:" << "\n";

     for (auto&& critique : critiques_)
         critique->afficher();

     cout << "Note moyenne: " << obtenirNoteMoyenne() << "\n";











}
