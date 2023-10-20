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
    Acteur(const Acteur& acteur);
    Acteur& operator=(const Acteur& acteur);

    // Getters
    string getNom() const;
    int getAnneeNaissance() const;
    string getBiographie() const;

    // Setters
    void setNom(const string nom);
    void setAnneeNaissance(int anneeNaissance);
    void setBiographie(const string bio);

    // Opérateurs
    bool operator==(const Acteur& acteur) const;
    bool operator!=(const Acteur& acteur) const;

    // Méthode d'affichage
    friend ostream& operator<<(ostream& os, const Acteur& acteur);

private:
    string nom_;
    int anneeNaissance_;
    string biographie_;
};
