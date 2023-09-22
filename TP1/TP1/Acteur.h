/*
Fichier: Acteur.h
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Description de la classe Acteur.
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

const string SEPARATEUR_SIMPLE = "------------------------------------------------";

class Acteur {
public:
    // Constructeurs
    Acteur();
    Acteur(const string nom, int anneeNaissance, const string biographie);

    // Getters
    string getNom() const;
    int getAnneeNaissance() const;
    string getBiographie() const;

    // Setters
    void setNom(const string nom);
    void setAnneeNaissance(int anneeNaissance);
    void setBiographie(const string bio);

    // Méthode d'affichage
    void afficher() const;

private:
    string nom_;
    int anneeNaissance_;
    string biographie_;
};
