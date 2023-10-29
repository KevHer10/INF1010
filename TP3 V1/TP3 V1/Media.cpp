#include "Media.h"

// Constructeur
Media::Media() : titre_(""), anneeDeSortie_(0), categorie_(Categorie::ACTION) {}

Media::Media(string titre, int anneeDeSortie, Categorie categorie)
    : titre_(titre), anneeDeSortie_(anneeDeSortie), categorie_(categorie) {}

// Methodes virtuelles surchargees
float Media::obtenirEvaluation() const { 
    float moyenne = 0;
    
    for (auto& critique : critiques_) {

        moyenne += critique.obtenirEvaluation();
    }
    
    return moyenne/critiques_.size();

}  // TODO

// Opeators
void Media::operator+=(shared_ptr<Cast> cast) {
    casts_.push_back(cast);
}  // TODO

void Media::operator+=(Critique critique) {
    critiques_.push_back(critique);
}  // TODO

// Methodes d'affichage
void Media::afficher(ostream& os) const { }  // TODO

ostream& operator<<(ostream& os, const Media& media) { return os; }  // TODO
