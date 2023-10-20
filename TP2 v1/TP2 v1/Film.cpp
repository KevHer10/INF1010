/*
Fichier: Film.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez 
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: Implementation de la classe Film.
*/
#include "Film.h"
#include <iostream>
#include <iomanip>

// Constructeurs

/// @brief Constructeur par défaut de la classe Film.
Film::Film() : titre_(""), anneeDeSortie_(0), realisateur_(""), categorie_(Categorie::ACTION), duree_(0) {}

/// @brief Constructeur par paramètres de la classe Film.
/// @param titre: Titre du film. 
/// @param anneeDeSortie:  l’année de sortie du film. 
/// @param realisateur: le réalisateur du film.
/// @param categorie: la catégorie du film.
/// @param duree: la durée du film
Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree)
	: titre_(titre), anneeDeSortie_(anneeDeSortie), realisateur_(realisateur), categorie_(categorie), duree_(duree) {}

/// @brief Constructeur par copie de la classe Film
/// @param film variable de type Film avec tout l'information necessaire
Film::Film(const Film& film) {
	titre_ = film.titre_;
	anneeDeSortie_ = film.anneeDeSortie_;
	realisateur_ = film.realisateur_;
	categorie_ = film.categorie_;
	duree_ = film.duree_;
	acteurs_ = film.acteurs_;
	for (const auto& critique : film.critiques_)
		critiques_.push_back(make_unique<Critique> (*critique));
}


/// @brief definition de la surcharge de l'operateur = qui copie un obejet de type Film dans une autre abjet du meme type
/// @param acteur variable de type Film avec tout l'information necessaire
/// @return un objet de type Film
Film& Film::operator=(const Film& film) { 
	if (this != &film) {

		this->Film::Film(film);
	}
	
	
	return *this;
}	// TODO

// Getters

/// @brief Retourne le titre du film.
/// @return Titre du film.
string Film::getTitre() const { return titre_; }

/// @brief Retourne le réalisateur du film.
/// @return réalisateur du film.
string Film::getRealisateur() const { return realisateur_; }

/// @brief Retourne l’année de sortie du film. 
/// @return l’année de sortie du film. 
int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

/// @brief Retourne la catégorie du film. 
/// @return la catégorie du film.
Categorie Film::getCategorie() const { return categorie_; }

/// @brief Retourne la durée du film.
/// @return la durée du film.
int Film::getDuree() const { return duree_; }

/// @brief Retourne un vecteur vector<shared_ptr<Acteur>>
/// @return vecteur d'Acteurs
vector<shared_ptr<Acteur>> Film::getActeurs() const { return {acteurs_}; }	// TODO

/// @brief Retourne un vecteur de pointeurs uniques du type Critique
/// @return vecteur de Critiques
vector<unique_ptr<Critique>> Film::getCritiques() const { 
	
	vector<unique_ptr<Critique>> setCritiques;
	for (const auto& critique : critiques_) {
		setCritiques.push_back(make_unique <Critique>(*critique));
	}
	return setCritiques;
	
}			// TODO

/// @brief Retourne le nombre d'acterus presents dans le vecteur d'Acteurs 
/// @return nombre d'acteurs
int Film::getNbActeurs() const { return (int) acteurs_.size(); }

/// @brief Retourne le nombre de critique presents dans le vecteur de Critiques 
/// @return nombre de Critiques
int Film::getNbCritiques() const { return (int) critiques_.size(); }

// Setters

/// @brief Modifie le Titre du film. 
/// @param titre: Titre du film.  
void Film::setTitre(string titre) { this->titre_ = titre; }

/// @brief Modifie le réalisateur du film.
/// @param realisateur: le réalisateur du film. 
void Film::setRealisateur(string realisateur) { this->realisateur_ = realisateur; }

/// @brief Modifie l’année de sortie du film. 
/// @param anneeDeSortie: l’année de sortie du film. 
void Film::setAnneeDeSortie(int anneeDeSortie) { this->anneeDeSortie_ = anneeDeSortie; }

/// @brief Modifie la catégorie du film.
/// @param categorie: la catégorie du film. 
void Film::setCategorie(Categorie categorie) { this->categorie_ = categorie; }

/// @brief Modifie la durée du film 
/// @param duree: la durée du film 
void Film::setDuree(int duree) { this->duree_ = duree; }

/// @brief Modifie les acteurs qui sont dans le vecteur.
/// @param acteurs: Vecteur d'acteurs  
void Film::setActeurs(vector<shared_ptr<Acteur>> acteurs) { this->acteurs_ = acteurs; }

/// @brief Modifie les critiques qui sont dans le vecteur.
/// @param critiquesVec: Vecteur de critiques 
void Film::setCritiques(vector<Critique*> critiquesVec) {

	critiques_.clear();
	for (auto& critiques : critiquesVec)
		critiques_.push_back(make_unique <Critique>(*critiques));


}					// TODO

// Méthodes fonctionnelles

/// @brief vérifie si un acteur est présent dans le film en vérifiant son
/// nom. S’il est présent dans le film, on retourne son pointeur, sinon on retourne nullptr.
/// @param nom: nom de l'acteur. 
/// @return shared_ptr de type Acteur.
shared_ptr<Acteur> Film::trouverActeur(const string nom) const { 
	
	for (auto& acteur : acteurs_) {
		if (acteur->getNom() == nom)
			return acteur;
	}
	
	return nullptr; }		// TODO


