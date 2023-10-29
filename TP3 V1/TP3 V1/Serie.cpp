#include "Serie.h"

// Constructeurs
Serie::Serie(): Media() { }  // TODO

Serie::Serie(string titre, int anneeDeSortie, Categorie categorie, vector<pair<int, int>> episodes) 
	: Media(titre,anneeDeSortie,categorie) , episodes_(episodes) { }  // TODO

// Getters
int Serie::getNbEpisodes() const { return episodes_.size(); }  // TODO

pair<int, int> Serie::getEpisodeActuel() const { return episodeActuel_; }  // TODO

// Setter
void Serie::setEpisodeActuel(int numeroEpisode, int tempsVisionne) {
	episodeActuel_ = { numeroEpisode, tempsVisionne };
}  // TODO

void Serie::ajouterEpisode(int numeroEpisode, int duree) {
	episodes_.push_back(make_pair(numeroEpisode, duree));
}  // TODO

string Serie::progression() const { 
	int dureeTotal=0;
	for (auto& episode : episodes_) {
		if (episodeActuel_.first == episode.first) {
			dureeTotal = episode.second;
		}
	}
	
	return "Episode " + to_string(episodeActuel_.first) + ": Tempsecoule" +
		to_string(episodeActuel_.second) + "/" + to_string(dureeTotal) + " minutes";
}  // TODO

void Serie::afficher(ostream& os) const { }  // TODO