/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_JOUEUR_H_INCLUDED
#define HEADER_JOUEUR_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_personnage.h"
/*********************************************************************************************************/


/**< CLASSES >********************************************************************************************/
///JOUEUR
class Joueur
{
    private:
        int m_nb_partie;
        int m_nb_victoire;

        std::string m_grade;
        std::string m_pseudo;

        Enqueteur m_pt_enqueteur;

    public:
        //constructeurs and destructeur
        Joueur();
        Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade);
        ~Joueur();

        //methodes
        void sauvegarde();
        void lecture_sauvegarde();
        void afficher_le_joueur();

        //getters and setters
        std::string getPseudo() const;
        int getNbPartie() const;
        int getNbVictoire() const;
        std::string getGrade() const;

        void setPseudo(std::string pseudo);
        void setNbPartie(int nbPartie);
        void setNbVictoire(int nbVictoire);
        void setGrade(std::string grade);

        void add_card(Carte_alibi carte_ajouter);
        void jouer_tour();
};
///
/*********************************************************************************************************/

#endif // HEADER_JOUEUR_H_INCLUDED
