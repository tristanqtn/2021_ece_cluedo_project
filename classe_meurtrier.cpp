#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
#include "header_principal.h"

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



bool Meurtrier::verification_victoire(Meurtrier hypothese)
{
    int i = 0;
    if(Meurtrier::m_carte_arme.verification_egalite(hypothese.m_carte_arme) == true)
        i++;

    if(Meurtrier::m_carte_lieu.verification_egalite(hypothese.m_carte_lieu) == true)
        i++;

    if(Meurtrier::m_carte_personnage.verification_egalite(hypothese.m_carte_personnage) == true)
       i++;

    if(i==3)
        {
        std::cout << "Hypothese vraie, bravo !" <<std::endl;
        return true;}
    else
        return false;
}

bool Meurtrier::verification_carte(Carte_alibi test)
{
    bool resultat = false;

    if(Meurtrier::m_carte_arme.verification_egalite(test) == true)
    {
        resultat = true;
    }
    if(Meurtrier::m_carte_personnage.verification_egalite(test) == true)
    {
        resultat = true;
    }
    if(Meurtrier::m_carte_lieu.verification_egalite(test) == true)
    {
        resultat = true;
    }

    return resultat;
}

