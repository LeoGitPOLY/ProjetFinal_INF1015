// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 14 decembre 2022
// Cours: INF1015
// Nom de la classe: Objet.h

#pragma once
#include <iostream>
#include <vector>

class Jeu;
class Case; //Foward decleration: pour eviter les references circulaires


using namespace std;

class Objet
{
public:
	Objet(string nom);
	virtual ~Objet() = default;
	
	void creerDescription(string descriptionRegarder, string descriptionUtiliser);
	void ajouterMotsImportant(vector<string> mots);
	vector<string>& avoirMotsImportant();

	virtual void prendre(Jeu& jeu) const;
	virtual void regarder() const;
	virtual void utiliser(shared_ptr<Case> caseActuelle);

	friend ostream& operator<< (ostream& o, const shared_ptr<Objet> ptrObjet);
private:
	vector<string> motsImportants_;
	
	string nom_;
	string descriptionRegarder_;
	string descriptionUtiliser_;
};