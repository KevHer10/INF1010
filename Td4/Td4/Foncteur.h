/*
Fichier: Foncteur.h
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation des foncteurs.
*/
#pragma once
#include "Media.h"

/// @brief Foncteur de comparaison pour trier les médias par note d'évaluation décroissante.
class FoncteurComparerMedia {
public:
    /// @brief Surcharge de l'opérateur de comparaison pour trier les médias par note d'évaluation décroissante.
    /// @param media1 Le premier média à comparer.
    /// @param media2 Le deuxième média à comparer.
    /// @return true si la note d'évaluation du premier média est supérieure à celle du deuxième média, false sinon.
    bool operator () (const shared_ptr<Media>& media1, const shared_ptr<Media>& media2) {
        return media1->obtenirEvaluation() > media2->obtenirEvaluation();
    }
};

/// @brief Foncteur de recherche d'un média par son nom.
class FoncteurRechercheNomMedia {
public:
    /// @brief Constructeur prenant le nom du média à rechercher.
    /// @param nomMedia Le nom du média à rechercher.
    FoncteurRechercheNomMedia(string& nomMedia) :nomMedia_(nomMedia) {}

    /// @brief Surcharge de l'opérateur de recherche pour comparer le nom du média avec le nom fourni.
    /// @param media1 Le média à comparer.
    /// @return true si le nom du média correspond au nom recherché, false sinon.
    bool operator () (const shared_ptr<Media>& media1) {
        return media1->getTitre() == nomMedia_;
    }
private:
    string nomMedia_;
};

/// @brief Foncteur de recherche d'un utilisateur par son nom.
class FoncteurRechercheNomUtilisateur {
public:
    /// @brief Constructeur prenant le nom de l'utilisateur à rechercher.
    /// @param nomUtilisateur Le nom de l'utilisateur à rechercher.
    FoncteurRechercheNomUtilisateur(string& nomUtilisateur) : nomUtilisateur_(nomUtilisateur) {}

    /// @brief Surcharge de l'opérateur de recherche pour comparer le nom de l'utilisateur avec le nom fourni.
    /// @param utilisateur L'utilisateur à comparer.
    /// @return true si le nom de l'utilisateur correspond au nom recherché, false sinon.
    bool operator () (const shared_ptr<Utilisateur>& utilisateur) {
        return utilisateur->getNomUtilisateur() == nomUtilisateur_;
    }
private:
    string nomUtilisateur_;
};

