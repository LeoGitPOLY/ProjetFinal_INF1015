#pragma once
#include <iostream>
#include <map>
#include "Jeu.h"

class GestionAffichage;

using namespace std;

class Commande {
public:
	Commande(GestionAffichage& gestAff) :gestAff_(gestAff) {};
	virtual void execute(Jeu& jeu, vector<string>& commande) = 0;
	string nameFonction_;

protected:
	GestionAffichage& gestAff_;
};

class CommandePrendre : public Commande {
public:
	CommandePrendre(GestionAffichage& gestAff) : Commande(gestAff) { nameFonction_ = "Prendre objet"; };
	void execute(Jeu& jeu, vector<string>& commande) override;
};

class CommandeUtiliser : public Commande {
public:
	CommandeUtiliser(GestionAffichage& gestAff) : Commande(gestAff) { nameFonction_ = "Utiliser objet"; };
	void execute(Jeu& jeu, vector<string>& commande) override;
};

class CommandeRegarder : public Commande {
public:
	CommandeRegarder(GestionAffichage& gestAff) : Commande(gestAff) { nameFonction_ = "Regarder objet"; };
	void execute(Jeu& jeu, vector<string>& commande) override;
};

class CommandeQuiter : public Commande {
public:
	CommandeQuiter(GestionAffichage& gestAff) : Commande(gestAff) { nameFonction_ = "Quitter jeu"; };
	void execute(Jeu& jeu, vector<string>& commande) override;
};

class CommandeAllerDirection : public Commande {
public:
	CommandeAllerDirection(GestionAffichage& gestAff) : Commande(gestAff) { nameFonction_ = "Aller direction"; };
	void execute(Jeu& jeu, vector<string>& commande) override;
};

