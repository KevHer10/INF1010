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

// Test pour Liste (2.0 points)
double testListe() {
    double points = 0.0;

    Liste<int> liste1;
    liste1 += 5;
    liste1 += 10;
    liste1 += 15;

    // Test de la taille initiale de la liste
    if (liste1.obtenirNbElements() == 3) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout d'elements a la liste ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test du constructeur par copie
    Liste<int> liste2(liste1);
    if (*liste2[0] == 5 && *liste2[1] == 10 && *liste2[2] == 15) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Le constructeur par copie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'operateur =
    Liste<int> liste3;
    liste3 = liste1;
    if (*liste3[0] == 5 && *liste3[1] == 10 && *liste3[2] == 15) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "L'operateur = ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'operateur <<
    string sortie = testing::redirect_stdout([&] { cout << liste1; });
    string sortieAttendue = "5\n10\n15";

    if (sortie == sortieAttendue) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur << ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    // Test des iterateurs begin et end
    int sum = 0;
    for (auto it = liste1.begin(); it != liste1.end(); ++it) {
        sum += **it;
    }

    if (sum == 30) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Les iterateurs begin et/ou end ne fonctionnent pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}


// Test pour Media (1.75 points)
double testMedia() {
    double points = 0.0;
    Media media1(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1);

    string sortie = testing::redirect_stdout([&] { cout << media1; });
    if (sortie.find(TITRE_FILM_1) != string::npos) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "La construction ou l'affichage de Media ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    media1 += Cast(NOM_ACTEUR_A, ANNEE_NAISSANCE_ACTEUR_A, BIO_ACTEUR_A, SALAIRE_ACTEUR_A);
    sortie = testing::redirect_stdout([&] { cout << media1; });
    if (sortie.find(NOM_ACTEUR_A) != string::npos) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "L'ajout de Cast a Media ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    media1 += Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    media1 += Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);
    sortie = testing::redirect_stdout([&] { cout << media1; });
    if (sortie.find(AUTEUR_1) != string::npos && sortie.find(AUTEUR_2) != string::npos) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout de Critique a Media ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (media1.obtenirEvaluation() == (NOTE_1 + NOTE_2) / 2.0) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "obtenirEvaluation ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour FoncteurComparerMedia (0.5 point)
double testFoncteurComparerMedia() {
    double points = 0.0;

    shared_ptr<Media> media1 = make_shared<Media>(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1);
    shared_ptr<Media> media2 = make_shared<Media>(TITRE_FILM_2, ANNEE_SORTIE_FILM_2, CATEGORIE_FILM_2);

    *media1 += Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    *media2 += Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2);

    FoncteurComparerMedia comparer;

    if (comparer(media1, media2) == (NOTE_1 > NOTE_2)) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "FoncteurComparerMedia ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour FoncteurRechercheNomMedia (0.5 point)
double testFoncteurRechercheNomMedia() {
    double points = 0.0;

    shared_ptr<Media> media = make_shared<Media>(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1);

    FoncteurRechercheNomMedia rechercheNom(TITRE_FILM_1);

    if (rechercheNom(media)) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "FoncteurRechercheNomMedia ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test pour FoncteurRechercheNomUtilisateur (0.5 point)
double testFoncteurRechercheNomUtilisateur() {
    double points = 0.0;

    shared_ptr<Utilisateur> utilisateur = make_shared<Utilisateur>(AUTEUR_1, MOT_DE_PASSE_1);

    FoncteurRechercheNomUtilisateur rechercheNom(AUTEUR_1);

    if (rechercheNom(utilisateur)) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "FoncteurRechercheNomUtilisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}

// Test foncteur (1.5 points)
double testFoncteur() {
    return testFoncteurComparerMedia() + testFoncteurRechercheNomMedia() + testFoncteurRechercheNomUtilisateur();
}

// Test de la classe Polyflix (2.75 points)
double testPolyflix() {
    double points = 0.0;

    // Test pour le constructeur par copie
    Polyflix poly1;
    poly1 += Media(TITRE_FILM_1, ANNEE_SORTIE_FILM_1, CATEGORIE_FILM_1);
    poly1 += Utilisateur(AUTEUR_1, MOT_DE_PASSE_1);
    Polyflix poly2 = poly1;

    string sortie = testing::redirect_stdout([&] { cout << poly2; });

    if (sortie.find(TITRE_FILM_1) != string::npos) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur par copie de Polyflix ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour getNombreUtilisateurs
    if (poly1.getNombreUtilisateurs() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "getNombreUtilisateurs ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour chercherUtilisateur
    if (poly1.chercherUtilisateur(AUTEUR_1) && !poly1.chercherUtilisateur(AUTEUR_2)) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "chercherUtilisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour listersi
    auto mediaTrouves = poly1.listersi([](Media media) { return media.getTitre() == TITRE_FILM_1; });
    if (mediaTrouves.obtenirNbElements() == 1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "listersi ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour visionnerFilm
    if (poly1.visionnerFilm(AUTEUR_1, TITRE_FILM_1) && !poly1.visionnerFilm("Inexistant", TITRE_FILM_1)) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "visionnerFilm ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour utilisateurExiste
    if (poly1.utilisateurExiste(AUTEUR_1) && !poly1.utilisateurExiste("UtilisateurInexistant")) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "utilisateurExiste ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour mediaExiste
    if (poly1.mediaExiste(TITRE_FILM_1) && !poly1.mediaExiste("MediaInexistant")) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "mediaExiste ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour operator+= (Utilisateur)
    Utilisateur utilisateur2(AUTEUR_2, MOT_DE_PASSE_2);
    if (poly1 += utilisateur2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout d'un utilisateur via operator+= ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    if (!(poly1 += utilisateur2)) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout d'un utilisateur déjà existant via operator+= ne devrait pas être possible." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test pour operator+= (Media)
    Media media2(TITRE_FILM_2, ANNEE_SORTIE_FILM_2, CATEGORIE_FILM_2);
    if (poly1 += media2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout d'un média via operator+= ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    if (!(poly1 += media2)) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'ajout d'un média déjà existant via operator+= ne devrait pas être possible." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}


void lancerTests() {
    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Liste." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point1 = testListe();
    cout << "\033[32m => " << fixed << setprecision(2) << point1 << "/4.00" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Media." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point2 = testMedia();
    cout << "\033[32m => " << fixed << setprecision(2) << point2 << "/2.00" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour les foncteurs." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point3 = testFoncteur();
    cout << "\033[32m => " << fixed << setprecision(2) << point3 << "/1.50" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point4 = testPolyflix();
    cout << "\033[32m => " << fixed << setprecision(2) << point4 << "/2.50" << "\033[0m\n";

    cout << SEPARATEUR_2;
    cout << "Total des points: " << "\033[32m" << fixed << setprecision(2) << point1 + point2 + point3 + point4 << "/8.00" << "\033[0m" << endl;
    cout << SEPARATEUR_1;
    cout << "A cela s'ajoute 2 points pour le fonctionnement du menu!" << endl;
    cout << SEPARATEUR_2;
}