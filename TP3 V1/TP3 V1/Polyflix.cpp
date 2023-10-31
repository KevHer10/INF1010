/*
Fichier: Polyflix.cpp
Auteur(s): Kevin Alexander Bejarano Hernandez
Date de creation: 2023-10-25
Date de modification: 2023-10-30
Description: Implementation de la classe Polyflix.
*/
#include "Polyflix.h"

/// @brief Constructeur par d�faut de la classe Polyflix.
Polyflix::Polyflix() {}

/// @brief Constructeur de copie de la classe Polyflix.
/// @param polyflix L'objet Polyflix � copier.
Polyflix::Polyflix(const Polyflix& polyflix) : medias_(polyflix.medias_), utilisateurs_(polyflix.utilisateurs_) {}  // TODO

/// @brief Cherche un utilisateur par son nom d'utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur � rechercher.
/// @return Un pointeur vers l'objet Utilisateur correspondant, ou nullptr s'il n'est pas trouv�.
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

/// @brief V�rifie si un utilisateur existe.
/// @param nomUtilisateur Le nom d'utilisateur � v�rifier.
/// @return true si l'utilisateur existe, false sinon.
bool Polyflix::utilisateurExiste(string nomUtilisateur) { 
	if (chercherUtilisateur(nomUtilisateur) != nullptr)
		return true;
	return false;
}  // TODO

/// @brief Connecte un utilisateur en v�rifiant le nom d'utilisateur et le mot de passe.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur � connecter.
/// @param motDePasse Le mot de passe de l'utilisateur � v�rifier.
/// @return true si la connexion est r�ussie, false sinon.
bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) { 
	
	return utilisateurExiste(nomUtilisateur) && chercherUtilisateur(nomUtilisateur)->verifierConnexion(motDePasse);
}  // TODO

/// @brief Modifie le mot de passe d'un utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur dont le mot de passe doit �tre modifi�.
/// @param motDePasse Le nouveau mot de passe � d�finir.
/// @return true si la modification du mot de passe est r�ussie, false sinon.
bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) { 
	if (utilisateurExiste(nomUtilisateur)) {
		chercherUtilisateur(nomUtilisateur)->setMotDePasse(motDePasse);
		return true;
	}

	return false;
}  // TODO

/// @brief Permet � un utilisateur de visionner un m�dia.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur qui visionne le m�dia.
/// @param titreMedia Le titre du m�dia � visionner.
/// @return true si la visionnage est r�ussi, false sinon.
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

/// @brief Obtient le nombre total de s�ries dans Polyflix.
/// @return Le nombre total de s�ries.
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

/// @brief Obtient le nombre total de m�dias (films et s�ries) dans Polyflix.
/// @return Le nombre total de m�dias.
int Polyflix::getNombreTotalMedia() const { return static_cast<int>(medias_.size()); }  // TODO

/// @brief Cherche un m�dia par son titre.
/// @param titreMedia Le titre du m�dia � rechercher.
/// @return Un pointeur vers l'objet Media correspondant, ou nullptr s'il n'est pas trouv�.
Media* Polyflix::chercherMedia(string titreMedia) const { 
	for (auto& media : medias_) {
		if (media->getTitre()==titreMedia) {
			return media.get();
		}
	}
	return nullptr;
}  // TODO

/// @brief Liste tous les films de Polyflix.
/// @return Un vecteur de pointeurs vers les objets Film repr�sentant tous les films.
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

// @brief Liste toutes les s�ries de Polyflix.
/// @return Un vecteur de pointeurs vers les objets Serie repr�sentant toutes les s�ries.
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

/// @brief Liste les m�dias visionn�s par un utilisateur.
/// @param nomUtilisateur Le nom d'utilisateur de l'utilisateur dont les m�dias visionn�s sont list�s.
/// @return Un vecteur de pointeurs vers les objets Media repr�sentant les m�dias visionn�s par l'utilisateur.
vector<shared_ptr<Media>> Polyflix::listerMediaVisionnesParUtilisateur(string nomUtilisateur) { 
	
	return chercherUtilisateur(nomUtilisateur)->getMediaVus();
}  // TODO

/// @brief Liste les films par cat�gorie.
/// @param categorie La cat�gorie de films � lister.
/// @return Un vecteur de pointeurs vers les objets Film repr�sentant les films de la cat�gorie sp�cifi�e.
vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { 
	vector<Film*> filmsParCategorie;
	for (auto& films : listerTousLesFilms())
		if (films->getCategorie() == categorie)
			filmsParCategorie.push_back(films);

	return filmsParCategorie;
}  // TODO

/// @brief Liste les s�ries par cat�gorie.
/// @param categorie La cat�gorie de s�ries � lister.
/// @return Un vecteur de pointeurs vers les objets Serie repr�sentant les s�ries de la cat�gorie sp�cifi�e.
vector<Serie*> Polyflix::listerSeriesParCategorie(Categorie categorie) const { 
	vector<Serie*> seriesParCategorie;
	for (auto& serie : listerTousLesSeries())
		if (serie->getCategorie() == categorie)
			seriesParCategorie.push_back(serie);

	return seriesParCategorie;
}  // TODO

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un utilisateur � Polyflix.
/// @param utilisateur L'utilisateur � ajouter.
/// @return true si l'ajout est r�ussi, false sinon.
bool Polyflix::operator+=(Utilisateur utilisateur) { 
	if (!utilisateurExiste(utilisateur.getNomUtilisateur()))
		utilisateurs_.push_back(make_shared<Utilisateur>(utilisateur));
	
	return true;
}  // TODO

/// @brief Surcharge de l'op�rateur d'ajout pour ajouter un m�dia (Film ou Serie) � Polyflix.
/// @param media Le m�dia � ajouter.
/// @return true si l'ajout est r�ussi, false sinon.
bool Polyflix::operator+=(Media* media) { 
	medias_.emplace_back(media);

	return true;
}  // TODO

/// @brief Surcharge de l'op�rateur de sortie pour afficher les informations de Polyflix.
/// @param os Le flux de sortie.
/// @param polyflix L'objet Polyflix � afficher.
/// @return Le flux de sortie mis � jour.
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