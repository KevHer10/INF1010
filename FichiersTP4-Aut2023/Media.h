#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Evaluation.h"
#include "Cast.h"
#include "Critique.h"
#include "Liste.h"

using namespace std;

const string SEPARATEUR_SIMPLE = "------------------------------------------------";
const string SEPARATEUR_DOUBLE = "================================================";

enum class Categorie {
    ACTION,
    COMEDIE,
    DRAME,
    HORREUR
};

class Media : public Evaluation {
public:
    // Constructeurs
    Media();
    Media(string titre, int anneeDeSortie, Categorie categorie);

    // Destructeur
    virtual ~Media() = default;

    // Getters
    string getTitre() const { return titre_; }
    int getAnneeDeSortie() const { return anneeDeSortie_; }
    Categorie getCategorie() const { return categorie_; }

    // Setters
    void setTitre(string titre) { titre_ = titre; }
    void setAnneeDeSortie(int anneeDeSortie) { anneeDeSortie_ = anneeDeSortie; }
    void setCategorie(Categorie categorie) { categorie_ = categorie; }

    // Methode virtuelle surchargee
    virtual float obtenirEvaluation() const override;

    // Operator
    void operator+=(Cast cast);
    void operator+=(Critique critique);

    // Methodes d'affichage
    virtual void afficher(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Media& media);

protected:
    string titre_;
    int anneeDeSortie_;
    Categorie categorie_;

    Liste<Cast> casts_;
    Liste<Critique> critiques_;
};