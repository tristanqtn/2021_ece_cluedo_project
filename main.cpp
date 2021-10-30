#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

int main()
{
    srand(time(NULL));

    Partie nouvelle;
    int choix;

    do
    {
        choix = menu_principal();

        if(choix == 1)
        {//nouvelle partie
            nouvelle.creer_partie();
            nouvelle.parametrer();
            nouvelle.creer_joueurs();
            nouvelle.distribuer();
            nouvelle.lancer_partie();

        }
        else if(choix == 2)
        {//sauvegardé

        }
        else if(choix == 3)
        {//historique de victoires

        }

    }while(choix != 4);





    allegro_exit();

    return 0;
}END_OF_MAIN();
