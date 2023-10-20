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
    vector<shared_ptr<Media>> getMediaVus() const;

    // Setters
    void setNomUtilisateur(const string& nom);
    void setMotDePasse(const string& mdp);

    // Méthodes fonctionnelles
    void ajouterMedia(shared_ptr<Media> media);
    bool verifierConnexion(const string& mdp) const;

private:
    string nomUtilisateur;
    string motDePasse;
    vector<shared_ptr<Media>> mediaVus;
};
