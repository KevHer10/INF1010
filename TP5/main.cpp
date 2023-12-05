#include "vue.h"
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GestionnaireFilms gestionnaire;
    gestionnaire.chargerDepuisFichier("C:\\Users\\TODO"); // TODO! INSERER CHEMIN ABSOLU VERS films.txt

    Utilisateur utilisateur("user", 20);

    Vue w(&gestionnaire, &utilisateur);

    w.show();

    return a.exec();
}
