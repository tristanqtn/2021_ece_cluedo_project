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
        void deplacement_elementaire(Case_plateau case_initial, Case_plateau case_d_arrivee, Joueur * joueur, bool& is_station, bool& autor, std::vector<Joueur>vecteur_joueur, int dx, int dy, int p);
        void deplacement(int x, int y, int de, int & rendu_x, int & rendu_y, std::vector<Joueur>vecteur_joueur, int p);
        //void ajouter_joueur(Case_plateau case_plateau, Joueur * joueur); //ajouter le joueur dans la case
        //void supprimer_joueur(Case_plateau case_plateau); //supprimer le joueur d'une case
        void affichage_plateau(std::vector<Joueur>vecteur_joueur, int x, int y);

        //getter et setter
        Case_plateau get_case_plateau(int i, int j) const;     //getter d'une case
        //void set_plateau(Case_plateau _plateau[15][15]);
        bool verif_presence_joueur(int i, int j, std::vector < Joueur> vecteur_joueurs);
        void affichage_joueur_allegro(std::vector<Joueur>vecteur_joueur, BITMAP*& buffer);
        void conversion_coord(int x_console, int y_console, int& x_allegro, int& y_allegro);
};
/************************************************************************/


#endif // HEADER_PLATEAU_H_INCLUDED
