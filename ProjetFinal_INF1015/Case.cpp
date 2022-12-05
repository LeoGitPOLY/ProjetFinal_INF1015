#include "Case.h"

Case::Case(string nom, string description): nom_(nom), description_(description)
{
	casesAdjacente_.insert({ Direction::Nord, nullptr });
	casesAdjacente_.insert({ Direction::Est, nullptr });
	casesAdjacente_.insert({ Direction::Sud, nullptr });
	casesAdjacente_.insert({ Direction::Ouest, nullptr });
}

void Case::fixerCaseAdjacente(Direction direction, const shared_ptr<Case> caseAdjacente) 
{
	casesAdjacente_[direction] = caseAdjacente;
}

shared_ptr<Case> Case::allerDansDirection(Direction direction) const
{
	return casesAdjacente_.find(direction)->second;
}

 void Case::lienEntreCases(pair<shared_ptr<Case>, Direction> case1, pair<shared_ptr<Case>, Direction> case2)
{
	case1.first->fixerCaseAdjacente(case1.second, case2.first);
	case2.first->fixerCaseAdjacente(case2.second, case1.first);
}

 ostream& operator<<(ostream& o, const shared_ptr<Case>& ptrCase)
 {
	 o << "--" << ptrCase->nom_ << "--" << endl;
	 o << ptrCase->description_ << endl;
	 o << "\n";

	 return o;
 }
