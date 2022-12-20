// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Jeu.cpp

#include "Jeu.h"
#include "Clef.h"

Jeu::Jeu()
{
	creationJeu();
}

Jeu::~Jeu()
{
	for (auto& elem : casesDuJeu_) {
		elem->supprimerLiens();
	}
	cout << "Destruction jeu" << endl;
}

void Jeu::creationJeu()
{
	pair infoEntree("Entree", "Voici l'entree de la maison, il y a une vielle porte en bois et des chandelles aux murs.");
	pair infoSalon("Salon", "Voici le salon de la maison, il y a un vieux divan defonce et une table basse.");
	pair infoCouloir("Couloir", "Voici le couloir de la maison, tres etroit et lugubre.");
	pair infoPetiteChambre("Petite chambre", "Voici la petite chambre de la maison, on dirait que quelqu'un y a dormit recemment.");
	pair infoGrenier("Grenier", "Voici le grenier de la maison, il y a un vieux coffre sous une couche de poussiere.");
	pair infoCuisine("Cuisine", "Voici la cuisine de la maison, il y a un nombre anormale de couteau.");
	pair infoSalleR("Salle R", "");

	shared_ptr<Case> entree = make_shared<Case>(infoEntree.first, infoEntree.second);
	shared_ptr<Case> salon = make_shared<Case>(infoSalon.first, infoSalon.second);
	shared_ptr<Case> couloir = make_shared<Case>(infoCouloir.first, infoCouloir.second);
	shared_ptr<Case> petitChambre = make_shared<Case>(infoPetiteChambre.first, infoPetiteChambre.second);
	shared_ptr<Case> grenier = make_shared<Case>(infoGrenier.first, infoGrenier.second);
	shared_ptr<Case> cuisine = make_shared<Case>(infoCuisine.first, infoCuisine.second);
	shared_ptr<Case> salleR = make_shared<Case>(infoSalleR.first, infoSalleR.second);

	casesDuJeu_.push_back(entree);
	casesDuJeu_.push_back(salon);
	casesDuJeu_.push_back(couloir);
	casesDuJeu_.push_back(petitChambre);
	casesDuJeu_.push_back(grenier);
	casesDuJeu_.push_back(cuisine);
	casesDuJeu_.push_back(salleR);

	Case::lienEntreCases({ entree, Direction::Est }, { salon, Direction::Ouest });
	Case::lienEntreCases({ entree, Direction::Nord }, { couloir, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Nord }, { cuisine, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Ouest }, { petitChambre, Direction::Est });
	Case::lienEntreCases({ petitChambre, Direction::Nord }, { grenier, Direction::Sud });

	// CREATION DES OBJECTS
	shared_ptr<Objet> chandelier = make_shared<Objet>("Chandelier");
	chandelier->creerDescription("des. Regarder", "des. utiliser");
	chandelier->ajouterMotsImportant({"chandelier" , "chandelle", "feu"});

	shared_ptr<Objet> clef = make_unique<Clef>("Clef Rouge", pair(couloir, Direction::Est), pair(salleR, Direction::Sud));
	clef->creerDescription("des. Regarder", "des. utiliser");
	clef->ajouterMotsImportant({ "clef", "rouge"});

	entree->retournerObjets().push_back(chandelier);
	salon->retournerObjets().push_back(clef);

	caseActuelle_ = entree;
}

void Jeu::allerDansDirection(Direction direction)
{
	caseActuelle_ = caseActuelle_->retournerCaseDirection(direction);
}

void Jeu::prendreObjet(shared_ptr<Objet> objet)
{
	vector <shared_ptr<Objet>> objets = caseActuelle_->retournerObjets();
	objets.erase(remove(objets.begin(), objets.end(), objet), objets.end());

	objets_.push_back(objet);
}

shared_ptr<Case> Jeu::obtenirCaseDirection(Direction direction) const
{
	return caseActuelle_->retournerCaseDirection(direction);
}

vector<shared_ptr<Objet>>& Jeu::obtenirListeObjetJeu()
{
	return objets_;
}

vector<shared_ptr<Objet>>& Jeu::obtenirListeObjetCase()
{
	return caseActuelle_->retournerObjets();
}


ostream& operator<<(ostream& o, const Jeu& jeu)
{
	o << jeu.caseActuelle_;

	if (jeu.objets_.size() != 0) {
		o << "Vous avez: " << endl;

		for (auto objet : jeu.objets_)
			o << objet;
	}

	o << endl;

	return o;
}

