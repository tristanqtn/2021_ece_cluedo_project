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




