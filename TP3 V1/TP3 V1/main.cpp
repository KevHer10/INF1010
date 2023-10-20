#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>

#include "Acteur.h"
#include "Realisateur.h"
#include "Critique.h"
#include "Utilisateur.h"
#include "Film.h"
#include "Serie.h"
#include "Polyflix.h"
#include "Constants.h"
#include "test.h"

using namespace std;

void afficherMenu() {
    cout << "\033[33mEntrez un chiffre pour : \033[0m" << endl;
    cout << "\033[32m1.  Rouler les tests\033[0m" << endl;
    cout << "\033[32m2.  Creer un compte\033[0m" << endl;
    cout << "\033[32m3.  Se connecter\033[0m" << endl;
    cout << "\033[32m4.  Afficher les medias\033[0m" << endl;
    cout << "\033[32m5.  Afficher les films\033[0m" << endl;
    cout << "\033[32m6.  Afficher les series\033[0m" << endl;
    cout << "\033[32m7.  Afficher les films d'une categorie\033[0m" << endl;
    cout << "\033[32m8.  Afficher les series d'une categorie\033[0m" << endl;
    cout << "\033[32m9.  Modifier mot de passe\033[0m" << endl;
    cout << "\033[32m10. Se deconnecter\033[0m" << endl;
    cout << "\033[31m0.  Quitter\033[0m" << endl;

    cout << "\033[33mEntrez votre choix : \033[0m";
}

Categorie stringToCategorie(string categorie) {
    transform(categorie.begin(), categorie.end(), categorie.begin(), ::tolower);

    if (categorie == "action") {
        return Categorie::ACTION;
    }
    else if (categorie == "comedie") {
        return Categorie::COMEDIE;
    }
    else if (categorie == "drame") {
        return Categorie::DRAME;
    }
    else if (categorie == "horreur") {
        return Categorie::HORREUR;
    }
    else {
        throw invalid_argument("Categorie invalide");
    }
}

int main() {

    cout << ASCII_ART << "\n\n";

    cout << "\033[33m================================ \033[0m" << endl;
    cout << "\033[33m     Bienvenue sur Polyflix      \033[0m" << endl;
    cout << "\033[33m================================ \033[0m" << endl;

    Polyflix polyflix;

    Film* film1 = new Film(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1, DUREE_FILM_1);

    auto acteur1 = make_shared<Acteur>(NOM_ACTEUR_A, ANNEE_NAISSANCE_ACTEUR_A, BIO_ACTEUR_A, SALAIRE_ACTEUR_A, AGENCE_ACTEUR_A);
    auto realisateur1 = make_shared<Realisateur>(NOM_REALISATEUR_A, ANNEE_NAISSANCE_REALISATEUR_A, BIO_REALISATEUR_A, SALAIRE_REALISATEUR_A, STUDIO_A);

    auto critique1 = Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    auto critique2 = Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    *film1 += acteur1;
    *film1 += realisateur1;
    *film1 += critique1;
    *film1 += critique2;

    Film* film2 = new Film(TITRE_FILM_2, ANNEE_SORTIE_FILM_2, CATEGORIE_FILM_2, DUREE_FILM_2);

    auto acteur2 = make_shared<Acteur>(NOM_ACTEUR_B, ANNEE_NAISSANCE_ACTEUR_B, BIO_ACTEUR_B, SALAIRE_ACTEUR_B, AGENCE_ACTEUR_B);
    auto realisateur2 = make_shared<Realisateur>(NOM_REALISATEUR_B, ANNEE_NAISSANCE_REALISATEUR_B, BIO_REALISATEUR_B, SALAIRE_REALISATEUR_B, STUDIO_B);

    *film2 += acteur2;
    *film2 += realisateur2;
    *film2 += critique1;

    Serie* serie1 = new Serie(TITRE_SERIE_1, ANNEE_SORTIE_SERIE_1, CATEGORIE_SERIE_1, EPISODES_SERIE_1);

    auto acteur3 = make_shared<Acteur>(NOM_ACTEUR_C, ANNEE_NAISSANCE_ACTEUR_C, BIO_ACTEUR_C, SALAIRE_ACTEUR_C, AGENCE_ACTEUR_C);
    auto realisateur3 = make_shared<Realisateur>(NOM_REALISATEUR_C, ANNEE_NAISSANCE_REALISATEUR_C, BIO_REALISATEUR_C, SALAIRE_REALISATEUR_C, STUDIO_C);

    auto critique3 = Critique(AUTEUR_3, COMMENTAIRE_3, NOTE_3);

    *serie1 += acteur3;
    *serie1 += realisateur3;
    *serie1 += critique3;

    Utilisateur user1 = { AUTEUR_1, MOT_DE_PASSE_1 };
    Utilisateur user2 = { AUTEUR_2, MOT_DE_PASSE_2 };
    Utilisateur user3 = { AUTEUR_3, MOT_DE_PASSE_3 };

    polyflix += film1;
    polyflix += film2;
    polyflix += serie1;

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
            lancerTests();
            break;
        }
        case 2: {
            if (connecte) {
                cout << "Vous etes deja connecte!" << endl;
            }
            else
            {
                string nom, motDePasse;
                cout << "Entrez votre nom d'utilisateur: ";
                cin >> nom;
                cout << "Entrez votre mot de passe: ";
                cin >> motDePasse;
                polyflix += Utilisateur{ nom, motDePasse };
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 3: {
            if (connecte) {
                cout << "Vous etes deja connecte!" << endl;
            }
            else {
                string nom, motDePasse;
                cout << "Entrez votre nom d'utilisateur: ";
                cin >> nom;
                cout << "Entrez votre mot de passe: ";
                cin >> motDePasse;
                connecte = polyflix.connecterUtilisateur(nom, motDePasse);
                if (connecte) {
                    cout << "Vous etes maintenant connecte!" << endl;
                    nomUtilisateurConnecte = nom;
                }
                else {
                    cout << SEPARATEUR_2;
                    cout << "Nom d'utilisateur ou mot de passe incorrect!" << endl;
                }
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 4: {
            // TODO: Afficher les medias
            break;
        }
        case 5: {
            // TODO: Afficher les films
            break;
        }
        case 6: {
            // TODO: Afficher les series
            break;
        }
        case 7: {
            // TODO: Afficher les films d'une categorie
            break;
        }
        case 8: {
            // TODO: Afficher les series d'une categorie
            break;
        }
        case 9: {
            if (!connecte) {
                cout << "Vous devez etre connecte pour effectuer cette action!" << endl;
            }
            else {
                string nouveauMotDePasse;
                cout << "Entrez votre nouveau mot de passe: ";
                cin >> nouveauMotDePasse;
                if (polyflix.modifierMotDePasse(nomUtilisateurConnecte, nouveauMotDePasse)) {
                    cout << "Mot de passe modifie avec succes." << endl;
                }
                else {
                    cout << "Erreur lors de la modification du mot de passe." << endl;

                }
            }
            cout << SEPARATEUR_2;
            break;
        }
        case 10: {
            if (!connecte) {
                cout << "Vous etes deja deconnecte" << endl;
            }
            else {
                connecte = false;
                cout << "Vous etes maintenant deconnecte!" << endl;
            }
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