// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Jeu.h

#pragma once
#include <iostream>
#include "Case.h"

using namespace std;

class Jeu
{
public:
	Jeu();
	~Jeu() = default;

	void allerDansDirection(Direction direction);
	shared_ptr<Case> obtenirCaseDirection(Direction direction) const;
	friend ostream& operator<< (ostream& o, const Jeu& ptrJeu);

private:
	void creationJeu();
	shared_ptr<Case> caseActuelle_;
};
