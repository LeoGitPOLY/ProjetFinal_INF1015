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
	Objet(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre);
	virtual ~Objet() = default;
	

	void ajouterMotsImportant(vector<string> mots);
	
	vector<string>& avoirMotsImportant();
	string avoirNom() const;

	virtual void prendre(Jeu& jeu) const;
	virtual void regarder() const;
	virtual void utiliser(Jeu& jeu, shared_ptr<Case> caseActuelle);
	void setEstPrenable(bool estPrenable) { estPrenable_ = estPrenable; }
	bool estPrenable() { return estPrenable_; }
	friend ostream& operator<< (ostream& o, const shared_ptr<Objet> ptrObjet);
private:

	string nom_;
	string descriptionRegarder_;
	string descriptionUtiliser_;
	string descriptionPrendre_;
	vector<string> motsImportants_;
	bool estPrenable_;

};