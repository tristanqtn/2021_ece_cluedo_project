#include "header_case.h"
#include "header_carte.h"
#include "header_cluedo.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
#include "header_principal.h"

/*********************************************************************************************************/
int main()
{
    //initialisation
    srand(time(NULL));
    setupAllegro();

    //lancement du jeu
    Cluedo jeu;
    jeu.lancer_jeu();

    //sortie du jeu
    allegro_exit();
    return 0;

}END_OF_MAIN();
/*********************************************************************************************************/
