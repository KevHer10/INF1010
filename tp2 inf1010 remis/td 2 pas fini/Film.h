#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Acteur.h"
#include "Critique.h"

using namespace std;

// Catégories de films
enum class Categorie {
    ACTION,
    COMEDIE,
    DRAME,
    HORREUR
};

class Film {
public:
    // Constructeurs
    Film();
    Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree);
    Film(const Film& film);
    Film& operator=(const Film& film);

    // Getters
    string getTitre() const;
    string getRealisateur() const;
    int getAnneeDeSortie() const;
    Categorie getCategorie() const;
    int getDuree() const;

    vector<shared_ptr<Acteur>> getActeurs() const;
    vector<unique_ptr<Critique>> getCritiques() const;

    int getNbActeurs() const;
    int getNbCritiques() const;

    // Setters
    void setTitre(string titre);
    void setRealisateur(string realisateur);
    void setAnneeDeSortie(int anneeDeSortie);
    void setCategorie(Categorie categorie);
    void setDuree(int duree);

    void setActeurs(vector<shared_ptr<Acteur>> acteurs);
    void setCritiques(vector<Critique*> acteurs);

    // Méthodes fonctionnelles
    shared_ptr<Acteur> trouverActeur(const string nom) const;
    unique_ptr<Critique> trouverCritique(const string auteur) const;

    bool isActeurPresent(string nomActeur) const;
    bool isCritiquePresent(string auteur) const;

    float obtenirNoteMoyenne() const;

    // Opérateurs
    bool operator+=(shared_ptr<Acteur>& acteur);
    bool operator+=(Critique* critique);

    bool operator==(const Film& film) const;
    bool operator!=(const Film& film) const;

    bool operator-=(shared_ptr<Acteur>& acteur);
    bool operator-=(Critique* critique);

    // Méthode d'affichage
    friend ostream& operator<<(ostream& os, const Film& film);

private:
    string titre_;
    int anneeDeSortie_;
    string realisateur_;
    Categorie categorie_;
    int duree_;

    vector<shared_ptr<Acteur>> acteurs_;
    vector<unique_ptr<Critique>> critiques_;
};