// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Clef.cpp
#include"Jeu.h"
#include "Clef.h"

Clef::Clef(string nom, typeCaseDir caseUtiliser, typeCaseDir caseOuvrir) : Objet(nom) // Kamil: j'aurais utilise une lsite d'initialisation
{
	caseOuvrir_ = caseOuvrir;
	caseUtiliser_ = caseUtiliser;
}

void Clef::prendre(Jeu& jeu) const
{
	cout << "Vous prenez la clef, elle pourra probablement vous etre utile...\n" << endl;
	jeu.prendreObjet(make_shared<Objet>(*this));
}

void Clef::utiliser(shared_ptr<Case> caseActuelle)
{
	if (caseActuelle == caseUtiliser_.first)
		Case::lienEntreCases(caseUtiliser_, caseOuvrir_);
	else
		cout << "La clef ne fonctionne pas ici!" << endl;
}
