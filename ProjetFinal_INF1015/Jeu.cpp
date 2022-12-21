// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: Jeu.cpp

#include "Jeu.h"
#include "ObjetDeverouillant.h"
#include "ObjetTransportBidirectionnel.h"
#include "ObjetTransportUnidirectionnel.h"

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
	pair infoCuisine("Cuisine", "Voici la cuisine de la maison, il y a un nombre anormale de couteaux.");
	pair infoSalleR("Salle R", "Voici la mysterieuse Salle R");
	pair infoSousSol("Sous-Sol", "Voici le sous-sol de la maison. Il y a des vieux livres qui trainent un peu partout et une inscription sur un des murs lit '42069 forever'... Les gens qui ont habite cette maison sont decidement de haute culture!");
	pair infoCaveVin("Cave a vin", "Voici la cave a vin. La piece est fortement illuminee par des lampadaires et l'air empeste de l'alcool. Mmmmhhh.... une envie soudaine vous prend de faire un tour d'auto");

	shared_ptr<Case> entree = make_shared<Case>(infoEntree.first, infoEntree.second);
	shared_ptr<Case> salon = make_shared<Case>(infoSalon.first, infoSalon.second);
	shared_ptr<Case> couloir = make_shared<Case>(infoCouloir.first, infoCouloir.second);
	shared_ptr<Case> petitChambre = make_shared<Case>(infoPetiteChambre.first, infoPetiteChambre.second);
	shared_ptr<Case> grenier = make_shared<Case>(infoGrenier.first, infoGrenier.second);
	shared_ptr<Case> cuisine = make_shared<Case>(infoCuisine.first, infoCuisine.second);
	shared_ptr<Case> salleR = make_shared<Case>(infoSalleR.first, infoSalleR.second);
	shared_ptr<Case> sousSol = make_shared<Case>(infoSousSol.first, infoSousSol.second);
	shared_ptr<Case> caveVin = make_shared<Case>(infoCaveVin.first, infoCaveVin.second);

	casesDuJeu_.push_back(entree);
	casesDuJeu_.push_back(salon);
	casesDuJeu_.push_back(couloir);
	casesDuJeu_.push_back(petitChambre);
	casesDuJeu_.push_back(grenier);
	casesDuJeu_.push_back(cuisine);
	casesDuJeu_.push_back(salleR);
	casesDuJeu_.push_back(sousSol);
	casesDuJeu_.push_back(caveVin);

	Case::lienEntreCases({ entree, Direction::Est }, { salon, Direction::Ouest });
	Case::lienEntreCases({ entree, Direction::Nord }, { couloir, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Nord }, { cuisine, Direction::Sud });
	Case::lienEntreCases({ couloir, Direction::Ouest }, { petitChambre, Direction::Est });

	// CREATION DES OBJECTS
	shared_ptr<Objet> chandelier = make_shared<Objet>("Chandelier", "Le chandelier est une presence imposante dans la piece: fait de bronze, il illumine tous les environs", 
		"On ne peut pas utiliser le chandelier!", "On ne peut pas prendre le chandelier!");
	chandelier->ajouterMotsImportant({"chandelier" , "chandelle", "feu"});

	shared_ptr<Objet> clef = make_shared<ObjetDeverouillant>("Clef Rouge", "La clef est rouillee et semble tres agee...", 
		"Un passage entre le couloir et la Salle R s'est ouvert!\n","Vous prenez la clef, elle pourra probablement vous etre utile...\n",
		pair(couloir, Direction::Est), pair(salleR, Direction::Ouest));
	clef->ajouterMotsImportant({ "clef", "rouge"});

	shared_ptr<Objet> bouleCristal = make_shared<ObjetDeverouillant>("Boule de Cristal", "La boule de cristal est d'une lueur etrange et indescriptible. Elle emet une lumiere continuellement en mouvement, comme si elle etait vivante...","Un passage entre le sous-sol et la cave a vin s'est ouvert!\n", "Vous prenez la boule de cristal: ce faisant, vous croyez entendre un faible ricanement\n", pair(sousSol, Direction::Sud), pair(caveVin, Direction::Nord));
	bouleCristal->ajouterMotsImportant({ "boule", "cristal" });

	shared_ptr<Objet> echelle = make_shared<ObjetTransportBidirectionnel>("Echelle", "L'echelle est somme toute tres banale, et semble assez solide pour etre utilisee",
		"Vous prenez l'echelle pour changer de piece", "On ne peut pas prendre l'echelle!", petitChambre, grenier);
	echelle->ajouterMotsImportant({"echelle"});

	shared_ptr<Objet> trappe = make_shared<ObjetTransportUnidirectionnel>("Trappe Beante", "La trappe est recouverte de poussiere et de detritus, comme si quelqu'un essayait de la cacher... Vous sentez une brise fraiche monter de la trappe", "Vous prenez votre courage a deux mains et decidez de sauter par la trappe", "On ne peut pas prendre la trappe!",
		cuisine, sousSol);
	trappe->ajouterMotsImportant({ "trappe", "beante"});

	shared_ptr<Objet> corde = make_shared<ObjetTransportUnidirectionnel>("Longue Corde Rugueuse", "La corde pendouille d'un haut plafond. Elle a l'air rugueuse et remplie d'echardes, mais assez stable pour vous permettre de la grimper", "Vous aggrippez la corde de toutes vos forces avec vos mains et vos jambes, et faites laborieusement la montee...", "On ne peut pas prendre la corde!",
		caveVin, couloir);
	corde->ajouterMotsImportant({ "longue", "corde", "rugueuse"});

	entree->retournerObjets().push_back(chandelier);
	salon->retournerObjets().push_back(clef);
	petitChambre->retournerObjets().push_back(echelle);
	cuisine->retournerObjets().push_back(trappe);
	grenier->retournerObjets().push_back(echelle);
	sousSol->retournerObjets().push_back(bouleCristal);
	caveVin->retournerObjets().push_back(corde);

	caseActuelle_ = entree;
}

void Jeu::allerDansDirection(Direction direction)
{
	caseActuelle_ = caseActuelle_->retournerCaseDirection(direction);
}

// si l'objet est dans la case actuelle, on l'enleve de cette case et on l'ajoute dans les objets que le joueur possede
// on voudrait que cette methode fasse juste enlever de la case actuelle l'objet et l'ajoute dans les objets que le joueur possede, car on sait deja que l'objet est dans la case actuelle
void Jeu::prendreObjet(shared_ptr<Objet> objet)
{
	vector <shared_ptr<Objet>>& objets = obtenirListeObjetCase();
	auto itEnlever = objets.end();

	for (auto it = objets.begin(); it != objets.end(); it ++)
	{
		if ((*it)->avoirNom() == objet->avoirNom())
			itEnlever = remove(objets.begin(), objets.end(), *it);
	}
	objets.erase(itEnlever, objets.end());

	objets_.push_back(objet);
}

shared_ptr<Case> Jeu::obtenirCaseDirection(Direction direction) const
{
	return caseActuelle_->retournerCaseDirection(direction);
}

shared_ptr<Case>& Jeu::obtenirCaseActuelle()
{
	return caseActuelle_;
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

