#include "Film.h"

// Constructeurs
Film::Film() : Media(), duree_(0), dureeVisionne_(0) {}

Film::Film(string titre, int anneeDeSortie, Categorie categorie, int duree) {}  // TODO


// Methodes virtuelles surchargees
string Film::progression() const { return ""; }  // TODO

void Film::afficher(ostream& os) const { }  // TODO