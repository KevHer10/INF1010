/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-11-25
Date de modification: 2023-11-28
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"

/// @brief Constructeur par défaut de la classe Polyflix.
Polyflix::Polyflix() {}

/// @brief Constructeur de copie de la classe Polyflix.
/// @param polyflix L'objet Polyflix à copier.
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
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur à rechercher.
/// @return Un pointeur vers l'objet Utilisateur correspondant, ou nullptr s'il n'est pas trouvé.
Utilisateur* Polyflix::chercherUtilisateur(string nomUtilisateur) {

    auto iterateur = find_if(utilisateurs_.begin(), utilisateurs_.end(), FoncteurRechercheNomUtilisateur(nomUtilisateur));
    if (iterateur != utilisateurs_.end())
        return iterateur->get();

    return nullptr;
}

/// @brief Liste les médias qui satisfont un critère donné.
/// @param critere Une fonction booléenne représentant le critère de sélection des médias.
/// @return Une liste de médias qui satisfont le critère.
Liste<Media> Polyflix::listersi(const function<bool(Media media)>& critere) const {
    Liste<Media> tableauRetourne;

    for (auto& media : medias_)
        if (critere(*media))
            tableauRetourne += *media;

    return tableauRetourne;
}

/// @brief Obtient les N meilleurs médias.
/// @param n Le nombre de meilleurs médias à obtenir.
/// @return Une liste des N meilleurs médias.
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

/// @brief Permet à un utilisateur de visionner un film.
/// @param utilisateur Le nom de l'utilisateur visionnant le film.
/// @param media Le titre du film à visionner.
/// @return true si le visionnage est réussi, false sinon.
bool Polyflix::visionnerFilm(string utilisateur, string media) {
    if (utilisateurExiste(utilisateur) && mediaExiste(media)) {
        historique_[utilisateur].insert(media);
        return true;
    }

    return false;
}

/// @brief Vérifie si un utilisateur existe dans Polyflix.
/// @param nomUtilisateur Le nom de l'utilisateur à vérifier.
/// @return true si l'utilisateur existe, false sinon.
bool Polyflix::utilisateurExiste(string nomUtilisateur) const {
    auto iterateur = find_if(utilisateurs_.begin(), utilisateurs_.end(), FoncteurRechercheNomUtilisateur(nomUtilisateur));
    return iterateur != utilisateurs_.end();
}

/// @brief Vérifie si un média existe dans Polyflix.
/// @param nomMedia Le titre du média à vérifier.
/// @return true si le média existe, false sinon.
bool Polyflix::mediaExiste(string nomMedia) const {
    auto iterateur = find_if(medias_.begin(), medias_.end(), FoncteurRechercheNomMedia(nomMedia));
    return iterateur != medias_.end();
}

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un utilisateur à Polyflix.
/// @param utilisateur L'utilisateur à ajouter.
/// @return true si l'ajout est réussi, false sinon.
bool Polyflix::operator+=(Utilisateur utilisateur) {
    if (!utilisateurExiste(utilisateur.getNomUtilisateur())) {
        utilisateurs_ += utilisateur;
        return true;
    }
    return false;
}

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un média à Polyflix.
/// @param media Le média à ajouter.
/// @return true si l'ajout est réussi, false sinon.
bool Polyflix::operator+=(Media media) {
    if (!mediaExiste(media.getTitre())) {
        medias_ += media;
        return true;
    }
    return false;
}

/// @brief Surcharge de l'opérateur de sortie pour afficher les informations de Polyflix.
/// @param os Le flux de sortie.
/// @param polyflix L'objet Polyflix à afficher.
/// @return Le flux de sortie mis à jour.
ostream& operator<<(ostream& os, const Polyflix& polyflix) {
    os << "Polyflix" << endl;
    os << SEPARATEUR_SIMPLE << endl;
    os << "Media:" << endl;
    os << polyflix.medias_;
    return os;
}

/// @brief Trie les médias de Polyflix.
void Polyflix::trierMedias() {
    sort(medias_.begin(), medias_.end(), FoncteurComparerMedia());
}
