#pragma once
#include "Cast.h"
#include <vector>
#include <string>
#include <iostream>

class Realisateur : public Cast {
public:
    // Constructeurs
    Realisateur();
    Realisateur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& studioAssocie);
    Realisateur(const Realisateur& realisateur);

    // Getters
    string getStudio() const { return studio_; }
    vector<pair<int, string>> getPrix() const;

    // Setters
    void setStudio(const string& studio) { studio_ = studio; }
    void ajouterPrix(int annee, const string& nomPrix);

    // Methodes virtuelles surchargees
    bool accepterRole(const pair<int, Cast*>& role) const override;
    ClasseCelebrite calculerPopularite() const override;
    void afficher(ostream& os) const override;

    // Operator
    Realisateur& operator+=(const pair<int, string>& prix);

    // Methode d'affichage
    void afficherPrix() const;

private:
    string studio_;
    vector<pair<int, string>> prix_;  // annee, nomPrix
};