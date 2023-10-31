/*
Fichier: Serie.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Serie.
*/
#include "Serie.h"

// Constructeurs
/// @brief Constructeur par d�faut de la classe Serie.
Serie::Serie(): Media() { }  // TODO

/// @brief Constructeur de la classe Serie avec des param�tres.
/// @param titre Le titre de la s�rie.
/// @param anneeDeSortie L'ann�e de sortie de la s�rie.
/// @param categorie La cat�gorie de la s�rie.
/// @param episodes Un vecteur de paires (num�ro d'�pisode, dur�e) repr�sentant les �pisodes de la s�rie.
Serie::Serie(string titre, int anneeDeSortie, Categorie categorie, vector<pair<int, int>> episodes) 
	: Media(titre,anneeDeSortie,categorie) , episodes_(episodes) { }  // TODO

// Getters

/// @brief Obtient le nombre d'�pisodes de la s�rie.
/// @return Le nombre d'�pisodes de la s�rie.
int Serie::getNbEpisodes() const { return static_cast<int>(episodes_.size()); }  // TODO

/// @brief Obtient l'�pisode actuellement visionn�.
/// @return Une paire (num�ro d'�pisode, temps visionn�) repr�sentant l'�pisode actuel.
pair<int, int> Serie::getEpisodeActuel() const { return episodeActuel_; }  // TODO

// Setter
/// @brief D�finit l'�pisode actuellement visionn�.
/// @param numeroEpisode Le num�ro de l'�pisode.
/// @param tempsVisionne Le temps visionn� de l'�pisode.
void Serie::setEpisodeActuel(int numeroEpisode, int tempsVisionne) {
	episodeActuel_ = { numeroEpisode, tempsVisionne };
}  // TODO

/// @brief Ajoute un �pisode � la s�rie.
/// @param numeroEpisode Le num�ro de l'�pisode � ajouter.
/// @param duree La dur�e de l'�pisode � ajouter.
void Serie::ajouterEpisode(int numeroEpisode, int duree) {
	episodes_.push_back(make_pair(numeroEpisode, duree));
}  // TODO

/// @brief Calcule la progression de la lecture de la s�rie.
/// @return Une cha�ne de caract�res repr�sentant la progression de lecture.
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

/// @brief Affiche les informations de la s�rie.
/// @param os Le flux de sortie o� afficher les informations.
void Serie::afficher(ostream& os) const {

	Media::afficher(os);
	cout << "Nombre d'episodes: " << episodes_.size() << "\n";
}  // TODO