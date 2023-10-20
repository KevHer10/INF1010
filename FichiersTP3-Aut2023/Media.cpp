#include "Media.h"

// Constructeur
Media::Media() : titre_(""), anneeDeSortie_(0), categorie_(Categorie::ACTION) {}

Media::Media(string titre, int anneeDeSortie, Categorie categorie)
    : titre_(titre), anneeDeSortie_(anneeDeSortie), categorie_(categorie) {}

// Methodes virtuelles surchargees
float Media::obtenirEvaluation() const { return 0.0; }  // TODO

// Opeators
void Media::operator+=(shared_ptr<Cast> cast) { }  // TODO

void Media::operator+=(Critique critique) { }  // TODO

// Methodes d'affichage
void Media::afficher(ostream& os) const { }  // TODO

ostream& operator<<(ostream& os, const Media& media) { return os; }  // TODO
