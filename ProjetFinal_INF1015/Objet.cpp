// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Objet.cpp

#include "Objet.h"

Objet::Objet(string nom) :nom_(nom)
{
}

void Objet::creerDescription(string descriptionRegarder, string descriptionUtiliser) // Kamil: j'aurais fait ca dans une liste d'initialisation
{
	descriptionRegarder_ = descriptionRegarder;
	descriptionUtiliser_ = descriptionUtiliser;
}

void Objet::ajouterMotsImportant(vector<string> mots)
{
	motsImportants_.insert(motsImportants_.end(), mots.begin(), mots.end());
}

vector<string>& Objet::avoirMotsImportant()
{
	return motsImportants_;
}

bool Objet::prendre() const
{
	cout << "Il est impossible de prendre: " << nom_ << "\n" << endl;
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

ostream& operator<<(ostream& o, const shared_ptr<Objet> ptrObjet)
{
	o << "    " << ptrObjet->nom_ << endl;
	return o;
}
