#include "Film.h"

// Constructeurs
Film::Film() : Media(), duree_(0), dureeVisionne_(0) {}

Film::Film(string titre, int anneeDeSortie, Categorie categorie, int duree): Media(titre,anneeDeSortie,categorie), duree_(duree) {}  // TODO


// Methodes virtuelles surchargees
string Film::progression() const { return "Temps ecoule: " + to_string(dureeVisionne_) + "/" +
to_string(duree_) + " minutes\n"; }  // TODO

void Film::afficher(ostream& os) const { }  // TODO