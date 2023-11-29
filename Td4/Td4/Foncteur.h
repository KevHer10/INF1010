/*
Fichier: Foncteur.h
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation des foncteurs.
*/
#pragma once
#include "Media.h"

/// @brief Foncteur de comparaison pour trier les m�dias par note d'�valuation d�croissante.
class FoncteurComparerMedia {
public:
    /// @brief Surcharge de l'op�rateur de comparaison pour trier les m�dias par note d'�valuation d�croissante.
    /// @param media1 Le premier m�dia � comparer.
    /// @param media2 Le deuxi�me m�dia � comparer.
    /// @return true si la note d'�valuation du premier m�dia est sup�rieure � celle du deuxi�me m�dia, false sinon.
    bool operator () (const shared_ptr<Media>& media1, const shared_ptr<Media>& media2) {
        return media1->obtenirEvaluation() > media2->obtenirEvaluation();
    }
};

/// @brief Foncteur de recherche d'un m�dia par son nom.
class FoncteurRechercheNomMedia {
public:
    /// @brief Constructeur prenant le nom du m�dia � rechercher.
    /// @param nomMedia Le nom du m�dia � rechercher.
    FoncteurRechercheNomMedia(string& nomMedia) :nomMedia_(nomMedia) {}

    /// @brief Surcharge de l'op�rateur de recherche pour comparer le nom du m�dia avec le nom fourni.
    /// @param media1 Le m�dia � comparer.
    /// @return true si le nom du m�dia correspond au nom recherch�, false sinon.
    bool operator () (const shared_ptr<Media>& media1) {
        return media1->getTitre() == nomMedia_;
    }
private:
    string nomMedia_;
};

/// @brief Foncteur de recherche d'un utilisateur par son nom.
class FoncteurRechercheNomUtilisateur {
public:
    /// @brief Constructeur prenant le nom de l'utilisateur � rechercher.
    /// @param nomUtilisateur Le nom de l'utilisateur � rechercher.
    FoncteurRechercheNomUtilisateur(string& nomUtilisateur) : nomUtilisateur_(nomUtilisateur) {}

    /// @brief Surcharge de l'op�rateur de recherche pour comparer le nom de l'utilisateur avec le nom fourni.
    /// @param utilisateur L'utilisateur � comparer.
    /// @return true si le nom de l'utilisateur correspond au nom recherch�, false sinon.
    bool operator () (const shared_ptr<Utilisateur>& utilisateur) {
        return utilisateur->getNomUtilisateur() == nomUtilisateur_;
    }
private:
    string nomUtilisateur_;
};

