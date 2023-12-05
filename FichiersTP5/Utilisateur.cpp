#include "Utilisateur.h"

/**
 * @brief Constructeur de la classe Utilisateur.
 *
 * @param nom Le nom de l'utilisateur.
 * @param age L'�ge de l'utilisateur.
 */
Utilisateur::Utilisateur(const std::string& nom, unsigned int age)
    : nom_(nom)
    , age_(age)
{
}

/**
 * @brief Surcharge de l'op�rateur '<<' pour afficher les informations de l'utilisateur.
 *
 * @param stream Le flux de sortie.
 * @param utilisateur L'objet Utilisateur � afficher.
 * @return std::ostream& Le flux de sortie modifi�.
 */
std::ostream& operator<<(std::ostream& stream, const Utilisateur& utilisateur)
{
    stream << utilisateur.nom_ << " (" << utilisateur.age_ << " ans). ";
    stream << "Films: [";
    for (std::size_t i = 0; i < utilisateur.listeFilms_.size(); ++i)
    {
        stream << utilisateur.listeFilms_[i]->getTitre();
        if (i != utilisateur.listeFilms_.size() - 1)
        {
            stream << ',';
        }
    }

    return stream << ']';
}

/**
 * @brief Obtient le nombre de films dans la liste de l'utilisateur.
 *
 * @return std::size_t Le nombre de films.
 */
std::size_t Utilisateur::getNbFilms() const
{
    return listeFilms_.size();
}

/**
 * @brief Obtient le nom de l'utilisateur.
 *
 * @return const std::string& Le nom de l'utilisateur.
 */
const std::string& Utilisateur::getNom() const
{
    return nom_;
}

/**
 * @brief Obtient l'�ge de l'utilisateur.
 *
 * @return unsigned int L'�ge de l'utilisateur.
 */
unsigned int Utilisateur::getAge() const
{
    return age_;
}

/**
 * @brief Ajoute un film � la liste de l'utilisateur.
 *
 * @param film Le pointeur vers le film � ajouter.
 */
void Utilisateur::ajouterFilm(const Film* film)
{
    // TODO
}

/**
 * @brief Retire un film de la liste de l'utilisateur.
 *
 * @param film Le pointeur vers le film � retirer.
 */
void Utilisateur::retirerFilm(const Film* film)
{
    // TODO
}

/**
 * @brief Obtient une r�f�rence vers la liste des films de l'utilisateur.
 *
 * @return std::vector<const Film*>& R�f�rence vers la liste des films.
 */
std::vector<const Film*>& Utilisateur::getFilms() {
    return listeFilms_;
}
