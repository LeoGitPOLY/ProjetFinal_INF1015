// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Jeu.h

#pragma once
#include <iostream>
#include <vector>
#include "Case.h"

using namespace std;

class Jeu
{
public:
	Jeu();
	~Jeu();

	void allerDansDirection(Direction direction);
	void prendreObjet(shared_ptr<Objet> objet);
	shared_ptr<Case>& obtenirCaseActuelle();

	shared_ptr<Case> obtenirCaseDirection(Direction direction) const;
	vector<shared_ptr<Objet>>& obtenirListeObjetJeu();
	vector<shared_ptr<Objet>>& obtenirListeObjetCase();

	friend ostream& operator<< (ostream& o, const Jeu& ptrJeu);

private:
	void creationJeu();

	shared_ptr<Case> caseActuelle_;
	vector<shared_ptr<Case>> casesDuJeu_;
	vector<shared_ptr<Objet>> objets_;
};
