// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Case.h

#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Objet.h"

using namespace std;

enum class Direction
{
	Nord = 'N',
	Est = 'E',
	Sud = 'S',
	Ouest = 'O'
};

class Case
{
public:
	Case(string nom, string description);
	~Case();

	shared_ptr<Case> retournerCaseDirection(Direction direction) const;
	vector<unique_ptr<Objet>>& retournerObjets(); // Leo: Probablement a enlever pour l'encapsulation, mais je sais pas encore ce qu'on a besoin sur les objets
	void supprimerLiens();

	friend ostream& operator<< (ostream& o, const shared_ptr<Case>& ptrCase);

	static void lienEntreCases(pair<shared_ptr<Case>, Direction> case1, pair<shared_ptr<Case>, Direction> case2);
	static map<Direction, string> directionNom_;

private:
	void fixerCaseAdjacente(Direction direction, const shared_ptr<Case> caseAdjacente);

	string nom_;
	string description_;
	map<Direction, shared_ptr<Case>> casesAdjacente_;
	vector<unique_ptr<Objet>> objets_;
};