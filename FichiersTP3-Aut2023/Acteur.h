#pragma once
#include "Cast.h"
#include <vector>
#include <string>
#include <iostream>

class Acteur : public Cast {
public:
    // Constructeurs
    Acteur();
    Acteur(const string& nom, int anneeNaissance, const string& biographie, int salaire, const string& agence);
    Acteur(const Acteur& acteur);

    // Getters
    string getAgence() const { return agence_; }
    vector<string> getRolesJoues() const { return rolesJoues_; }

    // Setters
    void setAgence(const string& agence) { agence_ = agence; }
    void ajouterRole(const string& role) { rolesJoues_.push_back(role); }

    // Methodes virtuelles surchargees
    bool accepterRole(const pair<int, Cast*>& role) const override;
    ClasseCelebrite calculerPopularite() const override;
    void afficher(ostream& os) const override;

    // Operator
    Acteur& operator+=(const string& role);

    // Methode d'affichage
    void afficherRoles() const;

private:
    string agence_;
    vector<string> rolesJoues_;
};