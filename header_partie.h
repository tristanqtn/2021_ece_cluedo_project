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

        int m_nb_joueur;

        Meurtrier m_meurtrier;

        std::vector <Carte_alibi> m_deck_cartes;
        std::vector <Joueur> m_joueurs;

    public :

        Partie();
        Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs);
        ~Partie();

        int get_nb_joueur() const;
        Carte_alibi get_carte(int valeur) const;
        std::vector <Carte_alibi> get_pioche() const;

        void set_deck (std::vector <Carte_alibi> deck);
        void set_meurtrier (Meurtrier tueur);
        void set_nb_joueur (int valeur);

        void afficher_deck() const;
        void afficher_meurtrier() const;

        void creer_partie();
        void parametrer();
        void creer_joueurs();
        void distribuer();
        bool doublon_pseudo(std::string chaine);

        std::vector <Carte_alibi> creer_deck_lieux();
        std::vector <Carte_alibi> creer_deck_armes();
        std::vector <Carte_alibi> creer_deck_personnage();

        void lancer_partie ();

        Meurtrier creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes);
};
/*********************************************************************************************************/


#endif // HEADER_PARTIE_H_INCLUDED
