/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"

/// @brief Constructeur par défaut de la classe Polyflix.
Polyflix::Polyflix() {}

/// @brief Constructeur de copie de la classe Polyflix.
/// @param polyflix L'objet Polyflix à copier.
Polyflix::Polyflix(const Polyflix& polyflix) : medias_(polyflix.medias_), utilisateurs_(polyflix.utilisateurs_) {}  // TODO

/// @brief Cherche un utilisateur par son nom d'utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur à rechercher.
/// @return Un pointeur vers l'objet Utilisateur correspondant, ou nullptr s'il n'est pas trouvé.
Utilisateur* Polyflix::chercherUtilisateur(string nomUtilisateur) { 
	Utilisateur* utilisateurTrouve;
	for (auto& utilisateur : utilisateurs_) {
		if (utilisateur->getNomUtilisateur() == nomUtilisateur) {
			utilisateurTrouve = utilisateur.get();
			return utilisateurTrouve;
		}
	}
	return nullptr;
}  // TODO

/// @brief Obtient le nombre total d'utilisateurs dans Polyflix.
/// @return Le nombre total d'utilisateurs.
int Polyflix::getNombreUtilisateurs() const { 
	return static_cast<int>(utilisateurs_.size());
}  // TODO

/// @brief Vérifie si un utilisateur existe.
/// @param nomUtilisateur Le nom d'utilisateur à vérifier.
/// @return true si l'utilisateur existe, false sinon.
bool Polyflix::utilisateurExiste(string nomUtilisateur) { 
	if (chercherUtilisateur(nomUtilisateur) != nullptr)
		return true;
	return false;
}  // TODO

/// @brief Connecte un utilisateur en vérifiant le nom d'utilisateur et le mot de passe.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur à connecter.
/// @param motDePasse Le mot de passe de l'utilisateur à vérifier.
/// @return true si la connexion est réussie, false sinon.
bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) { 
	
	return utilisateurExiste(nomUtilisateur) && chercherUtilisateur(nomUtilisateur)->verifierConnexion(motDePasse);
}  // TODO

/// @brief Modifie le mot de passe d'un utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur dont le mot de passe doit être modifié.
/// @param motDePasse Le nouveau mot de passe à définir.
/// @return true si la modification du mot de passe est réussie, false sinon.
bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) { 
	if (utilisateurExiste(nomUtilisateur)) {
		chercherUtilisateur(nomUtilisateur)->setMotDePasse(motDePasse);
		return true;
	}

	return false;
}  // TODO

/// @brief Permet à un utilisateur de visionner un média.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur qui visionne le média.
/// @param titreMedia Le titre du média à visionner.
/// @return true si la visionnage est réussi, false sinon.
bool Polyflix::visionnerMedia(string nomUtilisateur, string titreMedia) { 
	
	if (utilisateurExiste(nomUtilisateur)) {
		for (auto& media : medias_) {
			if (titreMedia == media->getTitre()) {
				chercherUtilisateur(nomUtilisateur)->ajouterMedia(media);
					return true;
			}
		}
	}
	return false;
}  // TODO

/// @brief Obtient le nombre total de films dans Polyflix.
/// @return Le nombre total de films.
int Polyflix::getNombreTotalFilms() const { 
	//const Film* film{};
	int nombreTotalFilm = 0;
	for (const auto& media : medias_) {
		if (dynamic_cast<Film*>(media.get())) {
			nombreTotalFilm++;
		}
	}
	return nombreTotalFilm;
}  // TODO

/// @brief Obtient le nombre total de séries dans Polyflix.
/// @return Le nombre total de séries.
int Polyflix::getNombreTotalSeries() const { 
	//const Serie* serie{};
	int nbrTotaleSeries = 0;
	for (const auto& media : medias_) {
		if (dynamic_cast<const Serie*>(media.get())) {
			nbrTotaleSeries++;
		}
	}

	return nbrTotaleSeries;
}  // TODO

/// @brief Obtient le nombre total de médias (films et séries) dans Polyflix.
/// @return Le nombre total de médias.
int Polyflix::getNombreTotalMedia() const { return static_cast<int>(medias_.size()); }  // TODO

