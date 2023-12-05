#ifndef VUE_H
#define VUE_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>

#include "Film.h"
#include "Utilisateur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Vue; }
QT_END_NAMESPACE

class Vue : public QMainWindow
{
    Q_OBJECT

public:
    Vue(GestionnaireFilms* gestionnaire, Utilisateur* utilisateur, QWidget *parent = nullptr);
    ~Vue();
    void setup();

public slots:
    void selectionnerFilmPolyflix(QListWidgetItem*);
    void selectionnerFilmListe(QListWidgetItem*);
    void ajouterFilm();
    void retirerFilm();

private:
    void setUI();
    void etablirConnections();
    void chargerFilmPolyflix();
    void chargerFilmListe();
    void afficherMessage(QString msg);

    GestionnaireFilms* gestionnaire_;
    Utilisateur* utilisateur_;

    Ui::Vue *ui;
};
#endif // VUE_H
