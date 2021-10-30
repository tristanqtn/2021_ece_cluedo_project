#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
//surcharg�
Carte_alibi::Carte_alibi(bool _personnage, bool _lieu, bool _arme, std::string _spec)
            :m_personnage (_personnage), m_lieu (_lieu), m_arme (_arme), m_caracteristique(_spec)
{}

//d�fault
Carte_alibi::Carte_alibi()
            :m_personnage (), m_lieu(), m_arme(), m_caracteristique("")
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Carte_alibi::~Carte_alibi() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Carte_alibi::get_personnage() const { return m_personnage; } //suspect
bool Carte_alibi::get_lieu() const { return m_lieu; } //lieu
bool Carte_alibi::get_arme() const { return m_arme; } //arme

std::string Carte_alibi::get_caracteristique() const { return m_caracteristique; } //definition
/*********************************************************************************************************/


/**<  AFFICHER ELEMENT DE LA CARTE >**********************************************************************/
void Carte_alibi::afficher_carac() const
{
    if(get_personnage() == true)
    {//affichage d'un suspect
        std::cout << "Carte suspect : " << get_caracteristique() << std::endl;
    }
    else if(get_arme() == true)
    {//affichage d'une arme
        std::cout << "Carte arme : " << get_caracteristique() << std::endl;
    }
    else if(get_lieu() == true)
    {//affichage d'un lieu
        std::cout << "Carte lieu : " << get_caracteristique() << std::endl;
    }
    else
    {//cas normalement impossible
        std::cout << "ERROR" << std::endl;
    }
}
/*********************************************************************************************************/



