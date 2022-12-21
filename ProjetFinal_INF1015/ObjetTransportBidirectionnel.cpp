// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Echelle.cpp

#include "ObjetTransportBidirectionnel.h"

ObjetTransportBidirectionnel::ObjetTransportBidirectionnel(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, shared_ptr<Case> case1, shared_ptr<Case> case2) :
	Objet(nom,descriptionRegarder,descriptionUtiliser, descriptionPrendre), case1_(case1), case2_(case2)
{
	setEstPrenable(false);
}

void ObjetTransportBidirectionnel::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle)
{
	if (caseActuelle == case1_) {
		Objet::utiliser(jeu, caseActuelle);
		jeu.obtenirCaseActuelle() = case2_;
	}
	else if (caseActuelle == case2_) {
		Objet::utiliser(jeu, caseActuelle);
		jeu.obtenirCaseActuelle() = case1_;
	}
	else
		cout << "Il n'y a pas de tel objet dans cette piece!\n";

}