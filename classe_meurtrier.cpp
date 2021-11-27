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


/**< VERIFICATION DE L'EXCATITUDE D'UNE ACCUSATION AVEC LE MEURTRE COMMIS >*******************************/
bool Meurtrier::verification_victoire(Meurtrier hypothese)
{
    int i = 0;
    if(Meurtrier::m_carte_arme.verification_egalite(hypothese.m_carte_arme) == true)//arme
        i++;

    if(Meurtrier::m_carte_lieu.verification_egalite(hypothese.m_carte_lieu) == true)//lieu
        i++;

    if(Meurtrier::m_carte_personnage.verification_egalite(hypothese.m_carte_personnage) == true)//perso
       i++;

    if(i==3)
        {return true;}
    else
        return false;
}
/*********************************************************************************************************/


/**< VERIFICATION DE L'EGALITE DE 2 CARTES >**************************************************************/
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
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
std::string Meurtrier::get_arme()
{
    return  m_carte_arme.get_caracteristique();
}

std::string Meurtrier::get_lieu()
{
   return  m_carte_lieu.get_caracteristique();
}

std::string Meurtrier::get_perso()
{

   return  m_carte_personnage.get_caracteristique();
}
/*********************************************************************************************************/


/**< SAUVEGARDE DES INFORMATIONS DU MEURTRIER >***********************************************************/
void Meurtrier::sauvegarde()
{
    std::ofstream fichier;

    fichier.open("data/saves/game/meurtrier.txt"); //ouverture du fichier

    if(fichier.is_open())
    {// si fichier ouvert
        //sauvegarde des infos du crime
        fichier << Meurtrier::m_carte_arme.get_arme() << "\t\t" << Meurtrier::m_carte_arme.get_lieu() << "\t\t" << Meurtrier::m_carte_arme.get_personnage() << "\t\t" << Meurtrier::m_carte_arme.get_caracteristique() << "\n";
        fichier << Meurtrier::m_carte_lieu.get_arme() << "\t\t" << Meurtrier::m_carte_lieu.get_lieu() << "\t\t" << Meurtrier::m_carte_lieu.get_personnage() << "\t\t" << Meurtrier::m_carte_lieu.get_caracteristique() << "\n";
        fichier << Meurtrier::m_carte_personnage.get_arme() << "\t\t" << Meurtrier::m_carte_personnage.get_lieu() << "\t\t" << Meurtrier::m_carte_personnage.get_personnage() << "\t\t" << Meurtrier::m_carte_personnage.get_caracteristique() << "\n";
        fichier.close();//fermeture du fichier
    }
}
/*********************************************************************************************************/
