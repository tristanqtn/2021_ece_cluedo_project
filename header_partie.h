/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PARTIE_H_INCLUDED
#define HEADER_PARTIE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_carte.h"
#include "header_joueur.h"
#include "header_personnage.h"
/*********************************************************************************************************/


/**< CLASSES >********************************************************************************************/
class Partie
{
    private :
        Meurtrier m_meurtrier;

        std::vector <Carte_alibi> m_deck_cartes;
        std::vector <Joueur> m_joueurs;

    public :

        Partie();
        Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs);
        ~Partie();

        Carte_alibi get_carte(int valeur) const;
        std::vector <Carte_alibi> get_pioche() const;

        void set_deck (std::vector <Carte_alibi> deck);
        void set_meurtrier (Meurtrier tueur);

        void afficher_deck() const;
        void afficher_meurtrier() const;

        void creer_partie();
};
/*********************************************************************************************************/


#endif // HEADER_PARTIE_H_INCLUDED
