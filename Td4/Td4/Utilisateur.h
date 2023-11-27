#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Media.h"

using namespace std;

class Utilisateur {
public:
    // Constructeur
    Utilisateur(const string& nom, const string& mdp);

    // Getters
    string getNomUtilisateur() const;

    // Setters
    void setNomUtilisateur(const string& nom);
    void setMotDePasse(const string& mdp);

    // Méthodes fonctionnelles
    bool verifierConnexion(const string& mdp) const;

private:
    string nomUtilisateur;
    string motDePasse;
};
