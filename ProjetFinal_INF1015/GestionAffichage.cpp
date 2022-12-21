// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: GestionAffichage.cpp

#include "GestionAffichage.h"

using namespace std;

void GestionAffichage::afficherEtapejeu(Jeu& jeu)
{
	cout << jeu;
	gestionEntree(jeu);
}


void GestionAffichage::gestionEntree(Jeu& jeu)
{
	// map<string nomCommande, function<void(Jeu& jeu, objetEntree)>> mapCommandes;
	// executerCommande(mapCommandes[CommandeEntree], objetEntree);
	string CommandeEntree;
	string objetEntree;

	cout << ">";
	cin >> CommandeEntree >> objetEntree;

	//initialiserMapCommandes();
	if (CommandeEntree == "N" || CommandeEntree == "S" || CommandeEntree == "E" || CommandeEntree == "O") {
		Direction direction = static_cast<Direction>(CommandeEntree[0]);

		if (jeu.obtenirCaseDirection(direction) != nullptr) {
			jeu.allerDansDirection(direction);
			cout << "Aller " << Case::directionNom_[direction] << "\n" << endl;
		}
		else {
			cout << "Vous ne pouvez pas aller la!\n" << endl;
			gestionEntree(jeu);
		}
	}
	else if (CommandeEntree == "U") { //Leo: En attendant que la bonne maniere sois fait, pour tester
		utiliserObjet(jeu, objetEntree);
	}
	else if (CommandeEntree == "P") { //Leo: En attendant que la bonne maniere sois fait, pour tester
		prendreObjet(jeu, objetEntree);
	}
	else if (CommandeEntree == "R") { //Leo: En attendant que la bonne maniere sois fait, pour tester
		regarderObjet(jeu, objetEntree);
	}
	else {
		cout << "Commande inconnue\n" << endl;
		gestionEntree(jeu);
	}
	//mapCommandes_[CommandeEntree](jeu, objetEntree);
}

// si, dans la case actuelle du jeu, ya un objet dont le nom concorde avec objetCommande, on fait cet objet->prendre();
void GestionAffichage::prendreObjet(Jeu& jeu, string objetCommande)
{
	vector<shared_ptr<Objet>>& objets = jeu.obtenirListeObjetCase();

	if (shared_ptr<Objet> objet = rechercheBanqueMots(objets, objetCommande)) {
		objet->prendre(jeu);
	}
}

void GestionAffichage::utiliserObjet(Jeu& jeu, string objetCommande)
{
	vector<shared_ptr<Objet>>& objets = jeu.obtenirListeObjetJeu();

	if (shared_ptr<Objet> objet = rechercheBanqueMots(objets, objetCommande)) {
		objet->utiliser(jeu, jeu.obtenirCaseActuelle()); // Kamil: le polymorphisme ne marche pas, il utilise objet::utiliser() et non celle de clef, etrange
	}
}

void GestionAffichage::regarderObjet(Jeu& jeu, string objetCommande)
{
}

// si, dans un vector d'objets, il y en un qui a objetCommande dans ses mots importants, retourner cet objet (en shared_ptr)
shared_ptr<Objet> GestionAffichage::rechercheBanqueMots(vector<shared_ptr<Objet>>& objets, string objetCommande)
{
	//Leo: va aussi devoir rajouter ici que c<est possible de ne pas avoir le mot au complet?
	// Ou quelque chose comme ca, non?
	for (shared_ptr<Objet> objet : objets) {
		for (auto& mot : objet->avoirMotsImportant()) {
			if (mot == objetCommande)
				return objet;
		}
	}
	cout << "Aucun objet nommee comme ca! \n" << endl;
	return nullptr;
}

//void GestionAffichage::initialiserMapCommandes()
//{
//	mapCommandes_["U"] = utiliserObjet;
//	mapCommandes_["P"] = prendreObjet;
//	mapCommandes_["R"] = regarderObjet;
//}

