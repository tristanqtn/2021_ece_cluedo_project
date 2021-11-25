#include "header_principal.h"

/**< SETUP ALLEGRO >**************************************************************************************/
void setupAllegro ()
{
    allegro_init();                                                         //initialisation allegro

    install_keyboard();                                                     //installation du clavier
    install_mouse();                                                        //installation de la souris

    set_color_depth(desktop_color_depth());                                 //palette de couleur

    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0))!=0)        //paramètres fenêtre
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


/**< CHARGER MUSIQUE >*************************************************************************************/
SAMPLE * chargerMusique(const char * filename)
{
    //Déclarations
    SAMPLE* musique;

    musique = load_sample(filename);                                        //chargement du fichier son

    if (musique == NULL)
    {//le pointeur de sample ne pointe pas correctement sur le fichier
        allegro_message("Erreur de chargement de la musique : %s", filename);         //message d'erreur
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    return musique;                                                         //retourne le pointeur sur fichier son
}
/*********************************************************************************************************/



/**< CHARGER D'UNE IMAGE >********************************************************************************/
BITMAP * chargerImage (const char * filename)
{
    //Déclarations
    BITMAP * image;

    image = load_bitmap(filename, NULL);                                    //chargement de l'image

    if (image == NULL)
    {//le pointeur d'image ne pointe pas correctement sur le fichier
        allegro_message("Erreur de chargement de l'image : %s", filename);                        //message d'erreur
        allegro_exit();                                                     //fermeture allegro
        exit(EXIT_FAILURE);
    }

    return image;
}
/*********************************************************************************************************/



/**< CREER UNE BITMAP >***********************************************************************************/
BITMAP * creerBuffer (int largeur, int hauteur, const char * filename)
{
    //Déclarations
    BITMAP * image;

    image = create_bitmap(largeur, hauteur);                                    //chargement de l'image

    if (image == NULL)
    {//le pointeur d'image ne pointe pas correctement sur le fichier
        allegro_message("Erreur de creation bitmap : %s", filename);                        //message d'erreur
        allegro_exit();                                                     //fermeture allegro
        exit(EXIT_FAILURE);
    }

    return image;
}
/*********************************************************************************************************/



/**< CHARGER UN FICHIER >*********************************************************************************/
FILE * chargerFichier (const char * filename, const char * typeOuverture)
{
    FILE * fichier;

    fichier = fopen(filename, typeOuverture);

    if (fichier == NULL)
    {//le pointeur sur fichier ne pointe pas correctement sur le fichier
        allegro_message("Erreur d'ouverture du fichier : %s", filename);                         //message d'erreur
        allegro_exit();                                                                         //fermeture allegro
        exit(EXIT_FAILURE);
    }

    return fichier;
}
/*********************************************************************************************************/

/**< CHARGER UNE POLICE >*********************************************************************************/
FONT * chargerPolice (const char * filename)
{
    FONT * maPolice;

    maPolice = load_font(filename, NULL, NULL);

    if(maPolice == NULL)
    {
        allegro_message("Erreur de chargement de la police : %s", filename);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    return maPolice;
}
/*********************************************************************************************************/


/**< SAUVER UNE BITMAP >**********************************************************************************/
void saveBitmap(BITMAP * bitmapASauver, const char * filename)
{
    //Déclarations
    int verifSave;

    verifSave = save_bmp(filename, bitmapASauver, NULL);                         //sauvegarde du bitmap
    //la fct save_bitmap rend un entier différent de 0 si une erreur s'est produite

    if(verifSave != 0)
    {//en cas d'erreur dans la sauvegarde
        allegro_message("Erreur dans la sauvegarde de la bitmap : %s", filename);   //message d'erreur
        allegro_exit();                                                             //fermeture allegro
        exit(EXIT_FAILURE);                                                         //sortie forcée du programme
    }
}
/*********************************************************************************************************/


/**< PROCEDURE DE SORTIE EN CAS D'ERREUR>*****************************************************************/
void sortieErreur (const char * phrase)
{
    allegro_exit();
    allegro_message(phrase);
    exit(EXIT_FAILURE);
}
/*********************************************************************************************************/

void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


void clear_prompt(int x, int y)
{
    Color(0, 0);
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    Color(7, 0);
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

/*********************************************************************************************************/
//Affichage des coordonées du curseur sur l'écran (uniquement utile pour le dev)
void afficherCoord ()
{
        textprintf_ex(screen, font, 400, 30, makecol(255, 255, 255), makecol(0,0,0), "Position souris X : %d ", mouse_x);    //affichage pos X souris
        textprintf_ex(screen, font, 400, 50, makecol(255, 255, 255), makecol(0,0,0), "Position souris Y : %d ", mouse_y);    //affichage pos Y souris
}
/*********************************************************************************************************/
