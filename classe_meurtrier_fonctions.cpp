#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Meurtrier::Meurtrier(Carte_alibi  _carte_personnage, Carte_alibi  _carte_arme, Carte_alibi  _carte_lieu)
          :m_carte_personnage( _carte_personnage), m_carte_arme(_carte_arme), m_carte_lieu(_carte_lieu)
{}

Meurtrier::Meurtrier()
          :m_carte_personnage(), m_carte_arme(), m_carte_lieu()
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Meurtrier::~Meurtrier() {}
/*********************************************************************************************************/


/**< AFFICHER LE MEURTRIER >******************************************************************************/
void Meurtrier::afficher_meurtrier() const
{
    std::cout << "***** MEURTRIER *****" << std::endl;

    m_carte_personnage.afficher_carac();
    m_carte_lieu.afficher_carac();
    m_carte_arme.afficher_carac();

    std::cout << "*********************" << std::endl;
}
/*********************************************************************************************************/


/**< CREATION DU MEURTRIER >******************************************************************************/
Meurtrier creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes)
{
    //création de 3 entier aléatoires
    int rand_1 = rand()%6;
    int rand_2 = rand()%6;
    int rand_3 = rand()%6;

    //création d'un nouveau meurtrier en piochant alétoirement un alibi dans chaque pioche
    Meurtrier murderer(deck_personnages[rand_1], deck_lieux[rand_2], deck_armes[rand_3]);

    //suppression de la carte utlisée pour le meurtrier dans chaque pioche
    deck_personnages.erase(deck_personnages.begin()+ rand_1);
    deck_lieux.erase(deck_lieux.begin()+ rand_2);
    deck_armes.erase(deck_armes.begin()+ rand_3);

    return murderer; //rendu du meurtrier
}
/*********************************************************************************************************/

