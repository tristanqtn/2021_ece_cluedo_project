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
    srand(time(NULL));
    setupAllegro();
    Cluedo jeu;

    jeu.lancer_jeu();

    return 0;

}END_OF_MAIN();
/*********************************************************************************************************/
