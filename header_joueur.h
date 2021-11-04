/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_JOUEUR_H_INCLUDED
#define HEADER_JOUEUR_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_carte.h"
#include "header_meurtrier.h"
/*********************************************************************************************************/


/**< CLASSE >*********************************************************************************************/
class Joueur
{
    private:

        ///variables privées
        int m_nb_partie;
        int m_nb_victoire;

        std::string m_grade;
        std::string m_pseudo;

        std::vector <Carte_alibi> m_main;

        bool m_IA;
        bool m_dans_une_piece;
        bool m_autorisation_jeu;


        ///fonctions privées, seulement utile au sein de la classe
        bool verification_hypothese_arme(std::string chaine);
        bool verification_hypothese_lieu(std::string chaine);
        bool verification_hypothese_perso(std::string chaine);

    public:

        ///constructeurs
        Joueur(); //defaut
        Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade, std::vector <Carte_alibi> _main, bool _IA, bool _piece, bool _autorisation_jeu); //surchagé

        ///destructeur
        ~Joueur();

        ///methodes
        //sauvegarde
        void sauvegarde();
        void lecture_sauvegarde();

        //getters
        bool get_IA() const;
        bool get_autorisation() const;


        int getNbPartie() const;
        int getNbVictoire() const;

        std::string getGrade() const;
        std::string getPseudo() const;

        //setters
        void setNbPartie(int nbPartie);
        void setNbVictoire(int nbVictoire);

        void setGrade(std::string grade);
        void setPseudo(std::string pseudo);
        void set_autorisation_jeu(bool valeur);

        std::vector <Carte_alibi> get_main() const;

        //tour du joueur
        Meurtrier formuler_hypothese(); //formuler une nouvelle hypothèse/accusation
        int jouer_tour(int * deplacement); //tour du joueur, affichage, recuperation du déplacement et recuperation du choix d'action

        //validation des hypothèses
        void validation_hypothese_joueur(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese); //verification si le joueur suivant est un joueur
        void verification_hypothese_IA(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese); //verification si le joueur suivant est une IA

        //affichage
        void afficher_tour() const; //affichage spécifique pour le tour du joueur
        void afficher_le_joueur(); //affichage des données du joueur

        //pointeur
        Joueur * get_pointer(); //rend un pointeur sur le joueur

        //initialisation
        void recevoir_carte(Carte_alibi nouvelle_carte); //permet de recevoir dans la main du joueur un carte alibi
};
/*********************************************************************************************************/


#endif // HEADER_JOUEUR_H_INCLUDED
