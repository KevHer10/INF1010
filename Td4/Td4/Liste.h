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
    /// @brief Constructeur par défaut de la classe Liste avec capacité par défaut.
    Liste() : nElements_(0), elements_(make_unique<shared_ptr<T>[]>(CAPACITE_DEFAUT)) {}

    /// @brief Constructeur de la classe Liste avec une capacité spécifiée.
    /// @param nElements Le nombre initial d'éléments dans la liste.
    Liste(int nElements) : nElements_(nElements), elements_(make_unique<shared_ptr<T>[]>(nElements)) {}

    /// @brief Constructeur de copie de la classe Liste.
    /// @param autre L'objet Liste à copier.
    Liste(const Liste& autre) : nElements_(autre.nElements_), elements_(make_unique<shared_ptr<T>[]>(autre.nElements_)) {
        copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
    }

    /// @brief Surcharge de l'opérateur d'assignation de la classe Liste.
    /// @param autre L'objet Liste à assigner.
    /// @return Une référence vers l'objet Liste après l'assignation.
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

    /// @brief Surcharge de l'opérateur d'indexation pour accéder à un élément de la liste.
    /// @param index L'indice de l'élément à accéder.
    /// @return Une référence vers le pointeur partagé à l'indice spécifié.
    shared_ptr<T>& operator[](int index) const { return elements_[index]; }

    /// @brief Surcharge de l'opérateur d'ajout pour ajouter un élément à la liste.
    /// @param element L'élément à ajouter à la liste.
    void operator+=(const T& element) { elements_[nElements_++] = make_shared<T>(element); }

    /// @brief Obtient le nombre d'éléments dans la liste.
    /// @return Le nombre d'éléments dans la liste.
    int obtenirNbElements() const { return nElements_; }

    /// @brief Obtient un itérateur pointant vers le début de la liste.
    /// @return Un pointeur vers le début de la liste.
    shared_ptr<T>* begin() const { return elements_.get(); }

    /// @brief Obtient un itérateur pointant vers la fin de la liste.
    /// @return Un pointeur vers la fin de la liste.
    shared_ptr<T>* end() const { return elements_.get() + nElements_; }

    /// @brief Surcharge de l'opérateur de sortie pour afficher les éléments de la liste.
    /// @param os Le flux de sortie où afficher les éléments.
    /// @param liste L'objet Liste à afficher.
    /// @return Le flux de sortie mis à jour.
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
