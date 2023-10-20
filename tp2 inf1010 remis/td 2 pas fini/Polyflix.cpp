#include "Polyflix.h"
#include <algorithm>

string SEPARATEUR = "======================================================================================\n";

// Constructeur
Polyflix::Polyflix() {}

// Copy Constructor
Polyflix::Polyflix(const Polyflix& poyflix) 
{


	for (const auto& film : poyflix.films_)
	{
		films_.push_back(make_unique <Film>(*film));

	}

	utilisateurs_ = poyflix.utilisateurs_;
	

} // TODO

// Méthodes pour la recherche
Film* Polyflix::chercherFilmParTitre(const string& titre) const { 
	for (const auto& film : films_) 
	{
		if (film->getTitre() == titre) 
		{
			return film.get();
		}

	}

	return nullptr;
}		// TODO

Utilisateur* Polyflix::chercherUtilisateur(const string& nomUtilisateur) {
	
	for (auto& utilisateur : utilisateurs_)
	{
		if (utilisateur.getNomUtilisateur() == nomUtilisateur)
		{
			return &utilisateur;
		}

	}
	
	return nullptr; 
}


// TODO

// Méthodes liées aux utilisateurs
int Polyflix::getNombreUtilisateurs() const { return (int) utilisateurs_.size(); }

bool Polyflix::utilisateurExiste(const string& nomUtilisateur) 
{ 
	for (const auto& utilisateur : utilisateurs_) 
	{
		if (utilisateur.getNomUtilisateur() == nomUtilisateur) 
		{
			
			return true;
		}
	}
	return false;
}					// TODO

bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) 
{ 
	Utilisateur* utilisateur = chercherUtilisateur(nomUtilisateur);
	if (utilisateurExiste(nomUtilisateur)) 
	{
	
		
		if (utilisateur->verifierConnexion(motDePasse)) 
		{
			return true;
		}

	}

	return false; 

}		// TODO

bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) 
{ 
		Utilisateur* utilisateur = chercherUtilisateur(nomUtilisateur);
		utilisateur->setMotDePasse(motDePasse);
		return true;

			if (utilisateur == nullptr) 
			{
				return false;
			}
	
	
}		// TODO

bool Polyflix::visionnerFilm(string nomUtilisateur, string titreFilm) 
{ 
	Utilisateur* utilisateur = chercherUtilisateur(nomUtilisateur);
	Film* film = chercherFilmParTitre(titreFilm);
	if (utilisateur != nullptr && film != nullptr) 
	{

		utilisateur->ajouterFilm(make_shared<Film>(*film));
		return true;

	}
	
	
	
	return false; 
}				// TODO

// Méthodes pour obtenir des statistiques
int Polyflix::getNombreTotalFilms() const { return (int) films_.size(); }

int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const 
{
	int nombredefilm = 0;
	for (const unique_ptr<Film>& films : films_) 
	{
		if (films->getCategorie() == categorie)
		{
			nombredefilm++;
		}

	}
	
	
	return nombredefilm;
}						// TODO

int Polyflix::getNombreTotalFilmsVisionnes() const {
	
	int nombretotaleVi = 0;
	
	for (const Utilisateur& utilisateur : utilisateurs_) 
	{
		
		nombretotaleVi += utilisateur.getFilmsVus().size();

	}
	
	return nombretotaleVi;


}										// TODO

int Polyflix::getNombreUtilisateursAyantVisionne(const string& titreFilm) const 
{
	int NombreUtilisateursAyantVisionne = 0;
	for (const Utilisateur& utilisateurs : utilisateurs_) {
		
		for (auto& film : utilisateurs.getFilmsVus()) 
		{
			if (film->getTitre() == titreFilm) 
			{
				NombreUtilisateursAyantVisionne++;
			}

		}

	}
	
	return NombreUtilisateursAyantVisionne;
}			// TODO

unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusHauteNote() const 
{
	const Film* filmAvecLaPlusHauteNote = films_[0].get();
	for (const unique_ptr<Film>& films : films_)
	{
		if (films->obtenirNoteMoyenne() > filmAvecLaPlusHauteNote->obtenirNoteMoyenne())
		{
			filmAvecLaPlusHauteNote = films.get();
		}

	}


	return make_unique<Film>(*filmAvecLaPlusHauteNote);

}								// TODO

unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusBasseNote() const { 
	
	
	const Film* filmAvecLaPlusBasseNote = films_[0].get();
	for (const unique_ptr<Film>& films : films_)
	{
		if (films->obtenirNoteMoyenne() > filmAvecLaPlusBasseNote->obtenirNoteMoyenne())
		{
			filmAvecLaPlusBasseNote = films.get();
		}

	}


	return make_unique<Film>(*filmAvecLaPlusBasseNote);



}								// TODO

unique_ptr<Film> Polyflix::obtenirFilmPlusRecent() const 
{ 
	const Film* filmPlusRecent = films_[0].get();
	for (const unique_ptr<Film>& films : films_)
	{
		if (films->getAnneeDeSortie() > filmPlusRecent->getAnneeDeSortie())
		{
			filmPlusRecent = films.get();
		}

	}
	return make_unique<Film>(*filmPlusRecent);
	
	
}										// TODO

vector<unique_ptr<Film>> Polyflix::listerFilmsParCategorie(Categorie categorie) const 
{
	vector<unique_ptr<Film>> filmsParCategorie;
	for (const unique_ptr<Film>& films : films_) 
	{
		if (films->getCategorie() == categorie) 
		{
			filmsParCategorie.push_back(make_unique<Film>(*films));
		}
	}
	
	
	return filmsParCategorie;
}				// TODO

vector<shared_ptr<Film>> Polyflix::listerFilmsVisionnesParUtilisateur(const string& nomUtilisateur) 
{
	vector<shared_ptr<Film>> filmsVisionnesParUtilisateur;
	Utilisateur* utilisateur = chercherUtilisateur(nomUtilisateur);
	if (utilisateur) 
	{
		

		for (auto& films : utilisateur->getFilmsVus()) 
		{
			filmsVisionnesParUtilisateur.push_back(make_shared<Film>(*films));
		}




	}


	return filmsVisionnesParUtilisateur;

}	// TODO

// Opérateurs
bool Polyflix::operator+=(Utilisateur utilisateur) 
{
	if (!utilisateurExiste(utilisateur.getNomUtilisateur())) 
	{
		utilisateurs_.push_back(utilisateur);

		return true;
	}

	return false;
}	// TODO

bool Polyflix::operator+=(Film* film) 
{ 
	const string titreFilm = film->getTitre();

	if (!chercherFilmParTitre(titreFilm))
	{
		films_.emplace_back(film);

		return true;
	}
	
	return false;
}			// TODO

bool Polyflix::operator-=(string titre) { 
	
	for (auto& films : films_)
	{
		if (films->getTitre() ==titre)
		{
			films = move(films_.back());
			films_.pop_back();
			return true;

		}


	}
	
	return false; 
}		// TODO

Film* Polyflix::operator[](string titre)
{
	for (const unique_ptr<Film>& films : films_) 
	{
		if (films->getTitre() == titre) 
		{
			return films.get();
		}
	}
	
	return nullptr; 
}	// TODO

// Méthodes pour l'affichage
ostream& operator<<(ostream& os, const Polyflix& polyflix) { 
	
	os << SEPARATEUR;
	os << "Polyflix vous presente les films suivants:" << endl;
	os << SEPARATEUR ;
	for (const unique_ptr<Film>& films : polyflix.films_) 
	{
		os << *films ;
		os << SEPARATEUR;
	}

	return os;


} // TODO
