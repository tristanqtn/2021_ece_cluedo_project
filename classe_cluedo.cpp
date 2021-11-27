#include "header_cluedo.h"
#include "header_principal.h"

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


/**< MENU PRINCIPAL >*************************************************************************************/
int Cluedo::menu_principal()
{
    int choix_utilisateur;

    //affichage de l'image de fond
    BITMAP * background = chargerImage("data/bitmap/menu/menu_1.bmp");
    stretch_blit(background, screen, 0, 0, background->w, background->h, 0, 0, SCREEN_W, SCREEN_H);
    show_mouse(screen);
    destroy_bitmap(background);

    do
    {//menu
        system("CLS"); //nettoyage ecran

        std::cout<<"\t\t   ________    __  ____________  ____ "   << std::endl;
        std::cout<<"\t\t  / ____/ /   / / / / ____/ __ \\/ __ \\"  << std::endl;
        std::cout<<"\t\t / /   / /   / / / / __/ / / / / / / /"   << std::endl;
        std::cout<<"\t\t/ /___/ /___/ /_/ / /___/ /_/ / /_/ / "   << std::endl;
        std::cout<<"\t\t\\____/_____/\\____/_____/_____/\\____/  "   << std::endl;
        std::cout<<"                                      "   << std::endl;
        std::cout<<"\t\t       ____  ___  __________          "   << std::endl;
        std::cout<<"\t\t      / __ \\/   |/_  __/ __ \\         "   << std::endl;
        std::cout<<"\t\t     / /_/ / /| | / / / /_/ /         "   << std::endl;
        std::cout<<"\t\t    / _, _/ ___ |/ / / ____/          "   << std::endl;
        std::cout<<"\t\t   /_/ |_/_/  |_/_/ /_/               "   << std::endl << std::endl << std::endl;



        //affichage
        std::cout << "\t\t              MENU              " << std::endl << std::endl << std::endl;
        std::cout << "\t\t  1- Nouvelle partie            " << std::endl << std::endl;
        std::cout << "\t\t  2- Partie sauvegarde          " << std::endl << std::endl;
        std::cout << "\t\t  3- Historique de victoires    " << std::endl << std::endl;
        std::cout << "\t\t  4- Sortie                     " << std::endl << std::endl;
        std::cout << "\t\t                                " << std::endl << std::endl;

        std::cout << std::endl << "\t\t\t Choix : ";

        //saisie
        std::cin>>choix_utilisateur;

    }
    while(choix_utilisateur>4 || choix_utilisateur<1);

    return choix_utilisateur; //rendu du choix
}
/*********************************************************************************************************/


/**< JEU >************************************************************************************************/
void Cluedo::lancer_jeu()
{
    int choix;

    do
    {
        choix = Cluedo::menu_principal();

        if(choix == 1)
        {//nouvelle partie

            m_partie.creer_partie(); //création de la partie

            //affichage du fond d'écran
            clear_bitmap(screen);
            BITMAP * background = chargerImage("data/bitmap/menu/menu_2.bmp");
            show_mouse(NULL);
            stretch_blit(background, screen, 0, 0, background->w, background->h, 0, 0, SCREEN_W, SCREEN_H);
            show_mouse(screen);
            destroy_bitmap(background);

            m_partie.parametrer(); // paramétrage de la partie
            m_partie.creer_joueurs(); // création des joueurs
            m_partie.creer_IA(); //création des IAS
            m_partie.choix_pion(); //choix des pions
            m_partie.distribuer(); //distribution des cartes
            m_partie.initialisation(); //initialisation de la partie (compteurs, sauvegarde partiels, destructions de certains fichiers)
            m_partie.lancer_partie(); //boucle de jeu
        }
        else if(choix == 2)
        {//sauvegardé
            m_partie.recuperation_tot_partie(); //recuperation de la sauvegarde
            m_partie.creer_IA(); //création des IA si nécessaire
            m_partie.lancer_partie(); //boucle de jeu
        }
        else if(choix == 3)
        {//historique de victoires
            int nb_victoires = m_partie.nombre_victoire(); //recuperation du nombre de victoire enregistrées
            m_partie.historique_victoire(nb_victoires); // affichage des victoires passées
            system("pause");
        }
    }
    while(choix != 4);
}
/*********************************************************************************************************/
