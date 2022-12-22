// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 11 decembre 2022
// Cours: INF1015
// Nom de la classe: GestionAffichage.cpp

#include "GestionAffichage.h"

using namespace std;

// Nous avons voulu �viter d'utiliser string::find() pour savoir si un string fait partie d'un autre, donc nous avons impl�ment� manuellement cette fonctionnalit�
// Il n'etait pas appropri� de donner � cette fonction un objet this, donc ce n'est qu'une fonction � c�t�
bool estSubstring(string str1, string str2) {
	for (size_t i = 0; i < str2.length(); ++i) {
		if (str2[i] == str1[0]) {
			size_t j;
			for (j = 0; j < str1.length(); ++j) {
				if (str2[i + j] != str1[j]) {
					break;
				}
			}
			if (j == str1.length())
				return true;
		}
	}
	return false;
}

GestionAffichage::GestionAffichage(Jeu& jeu) : jeu_(jeu)
{
	changerBesoinQuiter(false);
	initialiserMapCommandes();
}

void GestionAffichage::afficherEtapejeu()
{
	cout << jeu_;
	gestionEntree();
}

void GestionAffichage::afficherCommande()
{
	changerCouleurConsole(Couleur::VERT);

	cout << "Les commandes du jeu sont: " << endl;
	string dernierNom;

	cout << "(N/n):" << mapCommandes_["n"]->nameFonction_ << " nord | ";
	cout << "(E/e):" << mapCommandes_["e"]->nameFonction_ << " est\n";
	cout << "(S/s):" << mapCommandes_["s"]->nameFonction_ << " sud | ";
	cout << "(O/o):" << mapCommandes_["o"]->nameFonction_ << " ouest\n";
	cout << "(P/p/prendre):" << mapCommandes_["p"]->nameFonction_ << " | ";
	cout << "(U/u/utiliser):" << mapCommandes_["u"]->nameFonction_ << "\n";
	cout << "(R/r/regarder):" << mapCommandes_["r"]->nameFonction_ << " | ";
	cout << "(Q/q/quit):" << mapCommandes_["q"]->nameFonction_ << " ";

	cout << "\n" << endl;
	changerCouleurConsole(Couleur::DEFAUT);
}

void GestionAffichage::gestionEntree()
{
	string commandeEntree;
	vector<string> vectorCommandeEntree;

	changerCouleurConsole(Couleur::DEFAUT);

	cout << ">";
	getline(cin, commandeEntree); // comme un cin normal, mais ne s'arrete pas pour les espaces
	vectorCommandeEntree = diviserParMots(commandeEntree);

	changerCouleurConsole(Couleur::ROUGE);

	if (shared_ptr<Commande> commande = mapCommandes_[vectorCommandeEntree[0]])
		commande->execute(jeu_, vectorCommandeEntree);
	else {
		cout << "Commande inconnue\n" << endl;
		gestionEntree();
	}

	changerCouleurConsole(Couleur::DEFAUT);
}

shared_ptr<Objet> GestionAffichage::rechercheBanqueMots(vector<shared_ptr<Objet>>& objets, vector<string>& objetCommande)
{
	//Leo: va aussi devoir rajouter ici que c<est possible de ne pas avoir le mot au complet?
	// Ou quelque chose comme ca, non?
	for (shared_ptr<Objet> objet : objets) {
		for (auto& motImportant : objet->avoirMotsImportant()) {
			for (auto& motCommande : objetCommande)
				if (estSubstring(motImportant, motCommande)) 
					return objet;
		}
	}
	return nullptr;
}

vector<string> GestionAffichage::diviserParMots(string commande)
{
	vector<string> mots;
	string::iterator itDebutMot = commande.begin();

	for (auto it = commande.begin(); it != commande.end(); it++)
	{
		if (*it == ' ') {
			mots.push_back(string(itDebutMot, it));
			itDebutMot = it + 1;
		}
		else if (next(it) == commande.end()) {
			mots.push_back(string(itDebutMot, next(it)));
		}
	}

	if (mots.size() == 0)
		mots.push_back(" ");

	return mots;
}

void GestionAffichage::changerCouleurConsole(Couleur couleur)
{
	if (couleur == Couleur::ROUGE) { cout << "\033[91m"; }
	else if (couleur == Couleur::BLEU) { cout << "\033[94m"; }
	else if (couleur == Couleur::VERT) { cout << "\033[92m"; }
	else if (couleur == Couleur::DEFAUT) { cout << "\033[0m"; }

}

void GestionAffichage::initialiserMapCommandes()
{
	shared_ptr<GestionAffichage> gestAff = make_shared<GestionAffichage>(*this);

	shared_ptr<CommandeUtiliser> commandeUtiliser = make_shared<CommandeUtiliser>(*this);
	shared_ptr<CommandePrendre> commandePrendre = make_shared<CommandePrendre>(*this);
	shared_ptr<CommandeRegarder> commandeRegarder = make_shared<CommandeRegarder>(*this);
	shared_ptr<CommandeAllerDirection> commandeDirection = make_shared<CommandeAllerDirection>(*this);
	shared_ptr<CommandeQuiter> commandeQuiter = make_shared<CommandeQuiter>(*this);

	mapCommandes_["U"] = commandeUtiliser;
	mapCommandes_["u"] = commandeUtiliser;
	mapCommandes_["utiliser"] = commandeUtiliser;

	mapCommandes_["P"] = commandePrendre;
	mapCommandes_["p"] = commandePrendre;
	mapCommandes_["prendre"] = commandePrendre;

	mapCommandes_["R"] = commandeRegarder;
	mapCommandes_["r"] = commandeRegarder;
	mapCommandes_["regarder"] = commandeRegarder;

	mapCommandes_["N"] = commandeDirection;
	mapCommandes_["n"] = commandeDirection;

	mapCommandes_["E"] = commandeDirection;
	mapCommandes_["e"] = commandeDirection;

	mapCommandes_["S"] = commandeDirection;
	mapCommandes_["s"] = commandeDirection;

	mapCommandes_["O"] = commandeDirection;
	mapCommandes_["o"] = commandeDirection;

	mapCommandes_["Q"] = commandeQuiter;
	mapCommandes_["q"] = commandeQuiter;
	mapCommandes_["quit"] = commandeQuiter;
}

