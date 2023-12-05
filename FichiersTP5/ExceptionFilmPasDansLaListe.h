#ifndef EXCEPTIONFILMPASDANSLALISTE_H
#define EXCEPTIONFILMPASDANSLALISTE_H

#include <QException>

/**
 * @brief Exception personnalis�e pour indiquer qu'un film n'est pas dans la liste.
 *
 * Cette exception est lev�e lorsqu'une tentative est faite pour acc�der ou retirer un film
 * qui n'est pas pr�sent dans la liste de l'utilisateur.
 */
class ExceptionFilmPasDansLaListe: public QException
{
// TODO
private :
    QString s_;
};

#endif // EXCEPTIONFILMPASDANSLALISTE_H
