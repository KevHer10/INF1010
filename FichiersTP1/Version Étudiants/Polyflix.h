#pragma once

#include "Film.h"
#include <iostream>

class Polyflix {
public:
    // Constructeurs et destructeur
    Polyflix();
    Polyflix(string nomUtilisateur, string motDePasse);

    ~Polyflix();

    // getters
    string getUtilisateur() const;

    // setters
    void setUtilisateur(string utilisateur);
    void setMotDePasse(string motDePasse);

    // Méthodes pour la connexion
    bool connecter(string utilisateur, string motDePasse);

    // Méthodes pour gérer les films
    bool ajouterFilm(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree);
    bool retirerFilm(string titre, int anneeDeSortie);

    // Méthodes pour la recherche
    Film* chercherFilmParTitre(const string& titre) const;
    vector<Film*> listerFilmsParCategorie(Categorie categorie) const;

    // Méthodes pour obtenir des statistiques
    int getNombreTotalFilms() const;
    int getNombreFilmsParCategorie(Categorie categorie) const;
    Film* obtenirFilmAvecLaPlusHauteNote() const;
    Film* obtenirFilmAvecLaPlusBasseNote() const;
    Film* obtenirFilmPlusRecent() const;

    // Méthodes pour l'affichage
    void afficherListeFilms() const;
    void afficherFilmsParCategorie(Categorie categorie) const;

private:
    string utilisateur_;
    string motDePasse_;
    vector<Film*> films_;
};

