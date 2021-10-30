/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_CARTE_H_INCLUDED
#define HEADER_CARTE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
///LIBRAIRIES TO INCLUDE HERE
#include <stack>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <time.h>
#include <allegro.h>
#include <unistd.h>
/*********************************************************************************************************/


/**< CLASSES >********************************************************************************************/
class Carte_alibi
{
    private :
        bool m_personnage = false;
        bool m_lieu = false;
        bool m_arme = false;

        std::string m_caracteristique;

    public :
        Carte_alibi();
        Carte_alibi(bool _personnage, bool _lieu, bool _arme, std::string _spec);
        ~Carte_alibi();

        bool get_personnage() const;
        bool get_lieu() const;
        bool get_arme() const;
        std::string get_caracteristique() const;

        void afficher_carac() const;
};
/*********************************************************************************************************/


#endif // HEADER_CARTE_H_INCLUDED
