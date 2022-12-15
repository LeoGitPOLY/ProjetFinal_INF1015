// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Objet.cpp

#include "Objet.h"

Objet::Objet(string nom) :nom_(nom)
{
}

void Objet::creerDescription(string descriptionRegarder, string descriptionUtiliser)
{
	descriptionRegarder_ = descriptionRegarder;
	descriptionUtiliser_ = descriptionUtiliser;
}

bool Objet::prendre() const
{
	cout << "Il est impossible de prendre: " << nom_ << endl;
	return false;
}

void Objet::regarder() const
{
	cout << descriptionRegarder_ << endl;
}

void Objet::utiliser(shared_ptr<Case> caseActuelle)
{
	cout << descriptionUtiliser_ << endl;
}

ostream& operator<<(ostream& o, const unique_ptr<Objet>& ptrObjet)
{
	o << "$ " << ptrObjet->nom_ << endl;
	return o;
}
