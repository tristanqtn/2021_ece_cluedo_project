#include "header_main.h"

/**< MENU PRINCIPAL >*************************************************************************************/
int menu_principal()
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

        std::cout << "\t\t\t Choice :";

        //saisie
        std::cin>>choix_utilisateur;

    }while(choix_utilisateur>4 || choix_utilisateur<1);

    return choix_utilisateur; //rendu du choix
}
/*********************************************************************************************************/
