#include "Film.h"
#include <limits>

/**
 * @brief Constructeur par défaut de la classe Film.
 * Initialise un film avec un titre inconnu et une note maximale.
 */
Film::Film()
    : titre_("Unknown")
    , note_(std::numeric_limits<float>::max())
{
}

/**
 * @brief Constructeur de la classe Film avec titre et note.
 *
 * @param titre Le titre du film.
 * @param note La note du film.
 */
Film::Film(std::string titre, float note)
    : titre_(std::move(titre))
    , note_(note)
{
}

/**
 * @brief Surcharge de l'opérateur '<<' pour l'affichage du film.
 *
 * @param stream Le flux de sortie.
 * @param film L'objet Film à afficher.
 * @return std::ostream& Le flux de sortie modifié.
 */
std::ostream& operator<<(std::ostream& stream, const Film& film)
{
    return stream << film.titre_ << ": " << film.note_ << "/10";
}

/**
 * @brief Surcharge de l'opérateur '<' pour comparer deux films par leur note.
 *
 * @param film L'objet Film à comparer.
 * @return bool Vrai si la note de ce film est inférieure à celle de l'autre.
 */
bool Film::operator<(const Film& film) const
{
    return note_ < film.note_;
}

/**
 * @brief Surcharge de l'opérateur '>' pour comparer deux films par leur note.
 *
 * @param film L'objet Film à comparer.
 * @return bool Vrai si la note de ce film est supérieure à celle de l'autre.
 */
bool Film::operator>(const Film& film) const
{
    return note_ > film.note_;
}

/**
 * @brief Surcharge de l'opérateur '==' pour comparer deux films.
 *
 * @param film L'objet Film à comparer.
 * @return bool Vrai si les deux films ont le même titre et la même note.
 */
bool Film::operator==(const Film& film) const
{
    return note_ == film.note_ && titre_ == film.titre_;
}

/**
 * @brief Surcharge de l'opérateur '==' pour comparer un film avec un titre.
 *
 * @param titre Le titre à comparer.
 * @return bool Vrai si le titre du film est égal au titre fourni.
 */
bool Film::operator==(const std::string& titre) const
{
    return titre_ == titre;
}

/**
 * @brief Surcharge globale de l'opérateur '==' pour comparer un titre avec un film.
 *
 * @param titre Le titre à comparer.
 * @param film L'objet Film à comparer.
 * @return bool Vrai si le titre est égal au titre du film.
 */
bool operator==(const std::string& titre, const Film& film)
{
    return titre == film.titre_;
}

/**
 * @brief Obtient le titre du film.
 *
 * @return const std::string& Le titre du film.
 */
const std::string& Film::getTitre() const
{
    return titre_;
}

/**
 * @brief Obtient la note du film.
 *
 * @return float La note du film.
 */
float Film::getNote() const
{
    return note_;
}
