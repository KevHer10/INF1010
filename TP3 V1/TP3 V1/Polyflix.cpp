#include "Polyflix.h"

Polyflix::Polyflix() {}

Polyflix::Polyflix(const Polyflix& polyflix) : medias_(polyflix.medias_), utilisateurs_(polyflix.utilisateurs_) {}  // TODO

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

int Polyflix::getNombreUtilisateurs() const { 
	return static_cast<int>(utilisateurs_.size());
}  // TODO

bool Polyflix::utilisateurExiste(string nomUtilisateur) { 
	if (chercherUtilisateur(nomUtilisateur) != nullptr)
		return true;
	return false;
}  // TODO

bool Polyflix::connecterUtilisateur(string nomUtilisateur, string motDePasse) { 
	
	return utilisateurExiste(nomUtilisateur) && chercherUtilisateur(nomUtilisateur)->verifierConnexion(motDePasse);
}  // TODO

bool Polyflix::modifierMotDePasse(string nomUtilisateur, string motDePasse) { 
	if (utilisateurExiste(nomUtilisateur)) {
		chercherUtilisateur(nomUtilisateur)->setMotDePasse(motDePasse);
		return true;
	}

	return false;
}  // TODO

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

int Polyflix::getNombreTotalFilms() const { 
	const Film* film{};
	int nombreTotalFilm=0;
	for (auto& media : medias_) {
		if (dynamic_cast<const Film*>(media.get()) != nullptr) {
			nombreTotalFilm++;
		}
	}
	return nombreTotalFilm;
}  // TODO

int Polyflix::getNombreTotalSeries() const { 
	const Serie* serie{};
	int nbrTotaleSeries=0;
	for (auto& media : medias_) {
		if (dynamic_cast<const Serie*>(media.get()) != nullptr) {
			nbrTotaleSeries++;
		}
	}

	return nbrTotaleSeries;
}  // TODO

int Polyflix::getNombreTotalMedia() const { return static_cast<int>(medias_.size()); }  // TODO

Media* Polyflix::chercherMedia(string titreMedia) const { 
	for (auto& media : medias_) {
		if (media->getTitre()==titreMedia) {
			return media.get();
		}
	}
	return nullptr;
}  // TODO

vector<Film*> Polyflix::listerTousLesFilms() const { 
	vector<Film*> films;
		
	for (auto& media : medias_) {
		if (dynamic_cast<const Film*>(media.get()) != nullptr) {
			;
			films.push_back(dynamic_cast<Film*>(media.get()));
		}
	}

	return films;
}  // TODO

vector<Serie*> Polyflix::listerTousLesSeries() const {
	vector<Serie*> series;

	for (auto& media : medias_) {
		if (dynamic_cast<const Serie*>(media.get()) != nullptr) {
			;
			series.push_back(dynamic_cast<Serie*>(media.get()));
		}
	}
	return series;
}  // TODO

vector<shared_ptr<Media>> Polyflix::listerMediaVisionnesParUtilisateur(string nomUtilisateur) { 
	
	return chercherUtilisateur(nomUtilisateur)->getMediaVus();
}  // TODO

vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { return {}; }  // TODO

vector<Serie*> Polyflix::listerSeriesParCategorie(Categorie categorie) const { return {}; }  // TODO

bool Polyflix::operator+=(Utilisateur utilisateur) { 
	if (!utilisateurExiste(utilisateur.getNomUtilisateur()))
		utilisateurs_.push_back(make_shared<Utilisateur>(utilisateur));
	
	return true;
}  // TODO

bool Polyflix::operator+=(Media* media) { 
	medias_.emplace_back(media);

	return false;
}  // TODO

ostream& operator<<(ostream& os, const Polyflix& polyflix) { return os; }  // TODO