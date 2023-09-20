#include "Polyflix.h"

string SEPARATEUR = "======================================================================================\n";

// TODO: Impl�menter les m�thodes de la classe Polyflix ici.

// Constructeurs et destructeur
Polyflix::Polyflix() : Polyflix("","") {
}

Polyflix::Polyflix(string nomUtilisateur, string motDePasse) : utilisateur_(nomUtilisateur), motDePasse_(motDePasse) {}

Polyflix::~Polyflix() {}

// getters
string Polyflix::getUtilisateur() const { return utilisateur_; }

// setters
void Polyflix::setUtilisateur(string utilisateur) { utilisateur_ = utilisateur; }

void Polyflix::setMotDePasse(string motDePasse) { motDePasse_ = motDePasse; }

// M�thodes pour la connexion
bool Polyflix::connecter(string utilisateur, string motDePasse) { 
	return false; 
} //je vois pas l'utilisation de cette methode.

// M�thodes pour g�rer les films
bool Polyflix::ajouterFilm(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree) { 
	films_.push_back(new Film(titre, anneeDeSortie, realisateur,categorie,duree));

	
	return true;
}

bool Polyflix::retirerFilm(string titre, int anneeDeSortie) { 
	
	for (auto&& film : films_) {
		if (film->getTitre() == titre && film->getAnneeDeSortie() == anneeDeSortie)
			film = films_.back();
		films_.pop_back();
		return true;
	}
		
	return false;
}

// M�thodes pour la recherche
Film* Polyflix::chercherFilmParTitre(const string& titre) const { 
	
	for (auto&& film : films_) {
		if (film->getTitre() == titre)
			return film;
	}
	return nullptr;

}

vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { 
	vector<Film*> vecFilmParCategorie;
	for (auto&& film : films_)
		if (film->getCategorie() == categorie)
			vecFilmParCategorie.push_back(film);


	return {vecFilmParCategorie}; 

}

// M�thodes pour obtenir des statistiques
int Polyflix::getNombreTotalFilms() const { return films_.size(); }

int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { 
	unsigned int compteur = 0;
	for (auto&& film : films_)
		if (film->getCategorie() == categorie)
			compteur++;
	
	return compteur; 
}

Film* Polyflix::obtenirFilmAvecLaPlusHauteNote() const { 
	
	
	return nullptr; }

Film* Polyflix::obtenirFilmAvecLaPlusBasseNote() const { return nullptr; }

Film* Polyflix::obtenirFilmPlusRecent() const { return nullptr; }

// M�thodes pour l'affichage
void Polyflix::afficherListeFilms() const { }

void Polyflix::afficherFilmsParCategorie(Categorie categorie) const { }