// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: ObjetDeverouillant.h

#pragma once
#include <iostream>
#include "Objet.h"
#include "Case.h"

using namespace std;
using typeCaseDir = pair<shared_ptr<Case>, Direction>;

class ObjetDeverouillant :public Objet
{
public:
	ObjetDeverouillant(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, typeCaseDir caseUtiliser, typeCaseDir caseOuvrir);

	void prendre(Jeu& jeu) const override;
	void utiliser(Jeu& jeu,shared_ptr<Case> caseActuelle) override;

private:
	typeCaseDir caseUtiliser_, caseOuvrir_;
};