/// @brief vérifie si une critique est présente dans le film en vérifiant l’auteur de la critique.
/// S’il est présent dans le film, on retourne son pointeur, sinon on retourne nullptr.
/// @param nom: Nom de l'auteur de la critique
/// @return unique_ptr de type Critique.
unique_ptr<Critique> Film::trouverCritique(const string nom) const { 
	
	for (auto& critque : critiques_) {
		if (critque->getAuteur() == nom)
			return make_unique<Critique> (*critque);
	}
	
	return nullptr;
}	// TODO

/// @brief vérifie si le nom de l’acteur est présent dans le film
/// @param nomActeur : nom de l'acteur. 
/// @return true ou false 
bool Film::isActeurPresent(string nomActeur) const { 
	
	return trouverActeur(nomActeur) != nullptr;

}		// TODO

/// @brief vérifie si l’auteur de la critique est présent dans le film
/// @param nomCritique: Nom de l'auteur de la critique. 
/// @return true ou false 
bool Film::isCritiquePresent(string nomCritique) const { 
	
	return trouverCritique(nomCritique) != nullptr;

}	// TODO

/// @brief retourne la moyenne des notes des critiques.
/// @return moyenne des notes des critiques.
float Film::obtenirNoteMoyenne() const { 
	float moyenne = 0.0;

	for (auto& critique : critiques_)
		moyenne += critique->getNote();

	moyenne = moyenne / critiques_.size();
	
	return moyenne; }						// TODO

// Opérateurs

/// @brief ajoute l’acteur dans le vector s’il n’existe pas. 
/// @param acteur variable de type Acteur avec tout l'information necessaire  
/// @return true ou false 
bool Film::operator+=(shared_ptr<Acteur>& acteur) {	
	if (isActeurPresent(acteur->getNom()) != true) {
		acteurs_.push_back(acteur);
		return true;
	}
	
	return false;
}	// TODO

/// @brief ajoute la critique dans le vector si elle n’existe pas.
/// @param critique variable de type Critique avec tout l'information necessaire   
/// @return true ou false 
bool Film::operator+=(Critique* critique) {

	if (isCritiquePresent(critique->getAuteur()) != true) {
		critiques_.push_back(make_unique<Critique>(*critique));
		return true;
	}
	return false;
}			// TODO

/// @brief definition de la surcharge de l'operateur == qui compare 2 objets de type Film pour savoir s'ils ont le meme contenu.
/// @param acteur variable de type Film avec tout l'information necessaire
/// @return true si les objets sont pareils et false sinon
bool Film::operator==(const Film& film) const {
	
	if (titre_ == film.titre_  
		&& anneeDeSortie_ == film.anneeDeSortie_ 
		&& realisateur_ == film.realisateur_ 
		&& categorie_ == film.categorie_ 
		&& duree_ == film.duree_ )
		return true;

	
	return false;
}		// TODO

/// @brief definition de la surcharge de l'operateur != qui compare 2 objets de type Film pour savoir s'ils n'ont pas le meme contenu.
/// @param acteur variable de type Film avec tout l'information necessaire
/// @return true si les objets ne sont pas pareils et false sinon
bool Film::operator!=(const Film& film) const { 
	
	if (titre_ != film.titre_
		|| anneeDeSortie_ != film.anneeDeSortie_
		|| realisateur_ != film.realisateur_
		|| categorie_ != film.categorie_
		|| duree_ != film.duree_)
		return true;

	return false;
}		// TODO

/// @brief retire l'acteur dans le vector s’ils existent.
/// @param acteur variable de type Acteur avec tout l'information necessaire 
/// @return true ou false
bool Film::operator-=(shared_ptr<Acteur>& acteur) {	
	
	if (isActeurPresent(acteur->getNom()) == true) {
		for (auto& acteurs : acteurs_) {
			if (acteurs->getNom() == acteur->getNom())
			{
				acteurs = acteurs_.back();
				acteurs_.pop_back();
				

			}
		}
		return true;
	}
	
	return false;
}	// TODO

/// @brief retire la critique dans le vector si elles existent.
/// @param critique variable de type Critique avec tout l'information necessaire 
/// @return true ou false 
bool Film::operator-=(Critique* critique) {	
	
	if (isCritiquePresent(critique->getAuteur()) == true) {
		for (auto& critiques : critiques_) {
			if (critiques->getCommentaire() == critique->getCommentaire()) {
				critiques = move(critiques_.back());
				critiques_.pop_back();
				return true;

			}
		}
	}
	
	return false; }			// TODO


// Méthode d'affichage



/// @brief Une méthode d’affichage des informations qui concernent un film tel que présenté dans la sortie
/// @param os extraction operator 
/// @param film variable de type Film contenant toute l'information de l'objet
/// @return affichage de l'objet
ostream& operator<<(ostream& os, const Film& film) { 
	
	

	os << film.titre_ << " (" << film.anneeDeSortie_ << ") " << "de " << film.realisateur_ << "\n";
	os << "Duree: " << film.duree_ << " minutes" << "\n";

	os << "Categorie: ";
	switch (film.categorie_)
	{
	case Categorie::ACTION: os << "Action\n";   break;
	case Categorie::COMEDIE: os << "Comedie\n"; break;
	case Categorie::DRAME: os << "Drame\n";  break;
	case Categorie::HORREUR: os << "Horreur\n"; break;
	default: os << "Inconnu\n";
	}

	os << "Acteurs:" << "\n";

	for (auto&& acteur : film.acteurs_)
		os << *acteur;

	os << "Critiques:" << "\n";

	for (auto&& critique : film.critiques_)
		os << "\t" << *critique;

	os << "Note moyenne: " << film.obtenirNoteMoyenne() << "\n";
	

	return os;
}	// TODO
