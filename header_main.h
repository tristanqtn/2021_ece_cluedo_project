/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_MAIN_H_INCLUDED
#define HEADER_MAIN_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"
/*********************************************************************************************************/


/**< PROTOTYPES>******************************************************************************************/

///INITIALISATION
void setupAllegro ();
///


///CREATION DE LA PARTIE

///


///MENU
int menu_principal();
///


///MES FONCTIONS
FONT * chargerPolice(const char * filename);

SAMPLE * chargerMusique(const char * filename);

BITMAP * chargerImage(const char * filename);
BITMAP * creerBuffer(int largeur, int hauteur, const char * filename);

FILE * chargerFichier(const char * filename, const char * typeOuverture);

void afficherCoord();
void sortieErreur(const char * phrase);
void saveBitmap(BITMAP * bitmapASauver, const char * filename);
///

/*********************************************************************************************************/





#endif // HEADER_MAIN_H_INCLUDED
