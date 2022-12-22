// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 21 decembre 2022
// Cours: INF1015
// Nom de la classe: Commande.cpp

#include "Commande.h"
#include "GestionAffichage.h"

// si, parmi les objets de la case actuelle, il y en un dont un des mots importants existe dans commande, on fait objet-> prendre()
void CommandePrendre::execute(Jeu& jeu, vector<string>& commande)
{
	if (commande.size()>1){
		vector<shared_ptr<Objet>>& objets = jeu.obtenirListeObjetCase();
		if (shared_ptr<Objet> objet = gestAff_.rechercheBanqueMots(objets, commande)) {
			objet->prendre(jeu);
		}
		else { cout << "Aucun objet nommee comme ca! \n" << endl; }
	}
	else { cout << "Vous devez entrer un objet a prendre! \n" << endl; }

}

// si, parmi les objets de la case actuelle, il y en un dont un des mots importants existe dans commande, le joueur ne l'a pas sur lui et on lui dit
// si, parmi les objets que le joueur possede, il y en un dont un des mots importants existe dans commande, on fait objet->utiliser()
void CommandeUtiliser::execute(Jeu& jeu, vector<string>& commande)
{
	if (commande.size() > 1) {
		vector<shared_ptr<Objet>>& objetsJeu = jeu.obtenirListeObjetJeu();
		vector<shared_ptr<Objet>>& objetsCase = jeu.obtenirListeObjetCase();

		if (shared_ptr<Objet> objet = gestAff_.rechercheBanqueMots(objetsCase, commande)) {
			if (objet->estPrenable()) { cout << "Vous devez avoir l'objet sur vous pour l'utiliser \n" << endl; }
			else
				objet->utiliser(jeu, jeu.obtenirCaseActuelle());
		}
		else if (shared_ptr<Objet> objet = gestAff_.rechercheBanqueMots(objetsJeu, commande)) {
			objet->utiliser(jeu, jeu.obtenirCaseActuelle());
		}
		else { cout << "Aucun objet nommee comme ca! \n" << endl; }
	}
	else {cout << "Vous devez entrer un objet a utiliser! \n" << endl;}

}

void CommandeRegarder::execute(Jeu& jeu, vector<string>& commande)
{
	vector<shared_ptr<Objet>>& objetsCase = jeu.obtenirListeObjetCase();
	if (commande.size()>1){
		if (shared_ptr<Objet> objet = gestAff_.rechercheBanqueMots(objetsCase, commande)) {
			objet->regarder();
		}
		else { cout << "Aucun objet nommee comme ca! \n" << endl; }
	}
}

void CommandeQuiter::execute(Jeu& jeu, vector<string>& commande)
{
	cout << "Jeu termine " << endl;
	gestAff_.changerBesoinQuiter(true);
}

void CommandeAllerDirection::execute(Jeu& jeu, vector<string>& commande)
{
	Direction direction = static_cast<Direction>(toupper(commande[0][0]));

	if (jeu.obtenirCaseDirection(direction) != nullptr) {
		jeu.allerDansDirection(direction);
		cout << "Aller " << Case::directionNom_[direction] << "\n" << endl;
	}
	else {
		cout << "Vous ne pouvez pas aller la!\n" << endl;
	}
}
