#include "Media.h"

// Constructeur
Media::Media() : titre_(""), anneeDeSortie_(0), categorie_(Categorie::ACTION) {}

Media::Media(string titre, int anneeDeSortie, Categorie categorie)
    : titre_(titre), anneeDeSortie_(anneeDeSortie), categorie_(categorie) {}

// TODO
float Media::obtenirEvaluation() const { 
    return 0.0;
}

// TODO
void Media::operator+=(Cast cast) { }

// TODO
void Media::operator+=(Critique critique) { }

// TODO
void Media::afficher(ostream& os) const {
    os << SEPARATEUR_DOUBLE <<endl;
    // TODO : Afficher les informations de base du m�dia

    switch (categorie_) {
    case Categorie::ACTION: os << "Action" << endl; break;
    case Categorie::COMEDIE: os << "Com�die" << endl; break;
    case Categorie::DRAME: os << "Drame" << endl; break;
    case Categorie::HORREUR: os << "Horreur" << endl; break;
    }
    os << SEPARATEUR_DOUBLE << endl;
    os << "Casting: " << endl;
    // TODO : Afficher le casting du m�dia
    os << SEPARATEUR_SIMPLE << endl;

    os << "Critiques: " << endl;
    // TODO : Afficher les critiques du m�dia
}

ostream& operator<<(ostream& os, const Media& media) {
    media.afficher(os);
    return os;
}
