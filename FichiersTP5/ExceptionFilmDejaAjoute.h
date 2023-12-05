#ifndef EXCEPTIONFILMDEJAAJOUTE_H
#define EXCEPTIONFILMDEJAAJOUTE_H

#include <QException>

/**
 * @brief Exception personnalis�e pour indiquer qu'un film a d�j� �t� ajout� � la liste.
 *
 * Cette exception est lev�e lorsqu'une tentative est faite pour ajouter un film
 * qui est d�j� pr�sent dans la liste de l'utilisateur.
 */
class ExceptionFilmDejaAjoute: public QException
{
// TODO
private :
    QString s_;
};

#endif // EXCEPTIONFILMDEJAAJOUTE_H
