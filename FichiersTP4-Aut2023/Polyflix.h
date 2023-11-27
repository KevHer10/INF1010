#pragma once

#include "Media.h"
#include "Film.h"
#include "Serie.h"
#include "Utilisateur.h"
#include "Liste.h"
#include "Foncteur.h"

#include <iostream>
#include <utility>
#include <map>
#include <list>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>

using namespace std;

class Polyflix {
public:
    // Constructeur
    Polyflix();
    Polyflix(const Polyflix& polyflix);

    // Destructeur
    ~Polyflix() = default;

    // Metodes utilisateurs
    int getNombreUtilisateurs() const;
    Utilisateur* chercherUtilisateur(string nomUtilisateur);

    // Metode medias
    Liste<Media> listersi(const function<bool(Media media)>& critere) const;
    Liste<Media> obtenirNMeilleursMedias(int n);

    bool visionnerFilm(string utilisateur, string media);

    bool utilisateurExiste(string nomUtilisateur) const;
    bool mediaExiste(string nomMedia) const;

    // Operators
    bool operator+=(Utilisateur utilisateur);
    bool operator+=(Media media);

    // Metode d'affichage
    friend ostream& operator<<(ostream& os, const Polyflix& polyflix);

private:
    void trierMedias();

    Liste<Media> medias_;
    Liste<Utilisateur> utilisateurs_;
    map <string, set<string>> historique_;
};
