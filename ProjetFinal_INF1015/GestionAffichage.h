// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: GestionAffichage.h

#pragma once
#include <iostream>
#include "Jeu.h"

class GestionAffichage
{
public:
	static void afficherEtapejeu(Jeu& jeu);
	static void gestionEntree(Jeu& jeu);
	
private:
	static void prendreObjet(Jeu& jeu, string objetCommande);
	static void regarderObjet(Jeu& jeu, string objetCommande);
	static void utiliserObjet(Jeu& jeu, string objetCommande);

	static shared_ptr<Objet> rechercheBanqueMots(vector<shared_ptr<Objet>>& objets, string objetCommande);
};
