/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_CASE_H_INCLUDED
#define HEADER_CASE_H_INCLUDED
/*********************************************************************************************************/

/**< LIBRAIRIES >*****************************************************************************************/
#include "header_joueur.h"
#include "header_chance.h"
/*********************************************************************************************************/

/**< CLASSES >********************************************************************************************/
class Case_plateau
{

    private :

        ///variables privées
        bool m_vide;

        bool m_occupee;
        bool m_chance;
        bool m_station;

        bool m_sortie_haut;
        bool m_sortie_bas;
        bool m_sortie_gauche;
        bool m_sortie_droite;

        std::string m_nom_station;
        std::vector <Carte_chance> m_deck_chance;

        Joueur * m_occupant;

    public :

        ///constructeur
        Case_plateau(); //defaut
        Case_plateau(bool _occupee, bool _chance, bool _sortie_haut, bool _sortie_bas, bool _sortie_gauche, bool _sortie_droite, std::string _nom_station, std::vector <Carte_chance> _deck_chance, Joueur * _occupant); //surchargé

        ///destructeur
        ~Case_plateau();

        ///methodes
        //getters
        bool get_vide() const;
        bool get_occupee() const;
        bool get_chance() const;
        bool get_station() const;
        bool get_sortie_haut() const;
        bool get_sortie_bas() const;
        bool get_sortie_gauche() const;
        bool get_sortie_droite() const;

        std::vector <Carte_chance> get_deck_chance() const;

        Joueur * get_occupant() const;
};
/*********************************************************************************************************/


#endif // HEADER_CASE_H_INCLUDED
