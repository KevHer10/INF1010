#pragma once
#include <string>
#include <iostream>

using namespace std;

class Critique {
public:
    // Constructeurs
    Critique();
    Critique(std::string auteur, std::string commentaire, int note);
    Critique(const Critique& critique);
    Critique& operator=(const Critique& critique);

    // Getters
    string getAuteur() const;
    string getCommentaire() const;
    int getNote() const;

    // Setters
    void setAuteur(string auteur);
    void setCommentaire(string commentaire);
    void setNote(int note);

    // Opérateurs
    bool operator==(const Critique& critique) const;
    bool operator!=(const Critique& critique) const;

    // Méthode d'affichage
    friend ostream& operator<<(ostream& os, const Critique& critique);

private:
    string auteur_;
    string commentaire_;
    int note_;
};