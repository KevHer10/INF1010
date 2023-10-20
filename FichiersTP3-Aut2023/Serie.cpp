#include "Serie.h"

// Constructeurs
Serie::Serie() { }  // TODO

Serie::Serie(string titre, int anneeDeSortie, Categorie categorie, vector<pair<int, int>> episodes) { }  // TODO

// Getters
int Serie::getNbEpisodes() const { return 0; }  // TODO

pair<int, int> Serie::getEpisodeActuel() const { return { 0, 0 }; }  // TODO

// Setter
void Serie::setEpisodeActuel(int numeroEpisode, int tempsVisionne) { }  // TODO

void Serie::ajouterEpisode(int numeroEpisode, int duree) { }  // TODO

string Serie::progression() const { return ""; }  // TODO

void Serie::afficher(ostream& os) const { }  // TODO