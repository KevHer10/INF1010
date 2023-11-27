/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez 
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"
#include <algorithm>

string SEPARATEUR = "======================================================================================\n";

// Constructeur

/// @brief Constructeur par défaut de la classe Polyflix.
Polyflix::Polyflix() {}

// Copy Constructor

/// @brief Constructeur par copie de la classe Polyflix
/// @param poyflix variable de type Polyflix avec tout l'information necessaire
Polyflix::Polyflix(const Polyflix& poyflix) : utilisateurs_(poyflix.utilisateurs_) {
	for (const auto& film : poyflix.films_) {
		films_.push_back(make_unique<Film>(*film));
	}
} // TODO

// Méthodes pour la recherche

/// @brief retourne le film selon le titre reçu par paramètre s’il existe.
/// @param titre: Titre du film.   
/// @return retourne un Pointeur de type Film. 
Film* Polyflix::chercherFilmParTitre(const string& titre) const { 
	Film* filmParTitre;

	for (auto& film : films_) {
		if (film->getTitre() == titre)
			return filmParTitre = film.get();
	}
	return nullptr;
}		// TODO

/// @brief Cherche l'utilisateur par son nom s'il existe
/// @param nomUtilisateur nom de l'utilisateur 
/// @return pointeur de l'utilisateur si trouvé
Utilisateur* Polyflix::chercherUtilisateur(const string& nomUtilisateur) { 
	
	
	for (auto& utilisateur : utilisateurs_) {
		if (utilisateur.getNomUtilisateur() == nomUtilisateur)
			return &utilisateur;
	}

	return nullptr;

}	// TODO

// Méthodes liées aux utilisateurs

/// @brief Retourne le nombre total d'utilisateurs
/// @return nombre total d'utilisateurs
int Polyflix::getNombreUtilisateurs() const { return (int) utilisateurs_.size(); }

/// @brief Verifie si l'utilisateur existe avec son nom d'utilisateur 
/// @param nomUtilisateur nom de l'utilisateur
/// @return retourne true si l'utilisateur existe, retourne false sinon
bool Polyflix::utilisateurExiste(const string& nomUtilisateur) { 
	
	if (chercherUtilisateur(nomUtilisateur) != nullptr)
		return true;

	return false;
}					// TODO

/// @brief Verifie la connexion de l'utilisatues grace au nom d'utilisateur et mot de passe passes en parametre
/// @param nomUtilisateur nom de l'utilisateur
/// @param motDePasse mot de passe de l'utilisateur 
/// @return true si la verification a reussie false sinon
bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) { 
	
	if (utilisateurExiste(nomUtilisateur) == true)
		return chercherUtilisateur(nomUtilisateur)->verifierConnexion(motDePasse);
	
	return false;
}		// TODO

/// @brief Modifie le mot de passe de l'utilisateur si celui-ci existe
/// @param nomUtilisateur nom de l'utilisateur
/// @param motDePasse nouveau mot de passe de l'utilisateur 
/// @return true ou false
bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) { 
	
	if (utilisateurExiste(nomUtilisateur) == true) {
		chercherUtilisateur(nomUtilisateur)->setMotDePasse(motDePasse);
		return true;
	}
	
	return false;
}		// TODO

/// @brief Le film passe en parametre est ajoute au vecteur de films vus de l'utilisateur
/// @param nomUtilisateur nom de l'utilisateur
/// @param titreFilm titre du film visionne
/// @return true ou false
bool Polyflix::visionnerFilm(string nomUtilisateur, string titreFilm) {

	if (chercherUtilisateur(nomUtilisateur) != nullptr && chercherFilmParTitre(titreFilm) != nullptr)
	{

		chercherUtilisateur(nomUtilisateur)->ajouterFilm(make_shared<Film>(*chercherFilmParTitre(titreFilm)));
		return true;

	}


	return false;
}				// TODO

// Méthodes pour obtenir des statistiques

/// @brief Retourne le nombre total de films dans polyflix
/// @return nombre total de films dans polyflix
int Polyflix::getNombreTotalFilms() const { return (int) films_.size(); }

/// @brief Calcule le nombre de film de la meme categorie passee en parametre
/// @param categorie Categorie du film
/// @return nombre de film de la meme categorie 
int Polyflix::getNombreFilmsParCategorie(Categorie categorie) const { 
	
	int nombreFilms = 0;
	for (auto& film : films_)
		if (film->getCategorie() == categorie)
			nombreFilms++;
	return nombreFilms;
}						// TODO

/// @brief Calcule le nombre de films visionnes par tous les usagers
/// @return nombre total de films visionnes par tous les usagers 
int Polyflix::getNombreTotalFilmsVisionnes() const { 
	
	size_t filmVisionnes = 0;
	for (auto& utilisateur : utilisateurs_) {
		filmVisionnes += utilisateur.getFilmsVus().size();

	}
	
	return static_cast<int>(filmVisionnes);
}										// TODO

/// @brief Retourne le nombre d'utilisateurs ayant ecoute le meme film
/// @param titreFilm titre du film
/// @return nombre d'utilisateurs ayant ecoute le meme film
int Polyflix::getNombreUtilisateursAyantVisionne(const string& titreFilm) const { 
	int nbrUtilisateurs = 0;
	for (auto& utilisateur : utilisateurs_) {
		for (auto& film : utilisateur.getFilmsVus())
			if (film->getTitre() == titreFilm)
				nbrUtilisateurs++;
	}
	return nbrUtilisateurs;
}			// TODO

