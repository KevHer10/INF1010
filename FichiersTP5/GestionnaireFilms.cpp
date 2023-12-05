#include "GestionnaireFilms.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/**
 * @brief Surcharge de l'op�rateur '+=' pour ajouter un film � la collection.
 *
 * @param film L'objet Film � ajouter.
 * @return GestionnaireFilms& R�f�rence � ce gestionnaire de films.
 */
GestionnaireFilms& GestionnaireFilms::operator+=(const Film& film)
{
    if (films_.size() < nbFilmsMax) {
        films_.push_back(film);
    }
    return *this;
}

/**
 * @brief Surcharge de l'op�rateur '-=' pour retirer un film de la collection par son titre.
 *
 * @param titre Le titre du film � retirer.
 * @return GestionnaireFilms& R�f�rence � ce gestionnaire de films.
 */
GestionnaireFilms& GestionnaireFilms::operator-=(const std::string& titre)
{
    auto it = std::find_if(films_.begin(), films_.end(), [&titre](const Film& film) {
        return film.getTitre() == titre;
    });

    if (it != films_.end()) {
        films_.erase(it);
    }

    return *this;
}

/**
 * @brief Surcharge de l'op�rateur '-=' pour retirer un film de la collection.
 *
 * @param film L'objet Film � retirer.
 * @return GestionnaireFilms& R�f�rence � ce gestionnaire de films.
 */
GestionnaireFilms& GestionnaireFilms::operator-=(const Film& film)
{
    auto it = std::find(films_.begin(), films_.end(), film);
    if (it != films_.end()) {
        films_.erase(it);
    }

    return *this;
}

/**
 * @brief Cherche un film par son titre dans la collection.
 *
 * @param titreFilm Le titre du film � chercher.
 * @return const Film* Pointeur vers le film trouv�, ou nullptr si non trouv�.
 */
const Film* GestionnaireFilms::chercherFilm(const std::string& titreFilm) const
{
    auto it = std::find_if(films_.begin(), films_.end(), [&titreFilm](const Film& film) {
        return film.getTitre() == titreFilm;
    });

    if (it != films_.end()) {
        return &(*it);
    }

    return nullptr;
}

/**
 * @brief Charge les films depuis un fichier.
 *
 * @param nomFichier Le chemin ABSOLU vers le fichier � lire.
 * @return bool Vrai si le chargement est r�ussi, faux autrement.
 */
bool GestionnaireFilms::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        films_.clear();
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            if (lireLigneFilm(ligne) == false)
            {
                return false;
            }
        }
        return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez-vous de le mettre au bon endroit.\n";

    return false;
}

/**
 * @brief Surcharge de l'op�rateur '<<' pour afficher les films du gestionnaire.
 *
 * @param stream Le flux de sortie.
 * @param gestionnaireFilms L'objet GestionnaireFilms � afficher.
 * @return std::ostream& Le flux de sortie modifi�.
 */
std::ostream& operator<<(std::ostream& stream, const GestionnaireFilms& gestionnaireFilms)
{
    for (const Film& film : gestionnaireFilms.films_)
    {
        stream << film << std::endl;
    }

    return stream;
}

/**
 * @brief Obtient le nombre de films dans la collection.
 *
 * @return std::size_t Le nombre de films.
 */
std::size_t GestionnaireFilms::getNbFilms() const
{
    return films_.size();
}

/**
 * @brief Obtient une r�f�rence vers la collection de films.
 *
 * @return std::vector<Film>& R�f�rence vers la collection de films.
 */
std::vector<Film>& GestionnaireFilms::getFilms() {
    return films_;
}

/**
 * @brief Lit une ligne de texte et cr�e un objet Film � partir de celle-ci.
 *
 * @param ligne La ligne de texte repr�sentant un film.
 * @return bool Vrai si la lecture et la cr�ation du film sont r�ussies.
 */
bool GestionnaireFilms::lireLigneFilm(const std::string& ligne)
{
    std::istringstream stream(ligne);
    std::string titreFilm;
    float noteFilm;

    if (stream >> std::quoted(titreFilm) >> noteFilm)
    {
        *this += Film(titreFilm, noteFilm);

        return true;
    }

    return false;
}
