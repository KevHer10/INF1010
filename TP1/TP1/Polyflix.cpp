/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"

string SEPARATEUR = "======================================================================================\n";

// TODO: Implémenter les méthodes de la classe Polyflix ici.

// Constructeurs et destructeur

/// @brief Constructeur par défaut de la classe Polyflix.
Polyflix::Polyflix() : Polyflix("","") {
}
/// @brief Constructeur par paramètres de la classe Polyflix. 
/// @param nomUtilisateur :Nom de l'utilisateur. 
/// @param motDePasse: Mot de passe de l'utilisateur.
Polyflix::Polyflix(string nomUtilisateur, string motDePasse) : utilisateur_(nomUtilisateur), motDePasse_(motDePasse) {}

/// @brief Un destructeur qui supprime tous les films. 
Polyflix::~Polyflix() {
	for (auto&& film : films_) {
		delete film;
		film = nullptr; 
	}

	films_.clear();
}

// getters

/// @brief Retourne Nom de l'utilisateur. 
/// @return Nom de l'utilisateur.
string Polyflix::getUtilisateur() const { return utilisateur_; }

// setters

/// @brief Modifie le nom de l'utilisateur.
/// @param utilisateur: nom de l'utilisateur.  
void Polyflix::setUtilisateur(string utilisateur) { utilisateur_ = utilisateur; }

/// @brief Modifie le mot de passe de l'utilisateur.
/// @param motDePasse mot de passe de l'utilisateur.
void Polyflix::setMotDePasse(string motDePasse) { motDePasse_ = motDePasse; }

// Méthodes pour la connexion

/// @brief vérifie le nom et le mot de passe de l’utilisateur.
/// @param utilisateur: le nom de l’utilisateur. 
/// @param motDePasse: le mot de passe de l’utilisateur.
/// @return true ou false
bool Polyflix::connecter(string utilisateur, string motDePasse) { 
	if (utilisateur_ == utilisateur && motDePasse_ == motDePasse)
	{
		return true;
	}
	return false;
} 

// Méthodes pour gérer les films

/// @brief permet d’ajouter le film dont les attributs sont reçus en paramètre 
/// s’il n’existe pas dans le vector.
/// @param titre: Titre du film. 
/// @param anneeDeSortie:  l’année de sortie du film.  
/// @param realisateur: le réalisateur du film. 
/// @param categorie: la catégorie du film. 
/// @param duree : la durée du film 
/// @return true ou false 
bool Polyflix::ajouterFilm(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) { 
	if (chercherFilmParTitre(titre) == nullptr) {
		films_.push_back(new Film(titre, anneeDeSortie, realisateur,categorie,duree));
		return true;
	}
	
	return false;
}
/// @brief retirer le film s’il existe en utilisant son titre et son année de sortie reçus 
/// en paramètre.
/// @param titre: Titre du film. 
/// @param anneeDeSortie:  l’année de sortie du film. 
/// @return true ou false 
bool Polyflix::retirerFilm(string titre, int anneeDeSortie) { 
	
	for (auto&& film : films_) {
		if (film->getTitre() == titre && film->getAnneeDeSortie() == anneeDeSortie)
			film = films_.back();
		films_.pop_back();
		return true;
	}
		
	return false;
}

// Méthodes pour la recherche

/// @brief retourne le film selon le titre reçu par paramètre s’il existe.
/// @param titre: Titre du film.   
/// @return retourne un Pointeur de type Film. 
Film* Polyflix::chercherFilmParTitre(const string& titre) const { 
	
	for (auto&& film : films_) {
		if (film->getTitre() == titre)
			return film;
	}
	return nullptr;

}

/// @brief retourne un vecteur de films de la catégorie passée en paramètre.
/// @param categorie: la catégorie du film. 
/// @return retourne un vecteur de type Film*.   
vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { 
	vector<Film*> vecFilmParCategorie;
	for (auto&& film : films_)
		if (film->getCategorie() == categorie)
			vecFilmParCategorie.push_back(film);


	return {vecFilmParCategorie}; 

}

// Méthodes pour obtenir des statistiques

/// @brief retourne le nombre de films.
/// @return Nombre total de films
int Polyflix::getNombreTotalFilms() const { return films_.size(); }

/// @brief retourne le nombre de films de la catégorie.
/// @param categorie: la catégorie du film.
/// @return Nombre de films par categorie. 
int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { 
	unsigned int compteur = 0;
	for (auto&& film : films_)
		if (film->getCategorie() == categorie)
			compteur++;
	
	return compteur; 
}
/// @brief retourne le film ayant obtenu la plus grande note.
/// @return Pointeur du type Film 
Film* Polyflix::obtenirFilmAvecLaPlusHauteNote() const { 
	int notePlusHaute = 0;
	Film* FilmAvecLaPlusHauteNote = nullptr;
	for (auto&& film : films_) {
		if (film->obtenirNoteMoyenne() > notePlusHaute){
			notePlusHaute = film->obtenirNoteMoyenne();
			FilmAvecLaPlusHauteNote = film;
		}
	}

	return FilmAvecLaPlusHauteNote;
}
/// @brief retourne le film ayant obtenu la plus petite note.
/// @return Pointeur du type Film 
Film* Polyflix::obtenirFilmAvecLaPlusBasseNote() const { 
	
	int notePlusBasse = 10;
	Film* FilmAvecLaPlusBasseNote = nullptr;
	for (auto&& film : films_) {
		if (film->obtenirNoteMoyenne() < notePlusBasse) {
			notePlusBasse = film->obtenirNoteMoyenne();
			FilmAvecLaPlusBasseNote = film;
		}
	}

	return FilmAvecLaPlusBasseNote;
}

/// @brief retourne le film le plus récent. On suppose qu’il 
/// n’existe pas deux films ayant la même date de sortie.
/// @return Pointeur du type Film
Film* Polyflix::obtenirFilmPlusRecent() const { 
	int anneDeSortie = 0;
	Film* FilmPlusRecent = nullptr;
	for (auto&& film : films_) {
		if (film->getAnneeDeSortie() > anneDeSortie) {
			anneDeSortie = film->getAnneeDeSortie();
			FilmPlusRecent = film;
		}
	}

	return FilmPlusRecent;
	
}

// Méthodes pour l'affichage

/// @brief affiche toutes les informations concernant les films.
void Polyflix::afficherListeFilms() const {

	cout << "Polyflix vous presente les films suivants:" << "\n";
	cout << SEPARATEUR;

	for (auto&& film : films_) {
		film->afficher();
		cout << SEPARATEUR;
	}
	

}
/// @brief affiche les films correspondant à la catégorie reçu en paramètre.
/// @param categorie: la catégorie du film. 
void Polyflix::afficherFilmsParCategorie(Categorie categorie) const {
	vector<Film*> vecFilmParCategorie = listerFilmsParCategorie(categorie);


	cout << "Pour la categorie selectionne, Polyflix vous presente les films suivants:" << "\n";
	cout << SEPARATEUR;

	for (auto&& film : vecFilmParCategorie) {
		film->afficher();
		cout << SEPARATEUR;
	}


}