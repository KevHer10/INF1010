#pragma once
#include <string>
#include <iostream>

using namespace std;

class Critique {
public:
    // Constructeurs
    Critique();
    Critique(string auteur, string commentaire, int note);

    // Getters
    string getAuteur() const;
    string getCommentaire() const;
    int getNote() const;

    // Setters
    void setAuteur(string auteur);
    void setCommentaire(string commentaire);
    void setNote(int note);

    // Méthode d'affichage
    void afficher() const;

private:
    string auteur_;
    string commentaire_;
    int note_;
};
