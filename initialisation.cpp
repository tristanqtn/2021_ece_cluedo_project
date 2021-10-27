#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< SETUP ALLEGRO >**************************************************************************************/
void setupAllegro ()
{
    allegro_init();                                                         //initialisation allegro

    install_keyboard();                                                     //installation du clavier
    install_mouse();                                                        //installation de la souris

    set_color_depth(desktop_color_depth());                                 //palette de couleur

    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0))!=0)        //paramètres fenêtre
    {
        //problème avec fenêtre allegro
        allegro_exit();
        exit(EXIT_FAILURE);                                                    //fermeture allegro
        allegro_message("Pb de mode graphique");
    }

    //Initialisation du son
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {//si échec de l'initialisation, message d'erreur
        allegro_message("Erreur : %s", allegro_error);
    }

    srand(time(NULL));

}
/*********************************************************************************************************/
