/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_CARTE_H_INCLUDED
#define HEADER_CARTE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
///LIBRAIRIES TO INCLUDE HERE
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

        ///variables privées
        bool m_personnage = false;
        bool m_lieu = false;
        bool m_arme = false;

        std::string m_caracteristique;

    public :

        ///constructeurs
        Carte_alibi(); //défaut
        Carte_alibi(bool _personnage, bool _lieu, bool _arme, std::string _spec); //surchargé

        ///destructeur
        ~Carte_alibi();

        ///methodes
        //getters
        bool get_lieu() const;
        bool get_arme() const;
        bool get_personnage() const;

        std::string get_caracteristique() const;

        //autre
        void afficher_carac() const; //affichage des caractéristique d'une carte
        bool verification_egalite(Carte_alibi hypothese); //verification égalité de 2 cartes
};
/*********************************************************************************************************/


#endif // HEADER_CARTE_H_INCLUDED
