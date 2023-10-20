/*
Fichier: Film.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Implementation de la classe Film.
*/
#include "Film.h"
#include <iostream>
#include <iomanip>

// TODO: Implémenter les méthodes de la classe Film ici.

// Constructeurs et destructeur

/// @brief Constructeur par défaut de la classe Film.
Film::Film(){
    titre_ = "";
    anneeDeSortie_ = 0;
    realisateur_ = "";
    categorie_ = Categorie::ACTION;
    duree_ = 0;

} 
/// @brief Constructeur par paramètres de la classe Film.
/// @param titre: Titre du film. 
/// @param anneeDeSortie:  l’année de sortie du film. 
/// @param realisateur: le réalisateur du film.
/// @param categorie: la catégorie du film.
/// @param duree: la durée du film
Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) {
    titre_ = titre;
    anneeDeSortie_ = anneeDeSortie;
    realisateur_ = realisateur;
    categorie_ = categorie;
    duree_ = duree;
}
/// @brief Destructeur de la classe Film.
Film::~Film() {}

// Getters

/// @brief Retourne le titre du film.
/// @return Titre du film.
string Film::getTitre() const { return titre_; }

/// @brief Retourne le réalisateur du film.
/// @return réalisateur du film.
string Film::getRealisateur() const { return realisateur_; }

/// @brief Retourne l’année de sortie du film. 
/// @return l’année de sortie du film. 
int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

/// @brief Retourne la catégorie du film. 
/// @return la catégorie du film.
Categorie Film::getCategorie() const { return categorie_; }

/// @brief Retourne la durée du film.
/// @return la durée du film.
int Film::getDuree() const { return duree_; }

/// @brief Retourne un vecteur de pointeurs du type Acteur
/// @return vecteur d'Acteurs
vector<Acteur*> Film::getActeurs() const { return {acteurs_}; }

/// @brief Retourne un vecteur de pointeurs du type Critique
/// @return vecteur de Critiques
vector<Critique*> Film::getCritiques() const { return {critiques_}; }

/// @brief Retourne le nombre d'acterus presents dans le vecteur d'Acteurs 
/// @return nombre d'acteurs
int Film::getNbActeurs() const { return acteurs_.size(); }

/// @brief Retourne le nombre de critique presents dans le vecteur de Critiques 
/// @return nombre de Critiques
int Film::getNbCritiques() const { return critiques_.size(); }

// Setters

/// @brief Modifie le Titre du film. 
/// @param titre: Titre du film.   
void Film::setTitre(string titre) { titre_ = titre; }

/// @brief Modifie le réalisateur du film.
/// @param realisateur: le réalisateur du film. 
void Film::setRealisateur(string realisateur) { realisateur_ = realisateur; }

/// @brief Modifie l’année de sortie du film. 
/// @param anneeDeSortie: l’année de sortie du film.  
void Film::setAnneeDeSortie(int anneeDeSortie) { anneeDeSortie_ = anneeDeSortie; }

/// @brief Modifie la catégorie du film.
/// @param categorie: la catégorie du film. 
void Film::setCategorie(Categorie categorie) { categorie_ = categorie; }

/// @brief Modifie la durée du film 
/// @param duree: la durée du film 
void Film::setDuree(int duree) { duree_ = duree; }

/// @brief Modifie les acteurs qui sont dans le vecteur.
/// @param acteurs: Vecteur d'acteurs   
void Film::setActeurs(vector<Acteur*> acteurs) {
    for (auto& acteur : acteurs_) {
        delete acteur;
        acteur = nullptr;
    }
   
    acteurs_ = acteurs;
}
/// @brief Modifie les critiques qui sont dans le vecteur.
/// @param critiquesVec: Vecteur de critiques 
void Film::setCritiques(vector<Critique*> critiquesVec) {

    for (auto&& critique : critiques_) {
        delete critique;
        critique = nullptr;
    }
}

// Méthodes fonctionnelles

/// @brief vérifie si un acteur est présent dans le film en vérifiant son
/// nom. S’il est présent dans le film, on retourne son pointeur, sinon on retourne nullptr.
/// @param nom: nom de l'acteur. 
/// @return Pointeur de type Acteur.
Acteur* Film::trouverActeur(const string nom) const {
    for (auto& acteur : acteurs_) {
        if (acteur->getNom() == nom)
            return acteur;
    }
    
    return nullptr;
}
/// @brief vérifie si une critique est présente dans le film en vérifiant l’auteur de la critique.
/// S’il est présent dans le film, on retourne son pointeur, sinon on retourne nullptr.
/// @param nom: Nom de l'auteur de la critique
/// @return Pointeur de type Critique.
Critique* Film::trouverCritique(const string nom) const {
    for (auto&& critique : critiques_)
        if (critique->getAuteur() == nom)
            return critique;
       
    return nullptr;
}
/// @brief vérifie si le nom de l’acteur est présent dans le film
/// @param nomActeur : nom de l'acteur. 
/// @return true ou false 
bool Film::isActeurPresent(string nomActeur) const {
    
    if (trouverActeur(nomActeur) != nullptr)  
            return true;
        
    return false;
}
/// @brief vérifie si l’auteur de la critique est présent dans le film
/// @param nomCritique: Nom de l'auteur de la critique. 
/// @return true ou false 
bool Film::isCritiquePresent(string nomCritique) const {
    
    if (trouverCritique(nomCritique) != nullptr)
        return true;
    
    return false;
}
/// @brief ajoute l’acteur dans le vector s’il n’existe pas.
/// @param nom: nom de l'acteur 
/// @param anneeNaissance: anee de naissance de l'acteur. 
/// @param biographie: biographie de l'acteur.
/// @return true ou false 
bool Film::ajouterActeur(string nom, int anneeNaissance, string biographie) {
    
    acteurs_.push_back(new Acteur(nom,anneeNaissance,biographie));
    
    return true;
}
/// @brief ajoute la critique dans le vector si elle n’existe pas.
/// @param nom: Auteur de la critique du film.
/// @param commentaire: Commentaire du film.  
/// @param note: Note du film.
/// @return true ou false 
bool Film::ajouterCritique(string nom, string commentaire, int note) {
    
    critiques_.push_back(new Critique(nom, commentaire, note));

    return true;
}
/// @brief retire l'acteur dans le vector s’ils existent.
/// @param nom: Nom de l'acteur du film. 
/// @return true ou false
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
/// @brief retire la critique dans le vector s’elles existent.
/// @param nom: nom de l'auteur de la critique. 
/// @return true ou false
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
/// @brief retourne la moyenne des notes des critiques.
/// @return moyenne des notes des critiques.
float Film::obtenirNoteMoyenne() const {
    float moyenne = 0;
    for (auto&& critique : critiques_) {
        moyenne += critique->getNote();
    }
    moyenne = moyenne / critiques_.size();

    return moyenne;
}

// Méthodes d'affichage

/// @brief Une méthode d’affichage des informations qui concernent un film tel que présenté dans la sortie.
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
    default: std::cout << "Inconnu\n";
    }

     cout << "Acteurs:" << "\n";

     for (auto&& acteur : acteurs_)
         acteur->afficher();

     cout << "Critiques:" << "\n";

     for (auto&& critique : critiques_)
         critique->afficher();

     cout << "Note moyenne: " << obtenirNoteMoyenne() << "\n";


}
