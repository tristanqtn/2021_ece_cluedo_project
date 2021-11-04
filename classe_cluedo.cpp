#include "header_cluedo.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Cluedo::Cluedo()
       :m_partie()
{}

Cluedo::Cluedo(Partie _partie)
       :m_partie( _partie)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Cluedo::~Cluedo() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
Partie Cluedo::get_partie() const { return m_partie; }

Cluedo * Cluedo::get_pointeur() { return this; }
/*********************************************************************************************************/


/**< SETTERS >********************************************************************************************/
void Cluedo::set_partie(Partie valeur) { m_partie = valeur; }
/*********************************************************************************************************/


/**< MENU PRINCIPAL >*************************************************************************************/
int Cluedo::menu_principal()
{
    int choix_utilisateur;

    do
    {//blindage
        system("CLS"); //nettoyage ecran

        //affichage
        std::cout << "\t\t************* MENU *************" << std::endl;
        std::cout << "\t\t* 1- Nouvelle partie           *" << std::endl;
        std::cout << "\t\t* 2- Partie sauvegarde         *" << std::endl;
        std::cout << "\t\t* 3- Historique de victoires   *" << std::endl;
        std::cout << "\t\t* 4- Sortie                    *" << std::endl;
        std::cout << "\t\t********************************" << std::endl << std::endl;

        std::cout << "\t\t\t Choice : ";

        //saisie
        std::cin>>choix_utilisateur;

    }while(choix_utilisateur>4 || choix_utilisateur<1);

    return choix_utilisateur; //rendu du choix
}
/*********************************************************************************************************/


/**< FUNCTION >*******************************************************************************************/
void Cluedo::lancer_jeu()
{
    int choix;

    do
    {
        choix = Cluedo::menu_principal();

        if(choix == 1)
        {//nouvelle partie
            m_partie.creer_partie();
            m_partie.parametrer();
            m_partie.creer_joueurs();
            m_partie.creer_IA();
            m_partie.distribuer();
            m_partie.lancer_partie();

        }
        else if(choix == 2)
        {//sauvegardé

        }
        else if(choix == 3)
        {//historique de victoires

        }

    }while(choix != 4);

}
/*********************************************************************************************************/
