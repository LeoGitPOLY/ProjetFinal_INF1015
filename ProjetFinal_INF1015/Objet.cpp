// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 20 decembre 2022
// Cours: INF1015
// Nom de la classe: Objet.cpp

#include "Objet.h"

Objet::Objet(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre) :
	nom_(nom), descriptionRegarder_(descriptionRegarder), descriptionUtiliser_(descriptionUtiliser), descriptionPrendre_(descriptionPrendre)
{
	setEstPrenable(false);
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
	cout << descriptionPrendre_ << "\n" << endl;
}

void Objet::regarder() const
{
	cout << descriptionRegarder_ << "\n" << endl;
}

void Objet::utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle)
{
	cout << descriptionUtiliser_ << "\n" << endl;
}

ostream& operator<<(ostream& o, const shared_ptr<Objet> ptrObjet)
{
	o << "    " << ptrObjet->nom_ << endl;
	return o;
}
