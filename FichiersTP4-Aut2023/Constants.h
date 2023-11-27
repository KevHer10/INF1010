#pragma once

// Acteurs /////////////////////////////////////////////////////////////////////
string NOM_ACTEUR_A = "Leonardo DiCaprio";
int ANNEE_NAISSANCE_ACTEUR_A = 1974;
string BIO_ACTEUR_A = "Leonardo DiCaprio is an American actor and producer. He is known for his roles in films like 'Titanic', 'Inception', and 'The Revenant'.";
int SALAIRE_ACTEUR_A = 25000000;
string AGENCE_ACTEUR_A = "LBI Entertainment";
vector<string> ROLESJOUES_ACTEUR_A = { "Jack Dawson", "Jay Gatsby", "Jordan Belfort", "Billy Costigan", "Rick Dalton", "Arnie Grape", "Hugh Glass", "Cobb", "Howard Hughes", "Frank W. Abagnale Jr.", "J. Edgar Hoover", "Amsterdam Vallon", "Calvin Candie" };

string NOM_ACTEUR_B = "Brendan Fraser";
int ANNEE_NAISSANCE_ACTEUR_B = 1968;
string BIO_ACTEUR_B = "Brendan Fraser is a Canadian-American actor. He is best known for his role as 'Rick O'Connell' in 'The Mummy' series.";
int SALAIRE_ACTEUR_B = 1000000;
string AGENCE_ACTEUR_B = "CAA Talent Agency";
vector<string> ROLESJOUES_ACTEUR_B = { "Rick O'Connell", "Cliff Steele", "George of the Jungle", "David Greene", "Rick O'Connell" };

string NOM_ACTEUR_C = "Michael Mando";
int ANNEE_NAISSANCE_ACTEUR_C = 1981;
string BIO_ACTEUR_C = "Michael Mando is a Canadian actor known for his role as Nacho Varga in 'Better Call Saul' and Vaas Montenegro in the video game 'Far Cry 3'.";
int SALAIRE_ACTEUR_C = 500000;
string AGENCE_ACTEUR_C = "Unknown";
vector<string> ROLESJOUES_ACTEUR_C = { "Nacho Varga", "Vaas Montenegro" };

// Réalisateurs ////////////////////////////////////////////////////////////////
string NOM_REALISATEUR_A = "Quentin Tarantino";
int ANNEE_NAISSANCE_REALISATEUR_A = 1963;
string BIO_REALISATEUR_A = "Quentin Jerome Tarantino is an American film director, screenwriter, producer, and actor. He is best known for his movies like 'Pulp Fiction', 'Kill Bill', and 'Django Unchained'.";
int SALAIRE_REALISATEUR_A = 18000000;
string STUDIO_A = "A Band Apart";

string NOM_REALISATEUR_B = "Rob Cohen";
int ANNEE_NAISSANCE_REALISATEUR_B = 1949;
string BIO_REALISATEUR_B = "Rob Cohen is an American director, known for his work on movies such as 'The Fast and the Furious' and 'xXx'.";
int SALAIRE_REALISATEUR_B = 5000000;
string STUDIO_B = "FGG Productions";  // Make sure to validate the studio name as the given one aligns with F. Gary Gray's initials.

string NOM_REALISATEUR_C = "Vince Gilligan";
int ANNEE_NAISSANCE_REALISATEUR_C = 1967;
string BIO_REALISATEUR_C = "Vince Gilligan is an American writer, producer, and director, best known for creating the television series 'Breaking Bad' and its spin-off 'Better Call Saul'.";
int SALAIRE_REALISATEUR_C = 300000;
string STUDIO_C = "Bella Donna Productions";  // Please validate this studio name as well.

// Films //////////////////////////////////////////////////////////////////////
string TITRE_FILM_1 = "Django Unchained";
int ANNEE_SORTIE_FILM_1 = 2012;
Categorie CATEGORIE_FILM_1 = Categorie::DRAME;
int DUREE_FILM_1 = 165;

