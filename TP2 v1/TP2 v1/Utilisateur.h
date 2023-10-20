#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Film.h"

using namespace std;

class Utilisateur {
public:
    // Constructeur
    Utilisateur(const string& nom, const string& mdp);

    // Getters
    string getNomUtilisateur() const;

    /// @brief 
    /// @return 
    vector<shared_ptr<Film>> getFilmsVus() const;

    // Setters
    void setNomUtilisateur(const string& nom);
    void setMotDePasse(const string& mdp);

    // Méthodes fonctionnelles
    void ajouterFilm(shared_ptr<Film> film);
    bool verifierConnexion(const string& mdp) const;

private:
    string nomUtilisateur;
    string motDePasse;
    vector<shared_ptr<Film>> filmsVus;
};
