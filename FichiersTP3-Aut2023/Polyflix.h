#pragma once

#include "Media.h"
#include "Film.h"
#include "Serie.h"
#include "Utilisateur.h"

#include <iostream>
#include <utility>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Polyflix {
public:
    // Constructeur
    Polyflix();
    Polyflix(const Polyflix& polyflix);

// Destructeur
~Polyflix() = default;

    // Metodes utilisateurs
    Utilisateur* chercherUtilisateur(string nomUtilisateur);
    int getNombreUtilisateurs() const;
    bool utilisateurExiste(string nomUtilisateur);
    bool connecterUtilisateur(string nomUtilisateur, string motDePasse);
    bool modifierMotDePasse(string nomUtilisateur, string motDePasse);
    bool visionnerMedia(string nomUtilisateur, string titreMedia);

    // Metodes statistiques
    int getNombreTotalFilms() const;
    int getNombreTotalSeries() const;
    int getNombreTotalMedia() const;

    Media* chercherMedia(string titreMedia) const;

    vector<Film*> listerTousLesFilms() const;
    vector<Serie*> listerTousLesSeries() const;

    vector<Film*> listerFilmsParCategorie(Categorie categorie) const;
    vector<Serie*> listerSeriesParCategorie(Categorie categorie) const;

    vector<shared_ptr<Media>> listerMediaVisionnesParUtilisateur(string nomUtilisateur);

    // Operators
    bool operator+=(Utilisateur utilisateur);
    bool operator+=(Media* media);

    // Metode d'affichage
    friend ostream& operator<<(ostream& os, const Polyflix& polyflix);

private:
    vector<shared_ptr<Media>> medias_;
    vector<shared_ptr<Utilisateur>> utilisateurs_;
};
