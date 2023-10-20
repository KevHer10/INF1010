#pragma once

#include <tuple>
#include <vector>
#include "Media.h"

class Serie : public Media {
public:
    // Constructeurs
    Serie();
    Serie(string titre, int anneeDeSortie, Categorie categorie, vector <pair<int, int>> episodes);

    // Getters
    int getNbEpisodes() const;
    pair<int, int> getEpisodeActuel() const;

    // Setter
    void setEpisodeActuel(int numeroEpisode, int tempsVisionne);

    void ajouterEpisode(int numeroEpisode, int duree);

    // Methodes virtuelles surchargees
    string progression() const override;
    void afficher(ostream& os) const override;

private:
    vector <pair<int, int>> episodes_;  // vector<numeroEpisode, duree>
    pair<int, int> episodeActuel_;     // numeroEpisode, tempsVisionne
};