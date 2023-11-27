/*
Fichier: main.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez et Alireza Jafari
Date de creation: 2023-09-14
Date de modification: 2023-09-21
Description: Main.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>

#include "Acteur.h"
#include "Critique.h"
#include "Film.h"
#include "Polyflix.h"
#include "Constants.h"
#include "test.h"


void afficherMenu() {
    cout << "\033[33mEntrez un chiffre pour : \033[0m" << endl;
    cout << "\033[32m1. Rouler les tests\033[0m" << endl;
    cout << "\033[32m2. Creer un compte\033[0m" << endl;
    cout << "\033[32m3. Se connecter\033[0m" << endl;
    cout << "\033[32m4. Afficher la liste des films\033[0m" << endl;
    cout << "\033[32m5. Selectionner une categorie\033[0m" << endl;
    cout << "\033[31m0. Quitter\033[0m" << endl;

    cout << "\033[33mEntrez votre choix : \033[0m";
}

int main() {

    cout << ASCII_ART << "\n\n";

    cout << "\033[33m================================ \033[0m" << endl;
    cout << "\033[33m     Bienvenue sur Polyflix      \033[0m" << endl;
    cout << "\033[33m================================ \033[0m" << endl;

    Polyflix polyflix;

    // film 1
    polyflix.ajouterFilm(TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, CATEGORIE_1, DUREE_1);
    vector<Acteur*> acteurOnceUponATimeInHollywood = {
        new Acteur(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        new Acteur(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
        new Acteur(NOM_3, ANNEE_NAISSANCE_3, BIO_3),
    };
    polyflix.chercherFilmParTitre(TITRE_1)->setActeurs(acteurOnceUponATimeInHollywood);
    polyflix.chercherFilmParTitre(TITRE_1)->ajouterCritique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    polyflix.chercherFilmParTitre(TITRE_1)->ajouterCritique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    // film 2
    polyflix.ajouterFilm(TITRE_2, ANNEE_SORTIE_2, REALISATEUR_2, CATEGORIE_2, DUREE_2);
    vector<Acteur*> acteursWolfOfWallStreet = {
        new Acteur(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        new Acteur(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
    };
    polyflix.chercherFilmParTitre(TITRE_2)->setActeurs(acteursWolfOfWallStreet);
    polyflix.chercherFilmParTitre(TITRE_2)->ajouterCritique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);

    // film 3
    polyflix.ajouterFilm(TITRE_3, ANNEE_SORTIE_3, REALISATEUR_3, CATEGORIE_3, DUREE_3);
    vector<Acteur*> acteursInception = {
        new Acteur(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
    };
    polyflix.chercherFilmParTitre(TITRE_3)->setActeurs(acteursInception);
    polyflix.chercherFilmParTitre(TITRE_3)->ajouterCritique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    // film 4
    polyflix.ajouterFilm(TITRE_4, ANNEE_SORTIE_4, REALISATEUR_4, CATEGORIE_4, DUREE_4);
    vector<Acteur*> acteursFightClub = {
        new Acteur(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
    };
    polyflix.chercherFilmParTitre(TITRE_4)->setActeurs(acteursFightClub);
    polyflix.chercherFilmParTitre(TITRE_4)->ajouterCritique(AUTEUR_3, COMMENTAIRE_3, NOTE_3);

    bool connecte = false;
    int choix;
    Categorie categorie;
    string nomUtilisateur = "";
    string motDePasse = "";

    do {
        afficherMenu();
        cin >> choix;
        cout << SEPARATEUR_2;

        switch (choix) {
        case 1: {
            cout << "Lancement des tests..." << endl;
            lancerTests(polyflix);
            break;
        }
        case 2: {
            
            string nomUtilisateur="";
            string motDePasse = "";
            
            cout << "\033[32m2. Creer un compte\033[0m" << endl << endl;

            cout << "\033[33mEntrez un nom d'utilisateur pour creer un compte: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> nomUtilisateur;
            polyflix.setUtilisateur(nomUtilisateur);

            cout << endl;
            cout << "\033[33mEntrez un mot de passe: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> motDePasse;
            polyflix.setMotDePasse(motDePasse);

            cout << "\033[33mVous avez bien cree un compte. \033[0m" << endl;

            cout << SEPARATEUR_2;
            break;
        }
        case 3: {
            cout << "\033[32m Se connecter\033[0m" << endl << endl;
            cout << "\033[33mEntrez nom d'utilisateur pour connecter: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> nomUtilisateur;
            

            cout << endl;
            cout << "\033[33mEntrez votre mot de passe: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> motDePasse;
           
            connecte = polyflix.connecter(nomUtilisateur, motDePasse);
            if(connecte == 1)
                cout << "\033[33mBienvenu: \033[0m" << nomUtilisateur << endl;
            else
                cout << "\033[33mEchec de connexion\033[0m"  << endl;


            cout << SEPARATEUR_2;
            break;
        }
        case 4: {
            int choix = 0;
            
            cout << "\033[32m4. Choissisez comment vous voulez affficher las liste de films: \033[0m" << endl;
            cout << "\033[32m1. Tous\033[0m" << endl;
            cout << "\033[32m2. Par categorie\033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> choix;
            if (choix == 1) {
                polyflix.afficherListeFilms();
                cout << endl;
            }
            else if (choix == 2) {
                switch (categorie)
                {
                case Categorie::ACTION:
                    cout << "\033[33mVous avez choisi Action : \033[0m" << endl;
                    polyflix.afficherFilmsParCategorie(categorie);
                    categorie = {};
                    cout << endl;
                    break;
                case Categorie::COMEDIE:
                    cout << "\033[33mVous avez choisi Comedie : \033[0m" << endl;
                    polyflix.afficherFilmsParCategorie(categorie);
                    categorie = {};
                    cout << endl;
                    break;
                case Categorie::DRAME:
                    cout << "\033[33mVous avez choisi Drame : \033[0m" << endl;
                    polyflix.afficherFilmsParCategorie(categorie);
                    categorie = {};
                    cout << endl;
                    break;
                case Categorie::HORREUR:
                    cout << "\033[33mVous avez choisi Horreur : \033[0m" << endl;
                    polyflix.afficherFilmsParCategorie(categorie);
                    categorie = {};
                    cout << endl;
                    break;
                default:
                    cout << "\033[33mMauvais choix. Veuillez reesayer.\033[0m" << endl;
                
                }

            }
            else
                cout << "\033[33mMauvais choix. Veuillez reesayer.\033[0m" << endl;

            cout << SEPARATEUR_2;
            break;
        }
        case 5: {
            int choixCategorie;

            cout << "\033[32mSelectionner une categorie:\033[0m" << endl << endl;
            cout << "\033[32m1. Tous\033[0m" << endl;
            cout << "\033[32m2. Action\033[0m" << endl;
            cout << "\033[32m3. Comedie\033[0m" << endl;
            cout << "\033[32m4. Drame\033[0m" << endl;
            cout << "\033[32m5. Horreur\033[0m" << endl;

            cout << "\033[33mEntrez votre choix : \033[0m";
            cin >> choixCategorie;
           
            
            switch (choixCategorie)
            {
            case 1:
                cout << "\033[33mVous avez choisi Tous : \033[0m" << endl;
                break;
            case 2:
                cout << "\033[33mVous avez choisi Action : \033[0m" << endl;
                categorie = Categorie::ACTION;
                break;
            case 3:
                cout << "\033[33mVous avez choisi Comedie : \033[0m" << endl;
                categorie = Categorie::COMEDIE;
                break;
            case 4:
                cout << "\033[33mVous avez choisi Drame : \033[0m" << endl;
                categorie = Categorie::DRAME;
                break;
            case 5:
                cout << "\033[33mVous avez choisi Horreur : \033[0m" << endl;
                categorie = Categorie::HORREUR;
                break;
            default:
                cout << "\033[33mChoix invalide, essayez a nouveau : \033[0m" << endl;
            }
            
            cout << SEPARATEUR_2;
            break;
        }
        case 0:
            cout << "Au revoir!" << endl;
            cout << SEPARATEUR_2;
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer." << endl;
            cout << SEPARATEUR_2;
        }
    } while (choix != 0);

    return 0;
}
