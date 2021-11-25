/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PRINCIPAL_H_INCLUDED
#define HEADER_PRINCIPAL_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_case.h"
#include "header_carte.h"
#include "header_chance.h"
#include "header_cluedo.h"
#include "header_plateau.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
/*********************************************************************************************************/


/**< PROTOTYPES>******************************************************************************************/

///INITIALISATION
void setupAllegro ();
///


///CREATION DE LA PARTIE
void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void clear_prompt(int x, int y);
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





#endif // HEADER_PRINCIPAL_H_INCLUDED
