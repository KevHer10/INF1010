#include "Polyflix.h"

string SEPARATEUR = "======================================================================================\n";

// TODO: Implémenter les méthodes de la classe Polyflix ici.

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

// Méthodes pour la connexion
bool Polyflix::connecter(string utilisateur, string motDePasse) { 
	return false; 
} //je vois pas l'utilisation de cette methode.

// Méthodes pour gérer les films
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

// Méthodes pour la recherche
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

// Méthodes pour obtenir des statistiques
int Polyflix::getNombreTotalFilms() const { return films_.size(); }

int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { 
	unsigned int compteur = 0;
	for (auto&& film : films_)
		if (film->getCategorie() == categorie)
			compteur++;
	
	return compteur; 
}

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
void Polyflix::afficherListeFilms() const {

	cout << "Polyflix vous presente les films suivants:" << "\n";
	cout << SEPARATEUR;

	for (auto&& film : films_) {
		film->afficher();
		cout << SEPARATEUR;
	}
	

}

void Polyflix::afficherFilmsParCategorie(Categorie categorie) const {
	vector<Film*> vecFilmParCategorie = listerFilmsParCategorie(categorie);


	cout << "Pour la categorie selectionne, Polyflix vous presente les films suivants:" << "\n";
	cout << SEPARATEUR;

	for (auto&& film : vecFilmParCategorie) {
		film->afficher();
		cout << SEPARATEUR;
	}


}