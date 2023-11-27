#pragma once

#include "Film.h"
#include "Utilisateur.h"

#include <iostream>
#include <utility>
#include <map>
#include <list>

using namespace std;

class Polyflix {
public:
    // Constructeur
    Polyflix();
    Polyflix(const Polyflix& polyflix);

    // M�thodes pour la recherche
    Film* chercherFilmParTitre(const string& titre) const;
    Utilisateur* chercherUtilisateur(const string& nomUtilisateur);

    // M�thodes liees aux utilisateurs
    int getNombreUtilisateurs() const;
    bool utilisateurExiste(const string& nomUtilisateur);

    bool connecterUtilisateur(string nomUtilisateur, string motDePasse);
    bool modifierMotDePasse(string nomUtilisateur, string motDePasse);

    bool visionnerFilm(string nomUtilisateur, string titreFilm);

    // M�thodes pour obtenir des statistiques
    int getNombreTotalFilms() const;
    int getNombreFilmsParCategorie(Categorie categorie) const;
    int getNombreTotalFilmsVisionnes() const;
    int getNombreUtilisateursAyantVisionne(const string& titreFilm) const;

    unique_ptr<Film> obtenirFilmAvecLaPlusHauteNote() const;
    unique_ptr<Film> obtenirFilmAvecLaPlusBasseNote() const;
    unique_ptr<Film> obtenirFilmPlusRecent() const;

    vector<unique_ptr<Film>> listerFilmsParCategorie(Categorie categorie) const;
    vector<shared_ptr<Film>> listerFilmsVisionnesParUtilisateur(const string& nomUtilisateur);

    // Op�rateurs
    bool operator+=(Utilisateur utilisateur);

    bool operator+=(Film* film);
    bool operator-=(string titre);

    Film* operator[](string titre);

    // M�thodes pour l'affichage
    friend ostream& operator<<(ostream& os, const Polyflix& polyflix);

private:
    vector<unique_ptr<Film>> films_;
    vector<Utilisateur> utilisateurs_;
};

