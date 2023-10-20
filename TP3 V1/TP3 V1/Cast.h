#pragma once
#include <string>
#include <iostream>

using namespace std;

enum ClasseCelebrite {
    A_CELEBRITY, // plus de 10 prix ou rôles
    B_CELEBRITY, // 5-10 prix ou rôles
    C_CELEBRITY  // moins de 5 prix ou rôles
};

const int SEUIL_A = 10;
const int SEUIL_B = 5;

class Cast {
public:
    // Constructeurs
    Cast();
    Cast(const string& nom, int anneeNaissance, const string& biographie, int salaire);
    Cast(const Cast& cast);

    // Destructeur
    virtual ~Cast();

    // Getters
    string getNom() const { return nom_; }
    int getAnneeNaissance() const { return anneeNaissance_; }
    string getBiographie() const { return biographie_; }

    // Setters
    void setNom(const string& nom) { nom_ = nom; }
    void setAnneeNaissance(int anneeNaissance) { anneeNaissance_ = anneeNaissance; }
    void setBiographie(const string& bio) { biographie_ = bio; }

    // Methodes virtuelles pures
    virtual bool accepterRole(const pair<int, Cast*>& role) const = 0;
    virtual ClasseCelebrite calculerPopularite() const = 0;

    // Operators
    bool operator==(const Cast& cast) const;
    bool operator!=(const Cast& cast) const;

    // Methodes d'affichage
    virtual void afficher(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Cast& cast);

protected:
    string nom_;
    int anneeNaissance_;
    string biographie_;
    int salaire_;
};