/// @brief retourne le film ayant obtenu la plus grande note.
/// @return Pointeur unique du type Film 
unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusHauteNote() const { 
	
	unique_ptr<Film> filmNote;
	float noteMoyenne = 0;
	for (auto& film : films_)
		if (film->obtenirNoteMoyenne() > noteMoyenne) {
			noteMoyenne = film->obtenirNoteMoyenne();
			filmNote = make_unique<Film> (*film);
		}

	return filmNote;
}								// TODO

/// @brief retourne le film ayant obtenu la plus petite note.
/// @return Pointeur unique du type Film 
unique_ptr<Film> Polyflix::obtenirFilmAvecLaPlusBasseNote() const { 
	
	unique_ptr<Film> filmNote;
	float noteMoyenne = 5.0;
	for (auto& film : films_)
		if (film->obtenirNoteMoyenne() < noteMoyenne) {
			noteMoyenne = film->obtenirNoteMoyenne();
			filmNote = make_unique<Film>(*film);
		}
	
	return filmNote;
}								// TODO

/// @brief retourne le film le plus récent. On suppose qu’il 
/// n’existe pas deux films ayant la même date de sortie.
/// @return Pointeur unique du type Film
unique_ptr<Film> Polyflix::obtenirFilmPlusRecent() const { 
	
	unique_ptr<Film> filmPlusRencent;
	int anneDeSortie = 0;
	for (auto& film : films_)
		if (film->getAnneeDeSortie() > anneDeSortie) {
			anneDeSortie = film->getAnneeDeSortie();
			filmPlusRencent = make_unique<Film>(*film);
		}

	return filmPlusRencent;
}										// TODO

/// @brief retourne un vecteur de films de la catégorie passée en paramètre.
/// @param categorie: la catégorie du film. 
/// @return retourne un vecteur de type vector<unique_ptr<Film>>.  
vector<unique_ptr<Film>> Polyflix::listerFilmsParCategorie(Categorie categorie) const { 
	vector<unique_ptr<Film>> vecFilmsParCategorie;

	for (auto& film : films_)
		if (film->getCategorie() == categorie)
			vecFilmsParCategorie.push_back(make_unique<Film>(*film));

	return vecFilmsParCategorie;
}				// TODO

/// @brief Cree un vecteur avec les films que l'utilisateur passe en parametre a visionnes 
/// @param nomUtilisateur nom de l'utilisateur 
/// @return vecteur de type vector<shared_ptr<Film>> 
vector<shared_ptr<Film>> Polyflix::listerFilmsVisionnesParUtilisateur(const string& nomUtilisateur) { 
	vector<shared_ptr<Film>> vecFilmsVisionnesParUtilisateur;

	if (utilisateurExiste(nomUtilisateur) == true) {
		Utilisateur* utilisateurFilmsVus = chercherUtilisateur(nomUtilisateur);
		for (auto& utilisateur : utilisateurFilmsVus->getFilmsVus())
			vecFilmsVisionnesParUtilisateur.push_back(make_shared<Film>(*utilisateur));

	}
	return vecFilmsVisionnesParUtilisateur;
}	// TODO

// Opérateurs

/// @brief Ajoute un utilisateur au vecteur d'utilisateurs_
/// @param utilisateur variable de type Utilisateur contenant l'information de l'utilisateur 
/// @return true ou false
bool Polyflix::operator+=(Utilisateur utilisateur) { 
	if (utilisateurExiste(utilisateur.getNomUtilisateur()) == false) {
		utilisateurs_.push_back(utilisateur);
		return true;
	}

	return false;
}	// TODO

/// @brief permet d’ajouter le film dont les attributs sont reçus en paramètre 
/// s’il n’existe pas dans le vector.
/// @param film objet de type Film contenant toute l'information necessaire.
/// @return true ou false 
bool Polyflix::operator+=(Film* film) { 

	if (chercherFilmParTitre(film->getTitre()) == nullptr)
	{
		films_.emplace_back(film);

		return true;
	}

	return false;

}			// TODO

/// @brief retirer le film s’il existe en utilisant son titre reçu en paramètre.
/// @param titre: Titre du film. 
/// @return true ou false 
bool Polyflix::operator-=(string titre) { 
	
	
	if (chercherFilmParTitre(titre) != nullptr)
	{
		for (auto& film : films_) {
			if (film->getTitre() == titre) {
				film = move(films_.back());
				films_.pop_back();
				return true;
			}
		}
	}
	return false;
	
}		// TODO

/// @brief  Retourne le film selon le titre reçu par paramètre s’il existe
/// @param titre: Titre du film.
/// @return Pointeur contenant le film.
Film* Polyflix::operator[](string titre) { 
	
	if (chercherFilmParTitre(titre) != nullptr)
	{
		return chercherFilmParTitre(titre);
	}
	return nullptr;
}	// TODO

// Méthodes pour l'affichage

/// @brief affiche les films .
/// @param os extraction operator 
/// @param polyflix variable de type Polyflix contenant toute l'information de l'objet 
/// @return affichage de l'objet
ostream& operator<<(ostream& os, const Polyflix& polyflix) { 
	
	os << SEPARATEUR;
	os << "Polyflix vous presente les films suivants:" << "\n";
	os << SEPARATEUR;

	for (auto& film : polyflix.films_) {
		os << *film;
		os << SEPARATEUR;
	}

	return os;
} // TODO
