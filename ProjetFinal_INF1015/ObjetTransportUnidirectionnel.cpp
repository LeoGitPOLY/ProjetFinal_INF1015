// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: ObjetTransportUnidirectionnel.cpp

#include "ObjetTransportUnidirectionnel.h"

ObjetTransportUnidirectionnel::ObjetTransportUnidirectionnel(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, shared_ptr<Case> caseDepart, shared_ptr<Case> caseArrivee) :
	Objet(nom, descriptionRegarder, descriptionUtiliser, descriptionPrendre), caseDepart_(caseDepart), caseArrivee_(caseArrivee)
{
	setEstPrenable(false);
}

void ObjetTransportUnidirectionnel::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle)
{
	if (caseActuelle == caseDepart_) {
		Objet::utiliser(jeu, caseActuelle);
		jeu.obtenirCaseActuelle() = caseArrivee_;
	}
}