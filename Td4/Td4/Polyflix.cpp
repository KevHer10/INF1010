/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"

/// @brief Constructeur par d�faut de la classe Polyflix.
Polyflix::Polyflix() {}

/// @brief Constructeur de copie de la classe Polyflix.
/// @param polyflix L'objet Polyflix � copier.
Polyflix::Polyflix(const Polyflix& polyflix) {

    medias_ = polyflix.medias_;
    utilisateurs_ = polyflix.utilisateurs_;
    historique_ = polyflix.historique_;
}

/// @brief Obtient le nombre d'utilisateurs dans Polyflix.
/// @return Le nombre d'utilisateurs dans Polyflix.
int Polyflix::getNombreUtilisateurs() const {
    return utilisateurs_.obtenirNbElements();
}

/// @brief Cherche un utilisateur par son nom d'utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur � rechercher.
/// @return Un pointeur vers l'objet Utilisateur correspondant, ou nullptr s'il n'est pas trouv�.
Utilisateur* Polyflix::chercherUtilisateur(string nomUtilisateur) {

    auto iterateur = find_if(utilisateurs_.begin(), utilisateurs_.end(), FoncteurRechercheNomUtilisateur(nomUtilisateur));
    if (iterateur != utilisateurs_.end())
        return iterateur->get();

    return nullptr;
}

/// @brief Liste les m�dias qui satisfont un crit�re donn�.
/// @param critere Une fonction bool�enne repr�sentant le crit�re de s�lection des m�dias.
/// @return Une liste de m�dias qui satisfont le crit�re.
Liste<Media> Polyflix::listersi(const function<bool(Media media)>& critere) const {
    Liste<Media> tableauRetourne;

    for (auto& media : medias_)
        if (critere(*media))
            tableauRetourne += *media;

    return tableauRetourne;
}

/// @brief Obtient les N meilleurs m�dias.
/// @param n Le nombre de meilleurs m�dias � obtenir.
/// @return Une liste des N meilleurs m�dias.
Liste<Media> Polyflix::obtenirNMeilleursMedias(int n) {
    if (n <= 0 || n > medias_.obtenirNbElements()) {
        cout << "Erreur : Nombre invalide." << endl;
        return {}; 
    }
    
    Liste<Media> MeilleursNotes(n);
    trierMedias();
    reverse(medias_.begin(), medias_.end());
    copy_n(medias_.begin(), n, MeilleursNotes.begin());

    return MeilleursNotes;
}

/// @brief Permet � un utilisateur de visionner un film.
/// @param utilisateur Le nom de l'utilisateur visionnant le film.
/// @param media Le titre du film � visionner.
/// @return true si le visionnage est r�ussi, false sinon.
bool Polyflix::visionnerFilm(string utilisateur, string media) {
    if (utilisateurExiste(utilisateur) && mediaExiste(media)) {
        historique_[utilisateur].insert(media);
        return true;
    }

    return false;
}

/// @brief V�rifie si un utilisateur existe dans Polyflix.
/// @param nomUtilisateur Le nom de l'utilisateur � v�rifier.
/// @return true si l'utilisateur existe, false sinon.
bool Polyflix::utilisateurExiste(string nomUtilisateur) const {
    auto iterateur = find_if(utilisateurs_.begin(), utilisateurs_.end(), FoncteurRechercheNomUtilisateur(nomUtilisateur));
    return iterateur != utilisateurs_.end();
}

/// @brief V�rifie si un m�dia existe dans Polyflix.
/// @param nomMedia Le titre du m�dia � v�rifier.
/// @return true si le m�dia existe, false sinon.
bool Polyflix::mediaExiste(string nomMedia) const {
    auto iterateur = find_if(medias_.begin(), medias_.end(), FoncteurRechercheNomMedia(nomMedia));
    return iterateur != medias_.end();
}

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un utilisateur � Polyflix.
/// @param utilisateur L'utilisateur � ajouter.
/// @return true si l'ajout est r�ussi, false sinon.
bool Polyflix::operator+=(Utilisateur utilisateur) {
    if (!utilisateurExiste(utilisateur.getNomUtilisateur())) {
        utilisateurs_ += utilisateur;
        return true;
    }
    return false;
}

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un m�dia � Polyflix.
/// @param media Le m�dia � ajouter.
/// @return true si l'ajout est r�ussi, false sinon.
bool Polyflix::operator+=(Media media) {
    if (!mediaExiste(media.getTitre())) {
        medias_ += media;
        return true;
    }
    return false;
}

/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations de Polyflix.
/// @param os Le flux de sortie.
/// @param polyflix L'objet Polyflix � afficher.
/// @return Le flux de sortie mis � jour.
ostream& operator<<(ostream& os, const Polyflix& polyflix) {
    os << "Polyflix" << endl;
    os << SEPARATEUR_SIMPLE << endl;
    os << "Media:" << endl;
    os << polyflix.medias_;
    return os;
}

/// @brief Trie les m�dias de Polyflix.
void Polyflix::trierMedias() {
    sort(medias_.begin(), medias_.end(), FoncteurComparerMedia());
}