string TITRE_FILM_2 = "The Mummy";
int ANNEE_SORTIE_FILM_2 = 1999;
Categorie CATEGORIE_FILM_2 = Categorie::ACTION;
int DUREE_FILM_2 = 125;

// Serie //////////////////////////////////////////////////////////////////////
string TITRE_SERIE_1 = "Better Call Saul";
int ANNEE_SORTIE_SERIE_1 = 2015;
Categorie CATEGORIE_SERIE_1 = Categorie::DRAME;
map<int, vector<pair<int, int>>> EPISODES_SERIE_1 = {
    {1, {{1, 53}, {2, 47}, {3, 47}, {4, 42}, {5, 43}, {6, 41}, {7, 45}, {8, 43}, {9, 47}, {10, 48}}},
    {2, {{1, 47}, {2, 47}, {3, 42}, {4, 43}, {5, 44}, {6, 46}, {7, 45}, {8, 43}, {9, 47}, {10, 49}}},
    {3, {{1, 42}, {2, 45}, {3, 42}, {4, 43}, {5, 44}, {6, 46}, {7, 49}, {8, 44}, {9, 45}, {10, 48}}},
    {4, {{1, 47}, {2, 47}, {3, 42}, {4, 45}, {5, 45}, {6, 49}, {7, 47}, {8, 47}, {9, 50}, {10, 61}}},
    {5, {{1, 52}, {2, 47}, {3, 48}, {4, 44}, {5, 42}, {6, 47}, {7, 49}, {8, 44}, {9, 49}, {10, 50}}}
};

// Utilisateurs ///////////////////////////////////////////////////////////////
string AUTEUR_1 = "Kevin";
string MOT_DE_PASSE_1 = "1234";
string COMMENTAIRE_1 = "Super film!";
int NOTE_1 = 5;

string AUTEUR_2 = "Ryan";
string MOT_DE_PASSE_2 = "0000";
string COMMENTAIRE_2 = "Je n'ai pas compris la fin D:";
int NOTE_2 = 2;

string AUTEUR_3 = "Alex";
string MOT_DE_PASSE_3 = "iujug98eut093mc09ti2rxri490itm0c3qur0t9nu43cut483mcxtrm48xrtu487u5rn4b7v5tundx458m943mtxm439cn48n5vcmxq39";
string COMMENTAIRE_3 = "Un spin-off à la hauteur de Breaking Bad!";
int NOTE_3 = 4;

// Autres //////////////////////////////////////////////////////////////////////
string SEPARATEUR_1 = "\033[35m--------------------------------------------------------------------------------------\033[0m\n";
string SEPARATEUR_2 = "\033[35m======================================================================================\033[0m\n";
string ASCII_ART = R"(
 /$$$$$$$   /$$$$$$  /$$   /$$     /$$ /$$$$$$$$ /$$       /$$$$$$ /$$   /$$       /$$$$$$$$ /$$$$$$$  /$$   /$$
| $$__  $$ /$$__  $$| $$  |  $$   /$$/| $$_____/| $$      |_  $$_/| $$  / $$      |__  $$__/| $$__  $$| $$  | $$
| $$  \ $$| $$  \ $$| $$   \  $$ /$$/ | $$      | $$        | $$  |  $$/ $$/         | $$   | $$  \ $$| $$  | $$
| $$$$$$$/| $$  | $$| $$    \  $$$$/  | $$$$$   | $$        | $$   \  $$$$/          | $$   | $$$$$$$/| $$$$$$$$
| $$____/ | $$  | $$| $$     \  $$/   | $$__/   | $$        | $$    >$$  $$          | $$   | $$____/ |_____  $$
| $$      | $$  | $$| $$      | $$    | $$      | $$        | $$   /$$/\  $$         | $$   | $$            | $$
| $$      |  $$$$$$/| $$$$$$$$| $$    | $$      | $$$$$$$$ /$$$$$$| $$  \ $$         | $$   | $$            | $$
|__/       \______/ |________/|__/    |__/      |________/|______/|__/  |__/         |__/   |__/            |__/
)";