#include "vue.h"
#include "ui_vue.h"

Q_DECLARE_METATYPE(Film)
Q_DECLARE_METATYPE(const Film*)

/**
 * @brief Constructeur de la classe Vue
 */
Vue::Vue(GestionnaireFilms* gestionnaire, Utilisateur* utilisateur, QWidget *parent)
    : QMainWindow(parent), gestionnaire_(gestionnaire), utilisateur_(utilisateur)
    , ui(new Ui::Vue)
{
    ui->setupUi(this);
    setup();
}

/**
 * @brief Destructeur de la classe Vue avec titre et note.
 */
Vue::~Vue()
{
    delete ui;
}

/**
 * @brief Initialise l'interface utilisateur et les configurations initiales de la fen�tre Vue.
 */
void Vue::setup()
{
  setUI();
  chargerFilmPolyflix();
  etablirConnections();
}

/**
 * @brief G�re la s�lection d'un film dans la liste Polyflix.
 *
 * @param item L'�l�ment QListWidgetItem s�lectionn� repr�sentant un film.
 */
void Vue::selectionnerFilmPolyflix(QListWidgetItem* item) {
    Film film = item->data(Qt::UserRole).value<Film>();
    ui->lineEditTitre->setText(QString::fromStdString(film.getTitre()));
    ui->lineEditNote->setText(QString::number(film.getNote()));
}


/**
 * @brief G�re la s�lection d'un film dans la liste personnelle de l'utilisateur.
 *
 * @param item L'�l�ment QListWidgetItem s�lectionn� repr�sentant un film.
 */
void Vue::selectionnerFilmListe(QListWidgetItem* item) {
    const Film* film = item->data(Qt::UserRole).value<const Film*>();
    ui->lineEditTitre->setText(QString::fromStdString(film->getTitre()));
    ui->lineEditNote->setText(QString::number(film->getNote()));
}

/**
 * @brief Ajoute un film � la liste personnelle de l'utilisateur.
 */
void Vue::ajouterFilm() {
    // TODO :  insérer  le gestionnaire d'exception
     const Film* film = gestionnaire_->chercherFilm(ui->lineEditTitre->text().toStdString());
    utilisateur_->ajouterFilm(film);
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(film->getTitre()), ui->maListe);
    item->setData(Qt::UserRole, QVariant::fromValue<const Film*>(film));
}

/**
 * @brief Retire un film de la liste personnelle de l'utilisateur.
 */
void Vue::retirerFilm() {
    // TODO insérer  le gestionnaire d'exception
    const Film* jeu = gestionnaire_->chercherFilm(ui->lineEditTitre->text().toStdString()); 
      utilisateur_->retirerFilm(jeu);
      chargerFilmListe();    
}

/**
 * @brief �tablit les connexions entre les �l�ments de l'interface utilisateur et leurs slots correspondants.
 */
void Vue::etablirConnections() {
    // TODO
}

/**
 * @brief Initialise et configure les composants de l'interface utilisateur.
 */
void Vue::setUI() {

    ui->polyflixLib->setSortingEnabled(true);

    ui->lineEditTitre->setDisabled(true);
    ui->lineEditNote->setDisabled(true);

    ui->maListe->setSortingEnabled(true);
}

/**
 * @brief Charge la liste des films du gestionnaire dans la liste de l'interface utilisateur Polyflix.
 */
void Vue::chargerFilmPolyflix() {
    ui->polyflixLib->clear();
    for (Film film : gestionnaire_->getFilms()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(film.getTitre()), ui->polyflixLib);
        item->setData(Qt::UserRole, QVariant::fromValue<Film>(film));
    }
}

/**
 * @brief Charge la liste personnelle des films de l'utilisateur dans la liste de l'interface utilisateur.
 */
void Vue::chargerFilmListe() {
   ui->maListe->clear();
  for (const Film* jeu : utilisateur_->getFilms()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(jeu->getTitre()), ui->maListe);
        item->setData(Qt::UserRole, QVariant::fromValue<const Film*>(jeu));
    }
}

/**
 * @brief Affiche un message d'erreur dans une modale.
 *
 * @param msg Le message � afficher dans la bo�te de dialogue.
 */
void Vue::afficherMessage(QString msg) {
    QMessageBox mbox;
    mbox.setText(msg);
    mbox.exec();
}
