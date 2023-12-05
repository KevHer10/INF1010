#ifndef FILM_H
#define FILM_H

#include <ostream>
#include <string>
#include <QMetaType>

class Film
{
public:
    Film();
    Film(std::string titre, float note);

    friend std::ostream& operator<<(std::ostream &stream, const Film& film);

    bool operator<(const Film& film) const;
    bool operator>(const Film& film) const;
    bool operator==(const Film& film) const;
    bool operator==(const std::string& titre) const;
    friend bool operator==(const std::string& titre, const Film& film);

    const std::string& getTitre() const;
    float getNote() const;

private:
    std::string titre_;
    float note_;
};

Q_DECLARE_METATYPE(Film*)

#endif // FILM_H
