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
	shared_ptr<Case> obtenirCaseActuelle() const;
	friend ostream& operator<< (ostream& o, const Jeu& ptrJeu);

private:
	void creationJeu();
	shared_ptr<Case> caseActuelle_;
};
