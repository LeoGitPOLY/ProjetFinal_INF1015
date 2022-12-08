#pragma once
#include <iostream>
#include <map>

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
	~Case() = default;

	shared_ptr<Case> retournerCaseDirection(Direction direction) const;

	friend ostream& operator<< (ostream& o, const shared_ptr<Case>& ptrCase);
	static void lienEntreCases(pair<shared_ptr<Case>, Direction> case1, pair<shared_ptr<Case>, Direction> case2);

	static map<Direction, string> directionNom_;
private:
	void fixerCaseAdjacente(Direction direction, const shared_ptr<Case> caseAdjacente);
	
	string nom_;
	string description_;
	map<Direction, shared_ptr<Case>> casesAdjacente_;

};