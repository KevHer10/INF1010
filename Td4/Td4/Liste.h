/*
Fichier: Liste.h
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation de liste.
*/
#pragma once
#include <memory>
#include <iostream>

using namespace std;

const int CAPACITE_DEFAUT = 25;

// TODO 
template <typename T>
class Liste {
public:
    /// @brief Constructeur par d�faut de la classe Liste avec capacit� par d�faut.
    Liste() : nElements_(0), elements_(make_unique<shared_ptr<T>[]>(CAPACITE_DEFAUT)) {}

    /// @brief Constructeur de la classe Liste avec une capacit� sp�cifi�e.
    /// @param nElements Le nombre initial d'�l�ments dans la liste.
    Liste(int nElements) : nElements_(nElements), elements_(make_unique<shared_ptr<T>[]>(nElements)) {}

    /// @brief Constructeur de copie de la classe Liste.
    /// @param autre L'objet Liste � copier.
    Liste(const Liste& autre) : nElements_(autre.nElements_), elements_(make_unique<shared_ptr<T>[]>(autre.nElements_)) {
        copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
    }

    /// @brief Surcharge de l'op�rateur d'assignation de la classe Liste.
    /// @param autre L'objet Liste � assigner.
    /// @return Une r�f�rence vers l'objet Liste apr�s l'assignation.
    Liste& operator=(const Liste& autre) {
        if (this != &autre) {
            nElements_ = autre.nElements_;
            elements_ = make_unique<shared_ptr<T>[]>(autre.nElements_);
            copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
        }
        return *this;
    }

    /// @brief Destructeur de la classe Liste.
    ~Liste() {}

    /// @brief Surcharge de l'op�rateur d'indexation pour acc�der � un �l�ment de la liste.
    /// @param index L'indice de l'�l�ment � acc�der.
    /// @return Une r�f�rence vers le pointeur partag� � l'indice sp�cifi�.
    shared_ptr<T>& operator[](int index) const { return elements_[index]; }

    /// @brief Surcharge de l'op�rateur d'ajout pour ajouter un �l�ment � la liste.
    /// @param element L'�l�ment � ajouter � la liste.
    void operator+=(const T& element) { elements_[nElements_++] = make_shared<T>(element); }

    /// @brief Obtient le nombre d'�l�ments dans la liste.
    /// @return Le nombre d'�l�ments dans la liste.
    int obtenirNbElements() const { return nElements_; }

    /// @brief Obtient un it�rateur pointant vers le d�but de la liste.
    /// @return Un pointeur vers le d�but de la liste.
    shared_ptr<T>* begin() const { return elements_.get(); }

    /// @brief Obtient un it�rateur pointant vers la fin de la liste.
    /// @return Un pointeur vers la fin de la liste.
    shared_ptr<T>* end() const { return elements_.get() + nElements_; }

    /// @brief Surcharge de l'op�rateur de sortie pour afficher les �l�ments de la liste.
    /// @param os Le flux de sortie o� afficher les �l�ments.
    /// @param liste L'objet Liste � afficher.
    /// @return Le flux de sortie mis � jour.
    friend ostream& operator<<(ostream& os, const Liste<T>& liste) {
        for (int j = 0; j < liste.nElements_; j++) {
            if (j != liste.nElements_ - 1) {
                os << *(liste.elements_[j]) << endl;
            }
            else {
                os << *(liste.elements_[j]);
            }
        }
        return os;
    }

private:
    int nElements_ = 0;
    unique_ptr<shared_ptr<T>[]> elements_;
};
