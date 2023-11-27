#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <functional>

#include "Acteur.h"
#include "Critique.h"
#include "Film.h"
#include "Polyflix.h"
#include "Constants.h"

namespace testing {
    string redirect_stdout(function<void()> func) {
        stringstream buffer;
        auto old_cout = cout.rdbuf();

        cout.rdbuf(buffer.rdbuf());
        func();

        cout.rdbuf(old_cout);

        return buffer.str();
    }
}

// Test pour Acteur (1 point)
double testActeur() {
    double points = 0.0;

    Acteur acteur1;
    Acteur acteur2(NOM_1, ANNEE_NAISSANCE_1, BIO_1);

    // Test du constructeur par defaut
    if (acteur1.getNom() == "" && acteur1.getAnneeNaissance() == 0 && acteur1.getBiographie() == "") {

    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur par parametres
    if (acteur2.getNom() == NOM_1 && acteur2.getAnneeNaissance() == ANNEE_NAISSANCE_1 && acteur2.getBiographie() == BIO_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur par parametres ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test des setters et getters
    acteur1.setNom(NOM_2);
    acteur1.setAnneeNaissance(ANNEE_NAISSANCE_2);
    acteur1.setBiographie(BIO_2);
    if (acteur1.getNom() == NOM_2 && acteur1.getAnneeNaissance() == ANNEE_NAISSANCE_2 && acteur1.getBiographie() == BIO_2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Les setters et getters ne fonctionnent pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la methode afficher
    Acteur acteur3(NOM_1, ANNEE_NAISSANCE_1, BIO_1);
    string sortie = testing::redirect_stdout([&] { acteur3.afficher(); });
    string sortieAttendue = NOM_1 + "\n" + SEPARATEUR_SIMPLE + "\n\tDate de naissance: " + to_string(ANNEE_NAISSANCE_1) + "\n\tBiographie: " + BIO_1 + "\n" + SEPARATEUR_SIMPLE + "\n";

    if (sortie == sortieAttendue) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "La methode afficher ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }
    return points;
}

// Test pour Critique (1 point)
double testCritique() {
    double points = 0.0;

    Critique critique1;
    Critique critique2(AUTEUR_1, COMMENTAIRE_1, NOTE_1);

    // Test du constructeur par defaut
    if (critique1.getAuteur() == "" && critique1.getCommentaire() == "" && critique1.getNote() == 0) {

    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur par parametres
    if (critique2.getAuteur() == AUTEUR_1 && critique2.getCommentaire() == COMMENTAIRE_1 && critique2.getNote() == NOTE_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur par parametres ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test des setters et getters
    critique1.setAuteur(AUTEUR_2);
    critique1.setCommentaire(COMMENTAIRE_2);
    critique1.setNote(NOTE_2);
    if (critique1.getAuteur() == AUTEUR_2 && critique1.getCommentaire() == COMMENTAIRE_2 && critique1.getNote() == NOTE_2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Les setters et getters ne fonctionnent pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la methode afficher
    Critique critique3(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    string sortie = testing::redirect_stdout([&] { critique3.afficher(); });
    string sortieAttendue = AUTEUR_1 + ": " + COMMENTAIRE_1 + " - Note: " + to_string(NOTE_1) + "\n";

    if (sortie == sortieAttendue) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "La methode afficher ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    return points;
}

// Test pour Film (2 points)
double testFilm() {
    double points = 0.0;

    Film film1;
    Film film2(TITRE_2, ANNEE_SORTIE_2, REALISATEUR_2, CATEGORIE_2, DUREE_2);

    // Test du constructeur par defaut
    if (film1.getTitre() == "" && film1.getAnneeDeSortie() == 0 && film1.getRealisateur() == "" && film1.getDuree() == 0 && film1.getNbActeurs() == 0 && film1.getNbCritiques() == 0) {

    }
    else {
        cout << "\033[31m" << "Le constructeur par defaut de Film ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur avec parametres
    if (film2.getTitre() == TITRE_2 && film2.getAnneeDeSortie() == ANNEE_SORTIE_2 && film2.getRealisateur() == REALISATEUR_2 && film2.getDuree() == DUREE_2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur avec parametres de Film ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Créer des acteurs
    vector<Acteur*> acteurs = {
        new Acteur(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        new Acteur(NOM_3, ANNEE_NAISSANCE_3, BIO_3),
    };
    film2.setTitre("SAlut");
    // Définir les acteurs pour le film
    film2.setActeurs(acteurs);

    // Test getActeurs & setActeurs
    if (film2.getNbActeurs() == 2) {
        // Obtenir les acteurs depuis film2
        auto&& film2_acteurs = film2.getActeurs();

        if (film2_acteurs.size() != 2) {
            cout << "\033[31m" << "La methode getActeurs ne retourne pas le vecteur d'acteurs correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        }
        else {
            // Vérifier si les acteurs sont les mêmes
            bool actors_are_same = true;
            for (int i = 0; i < film2.getNbActeurs(); ++i) {
                if (film2_acteurs[i] != acteurs[i]) {
                    actors_are_same = false;
                    break;
                }
            }

            if (actors_are_same) {
                points += 0.25;
            }
            else {
                cout << "\033[31m" << "Les acteurs dans film2 ne correspondent pas aux acteurs passés à setActeurs." << endl << SEPARATEUR_1 << "\033[0m\n";
            }
        }
    }
    else {
        cout << "\033[31m" << "La methode setActeurs ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test ajouterActeur, isActeurPresent & trouverActeur
    bool ajouterActeur = film1.ajouterActeur(NOM_1, ANNEE_NAISSANCE_1, BIO_1);
    if (ajouterActeur && film1.isActeurPresent(NOM_1) &&
        film1.trouverActeur(NOM_1)->getNom() == NOM_1 &&
        film1.trouverActeur(NOM_1)->getAnneeNaissance() == ANNEE_NAISSANCE_1 &&
        film1.trouverActeur(NOM_1)->getBiographie() == BIO_1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec du test ajouterActeur, isActeurPresent & trouverActeur." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test ajouterCritique, isCritiquePresent & trouverCritique
    bool ajouterCritique = film1.ajouterCritique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    if (ajouterCritique && film1.isCritiquePresent(AUTEUR_1) &&
        film1.trouverCritique(AUTEUR_1)->getAuteur() == AUTEUR_1 &&
        film1.trouverCritique(AUTEUR_1)->getCommentaire() == COMMENTAIRE_1 &&
        film1.trouverCritique(AUTEUR_1)->getNote() == NOTE_1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec du test ajouterCritique & trouverCritique." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test obtenirNoteMoyenne
    film1.ajouterCritique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);
    float noteMoyenne = film1.obtenirNoteMoyenne();
    if (noteMoyenne == 3.5f) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Echec du test obtenirNoteMoyenne. Moyenne obtenue: " << noteMoyenne << " au lieu de 3.5" << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test retirerActeur & retirerCritique
    bool acteurRetire = film1.retirerActeur(NOM_1);
    bool critiqueRetire = film1.retirerCritique(AUTEUR_1);
    if (acteurRetire && film1.trouverActeur(NOM_1) == nullptr &&
        critiqueRetire && film1.trouverCritique(AUTEUR_1) == nullptr) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Echec du test retirerActeur & retirerCritique." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test d'affichage d'un film (points: 1)
double testAffichageFilm() {
    double points = 0.0;

    Film film(TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, CATEGORIE_1, DUREE_1);

    // Créer des acteurs
    vector<Acteur*> acteurs = {
        new Acteur(NOM_1, ANNEE_NAISSANCE_1, BIO_1),
        new Acteur(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
        new Acteur(NOM_3, ANNEE_NAISSANCE_3, BIO_3),
    };

    // Ajouter des acteurs et des critiques
    film.setActeurs(acteurs);

    film.ajouterCritique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    film.ajouterCritique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    // Lire la sortie attendue
    ifstream fichier("sortie_testAffichageFilm.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier)),
        istreambuf_iterator<char>());

    // Comparer la sortie attendue avec la sortie du programme
    string sortie = testing::redirect_stdout([&]() { film.afficher(); });

    if (sortieAttendue == sortie) {
        points += 1;
    }
    else {
        cout << "\033[31m" << "Echec du test afficherFilm." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    return points;
}

// Test de la classe Polyflix (3 points)
double testPolyflix(Polyflix& polyflix) {
    double points = 0.0;

    if (polyflix.getNombreTotalFilms() == 4) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec. Verifier les methodes ajouterFilm ou getNombreTotalFilms." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.obtenirFilmAvecLaPlusHauteNote()->getTitre() == TITRE_2) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec. Verifier la methode obtenirFilmAvecLaPlusHauteNote." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.obtenirFilmAvecLaPlusBasseNote()->getTitre() == TITRE_4) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec. Verifier la methode obtenirFilmAvecLaPlusBasseNote." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.obtenirFilmPlusRecent()->getTitre() == TITRE_1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec. Verifier la methode obtenirFilmPlusRecent." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Lire la sortie attendue
    ifstream fichier1("sortie_afficherListeFilms.txt");
    string sortieAttendue1((istreambuf_iterator<char>(fichier1)),
        istreambuf_iterator<char>());

    // Comparer la sortie attendue avec la sortie du programme
    string sortie1 = testing::redirect_stdout([&]() { polyflix.afficherListeFilms(); });

    if (sortieAttendue1 == sortie1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec du test afficherFilm." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue1 << "\n";
        cout << "Sortie du programme:\n" << sortie1 << "\n";
    }

    // Lire la sortie attendue
    ifstream fichier2("sortie_afficherFilmsParCategorie.txt");
    string sortieAttendue2((istreambuf_iterator<char>(fichier2)),
        istreambuf_iterator<char>());

    // Comparer la sortie attendue avec la sortie du programme
    string sortie2 = testing::redirect_stdout([&]() { polyflix.afficherFilmsParCategorie(Categorie::COMEDIE); });

    if (sortieAttendue2 == sortie2) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec du test afficherFilm." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue2 << "\n";
        cout << "Sortie du programme:\n" << sortie2 << "\n";
    }

    return points;
}

void lancerTests(Polyflix& polyflix) {

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Acteur." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point1 = testActeur();
    cout << "\033[32m => " << fixed << setprecision(1) << point1 << "/1.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Critique." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point2 = testCritique();
    cout << "\033[32m => " << fixed << setprecision(1) << point2 << "/1.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Film." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point3 = testFilm();
    cout << "\033[32m => " << fixed << setprecision(1) << point3 << "/2.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point4 = testAffichageFilm();
    cout << "\033[32m => " << fixed << setprecision(1) << point4 << "/1.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point5 = testPolyflix(polyflix);
    cout << "\033[32m => " << fixed << setprecision(1) << point5 << "/3.0" << "\033[0m\n";

    cout << SEPARATEUR_2;
    cout << "Total des points: " << "\033[32m" << fixed << setprecision(1) << point1 + point2 + point3 + point4 + point5 << "/10.0" << "\033[0m" << endl;
    cout << SEPARATEUR_1;
    cout << "A cela s'ajoute 2 points pour le fonctionnement du menu!" << endl;
    cout << SEPARATEUR_2;

}