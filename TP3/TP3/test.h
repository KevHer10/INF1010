#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>

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

// Test pour Acteur (0.75 point)
double testActeur() {
    double points = 0.0;

    Acteur acteur1 = Acteur(NOM_ACTEUR_A, ANNEE_NAISSANCE_ACTEUR_A, BIO_ACTEUR_A, SALAIRE_ACTEUR_A, AGENCE_ACTEUR_A);
    Acteur acteur2 = acteur1;

    // Test de l'operator+=
    for (auto r : ROLESJOUES_ACTEUR_A) {
        acteur2 += r;
    }

    if (acteur2.getRolesJoues() == ROLESJOUES_ACTEUR_A) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur += ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test accepterRole
    bool roleAccepte = acteur1.accepterRole({ SALAIRE_ACTEUR_A + 1000, &acteur2 });
    if (roleAccepte) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La methode accepterRole de Acteur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test calculerPopularite
    if (acteur2.calculerPopularite() == ClasseCelebrite::A_CELEBRITY) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La methode calculerPopularite de Acteur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour Realisateur (0.75 point)
double testRealisateur() {
    double points = 0.0;

    Realisateur realisateur1 = Realisateur(NOM_REALISATEUR_A, ANNEE_NAISSANCE_REALISATEUR_A, BIO_REALISATEUR_A, SALAIRE_REALISATEUR_A, STUDIO_A);
    Realisateur realisateur2 = realisateur1;

    pair<int, string> prix1 = { 2021, "Best Director - Oscars" };
    pair<int, string> prix2 = { 2020, "Best Story - Cannes" };

    // Test of the operator+=
    realisateur2 += prix1;
    realisateur2 += prix2;

    vector<pair<int, string>> expectedPrix = { prix1, prix2 };
    if (realisateur2.getPrix() == expectedPrix) {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "L'operateur += de Realisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test accepterRole
    bool roleAccepte = realisateur1.accepterRole({ SALAIRE_REALISATEUR_A + 1000, &realisateur2 });
    if (roleAccepte) {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "La methode accepterRole de Realisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test calculerPopularite
    if (realisateur2.calculerPopularite() == ClasseCelebrite::C_CELEBRITY) {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "La methode calculerPopularite de Realisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour Critique (0.25 point)
double testCritique() {
    double points = 0.0;

    Critique critique1(AUTEUR_1, COMMENTAIRE_1, NOTE_1);

    if (critique1.obtenirEvaluation() == float(NOTE_1)) {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "La methode obtenirEvaluation de Critique ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}


// Test pour Film (0.75 points)
double testFilm() {
    double points = 0.0;

    // Test constructors
    Film film1(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1, DUREE_FILM_1);

    // Add critiques
    Critique critique1(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    Critique critique2(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    film1 += critique1;
    film1 += critique2;

    // Test obtenirEvaluation method
    float expectedEvaluation = (NOTE_1 + NOTE_2) / 2.0f;
    if (fabs(film1.obtenirEvaluation() - expectedEvaluation) < 0.001) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La methode obtenirEvaluation() de Film ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test progression method
    film1.setDureeVisionne(50);
    if (film1.progression() == "Temps ecoule: 50/165 minutes\n") {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "La methode progression() de Film ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour Serie (1.75 points)
double testSerie() {
    double points = 0.0;

    // Test constructors and adding seasons/episodes
    Serie serie1(TITRE_SERIE_1, ANNEE_SORTIE_SERIE_1, CATEGORIE_SERIE_1, {});
    serie1.ajouterEpisode(1, 30);
    serie1.ajouterEpisode(2, 30);

    if (serie1.getNbEpisodes() == 2) {
        points += 0.75;
    }
    else {
        cout << "\033[31m" << "La gestion des episodes de Serie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test progression method
    serie1.setEpisodeActuel(2, 20);
    if (serie1.progression() == "Episode 2: Temps ecoule 20/30 minutes") {
        points += 0.75;
    }
    else {
        cout << "\033[31m" << "La methode progression() de Serie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}


// Test de la classe Polyflix (3 points)
double testPolyflix() {
    double points = 0.0;

    Polyflix polyflix;

    // Test d'ajout de medias et d'utilisateurs
    auto filmTest = new Film(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1, DUREE_FILM_1);
    if (polyflix += filmTest) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Impossible d'ajouter un nouveau film à Polyflix." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.getNombreTotalFilms() == 1 && polyflix.getNombreTotalMedia() == 1) {
        points += 0.50;
    }
    else {
        cout << "\033[31m" << "Le nombre de films/medias n'a pas ete correctement mis à jour après ajout." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    Utilisateur userTest(AUTEUR_1, MOT_DE_PASSE_1);
    if (polyflix += userTest) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Impossible d'ajouter un nouvel utilisateur à Polyflix." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la methode visionnerMedia
    if (polyflix.visionnerMedia(AUTEUR_1, TITRE_FILM_1)) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Impossible de visionner le media pour l'utilisateur." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de listerTousLesFilms et listerTousLesSeries
    Film* film2 = new Film(TITRE_FILM_2, ANNEE_SORTIE_FILM_2, CATEGORIE_FILM_2, DUREE_FILM_2);
    Serie* serie1 = new Serie(TITRE_SERIE_1, ANNEE_SORTIE_SERIE_1, CATEGORIE_SERIE_1, EPISODES_SERIE_1);

    polyflix += film2;
    polyflix += serie1;

    if (polyflix.listerTousLesFilms().size() == 2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La liste des films ne contient pas le bon nombre de films." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.listerTousLesSeries().size() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La liste des series ne contient pas le bon nombre de series." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de listerMediaVisionnesParUtilisateur
    if (polyflix.listerMediaVisionnesParUtilisateur(AUTEUR_1).size() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La liste des medias visionnes par l'utilisateur n'est pas correcte." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de listerFilmsParCategorie et listerSeriesParCategorie
    if (polyflix.listerFilmsParCategorie(CATEGORIE_FILM_1).size() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La liste des films par categorie ne contient pas le bon nombre de films." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.listerSeriesParCategorie(CATEGORIE_SERIE_1).size() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "La liste des series par categorie ne contient pas le bon nombre de series." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test de la classe Polyflix (3 points)
double testAffichage() {
    double points = 0.0;

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

    ifstream fichier2("sortie_polyflix.txt");
    string sortieDuProgramme((istreambuf_iterator<char>(fichier2)),
        istreambuf_iterator<char>());
    fichier2.close();

    string sortieDeAfficher = testing::redirect_stdout([&]() { cout << polyflix; });

    if (sortieDuProgramme == sortieDeAfficher) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Echec du test afficherFilm." << "\033[0m\n";
        cout << "Sortie attendue :\n" << sortieDuProgramme << "\n";
        cout << "Sortie obtenue :\n" << sortieDeAfficher << "\n";
    }

    return points;
}

void lancerTests() {
    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Acteur." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point1 = testActeur();
    cout << "\033[32m => " << fixed << setprecision(2) << point1 << "/0.75" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Realisateur." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point2 = testRealisateur();
    cout << "\033[32m => " << fixed << setprecision(2) << point2 << "/1.50" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Critique." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point3 = testCritique();
    cout << "\033[32m => " << fixed << setprecision(2) << point3 << "/0.50" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Film." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point4 = testFilm();
    cout << "\033[32m => " << fixed << setprecision(2) << point4 << "/0.75" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Serie." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point5 = testSerie();
    cout << "\033[32m => " << fixed << setprecision(2) << point5 << "/1.50" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point6 = testPolyflix();
    cout << "\033[32m => " << fixed << setprecision(2) << point6 << "/2.50" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement du test d'affichage pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point7 = testAffichage();
    cout << "\033[32m => " << fixed << setprecision(2) << point6 << "/2.50" << "\033[0m\n";

    cout << SEPARATEUR_2;
    cout << "Total des points: " << "\033[32m" << fixed << setprecision(2) << point1 + point2 + point3 + point4 + point5 + point6 + point7 << "/8.00" << "\033[0m" << endl;
    cout << SEPARATEUR_1;
    cout << "A cela s'ajoute 2 points pour le fonctionnement du menu!" << endl;
    cout << SEPARATEUR_2;
}