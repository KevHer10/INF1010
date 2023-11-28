#pragma once
#include <memory>
#include <iostream>

using namespace std;

const int CAPACITE_DEFAUT = 25;

// TODO 
template <typename T>
class Liste {
public:
    Liste(): nElements_(0), elements_(make_unique<shared_ptr<T>[]>(CAPACITE_DEFAUT)){}

    Liste(int nElements) : nElements_(nElements), elements_(make_unique<shared_ptr<T>[]>(nElements)){}

    Liste(const Liste& autre) : nElements_(autre.nElements_), elements_(make_unique<shared_ptr<T>[]>(autre.nElements_)) {
        copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
    }

    Liste& operator=(const Liste& autre) {
        if (this != &autre) {
            nElements_ = autre.nElements_;
            elements_ = make_unique<shared_ptr<T>[]>(autre.nElements_);
            copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
        }
        return *this;
    }
    
    ~Liste() {};

    shared_ptr<T>& operator[](int index) const { return elements_[index]; }

    void operator+=(const T& element) { elements_[nElements_++] = make_shared<T>(element); }
    
    int obtenirNbElements() const { return nElements_; }
    
    shared_ptr<T>* begin() const { return elements_.get(); }

    shared_ptr<T>* end() const { return elements_.get() + nElements_; }


    
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
