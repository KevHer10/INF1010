/*
Fichier: Serie.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Serie.
*/
#include "Serie.h"

// Constructeurs
/// @brief Constructeur par défaut de la classe Serie.
Serie::Serie(): Media() { }  // TODO

/// @brief Constructeur de la classe Serie avec des paramètres.
/// @param titre Le titre de la série.
/// @param anneeDeSortie L'année de sortie de la série.
/// @param categorie La catégorie de la série.
/// @param episodes Un vecteur de paires (numéro d'épisode, durée) représentant les épisodes de la série.
Serie::Serie(string titre, int anneeDeSortie, Categorie categorie, vector<pair<int, int>> episodes) 
	: Media(titre,anneeDeSortie,categorie) , episodes_(episodes) { }  // TODO

// Getters

/// @brief Obtient le nombre d'épisodes de la série.
/// @return Le nombre d'épisodes de la série.
int Serie::getNbEpisodes() const { return static_cast<int>(episodes_.size()); }  // TODO

/// @brief Obtient l'épisode actuellement visionné.
/// @return Une paire (numéro d'épisode, temps visionné) représentant l'épisode actuel.
pair<int, int> Serie::getEpisodeActuel() const { return episodeActuel_; }  // TODO

// Setter
/// @brief Définit l'épisode actuellement visionné.
/// @param numeroEpisode Le numéro de l'épisode.
/// @param tempsVisionne Le temps visionné de l'épisode.
void Serie::setEpisodeActuel(int numeroEpisode, int tempsVisionne) {
	episodeActuel_ = { numeroEpisode, tempsVisionne };
}  // TODO

/// @brief Ajoute un épisode à la série.
/// @param numeroEpisode Le numéro de l'épisode à ajouter.
/// @param duree La durée de l'épisode à ajouter.
void Serie::ajouterEpisode(int numeroEpisode, int duree) {
	episodes_.push_back(make_pair(numeroEpisode, duree));
}  // TODO

/// @brief Calcule la progression de la lecture de la série.
/// @return Une chaîne de caractères représentant la progression de lecture.
string Serie::progression() const { 
	int dureeTotal = 0;
	for (auto& episode : episodes_) {
		if (episodeActuel_.first == episode.first) {
			dureeTotal = episode.second;
		}
	}
	
	return "Episode " + to_string(episodeActuel_.first) + ": Temps ecoule " +
		to_string(episodeActuel_.second) + "/" + to_string(dureeTotal) + " minutes";
}  // TODO

/// @brief Affiche les informations de la série.
/// @param os Le flux de sortie où afficher les informations.
void Serie::afficher(ostream& os) const {

	Media::afficher(os);
	cout << "Nombre d'episodes: " << episodes_.size() << "\n";
}  // TODO