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
	string entree;
	cout << ">";
	cin >> entree;

	if (entree == "N" || entree == "S" || entree == "E" || entree == "O") {
		Direction direction = static_cast<Direction>(entree[0]);

		if (jeu.obtenirCaseDirection(direction) != nullptr) {
			jeu.allerDansDirection(direction);
			cout << "Aller " << Case::directionNom_[direction] << "\n" << endl;
		}
		else {
			cout << "Vous ne pouvez pas aller la!\n" << endl;
			gestionEntree(jeu);
		}
	}
	else if (entree == "look") {
		afficherEtapejeu(jeu);
	}
	else {
		cout << "Commande inconnue\n" << endl;
		gestionEntree(jeu);
	}
}
