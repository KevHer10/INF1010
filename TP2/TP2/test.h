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

// Test pour Acteur (1 point)
double testActeur() {
    double points = 0.0;

    Acteur acteur1(NOM_1, ANNEE_NAISSANCE_1, BIO_1);
    Acteur acteur2(acteur1);
    Acteur acteur3 = acteur1;

    // Test du constructeur par copie
    if (acteur2.getNom() == NOM_1 && acteur2.getAnneeNaissance() == ANNEE_NAISSANCE_1 && acteur2.getBiographie() == BIO_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur par copie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur =
    if (acteur3.getNom() == NOM_1 && acteur3.getAnneeNaissance() == ANNEE_NAISSANCE_1 && acteur3.getBiographie() == BIO_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur = ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur ==
    if (acteur1 == acteur2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur == ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur <<
    string sortie = testing::redirect_stdout([&] { cout << acteur1; });
    string sortieAttendue = NOM_1 + "\n" + SEPARATEUR_SIMPLE + "\n\tDate de naissance: " + to_string(ANNEE_NAISSANCE_1) + "\n\tBiographie: " + BIO_1 + "\n" + SEPARATEUR_SIMPLE + "\n";

    if (sortie == sortieAttendue) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur << ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    return points;
}

// Test pour Critique (1 point)
double testCritique() {
    double points = 0.0;

    Critique critique1(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    Critique critique2(critique1);
    Critique critique3 = critique1;

    // Test du constructeur par copie
    if (critique2.getAuteur() == AUTEUR_1 && critique2.getCommentaire() == COMMENTAIRE_1 && critique2.getNote() == NOTE_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Le constructeur par copie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur =
    if (critique3.getAuteur() == AUTEUR_1 && critique3.getCommentaire() == COMMENTAIRE_1 && critique3.getNote() == NOTE_1) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur = ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur ==
    if (critique1 == critique2) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur == ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur <<
    string sortie = testing::redirect_stdout([&] { cout << critique1; });
    string sortieAttendue = AUTEUR_1 + ": " + COMMENTAIRE_1 + " - Note: " + to_string(NOTE_1) + "\n";

    if (sortie == sortieAttendue) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "L'operateur << ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    return points;
}

bool checkFilm(const Film& film, const string& titre, int anneeSortie, const string& realisateur, int duree) {
    return film.getTitre() == titre
        && film.getAnneeDeSortie() == anneeSortie
        && film.getRealisateur() == realisateur
        && film.getDuree() == duree;
}

template <typename T>
bool checkVecteur(const vector<T>& actual, const vector<T>& expected) {
    if (actual.size() != expected.size()) {
        return false;
    }
    for (size_t i = 0; i < actual.size(); ++i) {
        if (*actual[i] != *expected[i]) {
            return false;
        }
    }
    return true;
}

// Test pour Film (3 points)
double testFilm() {
    double points = 0.0;

    Film film1(TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, CATEGORIE_1, DUREE_1);

    // Créer des acteurs
    auto acteur1 = make_shared<Acteur>(NOM_1, ANNEE_NAISSANCE_1, BIO_1);
    vector<shared_ptr<Acteur>> acteurs = {
        acteur1,
        make_shared<Acteur>(NOM_2, ANNEE_NAISSANCE_2, BIO_2),
        make_shared<Acteur>(NOM_3, ANNEE_NAISSANCE_3, BIO_3),
    };

    film1.setActeurs(acteurs);

    // Créer des critiques
    auto critique1 = new Critique(AUTEUR_1, COMMENTAIRE_1, NOTE_1);
    vector<Critique*> critiques = {
        critique1,
        new Critique(AUTEUR_2, COMMENTAIRE_2, NOTE_2),
    };

    film1.setCritiques(critiques);

    vector<shared_ptr<Acteur>> film1_acteurs = film1.getActeurs();
    vector<unique_ptr<Critique>> film1_critiques = film1.getCritiques();

    Film film2(film1);

    // Test du constructeur par copie
    if (checkFilm(film2, TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, DUREE_1)) {
        points += 0.25;

        if (checkVecteur<shared_ptr<Acteur>>(film2.getActeurs(), film1_acteurs)
            && checkVecteur<unique_ptr<Critique>>(film2.getCritiques(), film1_critiques)) {
            points += 0.25;
        }
        else {
            cout << "\033[31m" << "Le constructeur par copie ne fonctionne pas correctement pour le vecteur acteurs et/ou critiques." << "\033[0m\n";
        }
    }
    else {
        cout << "\033[31m" << "Le constructeur par copie ne fonctionne pas correctement." << "\033[0m\n";
    }

    Film film3 = film1;
    // Test de l'operateur =
    if (checkFilm(film3, TITRE_1, ANNEE_SORTIE_1, REALISATEUR_1, DUREE_1)) {
        points += 0.25;

        if (checkVecteur<shared_ptr<Acteur>>(film3.getActeurs(), film1_acteurs)
            && checkVecteur<unique_ptr<Critique>>(film3.getCritiques(), film1_critiques)) {
            points += 0.25;
        }
        else {
            cout << "\033[31m" << "L'operateur = ne fonctionne pas correctement pour le vecteur acteurs et/ou critiques." << "\033[0m\n";
        }
    }
    else {
        cout << "\033[31m" << "L'operateur = ne fonctionne pas correctement." << "\033[0m\n";
    }

    // Test de l'operateur +=
    film1 += acteur1;
    film1 += critique1;

    if (film1.isActeurPresent(NOM_1) && film1.isCritiquePresent(AUTEUR_1)) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Un ou des operateurs += ne fonctionne(nt) pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'operateur ==
    if (film2 == film1) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "L'operateur == ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'operateur -=
    film1 -= acteur1;
    film1 -= critique1;

    if (!film1.isActeurPresent(NOM_1) && !film1.isCritiquePresent(AUTEUR_1) && film1.getActeurs().size() != 0) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "Un ou des operateurs -= ne fonctionne(nt) pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'operateur <<
    string sortie = testing::redirect_stdout([&] { cout << film3; });
    // Lire la sortie attendue
    ifstream fichier1("sortie_testAffichageFilm.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier1)), istreambuf_iterator<char>());

    if (sortie == sortieAttendue) {
        points += 0.5;
    }
    else {
        cout << "\033[31m" << "L'operateur << ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    return points;
}

// Test de la classe Polyflix (3 points)
double testPolyflix(Polyflix& polyflix) {
    double points = 0.0;

    // Test du constructeur par copie
    Polyflix copyPolyflix = Polyflix(polyflix);
    if (copyPolyflix.getNombreTotalFilms() == polyflix.getNombreTotalFilms() && polyflix.getNombreTotalFilms() != 0) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "Le constructeur de copie ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode chercherFilmParTitre
    Film* filmTrouve = polyflix.chercherFilmParTitre(TITRE_1);
    if (filmTrouve != nullptr && filmTrouve->getTitre() == TITRE_1) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode chercherFilmParTitre ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode chercherUtilisateur
    Utilisateur* utilisateurTrouve = polyflix.chercherUtilisateur(AUTEUR_1);
    if (utilisateurTrouve != nullptr && utilisateurTrouve->getNomUtilisateur() == AUTEUR_1) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode chercherUtilisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode getNombreUtilisateurs
    if (polyflix.getNombreUtilisateurs() == 3) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode getNombreUtilisateurs ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode utilisateurExiste
    if (polyflix.utilisateurExiste(AUTEUR_1)) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode utilisateurExiste ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode connecterUtilisateur
    if (polyflix.connecterUtilisateur(AUTEUR_1, MOT_DE_PASSE_1) && !polyflix.connecterUtilisateur(AUTEUR_1, "incorrectPassword")) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode connecterUtilisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode modifierMotDePasse
    string nouveauMotDePasse = "newPassword";
    if (polyflix.modifierMotDePasse(AUTEUR_1, nouveauMotDePasse) && polyflix.connecterUtilisateur(AUTEUR_1, nouveauMotDePasse)) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode modifierMotDePasse ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de la méthode visionnerFilm
    if (polyflix.visionnerFilm(AUTEUR_1, TITRE_1)) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode visionnerFilm ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    if (polyflix.getNombreUtilisateursAyantVisionne(TITRE_1) == 1 &&
        polyflix.getNombreTotalFilmsVisionnes() == 1) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode getNombreUtilisateursAyantVisionne  ou getNombreTotalFilmsVisionnes ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    vector<shared_ptr<Film>> filmsVus = polyflix.listerFilmsVisionnesParUtilisateur(AUTEUR_1);
    if (!filmsVus.empty()) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "La methode listerFilmsVisionnesParUtilisateur ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Test de l'opérateur []
    Film* filmCherche = polyflix[TITRE_2];
    if (filmCherche && filmCherche->getTitre() == TITRE_2) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "L'operateur [] ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    // Lire la sortie attendue
    ifstream fichier1("sortie_afficherListeFilms.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier1)),
        istreambuf_iterator<char>());

    // Comparer la sortie attendue avec la sortie du programme
    string sortie = testing::redirect_stdout([&]() { cout << polyflix; });

    if (sortieAttendue == sortie) {
        points += 0.2;
    }
    else {
        cout << "\033[31m" << "Échec du test afficherFilm." << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    polyflix -= TITRE_1;
    polyflix -= TITRE_2;
    polyflix -= TITRE_3;

    if (polyflix.getNombreTotalFilms() == 1
        && polyflix.chercherFilmParTitre(TITRE_1) == nullptr
        && polyflix.chercherFilmParTitre(TITRE_2) == nullptr
        && polyflix.chercherFilmParTitre(TITRE_3) == nullptr
        && polyflix.chercherFilmParTitre(TITRE_4) != nullptr) {
        points += 0.6;
    }
    else {
        cout << "\033[31m" << "Un ou des operateurs -= film ne fonctionne(nt) pas correctement." << "\033[0m\n";
    }
    return points;
}

void lancerTests(Polyflix polyflix) {
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
    cout << "\033[32m => " << fixed << setprecision(1) << point3 << "/3.0" << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m" << "Lancement des tests pour la classe Polyflix." << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point4 = testPolyflix(polyflix);
    cout << "\033[32m => " << fixed << setprecision(1) << point4 << "/3.0" << "\033[0m\n";

    cout << SEPARATEUR_2;
    cout << "Total des points: " << "\033[32m" << fixed << setprecision(1) << point1 + point2 + point3 + point4 << "/8.0" << "\033[0m" << endl;
    cout << SEPARATEUR_1;
    cout << "A cela s'ajoute 2 points pour le fonctionnement du menu!" << endl;
    cout << SEPARATEUR_2;
}