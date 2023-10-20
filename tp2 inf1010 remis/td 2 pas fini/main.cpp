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
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 3: {
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 4: {
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 5: {
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 6: {
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 7: {
            cout << "TODO" << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 8: {
            cout << "TODO" << endl;
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