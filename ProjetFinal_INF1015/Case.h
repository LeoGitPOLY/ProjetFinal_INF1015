#pragma once
#include <iostream>
#include <map>

using namespace std;

enum class Direction
{
	Nord,
	Est, 
	Sud,
	Ouest
};

class Case
{
public:
	Case(string nom, string description);
	~Case() = default;

	void fixerCaseAdjacente(Direction direction, const shared_ptr<Case> caseAdjacente);
	shared_ptr<Case> allerDansDirection(Direction direction) const;

	friend ostream& operator<< (ostream& o, const shared_ptr<Case>& ptrCase);
	static void lienEntreCases(pair<shared_ptr<Case>, Direction> case1, pair<shared_ptr<Case>, Direction> case2);

private:
	string nom_;
	string description_;
	map<Direction, shared_ptr<Case>> casesAdjacente_;
};