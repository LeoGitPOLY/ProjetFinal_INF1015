#include <iostream>
#include "GestionAffichage.h"
#include "Jeu.h"

int main()
{
	Jeu jeu;

	cout << ">>>>> INF1015 DUNGEON CRAWLER <<<<<" << endl;
	cout << "  Leonard Pouliot & Kamil Maarite\n" << endl;

	while (true) {

		GestionAffichage::afficherEtapejeu(jeu);
	}
}
