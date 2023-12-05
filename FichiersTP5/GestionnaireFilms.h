#ifndef GESTIONNAIREFILMS_H
#define GESTIONNAIREFILMS_H

#include <ostream>
#include <string>
#include <vector>

#include "Film.h"

class GestionnaireFilms
{
public:
    GestionnaireFilms() = default;

    GestionnaireFilms& operator+=(const Film& film);
    GestionnaireFilms& operator-=(const std::string& titre);
    GestionnaireFilms& operator-=(const Film& film);

    const Film* chercherFilm(const std::string& titreFilm) const;
    bool chargerDepuisFichier(const std::string& nomFichier);

    friend std::ostream& operator<<(std::ostream& stream, const GestionnaireFilms& gestionnaireFilms);

    std::size_t getNbFilms() const;
    std::vector<Film>& getFilms();

    static constexpr std::size_t nbFilmsMax = 100;

private:
    bool lireLigneFilm(const std::string& ligne);

    std::vector<Film> films_;
};

#endif // GESTIONNAIREFILMS_H
