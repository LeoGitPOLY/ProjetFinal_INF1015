// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: main.cpp

#include <iostream>
#include "GestionAffichage.h"
#include "Jeu.h"

int main()
{
	Jeu jeu;
	GestionAffichage gestionAffichage(jeu);

	cout << ">>>>> INF1015 DUNGEON CRAWLER <<<<<" << endl;
	cout << "  Leonard Pouliot & Kamil Maarite" << endl;
	gestionAffichage.afficherCommande();

	while (true) {
		if (gestionAffichage.avoirBesoinQuiter())
			break;

		gestionAffichage.afficherEtapejeu();
	}
}
