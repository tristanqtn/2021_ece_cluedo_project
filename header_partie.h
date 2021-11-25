/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PARTIE_H_INCLUDED
#define HEADER_PARTIE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_plateau.h"
#include "header_meurtrier.h"
/*********************************************************************************************************/


/**< CLASSE >*********************************************************************************************/
class Partie
{
    private :

        ///varialbles privées
        int m_nb_IA;
        int m_nb_joueur;

        Meurtrier m_meurtrier;

        std::vector <Joueur> m_joueurs;
        std::vector <IA> m_IA;
        std::vector <Carte_alibi> m_deck_cartes;

        Plateau m_board;

        ///fonctions privées, seulement utile au sein de la classe
        std::vector <Carte_alibi> creer_deck_lieux();
        std::vector <Carte_alibi> creer_deck_armes();
        std::vector <Carte_alibi> creer_deck_personnage();

        bool doublon_pseudo(std::string chaine); //verification de la presence de doublons de pseudo

        Meurtrier creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes); //lfonction de création d'un meurtrier

        //tour d'une IA
        void tour_IA(int i);

        //tour d'un joueur
        bool tour_joueur(int i);

        //méthodes d'accusation ou d'hypothèses
        void hypothese_finale(int i, std::string nom_station);
        bool accusation_finale(int i);

         void sauvegarder_joueurs();
        void recuperation_joueur();
        void sauvegarde_meurtrier();

        void sauvegarde_config();
        void recup_config();
        void recuperation_joueurs();
        void recuperation_meurtrier();
        Joueur recuperation();


    public :

        ///constructeurs
        Partie(); //defaut
        Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs, std::vector <IA> _IA, Plateau _board); //surchargé

        ///destructeur
        ~Partie();

        ///methodes
        //getters
        int get_nb_IA() const;
        int get_nb_joueurs() const;
        int get_nb_tot_joueur() const;

        std::vector <IA> get_IA() const;
        std::vector <Joueur> get_joueurs() const;

        std::vector <Carte_alibi> get_pioche() const;

        Meurtrier get_meurtrier() const;
        Carte_alibi get_carte(int valeur) const;

        Partie * get_pointeur();

        //setters
        void set_nb_IA(int valeur);
        void set_nb_joueur (int valeur);
        void set_meurtrier (Meurtrier tueur);
        void set_deck (std::vector <Carte_alibi> deck);

        //affichage
        void afficher_deck() const; //seulement utile pour verification de la bonne création des cartes, ne pas utiliser dans le jeu
        void afficher_meurtrier() const; //affichage des cartes alibis composants le meurtre

        //fonctionnement de la partie
        void creer_partie(); //création de la pioche + plateau
        void parametrer(); //recuperation des parametres (nb joueurs, nb IA, ...)
        void creer_joueurs(); //création des objets joueurs
        void creer_IA(); //création des objets IA
        void distribuer(); //distribution des cartes
        void lancer_partie (); //boucle de jeu

        void sauvegarde_partie();
        void initialisation();
        void recuperation_tot_partie();
        void historique_victoire(int nb_sauv);
        void sauvegarde_victoire(std::string pseudo, std::string personnage, std::string lieu, std::string arme, int tour);
        int nombre_victoire();

};
/*********************************************************************************************************/


#endif // HEADER_PARTIE_H_INCLUDED
