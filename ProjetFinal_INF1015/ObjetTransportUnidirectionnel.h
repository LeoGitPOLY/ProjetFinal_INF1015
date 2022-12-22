// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 22 decembre 2022
// Cours: INF1015
// Nom de la classe: ObjetTransportUnidirectionnel.h

#pragma once
#include <iostream>
#include "Objet.h"
#include "Case.h"
#include "Jeu.h"

using namespace std;

class ObjetTransportUnidirectionnel : public Objet
{
public:
	ObjetTransportUnidirectionnel(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, shared_ptr<Case> case1, shared_ptr<Case> case2);
	void utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle) override;

private:
	shared_ptr<Case> caseDepart_, caseArrivee_;
};