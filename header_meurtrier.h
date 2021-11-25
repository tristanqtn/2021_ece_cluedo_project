/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_MEURTRIER_H_INCLUDED
#define HEADER_MEURTRIER_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_carte.h"
/*********************************************************************************************************/


/**< CLASSE >*********************************************************************************************/
class Meurtrier
{
    private :

        ///variables privées
        Carte_alibi m_carte_personnage;
        Carte_alibi m_carte_arme;
        Carte_alibi m_carte_lieu;


    public :

        ///constructeur
        Meurtrier(); //défaut
        Meurtrier(Carte_alibi _carte_personnage,Carte_alibi  _carte_arme,Carte_alibi  _carte_lieu); //surchargé

        ///destructeur
        ~Meurtrier();

        ///methodes
        void afficher_meurtrier() const; //affichage des données du crime

        void sauvegarde();

        bool verification_victoire(Meurtrier hypothese); //comparaison d'une hypthèse avec le crime
        bool verification_carte(Carte_alibi test); //verification egalite entre deux cartes

};
/*********************************************************************************************************/


#endif // HEADER_MEURTRIER_H_INCLUDED
