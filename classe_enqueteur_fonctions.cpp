#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
//default
Enqueteur::Enqueteur()
          : m_main(), m_pion(""), m_nom(""), m_prenom("")
{}

//surchagé
Enqueteur::Enqueteur(std::vector <Carte_alibi> _main, std::string _pion, std::string _nom, std::string _prenom)
          : m_main(_main), m_pion(_pion), m_nom(_nom), m_prenom(_prenom)
{}
/*********************************************************************************************************/


/**< DESTRUCTOR >*****************************************************************************************/
Enqueteur::~Enqueteur() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
std::vector <Carte_alibi> Enqueteur::get_main() const { return m_main; }

std::string Enqueteur::get_nom() const { return m_nom; }
std::string Enqueteur::get_prenom() const { return m_prenom; }
std::string Enqueteur::get_pion() const { return m_pion; }
/*********************************************************************************************************/


/**< AFFICHAGES >*****************************************************************************************/
void Enqueteur::afficher_main() const
{//affichage de la main de l'enqueteur
    std::cout << "*** MAIN DE L'ENQUETEUR ***" << std::endl;
    for(auto const& elem : m_main)
    {
        elem.afficher_carac();
    }
    std::cout << "***************************" << std::endl;
}

void Enqueteur::afficher_ID() const
{//affichage de toute les données de l'enqueteur
    std::cout << "*** " << get_nom() << " " << get_prenom() << " ***" <<std::endl;
    std::cout << "Pion : " << get_pion() << std::endl;

    Enqueteur::afficher_main();
}
/*********************************************************************************************************/


/**< RENDU DU POINTEUR SUR ENQUETEUR >********************************************************************/
Enqueteur * Enqueteur::get_pointer() { return this; }
/*********************************************************************************************************/


void Enqueteur::recevoir_carte(Carte_alibi nouvelle_carte)
{
    m_main.push_back(nouvelle_carte);
}
