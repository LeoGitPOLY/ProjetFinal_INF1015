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

	cout << ">>>>> INF1015 DUNGEON CRAWLER <<<<<" << endl;
	cout << "  Leonard Pouliot & Kamil Maarite\n" << endl;

	//int i = 0; Uniquement pour tester quand le progarmme termine
	while (true) {
		/*if (i == 3)
			break;
		else
			i++;*/

		GestionAffichage::afficherEtapejeu(jeu);
	}
}
