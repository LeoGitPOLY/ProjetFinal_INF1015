// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: GestionAffichage.h

#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include "Jeu.h"
#include "Commande.h"

enum class Couleur {
	ROUGE,
	BLEU,
	VERT,
	DEFAUT
};

class GestionAffichage
{
public:
	GestionAffichage(Jeu& jeu);

	void afficherEtapejeu();
	void afficherCommande();
	void gestionEntree();
	
	shared_ptr<Objet> rechercheBanqueMots(vector<shared_ptr<Objet>>& objets, vector<string>& objetCommande);
	
	void changerBesoinQuiter(bool besoinQuiter) { besoinQuiter_ = besoinQuiter; };
	bool avoirBesoinQuiter() { return besoinQuiter_; };

private:
	vector<string> diviserParMots(string objetCommande);
	void changerCouleurConsole(Couleur couleur);
	void initialiserMapCommandes();

	Jeu& jeu_;
	bool besoinQuiter_;
	map<string, shared_ptr<Commande>> mapCommandes_;
};
