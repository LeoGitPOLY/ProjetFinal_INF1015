// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: ObjetDeverouillant.cpp

#include"Jeu.h"
#include "ObjetDeverouillant.h"

ObjetDeverouillant::ObjetDeverouillant(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, typeCaseDir caseUtiliser, typeCaseDir caseOuvrir) :
	Objet(nom, descriptionRegarder, descriptionUtiliser, descriptionPrendre),
	caseOuvrir_(caseOuvrir), caseUtiliser_(caseUtiliser) 
{
	setEstPrenable(true);
}

void ObjetDeverouillant::prendre(Jeu& jeu) const
{
	Objet::prendre(jeu);
	jeu.prendreObjet(make_shared<ObjetDeverouillant>(*this));
}

void ObjetDeverouillant::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle) 
{
	if (caseActuelle == caseUtiliser_.first){
		Case::lienEntreCases(caseUtiliser_, caseOuvrir_);
		Objet::utiliser(jeu, caseActuelle);
	}
	else
		cout << "L'objet ne fonctionne pas ici! \n" << endl;
}

