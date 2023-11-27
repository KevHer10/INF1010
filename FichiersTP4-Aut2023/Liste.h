#pragma once
#include <memory>
#include <iostream>

using namespace std;

const int CAPACITE_DEFAUT = 25;

// TODO 
template <typename T>
class Liste {
public:
    Liste();
    Liste(int nElements);
    Liste(const Liste& autre);
    Liste& operator=(const Liste& autre);
    ~Liste();

    shared_ptr<T>& operator[](int index);
    void operator+=(const T& element);
    
    int obtenirNbElements() const;
    
    shared_ptr<T>* begin();
    shared_ptr<T>* end();
    
    friend ostream& operator<<(ostream& os, const Liste<T>& liste);

private:
    int nElements_ = 0;
    unique_ptr<shared_ptr<T>[]> elements_;
};
