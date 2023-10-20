#pragma once
#include "Media.h"

using namespace std;

class Film : public Media {
public:
    // Constructeurs
    Film();
    Film(string titre, int anneeDeSortie, Categorie categorie, int duree);

    // Getters
    int getDuree() const { return duree_;}
    int getDureeVisionne() const { return dureeVisionne_;}

    // Setters
    void setDuree(int duree) { duree_ = duree;}
    void setDureeVisionne(int dureeVue) { dureeVisionne_ = dureeVue;}

    // Methodes virtuelles surchargees
    string progression() const override;
    void afficher(ostream& os) const override;

private:
    int duree_;
    int dureeVisionne_ = 0;
};