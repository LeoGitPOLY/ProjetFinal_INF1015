// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: GestionAffichage.cpp

#include "GestionAffichage.h"
#include <functional>

using namespace std;

void GestionAffichage::afficherEtapejeu(Jeu& jeu)
{
	cout << jeu;
	gestionEntree(jeu);
}


void GestionAffichage::gestionEntree(Jeu& jeu)
{
	string CommandeEntree;
	string objetEntree;

	cout << ">";
	cin >> CommandeEntree >> objetEntree;

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
}

void GestionAffichage::prendreObjet(Jeu& jeu, string objetCommande)
{
	vector<unique_ptr<Objet>>& objets_ = jeu.obtenirListeObjetCase();
	
	for (auto& objet : objets_) {
		if (verificationCorrespondance(*objet, objetCommande))
			bool estPrenable = objet->prendre();
	}
	
}

void GestionAffichage::utiliserObjet(Jeu& jeu, string objetCommande)
{
}

void GestionAffichage::regarderObjet(Jeu& jeu, string objetCommande)
{
}

bool GestionAffichage::verificationCorrespondance(Objet& objet, string objetCommande)
{
	//Leo: va aussi devoir rajouter ici que c<est possible de ne pas avoir le mot au complet?
	// Ou quelque chose comme ca, non?
	for (auto& mot : objet.avoirMotsImportant()) {
		if (mot == objetCommande)
			return true;
	}
	cout << "Aucun objet nommee comme ca! \n" << endl;
	return false;
}