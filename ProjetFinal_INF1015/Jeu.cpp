#include "Jeu.h"

Jeu::Jeu()
{
	creationJeu();
}


void Jeu::creationJeu()
{
	pair<string, string> infoEntree = { "Entree", "Entree description" };
	pair<string, string> infoSalon = { "Salon", "Salon description" };
	pair<string, string> infoCouloir = { "Couloir", "Couloir description" };
	pair<string, string> infoPetiteChambre = { "Petite chambre", "Petite chambre description" };
	pair<string, string> infoGrenier = { "Grenier", "Grenier description" };
	pair<string, string> infoCuisine = { "Cuisine", "Cuisine description" };

	shared_ptr<Case> entree = make_shared<Case>(infoEntree.first, infoEntree.second);
	shared_ptr<Case> salon = make_shared<Case>(infoSalon.first, infoSalon.second);
	shared_ptr<Case> couloir = make_shared<Case>(infoCouloir.first, infoCouloir.second);
	shared_ptr<Case> petitChambre = make_shared<Case>(infoPetiteChambre.first, infoPetiteChambre.second);
	shared_ptr<Case> grenier = make_shared<Case>(infoGrenier.first, infoGrenier.second);
	shared_ptr<Case> cuisine = make_shared<Case>(infoCuisine.first, infoCuisine.second);

	Case::lienEntreCases({ entree, Direction::Est }, { salon, Direction::Ouest });
	Case::lienEntreCases({ entree, Direction::Nord }, { couloir, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Nord }, { cuisine, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Ouest }, { petitChambre, Direction::Est });
	Case::lienEntreCases({ petitChambre, Direction::Nord }, { grenier, Direction::Sud });

	caseActuelle_ = entree;
}

void Jeu::allerDansDirection(Direction direction)
{
	caseActuelle_ = caseActuelle_->retournerCaseDirection(direction);
}

ostream& operator<<(ostream& o, const Jeu& jeu)
{
	o << jeu.caseActuelle_ << endl;
	return o;
}

shared_ptr<Case> Jeu::obtenirCaseDirection(Direction direction) const
{
	return caseActuelle_->retournerCaseDirection(direction);
}


