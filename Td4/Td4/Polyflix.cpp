#include "Polyflix.h"

Polyflix::Polyflix() {}

// TODO
Polyflix::Polyflix(const Polyflix& polyflix) {

    medias_ = polyflix.medias_;
    utilisateurs_ = polyflix.utilisateurs_;
    historique_ = polyflix.historique_;
}

// TODO
int Polyflix::getNombreUtilisateurs() const {
    return utilisateurs_.obtenirNbElements();
}

// TODO : Utiliser une methode de la librairie Algorithm
Utilisateur* Polyflix::chercherUtilisateur(string nomUtilisateur) {
    
    auto iterateur = find_if(utilisateurs_.begin(), utilisateurs_.end(), FoncteurRechercheNomUtilisateur(nomUtilisateur));
    if (iterateur != nullptr)
        return iterateur->get();
    
}

// TODO
Liste<Media> Polyflix::listersi(const function<bool(Media media)>& critere) const {
  /* Liste<Media> tableauRetourne;

   for (auto& media : medias_)
       if (critere(*media) == true)
           tableauRetourne += *media;
   
    return tableauRetourne;*/
    return{};
        
}


// TODO
Liste<Media> Polyflix::obtenirNMeilleursMedias(int n) {
    //Liste<Media> MeilleursNotes;
    //trierMedias();

    return {};
}

// TODO
bool Polyflix::visionnerFilm(string utilisateur, string media) {
    return false;
}

// TODO 
bool Polyflix::utilisateurExiste(string nomUtilisateur) const {
    return false;
}

// TODO
bool Polyflix::mediaExiste(string nomMedia) const {
    return false;
}

// TODO
bool Polyflix::operator+=(Utilisateur utilisateur) {
	return false;
}

// TODO
bool Polyflix::operator+=(Media media) {
    return false;
}

ostream& operator<<(ostream& os, const Polyflix& polyflix) {
    os << "Polyflix" << endl;
    os << SEPARATEUR_SIMPLE << endl;
    os << "Media:" << endl;
    os << polyflix.medias_;
    return os;
}

// TODO
void Polyflix::trierMedias() {
    sort(medias_.begin(), medias_.end(), FoncteurComparerMedia());
}