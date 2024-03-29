//Ce mon code a moi

#include "Film.h"
#include <iostream>
#include <iomanip>

// Constructeurs
Film::Film() : titre_(""), anneeDeSortie_(0), realisateur_(""), categorie_(Categorie::ACTION), duree_(0) {}

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree)
	: titre_(titre), anneeDeSortie_(anneeDeSortie), realisateur_(realisateur), categorie_(categorie), duree_(duree) {}

Film::Film(const Film& film) {

	titre_ = film.titre_;
	anneeDeSortie_ = film.anneeDeSortie_;
	realisateur_ = film.realisateur_;
	categorie_ = film.categorie_;
	duree_ = film.duree_;
	acteurs_ = film.acteurs_;
	for (auto&& critique : critiques_)
		critique = make_unique<Critique>(film.critiques_);
}							// TODO


Film& Film::operator=(const Film& film) { 
	if (*this != film) {
		titre_ = film.titre_;
		anneeDeSortie_ = film.anneeDeSortie_;
		realisateur_ = film.realisateur_;
		categorie_ = film.categorie_;
		duree_ = film.duree_;
		acteurs_ = film.acteurs_;
		critiques_ = move(film.critiques_);

	}
		//critiques_ = film.critiques_;
	

	return *this;
}	// TODO

// Getters
string Film::getTitre() const { return titre_; }

string Film::getRealisateur() const { return realisateur_; }

int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

Categorie Film::getCategorie() const { return categorie_; }

int Film::getDuree() const { return duree_; }

vector<shared_ptr<Acteur>> Film::getActeurs() const { return {acteurs_};}	// TODO

vector<unique_ptr<Critique>> Film::getCritiques() const { return {critiques_}; }			// TODO

int Film::getNbActeurs() const { return (int) acteurs_.size(); }

int Film::getNbCritiques() const { return (int) critiques_.size(); }

// Setters
void Film::setTitre(string titre) { this->titre_ = titre; }

void Film::setRealisateur(string realisateur) { this->realisateur_ = realisateur; }

void Film::setAnneeDeSortie(int anneeDeSortie) { this->anneeDeSortie_ = anneeDeSortie; }

void Film::setCategorie(Categorie categorie) { this->categorie_ = categorie; }

void Film::setDuree(int duree) { this->duree_ = duree; }

void Film::setActeurs(vector<shared_ptr<Acteur>> acteurs) { this->acteurs_ = acteurs; }

void Film::setCritiques(vector<Critique*> critiquesVec) {


	for (const auto& critiques : critiquesVec)
		critiques_.push_back(make_unique<Critique>(*critiques));
}// TODO

// Méthodes fonctionnelles
shared_ptr<Acteur> Film::trouverActeur(const string nom) const { 
	for (auto&& acteur : acteurs_) {
		if (acteur->getNom() == nom)
			return acteur;
	}
	return nullptr;
}		// TODO

unique_ptr<Critique> Film::trouverCritique(const string nom) const { 
	
	for (auto&& critique : critiques_)
		if (critique->getAuteur() == nom)
			return make_unique<Critique>(critique);

	return nullptr; }	// TODO

bool Film::isActeurPresent(string nomActeur) const {
	if (trouverActeur(nomActeur) != nullptr)
		return true;

	return false;
}		// TODO

bool Film::isCritiquePresent(string nomCritique) const {
	if (trouverCritique(nomCritique) != nullptr)
		return true;

	return false;
}	// TODO

float Film::obtenirNoteMoyenne() const {
	float moyenne = 0;
	for (auto&& critique : critiques_) {
		moyenne += critique->getNote();
	}
	moyenne = moyenne / critiques_.size();

	return moyenne;
}						// TODO

// Opérateurs
bool Film::operator+=(shared_ptr<Acteur>& acteur) {	
	
	if (isActeurPresent(acteur->getNom()) != true) {
		acteurs_.push_back(acteur);
		return true;
	}

	
	return false;
}	// TODO

bool Film::operator+=(Critique* critique) {	
	
	if (isCritiquePresent(critique->getAuteur()) != true) {
		critiques_.push_back(make_unique<Critique>(critique));
		return true;
	}
	
	return false;
}			// TODO

bool Film::operator==(const Film& film) const { 
	if (titre_ == film.titre_ &&
		anneeDeSortie_ == film.anneeDeSortie_ &&
		realisateur_ == film.realisateur_ &&
		categorie_ == film.categorie_ &&
		duree_ == film.duree_ &&
		acteurs_ == film.acteurs_ &&
		critiques_ == film.critiques_)
		return true;

	return false;
}		// TODO

bool Film::operator!=(const Film& film) const {
	if (titre_ != film.titre_ ||
		anneeDeSortie_ != film.anneeDeSortie_ ||
		realisateur_ != film.realisateur_ ||
		categorie_ != film.categorie_ ||
		duree_ != film.duree_ ||
		acteurs_ != film.acteurs_ ||
		critiques_ != film.critiques_)
		return true;

	return false;
}		// TODO


bool Film::operator-=(shared_ptr<Acteur>& acteur) {	
	if (isActeurPresent(acteur->getNom()) == true) {

		for (auto&& acteurs : acteurs_) {
			if (acteurs == acteur)
				acteurs = acteurs_.back();
			acteurs_.pop_back();
			return true;
			
		}
	}

	return false;

}	// TODO

bool Film::operator-=(Critique* critique) {	
	
	if (isActeurPresent(critique->getAuteur()) == true) {

		for (auto&& critiques : critiques_) {
			Critique* critique_ptr = critiques.get();
			if (critique_ptr == critique)
				critiques = move(critiques_.back()) ;
			critiques_.pop_back();
			return true;
			//break;
		}
	}
	
	return false;
}			// TODO


// Méthode d'affichage
ostream& operator<<(ostream& os, const Film& film) { return os; }	// TODO

//Categorie categorie = getCategorie();
//
//cout << getTitre() << " (" << getAnneeDeSortie() << ") " << "de " << getRealisateur() << "\n";
//cout << "Duree: " << getDuree() << " minutes" << "\n";
//
//cout << "Categorie: ";
//switch (categorie)
//{
//case Categorie::ACTION: std::cout << "Action\n";   break;
//case Categorie::COMEDIE: std::cout << "Comedie\n"; break;
//case Categorie::DRAME: std::cout << "Drame\n";  break;
//case Categorie::HORREUR: std::cout << "Horreur\n"; break;
//default: std::cout << "Inconnu\n";
//}
//
//cout << "Acteurs:" << "\n";
//
//for (auto&& acteur : acteurs_)
//acteur->afficher();
//
//cout << "Critiques:" << "\n";
//
//for (auto&& critique : critiques_)
//critique->afficher();
//
//cout << "Note moyenne: " << obtenirNoteMoyenne() << "\n";