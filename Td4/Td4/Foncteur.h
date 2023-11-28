#pragma once
#include "Media.h"

// TODO: comparer les medias par note d'evaluation croissante
class FoncteurComparerMedia {
public:

	bool operator () (const shared_ptr<Media>& media1, const shared_ptr<Media>& media2) {
		return media1->obtenirEvaluation() > media2->obtenirEvaluation();
	}
};

// TODO: rechercher un media par son nom
class FoncteurRechercheNomMedia {
public:
	FoncteurRechercheNomMedia(string& nomMedia):nomMedia_(nomMedia){}

	bool operator () (const shared_ptr<Media>& media1) {
		return media1->getTitre() == nomMedia_ ;
	}
private:
	string nomMedia_;
};

// TODO: rechercher un utilisateur par son nom
class FoncteurRechercheNomUtilisateur {
public:
	FoncteurRechercheNomUtilisateur(string& nomUtilisateur) :nomUtilisateur_(nomUtilisateur) {}

	bool operator () (const shared_ptr<Utilisateur>& utilisateur) {
		return utilisateur->getNomUtilisateur() == nomUtilisateur_;
	}
private:
	string nomUtilisateur_;
};
