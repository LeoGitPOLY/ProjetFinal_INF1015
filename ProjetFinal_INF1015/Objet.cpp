// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Objet.cpp

#include "Objet.h"

Objet::Objet(string nom) :nom_(nom)
{
	setEstPrenable(false);
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

string Objet::avoirNom() const
{
	return nom_;
}

void Objet::prendre(Jeu& jeu) const
{
	cout << "Il est impossible de prendre: " << nom_ << "\n" << endl;
}

void Objet::regarder() const
{
	cout << descriptionRegarder_ << endl;
}

void Objet::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle)
{
	cout << "UTILISER OBJET" << endl;
	cout << descriptionUtiliser_ << "\n" << endl;
}

ostream& operator<<(ostream& o, const shared_ptr<Objet> ptrObjet)
{
	o << "    " << ptrObjet->nom_ << endl;
	return o;
}
