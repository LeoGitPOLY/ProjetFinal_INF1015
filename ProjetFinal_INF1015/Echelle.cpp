// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Echelle.cpp

#include "Echelle.h"

Echelle::Echelle(string nom, shared_ptr<Case> case1, shared_ptr<Case> case2) : Objet(nom), case1_(case1), case2_(case2) 
{
	setEstPrenable(false);
}

void Echelle::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle)
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
		cout << "Il n'y a pas d'echelle dans cette piece! \n" << endl;

}