/// @brief Cherche un média par son titre.
/// @param titreMedia Le titre du média à rechercher.
/// @return Un pointeur vers l'objet Media correspondant, ou nullptr s'il n'est pas trouvé.
Media* Polyflix::chercherMedia(string titreMedia) const { 
	for (auto& media : medias_) {
		if (media->getTitre()==titreMedia) {
			return media.get();
		}
	}
	return nullptr;
}  // TODO

/// @brief Liste tous les films de Polyflix.
/// @return Un vecteur de pointeurs vers les objets Film représentant tous les films.
vector<Film*> Polyflix::listerTousLesFilms() const { 
	vector<Film*> films;
		
	for (auto& media : medias_) {
		if (Film * filmPtr = dynamic_cast<Film*>(media.get())) {
			;
			films.push_back(filmPtr);
		}
	}

	return films;
}  // TODO

// @brief Liste toutes les séries de Polyflix.
/// @return Un vecteur de pointeurs vers les objets Serie représentant toutes les séries.
vector<Serie*> Polyflix::listerTousLesSeries() const {
	vector<Serie*> series;

	for (auto& media : medias_) {
		if (Serie* seriePtr = dynamic_cast<Serie*>(media.get())) {
			;
			series.push_back(seriePtr);
		}
	}
	return series;
}  // TODO

/// @brief Liste les médias visionnés par un utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur dont les médias visionnés sont listés.
/// @return Un vecteur de pointeurs vers les objets Media représentant les médias visionnés par l'utilisateur.
vector<shared_ptr<Media>> Polyflix::listerMediaVisionnesParUtilisateur(string nomUtilisateur) { 
	
	return chercherUtilisateur(nomUtilisateur)->getMediaVus();
}  // TODO

/// @brief Liste les films par catégorie.
/// @param categorie La catégorie de films à lister.
/// @return Un vecteur de pointeurs vers les objets Film représentant les films de la catégorie spécifiée.
vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { 
	vector<Film*> filmsParCategorie;
	for (auto& films : listerTousLesFilms())
		if (films->getCategorie() == categorie)
			filmsParCategorie.push_back(films);

	return filmsParCategorie;
}  // TODO

/// @brief Liste les séries par catégorie.
/// @param categorie La catégorie de séries à lister.
/// @return Un vecteur de pointeurs vers les objets Serie représentant les séries de la catégorie spécifiée.
vector<Serie*> Polyflix::listerSeriesParCategorie(Categorie categorie) const { 
	vector<Serie*> seriesParCategorie;
	for (auto& serie : listerTousLesSeries())
		if (serie->getCategorie() == categorie)
			seriesParCategorie.push_back(serie);

	return seriesParCategorie;
}  // TODO

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un utilisateur à Polyflix.
/// @param utilisateur L'utilisateur à ajouter.
/// @return true si l'ajout est réussi, false sinon.
bool Polyflix::operator+=(Utilisateur utilisateur) { 
	if (!utilisateurExiste(utilisateur.getNomUtilisateur()))
		utilisateurs_.push_back(make_shared<Utilisateur>(utilisateur));
	
	return true;
}  // TODO

/// @brief Surcharge de l'opérateur d'ajout pour ajouter un média (Film ou Serie) à Polyflix.
/// @param media Le média à ajouter.
/// @return true si l'ajout est réussi, false sinon.
bool Polyflix::operator+=(Media* media) { 
	medias_.emplace_back(media);

	return true;
}  // TODO

/// @brief Surcharge de l'opérateur de sortie pour afficher les informations de Polyflix.
/// @param os Le flux de sortie.
/// @param polyflix L'objet Polyflix à afficher.
/// @return Le flux de sortie mis à jour.
ostream& operator<<(ostream& os, const Polyflix& polyflix) { 
	os << "Polyflix Platform" << "\n" << "======================" << "\n";
	os << "Films:\n"
		<< "----------------------\n";
	for (auto& film : polyflix.listerTousLesFilms())
		os << *film;
	os << "\n";
	os << "Series:\n"
		<< "----------------------\n";
	for (auto& serie : polyflix.listerTousLesSeries())
		os << *serie;
	os << "\n";

	return os;


}  // TODO