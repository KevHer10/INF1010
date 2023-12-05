#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include <QObject>

#include "GestionnaireFilms.h"
#include "Film.h"
#include "def.h"
#include "ExceptionFilmDejaAjoute.h"
#include "ExceptionFilmPasDansLaListe.h"

class Utilisateur : public QObject
{
    Q_OBJECT
 public:
     Utilisateur(const std::string& nom, unsigned int age);

     friend std::ostream& operator<<(std::ostream& stream, const Utilisateur& utilisateur);

     std::size_t getNbFilms() const;
     const std::string& getNom() const;
     unsigned int getAge() const;
     std::vector<const Film*>& getFilms();

 public Q_SLOTS:
     void ajouterFilm(const Film* film);    // TODO
     void retirerFilm(const Film* film);    // TODO

 Q_SIGNALS:
     void listeModifiee();

 private:
     std::vector<const Film*> listeFilms_;
     std::string nom_;
     unsigned int age_;
};

#endif // UTILISATEUR_H
