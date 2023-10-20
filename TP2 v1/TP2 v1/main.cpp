/*
Fichier: main.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-09-30
Date de modification: 2023-10-04
Description: main
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
    cout << "\033[32m5. Visionner un film\033[0m" << endl;
    cout << "\033[32m6. Afficher les films que j'ai visionnes\033[0m" << endl;
    cout << "\033[32m7. Modifier mot de passe\033[0m" << endl;
    cout << "\033[32m8. Se deconnecter\033[0m" << endl;
    cout << "\033[31m0. Quitter\033[0m" << endl;

    cout << "\033[33mEntrez votre choix : \033[0m";
}

int main() {

    cout << ASCII_ART << "\n\n";

    cout << "\033[33m================================ \033[0m" << endl;
    cout << "\033[33m     Bienvenue sur Polyflix      \033[0m" << endl;
    cout << "\033[33m================================ \033[0m" << endl;

    Polyflix polyflix;

    Film* film1 = new Film(TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, CATEGORIE_1, DUREE_1);
    vector<shared_ptr<Acteur>> acteursOnceUponATimeInHollywood = {
        make_shared<Acteur>(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        make_shared<Acteur>(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
        make_shared<Acteur>(NOM_3, ANNEE_NAISSANCE_3, BIO_3)
    };

    vector<Critique*> critiquesOnceUponATimeInHollywood = {
        new Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1),
        new Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2)
    };

    film1->setActeurs(acteursOnceUponATimeInHollywood);
    film1->setCritiques(critiquesOnceUponATimeInHollywood);

    Film* film2 = new Film(TITRE_2, ANNEE_SORTIE_2, REALISATEUR_2, CATEGORIE_2, DUREE_2);
    vector<shared_ptr<Acteur>> acteursWolfOfWallStreet = {
        make_shared<Acteur>(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        make_shared<Acteur>(NOM_2, ANNEE_NAISSANCE_2, BIO_2)
    };

    vector<Critique*> critiquesWolfOfWallStreet = {
        new Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1)
    };

    film2->setActeurs(acteursWolfOfWallStreet);
    film2->setCritiques(critiquesWolfOfWallStreet);

    Film* film3 = new Film(TITRE_3, ANNEE_SORTIE_3, REALISATEUR_3, CATEGORIE_3, DUREE_3);
    vector<shared_ptr<Acteur>> acteursInception = {
        make_shared<Acteur>(NOM_1, ANNEE_NAISSANCE_1, BIO_1)
    };

    vector<Critique*> critiquesInception = {
        new Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2)
    };

    film3->setActeurs(acteursInception);
    film3->setCritiques(critiquesInception);

    Film* film4 = new Film(TITRE_4, ANNEE_SORTIE_4, REALISATEUR_4, CATEGORIE_4, DUREE_4);
    vector<shared_ptr<Acteur>> acteursFightClub = {
        make_shared<Acteur>(NOM_2, ANNEE_NAISSANCE_2, BIO_2)
    };

    vector<Critique*> critiquesFightClub = {
        new Critique(AUTEUR_3, COMMENTAIRE_3, NOTE_3)
    };

    film4->setActeurs(acteursFightClub);
    film4->setCritiques(critiquesFightClub);

    Utilisateur user1 = { AUTEUR_1, MOT_DE_PASSE_1 };
    Utilisateur user2 = { AUTEUR_2, MOT_DE_PASSE_2 };
    Utilisateur user3 = { AUTEUR_3, MOT_DE_PASSE_3 };

    polyflix += film1;
    polyflix += film2;
    polyflix += film3;
    polyflix += film4;

    polyflix += user1;
    polyflix += user2;
    polyflix += user3;

    bool connecte = false;
    string nomUtilisateurConnecte;
    int choix;
    
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
            
            string nomUtilisateur = "";
            string motDePasse = "";

            cout << "\033[32m2. Creer un compte\033[0m" << endl << endl;

            cout << "\033[33mEntrez un nom d'utilisateur pour creer un compte: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> nomUtilisateur;
            while (polyflix.utilisateurExiste(nomUtilisateur))
            {
                cout << "\033[33mNom d'utilisateur deja existant. Entrez un autre nom pour creer un compte: \033[0m" << endl;
                cout << "\033[32m>>\033[0m";
                cin >> nomUtilisateur;
            } 

            cout << endl;
            cout << "\033[33mEntrez un mot de passe: \033[0m" << endl;
            cout << "\033[32m>>\033[0m";
            cin >> motDePasse;
            cout << endl;

            Utilisateur nouvelUtilisateur(nomUtilisateur,motDePasse);
            
            polyflix += nouvelUtilisateur;

            if (polyflix.utilisateurExiste(nouvelUtilisateur.getNomUtilisateur()) == false) {
                cout << "Creation du compte echouee." << endl;
            }
            else
            {
                cout << "Creation du compte reussie." << endl;
            }


            cout << SEPARATEUR_2;
            break;
        }
        case 3: {
            if (connecte == false) {

                string nomUtilisateur = "";
                string motDePasse = "";

                cout << "\033[32m Se connecter\033[0m" << endl << endl;
                cout << "\033[33mEntrez nom d'utilisateur pour connecter: \033[0m" << endl;
                cout << "\033[32m>>\033[0m";
                cin >> nomUtilisateur;


                cout << endl;
                cout << "\033[33mEntrez votre mot de passe: \033[0m" << endl;
                cout << "\033[32m>>\033[0m";
                cin >> motDePasse;

                connecte = polyflix.connecterUtilisateur(nomUtilisateur, motDePasse);
                if (connecte == 1)
                {
                    cout << "\033[33mBienvenu: \033[0m" << nomUtilisateur << endl;
                    cout << "\033[33mVous etes maintenant connecte.\033[0m" << endl;
                    connecte = true;
                    nomUtilisateurConnecte = nomUtilisateur;
                }
                else
                {
                    cout << "\033[33mEchec de connexion\033[0m" << endl;
                    cout << "\033[33mNom d'utilisateur ou mot de passe incorrect!.\033[0m" << endl;
                }
            }
            else
            {
                cout << "\033[33mUn usager est deja connecte. \033[0m" << endl;
                cout << "\033[33mPour vous connecter a un autre compte, choisir l'option 8 (deconnexion) puis l'option 3(connexion).\033[0m" << endl;
            }

            cout << SEPARATEUR_2;
            break;
        }
        case 4: {
            if(connecte == true)
            {
                cout << polyflix;
                cout << endl;
            }
            else
            {
                cout << "\033[33mVous devez etre connecte pour effectuer cette action! \033[0m" << endl;
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 5: {
            if (connecte == true)
            {
                string titreFilm;
                cout << "\033[33mEntrez le titre du film:  \033[0m" << endl;
                cout << "\033[32m>>\033[0m";
                std::getline(std::cin >> std::ws, titreFilm);
                if (polyflix.chercherFilmParTitre(titreFilm) != nullptr) {
                    polyflix.visionnerFilm(nomUtilisateurConnecte, titreFilm);
                    cout << "\033[33mVous avez visionne le film: \033[0m" << titreFilm << endl;
                }
                else {
                    cout << "\033[33mLe film: \033[0m" << titreFilm << "\033[33m n'existe pas.\033[0m" << endl;
                    cout << "\033[33mEssayez a nouveau. \033[0m" << endl;
                }    
            }
            else
            {
                cout << "\033[33mVous devez etre connecte pour effectuer cette action! \033[0m" << endl;
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 6: {
            if (connecte == true)
            {  
                cout << "\033[33mVoici la liste de films que vous avez visionnes. \033[0m" << endl;
                for (auto& film : polyflix.listerFilmsVisionnesParUtilisateur(nomUtilisateurConnecte)) {
                    cout << *film;
                    cout << SEPARATEUR_2;
                }
            }
            else
            {
                cout << "\033[33mVous devez etre connecte pour effectuer cette action! \033[0m" << endl;
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 7: {
            if (connecte == true)
            {
                string motDePasse = "";
                cout << "\033[33mEntrez votre nouveau mot de passe: \033[0m" << endl;
                cout << "\033[32m>>\033[0m";
                cin >> motDePasse;

                if(polyflix.modifierMotDePasse(nomUtilisateurConnecte, motDePasse) == true)
                    cout << "\033[33mChangement de mot de passe reussie! \033[0m" << endl;
                else
                    cout << "\033[33mEchec Changement de mot de passe! \033[0m" << endl;
            }
            else
            {
                cout << "\033[33mVous devez etre connecte pour effectuer cette action! \033[0m" << endl;
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 8: {
            connecte = false;
            nomUtilisateurConnecte = "";
            cout << "\033[33mVous etes maintenant deconnecte!\033[0m" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 0:
            cout << "Au revoir!" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    } while (choix != 0);

    return 0;
}