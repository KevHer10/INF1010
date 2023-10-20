#pragma once
#include <string>
#include <iostream>
#include "Evaluation.h"

using namespace std;

class Critique : Evaluation {
public:
    // Constructeurs
    Critique();
    Critique(std::string auteur, std::string commentaire, int note);
    Critique(const Critique& critique);
    Critique& operator=(const Critique& critique);

    // Getters
    string getAuteur() const { return auteur_;}
    string getCommentaire() const { return commentaire_;}
    int getNote() const { return note_;}

    // Methode vituelle surchargee
    float obtenirEvaluation() const override;

    // Setters
    void setAuteur(string auteur) { auteur_ = auteur;}
    void setCommentaire(string commentaire) { commentaire_ = commentaire;}
    void setNote(int note) { note_ = note;}

    // Operators
    bool operator==(const Critique& critique) const;
    bool operator!=(const Critique& critique) const;

    // Methode d'affichage
    friend ostream& operator<<(ostream& os, const Critique& critique);

private:
    string auteur_;
    string commentaire_;
    int note_;
};