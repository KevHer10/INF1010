#pragma once
#include <memory>
#include <iostream>

using namespace std;

const int CAPACITE_DEFAUT = 25;

// TODO 
template <typename T>
class Liste {
public:
    Liste(): nElements_(0), elements_(make_unique<shared_ptr<T>[CAPACITE_DEFAUT]>);

    Liste(int nElements) : nElements_(nElements), elements_(make_unique<shared_ptr<T>[nElements]>);

    Liste(const Liste& autre){
        
        if(this != &autre) {
            nElements_(autre.nElements_);
            elements_(make_unique<shared_ptr<T>[autre.nElements_]>);
            copy(autre.elements_.get(), autre.elements_.get() + autre.nElements_, elements_.get());
        }
        return this*;
    };
    
    
    Liste& operator=(const Liste& autre);
    ~Liste();

    shared_ptr<T>& operator[](int index) const;
    void operator+=(const T& element);
    
    int obtenirNbElements() const{return nElements_};
    
    shared_ptr<T>* begin() const;
    shared_ptr<T>* end() const;
    
    friend ostream& operator<<(ostream& os, const Liste<T>& liste);

private:
    int nElements_ = 0;
    unique_ptr<shared_ptr<T>[]> elements_;
};
