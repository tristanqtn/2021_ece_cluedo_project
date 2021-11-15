/**< PREPROCESSOR >******************************************************/
#ifndef HEADER_PLATEAU_H_INCLUDED
#define HEADER_PLATEAU_H_INCLUDED
/************************************************************************/


/**< LIBRARIES >*********************************************************/
#include "header_case.h"
#include "header_chance.h"
/************************************************************************/


/**< CLASSES >***********************************************************/
class Plateau
{
    private:

        Case_plateau m_plateau[15][15];

    public:

        //constructeurs et destructeur
        Plateau();
        Plateau(Case_plateau _plateau[15][15]);
        ~Plateau();

        //methode
        void deplacement_elementaire(Case_plateau case_initial, Case_plateau case_d_arrivee, Joueur * joueur);
        void deplacement(int x, int y, int de, int & rendu_x, int & rendu_y);
        //void ajouter_joueur(Case_plateau case_plateau, Joueur * joueur); //ajouter le joueur dans la case
        //void supprimer_joueur(Case_plateau case_plateau); //supprimer le joueur d'une case

        //getter et setter
        Case_plateau get_case_plateau(int i, int j) const;     //getter d'une case
        void set_plateau(Case_plateau _plateau[15][15]);
};
/************************************************************************/


/**< PROTOTYPES>*********************************************************/
/************************************************************************/




#endif // HEADER_PLATEAU_H_INCLUDED
