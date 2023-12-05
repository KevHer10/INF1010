#include "GestionnaireFilms.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/**
 * @brief Surcharge de l'opérateur '+=' pour ajouter un film à la collection.
 *
 * @param film L'objet Film à ajouter.
 * @return GestionnaireFilms& Référence à ce gestionnaire de films.
 */
GestionnaireFilms& GestionnaireFilms::operator+=(const Film& film)
{
    if (films_.size() < nbFilmsMax) {
        films_.push_back(film);
    }
    return *this;
}

/**
 * @brief Surcharge de l'opérateur '-=' pour retirer un film de la collection par son titre.
 *
 * @param titre Le titre du film à retirer.
 * @return GestionnaireFilms& Référence à ce gestionnaire de films.
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
 * @brief Surcharge de l'opérateur '-=' pour retirer un film de la collection.
 *
 * @param film L'objet Film à retirer.
 * @return GestionnaireFilms& Référence à ce gestionnaire de films.
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
 * @param titreFilm Le titre du film à chercher.
 * @return const Film* Pointeur vers le film trouvé, ou nullptr si non trouvé.
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
 * @param nomFichier Le chemin ABSOLU vers le fichier à lire.
 * @return bool Vrai si le chargement est réussi, faux autrement.
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
 * @brief Surcharge de l'opérateur '<<' pour afficher les films du gestionnaire.
 *
 * @param stream Le flux de sortie.
 * @param gestionnaireFilms L'objet GestionnaireFilms à afficher.
 * @return std::ostream& Le flux de sortie modifié.
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
 * @brief Obtient une référence vers la collection de films.
 *
 * @return std::vector<Film>& Référence vers la collection de films.
 */
std::vector<Film>& GestionnaireFilms::getFilms() {
    return films_;
}

/**
 * @brief Lit une ligne de texte et crée un objet Film à partir de celle-ci.
 *
 * @param ligne La ligne de texte représentant un film.
 * @return bool Vrai si la lecture et la création du film sont réussies.
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
