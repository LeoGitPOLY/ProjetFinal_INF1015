#include <iostream>
#include "Case.h"

int main()
{
    pair<string, string> infoEntree = { "Entrée", "Entrée description" };
    pair<string, string> infoSalon = { "Salon", "Salon description" };
    pair<string, string> infoCouloir = { "Couloir", "Couloir description" };
    pair<string, string> infoPetiteChambre = { "Petite chambre", "Petite chambre description" };
    pair<string, string> infoGrenier = { "Grenier", "Grenier description" };
    pair<string, string> infoCuisine = { "Cuisine", "Cuisine description" };

    shared_ptr<Case> entree = make_shared<Case>(infoEntree.first, infoEntree.second);
    shared_ptr<Case> salon = make_shared<Case>(infoSalon.first, infoSalon.second);
    shared_ptr<Case> couloir = make_shared<Case>(infoCouloir.first, infoCouloir.second);
    shared_ptr<Case> petitChambre = make_shared<Case>(infoPetiteChambre.first, infoPetiteChambre.second);
    shared_ptr<Case> grenier = make_shared<Case>(infoGrenier.first, infoGrenier.second);
    shared_ptr<Case> cuisine = make_shared<Case>(infoCuisine.first, infoCuisine.second);

    Case::lienEntreCases({ entree, Direction::Est }, { salon, Direction::Ouest });
    Case::lienEntreCases({ entree, Direction::Nord }, { couloir, Direction::Sud });
    Case::lienEntreCases({ couloir, Direction::Nord }, { cuisine, Direction::Sud });
    Case::lienEntreCases({ couloir, Direction::Ouest }, { petitChambre, Direction::Est });
    Case::lienEntreCases({ petitChambre, Direction::Nord }, { grenier, Direction::Sud });


    shared_ptr<Case> caseActuelle = entree;

    cout << caseActuelle;
    caseActuelle = caseActuelle->allerDansDirection(Direction::Nord);

    cout << caseActuelle;
    caseActuelle = caseActuelle->allerDansDirection(Direction::Nord);

    cout << caseActuelle;
    caseActuelle = caseActuelle->allerDansDirection(Direction::Sud);

    cout << caseActuelle;
    caseActuelle = caseActuelle->allerDansDirection(Direction::Ouest);

    cout << caseActuelle;
    caseActuelle = caseActuelle->allerDansDirection(Direction::Nord);

    cout << caseActuelle;
}
