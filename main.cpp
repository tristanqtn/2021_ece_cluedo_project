#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

int main()
{
    srand(time(NULL));

    setupAllegro();

    Partie nouvelle;

    nouvelle.creer_partie();
    nouvelle.afficher_meurtrier();
    std::cout << std::endl << std::endl;
    nouvelle.afficher_deck();

    allegro_exit();

    return 0;
}END_OF_MAIN();
