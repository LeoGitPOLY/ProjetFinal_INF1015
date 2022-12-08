#include "GestionAffichage.h"

using namespace std;

void GestionAffichage::afficherEtapejeu(Jeu& jeu)
{
	cout << jeu;

	string entree;
	cout << "\n>";
	cin >> entree;

	if (entree == "N" || entree == "S" || entree == "E" || entree == "O") {
		Direction direction = static_cast<Direction>(entree[0]);
		jeu.allerDansDirection(direction);
	}
	else if (entree == "look") {
	}
	else {
		cout << "Commande inconnue" << endl;
	}
}
