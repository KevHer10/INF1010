
//Ce le codee a mohammed



#include "Film.h"
#include <iostream>
#include <iomanip>

// Constructeurs
Film::Film() : titre_(""), anneeDeSortie_(0), realisateur_(""), categorie_(Categorie::ACTION), duree_(0) {}

Film::Film(string titre, int anneeDeSortie, string realisateur, Categorie categorie, int duree)
	: titre_(titre), anneeDeSortie_(anneeDeSortie), realisateur_(realisateur), categorie_(categorie), duree_(duree) {}

Film::Film(const Film& film) 
{
	titre_ = film.titre_;
	anneeDeSortie_ = film.anneeDeSortie_;
	realisateur_ = film.realisateur_;
	categorie_ = film.categorie_;
	duree_ = film.duree_;
	acteurs_ = film.acteurs_;
	
	for (const auto& critique : film.critiques_) 
	{
		critiques_.push_back(make_unique <Critique>(*critique));

	}
	
}							// TODO

Film& Film::operator=(const Film& film) 
{ 
	if (this != &film)
	{
		titre_ = film.titre_;
		anneeDeSortie_ = film.anneeDeSortie_;
		realisateur_ = film.realisateur_;
		categorie_ = film.categorie_;
		duree_ = film.duree_;

	}
	
	
	return *this; 
}	// TODO

// Getters
string Film::getTitre() const { return titre_; }

string Film::getRealisateur() const { return realisateur_; }

int Film::getAnneeDeSortie() const { return anneeDeSortie_; }

Categorie Film::getCategorie() const { return categorie_; }

int Film::getDuree() const { return duree_; }

vector<shared_ptr<Acteur>> Film::getActeurs() const
{ 
	return acteurs_;
}	//TODO

vector<unique_ptr<Critique>> Film::getCritiques() const 
{ 
	vector<unique_ptr<Critique>> copieCritque;
	for (const auto& critique : critiques_) {
		copieCritque.push_back(make_unique <Critique>(*critique));
	}
	return copieCritque;

}			// TODO

int Film::getNbActeurs() const { return (int) acteurs_.size(); }

int Film::getNbCritiques() const { return (int) critiques_.size(); }

// Setters
void Film::setTitre(string titre) { this->titre_ = titre; }

void Film::setRealisateur(string realisateur) { this->realisateur_ = realisateur; }

void Film::setAnneeDeSortie(int anneeDeSortie) { this->anneeDeSortie_ = anneeDeSortie; }

void Film::setCategorie(Categorie categorie) { this->categorie_ = categorie; }

void Film::setDuree(int duree) { this->duree_ = duree; }

void Film::setActeurs(vector<shared_ptr<Acteur>> acteurs) { this->acteurs_ = acteurs; }

void Film::setCritiques(vector<Critique*> critiquesVec)
{
	critiques_.clear();
	for (Critique* critique : critiquesVec) 
	{

		critiques_.push_back(make_unique <Critique>(*critique));

	}
	
}					// TODO

// Méthodes fonctionnelles
shared_ptr<Acteur> Film::trouverActeur(const string nom) const { 
	
	for (const auto& acteur : acteurs_) 
	{
		if (acteur->getNom() == nom) 
		{
			return acteur;
		}

	}
	
	
	return nullptr; 
}		// TODO

unique_ptr<Critique> Film::trouverCritique(const string nom) const { 
	

	for (const auto& critique : critiques_)
	{
		if (critique->getAuteur() == nom)
		{
			return make_unique <Critique>(*critique);
		}

	}
	
	return nullptr;


}	// TODO

bool Film::isActeurPresent(string nomActeur) const
{
	
	return trouverActeur(nomActeur) != nullptr;

}		// TODO

bool Film::isCritiquePresent(string nomCritique) const 
{ 
	
	return trouverCritique (nomCritique) != nullptr; 

}	// TODO

float Film::obtenirNoteMoyenne() const 
{
	float somme = 0;
	for (auto& critique : critiques_) {
		somme += critique->getNote();
	}
	return somme / critiques_.size();
}						// TODO

// Opérateurs
bool Film::operator+=(shared_ptr<Acteur>& acteur) {	
	
	if (!isActeurPresent(acteur->getNom())) {
		acteurs_.push_back(acteur);
		return true;
	}
	return false; 

}	// TODO

bool Film::operator+=(Critique* critique) {	
	
	if (!isCritiquePresent(critique->getAuteur())) 
	{
		critiques_.push_back(make_unique <Critique>(*critique));
		return true;
	}



	return false; 

}			// TODO

bool Film::operator==(const Film& film) const 
{

	
		if(titre_ == film.titre_ && anneeDeSortie_ == film.anneeDeSortie_ && realisateur_ == film.realisateur_
			&& categorie_ == film.categorie_ && duree_ == film.duree_ )
		{
			return true;
		}
		return false;
		
		

}		// TODO

bool Film::operator!=(const Film& film) const
{ 
	
	
	if (titre_ != film.titre_ && anneeDeSortie_ != film.anneeDeSortie_ && realisateur_ != film.realisateur_
		&& categorie_ != film.categorie_ && duree_ != film.duree_ )
	{
		return true;
	}	
	return false;
}		// TODO


bool Film::operator-=(shared_ptr<Acteur>& acteur) 
{
	for (auto& acteurs : acteurs_) {

		if (acteurs->getNom() == acteur->getNom())
		{
			
			acteurs = acteurs_.back();
			acteurs_.pop_back();
			return true;

		}
	}
	return false; 
}	// TODO

bool Film::operator-=(Critique* critique) 
{
	/*for (auto& critiques : critiques_) 
	{
		if (critiques->getCommentaire() == critique->getCommentaire()) 
		{
			critiques = move(critiques_.back());
			critiques_.pop_back();
			return true;

		}


	}*/

	
	return false; 
}			// TODO


// Méthode d'affichage
ostream& operator<<(ostream& os, const Film& film) {
	
	os << film.titre_ << " (" << film.anneeDeSortie_ << ") de " << film.realisateur_ << endl;
	os << "Duree: " << film.duree_ << " minutes" << endl;
	os << "Categorie: ";
	switch (film.categorie_)
	{
	case Categorie::ACTION:
		os << "Action" << endl;
		break;
	case Categorie::COMEDIE:
		os << "Comedie" << endl;
		break;
	case Categorie::DRAME:
		os << "Drame" << endl;
		break;
	case Categorie::HORREUR:
		os << "Horreur" << endl;
		break;
	default:
		os << "Aucun" << endl;
		break;

	}
	os << "Acteurs:" << endl;


	for (const auto& acteur : film.acteurs_)
	{
		os << acteur->getNom() << endl;
		os << SEPARATEUR_SIMPLE << endl;
		os << "\tDate de naissance: " << acteur->getAnneeNaissance() << endl;
		os << "\tBiographie: " << acteur->getBiographie() << endl;
		os << SEPARATEUR_SIMPLE << endl;
	}
	cout << "Critiques:" << endl;
	for (const auto& critique : film.critiques_)
	{
		os <<"\t" << critique->getAuteur() << ": " << critique->getCommentaire() << " - Note: " << critique->getNote() << endl;
	}
	os << "Note moyenne: " << film.obtenirNoteMoyenne() << endl;




	
	return os; 



}	// TODO
