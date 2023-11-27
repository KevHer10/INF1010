#include "Polyflix.h"

Polyflix::Polyflix() {}

// TODO
Polyflix::Polyflix(const Polyflix& polyflix) {}

// TODO
int Polyflix::getNombreUtilisateurs() const {
    return 0;
}

// TODO : Utiliser une methode de la librairie Algorithm
Utilisateur* Polyflix::chercherUtilisateur(string nomUtilisateur) {
    return nullptr;
}

// TODO
Liste<Media> Polyflix::listersi(const function<bool(Media media)>& critere) const {
    return {};
}


// TODO
Liste<Media> Polyflix::obtenirNMeilleursMedias(int n) {
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
}