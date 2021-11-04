/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_CLUEDO_H_INCLUDED
#define HEADER_CLUEDO_H_INCLUDED
/*********************************************************************************************************/

/**< LIBRAIRIES >*****************************************************************************************/
#include "header_partie.h"
/*********************************************************************************************************/



/**< CLASSES >********************************************************************************************/
class Cluedo
{
    private :

        ///variables privées
        Partie m_partie;

        int menu_principal();

    public :

        ///constructeurs
        Cluedo(); //defaut
        Cluedo(Partie _partie); //surchargé

        ///destructeur
        ~Cluedo();

        ///methods
        //getters
        Partie get_partie () const;

        Cluedo * get_pointeur();

        //setters
        void set_partie(Partie valeur);

        void lancer_jeu();
};
/*********************************************************************************************************/


#endif // HEADER_CLUEDO_H_INCLUDED
