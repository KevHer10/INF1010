/*
Fichier: Critique.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Implementation de la classe Critique.
*/
#include "Critique.h"

// TODO: Implémenter les méthodes de la classe Critique ici.

// Constructeurs

/// @brief Constructeur par défaut de la classe Critique.
Critique::Critique() { 
	auteur_ = "";
	commentaire_ = "";
	note_ = 0;
}
/// @brief Constructeur par paramètres de la classe Critique.
/// @param auteur: Auteur de la critique du film.
/// @param contenu: Commentaire du film.
/// @param note: Note du film.
Critique::Critique(std::string auteur, std::string contenu, int note) {
	auteur_ = auteur;
	commentaire_ = contenu;
	note_ = note;
}

// Getters

/// @brief Retourne le nom de l'Auteur
/// @return nom auteur.
string Critique::getAuteur() const { return auteur_; }
/// @brief Retourne le commentaire de l'Auteur. 
/// @return commentaire de l'auteur.
string Critique::getCommentaire() const { return commentaire_; }
/// @brief Retourne la note de la critique.
/// @return note critique.
int Critique::getNote() const { return note_; }

// Setters

/// @brief Modifie le nom de l'Auteur. 
/// @param auteur: nom de l'Auteur. 
void Critique::setAuteur(string auteur) {
	auteur_ = auteur;
}
/// @brief Modifie le commentaire de l'auteur.
/// @param contenu: commentaire de l'auteur.
void Critique::setCommentaire(string contenu) {
	commentaire_ = contenu;
}
/// @brief Modifie la note de la critique.
/// @param note: note de la critique.
void Critique::setNote(int note) {
	note_ = note;
}


// Méthode d'affichage

/// @brief Affiche une seule critique.
void Critique::afficher() const {

	cout << auteur_ << ": " << commentaire_ << " - Note: " << note_ << "\n";
}
