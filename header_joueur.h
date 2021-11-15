/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_JOUEUR_H_INCLUDED
#define HEADER_JOUEUR_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_carte.h"
#include "header_meurtrier.h"
/*********************************************************************************************************/



/*********************************************************************************************************/
/**< PARSONNAGES ET HERITAGE >****************************************************************************/
/*********************************************************************************************************/

/**<PARTICIPANT>******************************************************************************************/
class Participant
{
    protected :

        std::string m_pseudo;
        std::vector <Carte_alibi> m_main;

        bool m_IA;



        ///fonctions privées, seulement utile au sein de la classe
        bool verification_hypothese_arme(std::string chaine);
        bool verification_hypothese_lieu(std::string chaine);
        bool verification_hypothese_perso(std::string chaine);

    public :

        Participant();
        Participant(std::string _pseudo, std::vector <Carte_alibi> _main, bool _IA);

        ~Participant();

        //getters
        bool get_IA() const;

        std::string getPseudo() const;

        //setters
        void setPseudo(std::string pseudo);

        std::vector <Carte_alibi> get_main() const;

        //tour du joueur
        Meurtrier formuler_hypothese(std::string nom_station); //formuler une nouvelle hypothèse/accusation
        //validation des hypothèses
        void validation_hypothese_joueur(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese); //verification si le joueur suivant est un joueur
        void verification_hypothese_IA(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese); //verification si le joueur suivant est une IA

        //initialisation
        void recevoir_carte(Carte_alibi nouvelle_carte); //permet de recevoir dans la main du joueur un carte alibi
};
/*********************************************************************************************************/


/**< JOUEUR >*********************************************************************************************/
class Joueur : public Participant
{
    private:

        ///variables privées
        int m_nb_partie;
        int m_nb_victoire;

        std::string m_grade;

        bool m_dans_une_piece;
        bool m_autorisation_jeu;

        int m_pos_x;
        int m_pos_y;



    public:

        ///constructeurs
        Joueur(); //defaut
        Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade, std::vector <Carte_alibi> _main, bool _IA, bool _piece, bool _autorisation_jeu, int _x, int _y);//surchagé

        ///destructeur
        ~Joueur();

        ///methodes
        //sauvegarde
        void sauvegarde();
        void lecture_sauvegarde();

        //getters
        bool get_autorisation() const;

        int getNbPartie() const;
        int getNbVictoire() const;

        std::string getGrade() const;

        //setters
        void setNbPartie(int nbPartie);
        void setNbVictoire(int nbVictoire);

        void setGrade(std::string grade);
        void set_autorisation_jeu(bool valeur);

        int get_pos_x() const;
        int get_pos_y() const;

        void set_pos_x(int x);
        void set_pos_y(int y);

        Meurtrier formuler_accusation();

        int jouer_tour(int& deplacement, bool joueur_en_station, std::string nom_station);

        //affichage
        void afficher_tour() const; //affichage spécifique pour le tour du joueur
        void afficher_le_joueur(); //affichage des données du joueur

        //pointeur
        Joueur * get_pointer(); //rend un pointeur sur le joueur
};
/*********************************************************************************************************/


/**< IA >*************************************************************************************************/
class IA : public Participant
{
    private :

    public :
        IA();
        IA(std::string _pseudo, std::vector <Carte_alibi> _main, bool _IA);

        ~IA();
};
/*********************************************************************************************************/


/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/

#endif // HEADER_JOUEUR_H_INCLUDED
