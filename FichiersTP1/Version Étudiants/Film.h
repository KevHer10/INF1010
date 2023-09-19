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
    // Constructeurs et destructeur
    Film();
    Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree);

    ~Film();

    // Getters
    string getTitre() const;
    string getRealisateur() const;
    int getAnneeDeSortie() const;
    Categorie getCategorie() const;
    int getDuree() const;

    vector<Acteur*> getActeurs() const;
    vector<Critique*> getCritiques() const;

    int getNbActeurs() const;
    int getNbCritiques() const;

    // Setters
    void setTitre(string titre);
    void setRealisateur(string realisateur);
    void setAnneeDeSortie(int anneeDeSortie);
    void setCategorie(Categorie categorie);
    void setDuree(int duree);

    void setActeurs(vector<Acteur*> acteurs);
    void setCritiques(vector<Critique*> acteurs);

    // Méthodes fonctionnelles
    Acteur* trouverActeur(const string nom) const;
    Critique* trouverCritique(const string auteur) const;

    bool isActeurPresent(string nomActeur) const;
    bool isCritiquePresent(string auteur) const;

    bool ajouterActeur(string nom, int anneeNaissance, string biographie);
    bool ajouterCritique(string auteur, string commentaire, int note);

    bool retirerActeur(const string nom);
    bool retirerCritique(const string auteur);

    float obtenirNoteMoyenne() const;

    // Méthodes d'affichage
    void afficher() const;

private:
    string titre_;
    int anneeDeSortie_;
    string realisateur_;
    Categorie categorie_;
    int duree_;

    vector<Acteur*> acteurs_;
    vector<Critique*> critiques_;
};