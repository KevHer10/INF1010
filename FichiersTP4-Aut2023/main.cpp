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
    cout << "\033[32m2.  Visualiser l'ensemble des medias\033[0m" << endl;
    cout << "\033[32m3.  Rechercher et afficher un media par nom\033[0m" << endl;
    cout << "\033[32m4.  Afficher les medias sortis durant ou apres une annee donnee\033[0m" << endl;
    cout << "\033[32m5.  Listez les medias par categorie\033[0m" << endl;
    cout << "\033[32m6.  Afficher les medias avec une evaluation superieure a une certaine valeur\033[0m" << endl;
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

void clearCin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {

    cout << ASCII_ART << "\n\n";

    cout << "\033[33m================================ \033[0m" << endl;
    cout << "\033[33m     Bienvenue sur Polyflix      \033[0m" << endl;
    cout << "\033[33m================================ \033[0m" << endl;

    Polyflix polyflix;

    Media media1 = Media(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1);

    media1 += Cast(NOM_ACTEUR_A, ANNEE_NAISSANCE_ACTEUR_A, BIO_ACTEUR_A, SALAIRE_ACTEUR_A);
    media1 += Cast(NOM_REALISATEUR_A, ANNEE_NAISSANCE_REALISATEUR_A, BIO_REALISATEUR_A, SALAIRE_REALISATEUR_A);
    media1 += Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    media1 += Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    Media media2 = Media(TITRE_FILM_2, ANNEE_SORTIE_FILM_2, CATEGORIE_FILM_2);

    media2 += Cast(NOM_ACTEUR_B, ANNEE_NAISSANCE_ACTEUR_B, BIO_ACTEUR_B, SALAIRE_ACTEUR_B);
    media2 += Cast(NOM_REALISATEUR_B, ANNEE_NAISSANCE_REALISATEUR_B, BIO_REALISATEUR_B, SALAIRE_REALISATEUR_B);
    media2 += Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);

    Media media3 = Media(TITRE_SERIE_1, ANNEE_SORTIE_SERIE_1, CATEGORIE_SERIE_1);

    media3 += Cast(NOM_ACTEUR_C, ANNEE_NAISSANCE_ACTEUR_C, BIO_ACTEUR_C, SALAIRE_ACTEUR_C);
    media3 += Cast(NOM_REALISATEUR_C, ANNEE_NAISSANCE_REALISATEUR_C, BIO_REALISATEUR_C, SALAIRE_REALISATEUR_C);
    media3 += Critique(AUTEUR_3, COMMENTAIRE_3, NOTE_3);

    polyflix += media1;
    polyflix += media2;
    polyflix += media3;

    polyflix += Utilisateur(AUTEUR_1, MOT_DE_PASSE_1);
    polyflix += Utilisateur(AUTEUR_2, MOT_DE_PASSE_2);
    polyflix += Utilisateur(AUTEUR_3, MOT_DE_PASSE_3);

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
            cout << polyflix << endl;
            cout << SEPARATEUR_2;
            break;
        }
        case 3: {
            string nomDuMedia;
            cout << "Entrez le nom du media: ";
            clearCin();
            getline(cin, nomDuMedia);

            // TODO: On utilise une fonction lambda pour trouver le media selon son nom
            // il  faut faire appel à la méthode listersi

            cout << SEPARATEUR_2;
            break;
        }
        case 4: {
            int annee;
            cout << "Entrez l'annee de sortie: ";
            cin >> annee;

            // TODO: On utilise une fonction lambda pour trouver le media selon son année

            cout << SEPARATEUR_2;
            break;
        }
        case 5: {
            Categorie categorieChoisie;
            int choixCategorie;

            cout << "Choisissez une categorie : " << endl;
            cout << "1. ACTION" << endl;
            cout << "2. COMEDIE" << endl;
            cout << "3. DRAME" << endl;
            cout << "4. HORREUR" << endl;

            cin >> choixCategorie;

            switch (choixCategorie) {
            case 1:
                categorieChoisie = Categorie::ACTION;
                break;
            case 2:
                categorieChoisie = Categorie::COMEDIE;
                break;
            case 3:
                categorieChoisie = Categorie::DRAME;
                break;
            case 4:
                categorieChoisie = Categorie::HORREUR;
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
            }

            // TODO: On utilise une fonction lambda pour trouver le media selon la catégorie

            cout << SEPARATEUR_2;
            break;
        }
        case 6: {
            double valeurEvaluation;
            cout << "Entrez la valeur minimale d'evaluation: ";
            cin >> valeurEvaluation;

            // TODO: On utilise une fonction lambda pour trouver le media selon l'évaluation

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