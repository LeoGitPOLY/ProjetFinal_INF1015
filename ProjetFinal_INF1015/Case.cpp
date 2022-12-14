// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Case.cpp

#include "Case.h"

map<Direction, string> Case::directionNom_ = { { Direction::Nord, "au nord (N)" },
											   { Direction::Est, "a l'est (E)" },
											   { Direction::Sud, "au sud (S)" },
											   { Direction::Ouest, "a l'ouest (O)" } };


Case::Case(string nom, string description) : nom_(nom), description_(description)
{
	casesAdjacente_.insert({ Direction::Nord, nullptr });
	casesAdjacente_.insert({ Direction::Est, nullptr });
	casesAdjacente_.insert({ Direction::Sud, nullptr });
	casesAdjacente_.insert({ Direction::Ouest, nullptr });
}


Case::~Case()
{
	cout << " Detruit case: " << nom_ << endl;
}


void Case::fixerCaseAdjacente(Direction direction, const shared_ptr<Case> caseAdjacente)
{
	casesAdjacente_[direction] = caseAdjacente;
}


shared_ptr<Case> Case::retournerCaseDirection(Direction direction) const
{
	return casesAdjacente_.find(direction)->second;
}

vector<shared_ptr<Objet>>& Case::retournerObjets()
{
	return objets_;
}

map<Direction, string>& Case::retournerDescriptionNom()
{
	return directionNom_;
}

void Case::supprimerLiens()
{
	for (auto& elem : casesAdjacente_) {
		elem.second = nullptr;
	}

	cout << " SupprimerLiens: " << nom_ << endl;
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

	if (ptrCase->objets_.size() != 0) {
		o << "Vous remarquez: " << endl;

		for (auto objet : ptrCase->objets_)
			o << objet;
	}

	o << "Les pieces adjacentes: " << endl;
	for (auto& caseAdjacente : ptrCase->casesAdjacente_)
	{
		if (caseAdjacente.second != nullptr)
			o << "- " << caseAdjacente.second->nom_ << " est "
			<< Case::directionNom_[caseAdjacente.first] << endl;
	}
	return o;
}

