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
	pair infoEntree("Entree", "Voici l'entree de la maison, il y a une vielle porte en bois et des chandelles aux murs");
	pair infoSalon("Salon", "Voici le salon de la maison, il y a un vieux divan defonce et une table basse");
	pair infoCouloir("Couloir", "Voici le couloir de la maison, tres etroit et lugubre");
	pair infoPetiteChambre("Petite chambre", "Voici la petite chambre de la maison, on dirait que quelqu'un y a dormit recemment.");
	pair infoGrenier("Grenier", "Voici le grenier de la maison. L'air est tres sale, et la visibilite est reduite a cause du manque de lumiere");
	pair infoCuisine("Cuisine", "Voici la cuisine de la maison, il y a un nombre anormal de couteaux");
	pair infoSalleR("Salle R", "Voici la mysterieuse Salle R. Il y a un grand nombre de 'R' peintures partout sur les murs de la piece");
	pair infoSousSol("Sous-Sol", "Voici le sous-sol de la maison. Il y a des vieux livres de magie qui trainent un peu partout");
	pair infoCaveVin("Cave a vin", "Voici la cave a vin. La piece est fortement illuminee par des lampadaires et l'air empeste de l'alcool. Miammmhh...");
	pair infoCinemaMaison("Cinema maison", "Voici le cinema maison. Il y a assez de sieges pour permettre a une vingtaine de personne de s'asseoir, et une grande vitre avec un projecteur est situee au fond arriere de la piece");
	pair infoSalleProjection("Salle de projection", "Voici la salle de projection. Vous voyez des fragments de vitre un peu partout sur le sol. Un projecteur est situe au centre.");

	shared_ptr<Case> entree = make_shared<Case>(infoEntree.first, infoEntree.second);
	shared_ptr<Case> salon = make_shared<Case>(infoSalon.first, infoSalon.second);
	shared_ptr<Case> couloir = make_shared<Case>(infoCouloir.first, infoCouloir.second);
	shared_ptr<Case> petitChambre = make_shared<Case>(infoPetiteChambre.first, infoPetiteChambre.second);
	shared_ptr<Case> grenier = make_shared<Case>(infoGrenier.first, infoGrenier.second);
	shared_ptr<Case> cuisine = make_shared<Case>(infoCuisine.first, infoCuisine.second);
	shared_ptr<Case> salleR = make_shared<Case>(infoSalleR.first, infoSalleR.second);
	shared_ptr<Case> sousSol = make_shared<Case>(infoSousSol.first, infoSousSol.second);
	shared_ptr<Case> caveVin = make_shared<Case>(infoCaveVin.first, infoCaveVin.second);
	shared_ptr<Case> cinemaMaison = make_shared<Case>(infoCinemaMaison.first, infoCinemaMaison.second);
	shared_ptr<Case> salleProjection = make_shared<Case>(infoSalleProjection.first, infoSalleProjection.second);

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


	shared_ptr<Objet> chandelier = make_shared<Objet>("Un majestueux chandelier", "Le chandelier est une presence imposante dans la piece: fait de bronze, il illumine tous les environs", 
		"Vous tentez d'eteindre la flamme du chandelier avec vos doigts, mais elle brule si fort que vous en etes incapable et vous vous brulez le bout des doigts", "Vous essayez de prendre le chandelier, mais il semble fixe au mur");
	chandelier->ajouterMotsImportant({"chandelier" , "chandelle", "feu"});

	shared_ptr<Objet> lecteurTourneDisque = make_shared<Objet>("Un lecteur tourne-disque", "Le lecteur est de style vintage et a un disque de Charles Aznavour", "Vous lancez la lecture du disque, et les paroles de 'La Boheme' remplissent l'air", "Vous tentez de prendre le lecture tourne-disque, mais il semble attache a la table sur laquelle il repose");
	lecteurTourneDisque->ajouterMotsImportant({ "lecteur", "tourne", "disque" });

	shared_ptr<Objet> clef = make_shared<ObjetDeverouillant>("Une petite clef rouge", "La clef est rouillee et semble tres agee...", 
		"Vous essayez chaque serrure, jusqu'a ce que vous debloquiez une porte et qu'un passage entre le couloir et une nouvelle salle a l'est se soit ouvert!","Vous prenez la clef, elle pourra probablement vous etre utile...", pair(couloir, Direction::Est), pair(salleR, Direction::Ouest));
	clef->ajouterMotsImportant({ "clef", "rouge"});

	shared_ptr<Objet> ouvreBouteille = make_shared<ObjetDeverouillant>("Un magnifique ouvre bouteille", "L'ouvre bouteille est un peu rouille et semble avoir fait son temps", "Vous ouvrez une bouteille de vin, puis en buvez le contenu. L'alcool fait rapidement son effet et vous vous sentez plus leger: en trepidant de joie, vous accrochez un bouton qui etait le mur... et cela ouvre un passge entre la cave a vin et une nouvelle piece!", "Vous prenez l'ouvre bouteille: peut-etre vous sera-t-il utile?",
		pair(caveVin, Direction::Sud), pair(cinemaMaison, Direction::Nord));
	ouvreBouteille->ajouterMotsImportant({ "ouvre", "bouteille", "ouvrebouteille", "ouvre bouteille" });

	shared_ptr<Objet> marteau = make_shared<ObjetDeverouillant>("Un imposant marteau", "Le marteau fait la taille d'une ballon de football, et son metal rouille semble indiquer un long historique d'utilisation", "Vous frappez dans la vitre de toutes vos forces: elle eclate en mille morceaux et vous avez le champ libre pour visiter la salle de projection!", "Malgre son poids, vous etes capable de prendre le marteau", pair(cinemaMaison, Direction::Ouest), pair(salleProjection, Direction::Est));
	marteau->ajouterMotsImportant({ "marteau", "imposant" });

	shared_ptr<Objet> bouleCristal = make_shared<ObjetDeverouillant>("Une boule de cristal", "La boule de cristal est d'une lueur etrange et indescriptible. Elle emet une lumiere continuellement en mouvement, comme si elle etait vivante...","Vous sentez quelque chose de magique dans l'air, et soudainement, un porte apparait au mur sud!", "Vous prenez la boule de cristal: ce faisant, vous croyez entendre un faible ricanement\n", pair(sousSol, Direction::Sud), pair(caveVin, Direction::Nord));
	bouleCristal->ajouterMotsImportant({ "boule", "cristal" });

	shared_ptr<Objet> echelle = make_shared<ObjetTransportBidirectionnel>("Une echelle en bois", "L'echelle est somme toute tres banale, et semble assez solide pour etre utilisee",
		"Vous prenez l'echelle pour changer de piece", "L'echelle fait partie de la structure de la maison et ne peut pas etre prise", petitChambre, grenier);
	echelle->ajouterMotsImportant({"echelle", "bois"});

	shared_ptr<Objet> trappe = make_shared<ObjetTransportUnidirectionnel>("Une trappe beante", "La trappe est recouverte de poussiere et de detritus, comme si quelqu'un essayait de la cacher... Vous sentez une brise fraiche monter de la trappe", "Vous prenez votre courage a deux mains et decidez de sauter par la trappe", "C'est un peu absurde d'essayer de prendre un objet qui est defini par l'absence de matiere, n'est-ce pas? :)))",
		cuisine, sousSol);
	trappe->ajouterMotsImportant({ "trappe", "beante"});

	shared_ptr<Objet> corde = make_shared<ObjetTransportUnidirectionnel>("Une longue corde rugueuse", "La corde pendouille d'un haut plafond. Elle a l'air rugueuse et remplie d'echardes, mais assez stable pour vous permettre de la grimper", "Vous aggrippez la corde de toutes vos forces avec vos mains et vos jambes, et faites laborieusement la montee...Une fois rendu en haut, vous avez soudainement le vertige et ne pourrez pas utiliser la corde pour redescendre", "On ne peut pas prendre la corde, elle fait partie de la maison!",
		caveVin, couloir);
	corde->ajouterMotsImportant({ "longue", "corde", "rugueuse"});

	entree->retournerObjets().push_back(chandelier);
	salon->retournerObjets().push_back(clef);
	petitChambre->retournerObjets().push_back(echelle);
	cuisine->retournerObjets().push_back(trappe);
	grenier->retournerObjets().push_back(echelle);
	grenier->retournerObjets().push_back(ouvreBouteille);
	salleR->retournerObjets().push_back(marteau);
	sousSol->retournerObjets().push_back(bouleCristal);
	caveVin->retournerObjets().push_back(corde);
	salleProjection->retournerObjets().push_back(lecteurTourneDisque);

	caseActuelle_ = entree;
}

void Jeu::allerDansDirection(Direction direction)
{
	caseActuelle_ = caseActuelle_->retournerCaseDirection(direction);
}

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

