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
	return false; }  // TODO

bool Polyflix::visionnerMedia(string nomUtilisateur, string titreMedia) { return false; }  // TODO

int Polyflix::getNombreTotalFilms() const { return 0; }  // TODO

int Polyflix::getNombreTotalSeries() const { return 0; }  // TODO

int Polyflix::getNombreTotalMedia() const { return 0; }  // TODO

Media* Polyflix::chercherMedia(string titreMedia) const { return nullptr; }  // TODO

vector<Film*> Polyflix::listerTousLesFilms() const { return {}; }  // TODO

vector<Serie*> Polyflix::listerTousLesSeries() const { return {}; }  // TODO

vector<shared_ptr<Media>> Polyflix::listerMediaVisionnesParUtilisateur(string nomUtilisateur) { return {}; }  // TODO

vector<Film*> Polyflix::listerFilmsParCategorie(Categorie categorie) const { return {}; }  // TODO

vector<Serie*> Polyflix::listerSeriesParCategorie(Categorie categorie) const { return {}; }  // TODO

bool Polyflix::operator+=(Utilisateur utilisateur) { return false; }  // TODO

bool Polyflix::operator+=(Media* media) { return false; }  // TODO

ostream& operator<<(ostream& os, const Polyflix& polyflix) { return os; }  // TODO