#include "header_plateau.h"
#include "header_joueur.h"
#include "header_carte.h"
#include "header_chance.h"
#include "header_principal.h"

/**< CONSTRUCTEURS >**************************************************************************************/
//constructeur par default
Plateau::Plateau()
{
    ///NUMEROTATION PLATEAU[COLONNE][LIGNE]

    //case vide
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            m_plateau[i][j].set_nom_station("trajet");
            m_plateau[i][j].set_chance(false);
            m_plateau[i][j].set_occupee(false);
            m_plateau[i][j].set_station(false);
            m_plateau[i][j].set_sortie_haut(false);
            m_plateau[i][j].set_sortie_bas(false);
            m_plateau[i][j].set_sortie_droite(false);
            m_plateau[i][j].set_sortie_gauche(false);
            m_plateau[i][j].set_occupant(NULL);
        }
    }
    //colonne 1
    for(int i=1; i<14; i++)
    {
        m_plateau[0][i].set_sortie_haut(true);
        m_plateau[0][i].set_sortie_bas(true);
    }
    m_plateau[0][0].set_sortie_droite(true);
    m_plateau[0][14].set_sortie_droite(true);
    m_plateau[0][0].set_sortie_bas(true);
    m_plateau[0][14].set_sortie_haut(true);

    m_plateau[0][0].set_nom_station("Etoile");
    m_plateau[0][0].set_station(true);

    m_plateau[0][7].set_nom_station("Trocadero");
    m_plateau[0][7].set_station(true);

    m_plateau[0][14].set_nom_station("Bir Hakeim");
    m_plateau[0][14].set_station(true);

    //colonne 2
    m_plateau[1][0].set_sortie_gauche(true);
    m_plateau[1][0].set_sortie_droite(true);
    m_plateau[1][14].set_sortie_gauche(true);
    m_plateau[1][14].set_sortie_droite(true);

    //colonne 3
    for(int i=1; i<14; i++)
    {
        if(i==2)
        {
            i=11;
        }
        m_plateau[2][i].set_sortie_bas(true);
        m_plateau[2][i].set_sortie_haut(true);
    }
    m_plateau[2][0].set_sortie_bas(true);
    m_plateau[2][0].set_sortie_droite(true);
    m_plateau[2][0].set_sortie_gauche(true);

    m_plateau[2][2].set_sortie_haut(true);
    m_plateau[2][2].set_sortie_droite(true);

    m_plateau[2][10].set_sortie_droite(true);
    m_plateau[2][10].set_sortie_bas(true);

    m_plateau[2][14].set_sortie_haut(true);
    m_plateau[2][14].set_sortie_droite(true);
    m_plateau[2][14].set_sortie_gauche(true);

    //colonne 4
    for(int i=0; i<15; i++)
    {
        if(i==1)
        {
            i=2;
        }
        else if(i==3)
        {
            i=10;
        }
        else if(i==11)
        {
            i=14;
        }
        m_plateau[3][i].set_sortie_droite(true);
        m_plateau[3][i].set_sortie_gauche(true);
    }

    //colonne 5
    for(int i=0; i<15; i++)
    {
        if(i==1)
        {
            i=2;
        }
        else if(i==3)
        {
            i=10;
        }
        else if(i==11)
        {
            i=14;
        }
        m_plateau[4][i].set_sortie_droite(true);
        m_plateau[4][i].set_sortie_gauche(true);
    }

    //colonne 6
    m_plateau[5][0].set_sortie_gauche(true);
    m_plateau[5][0].set_sortie_droite(true);

    m_plateau[5][2].set_sortie_gauche(true);
    m_plateau[5][2].set_sortie_bas(true);

    m_plateau[5][3].set_sortie_haut(true);
    m_plateau[5][3].set_sortie_bas(true);

    m_plateau[5][4].set_sortie_haut(true);
    m_plateau[5][4].set_sortie_droite(true);

    m_plateau[5][10].set_sortie_droite(true);
    m_plateau[5][10].set_sortie_gauche(true);

    m_plateau[5][14].set_sortie_droite(true);
    m_plateau[5][14].set_sortie_gauche(true);

    //colonne 7
    m_plateau[6][0].set_sortie_gauche(true);
    m_plateau[6][0].set_sortie_droite(true);

    m_plateau[6][4].set_sortie_gauche(true);
    m_plateau[6][4].set_sortie_droite(true);

    m_plateau[6][7].set_sortie_droite(true);
    m_plateau[6][7].set_sortie_bas(true);

    m_plateau[6][8].set_sortie_haut(true);
    m_plateau[6][8].set_sortie_bas(true);

    m_plateau[6][9].set_sortie_haut(true);
    m_plateau[6][9].set_sortie_bas(true);

    m_plateau[6][10].set_sortie_haut(true);
    m_plateau[6][10].set_sortie_gauche(true);

    m_plateau[6][14].set_sortie_droite(true);
    m_plateau[6][14].set_sortie_gauche(true);

    //colonne 8
    for(int i=1; i<7; i++)
    {
        m_plateau[7][i].set_sortie_bas(true);
        m_plateau[7][i].set_sortie_haut(true);
    }

    m_plateau[7][0].set_sortie_bas(true);
    m_plateau[7][0].set_sortie_droite(true);
    m_plateau[7][0].set_sortie_gauche(true);

    m_plateau[7][7].set_sortie_haut(true);
    m_plateau[7][7].set_sortie_droite(true);
    m_plateau[7][7].set_sortie_gauche(true);

    m_plateau[7][14].set_sortie_gauche(true);
    m_plateau[7][14].set_sortie_droite(true);

    m_plateau[7][4].set_sortie_gauche(true);

    m_plateau[7][0].set_nom_station("Barbes");
    m_plateau[7][0].set_station(true);

    m_plateau[7][7].set_nom_station("Concorde");
    m_plateau[7][7].set_station(true);

    m_plateau[7][14].set_nom_station("Vaugirard");
    m_plateau[7][14].set_station(true);

    //colonne 9
    m_plateau[8][0].set_sortie_droite(true);
    m_plateau[8][0].set_sortie_gauche(true);

    m_plateau[8][7].set_sortie_droite(true);
    m_plateau[8][7].set_sortie_gauche(true);

    m_plateau[8][14].set_sortie_droite(true);
    m_plateau[8][14].set_sortie_gauche(true);

    //colonne 10
    m_plateau[9][0].set_sortie_droite(true);
    m_plateau[9][0].set_sortie_gauche(true);

    m_plateau[9][7].set_sortie_droite(true);
    m_plateau[9][7].set_sortie_gauche(true);

    m_plateau[9][14].set_sortie_droite(true);
    m_plateau[9][14].set_sortie_gauche(true);

    //colonne 11
    m_plateau[10][0].set_sortie_droite(true);
    m_plateau[10][0].set_sortie_gauche(true);

    m_plateau[10][7].set_sortie_droite(true);
    m_plateau[10][7].set_sortie_gauche(true);

    m_plateau[10][10].set_sortie_bas(true);
    m_plateau[10][10].set_sortie_droite(true);

    m_plateau[10][11].set_sortie_bas(true);
    m_plateau[10][11].set_sortie_haut(true);

    m_plateau[10][12].set_sortie_bas(true);
    m_plateau[10][12].set_sortie_haut(true);

    m_plateau[10][13].set_sortie_bas(true);
    m_plateau[10][13].set_sortie_haut(true);

    m_plateau[10][14].set_sortie_gauche(true);
    m_plateau[10][14].set_sortie_haut(true);
    m_plateau[10][14].set_sortie_droite(true);

    //colonne 12
    m_plateau[11][0].set_sortie_droite(true);
    m_plateau[11][0].set_sortie_gauche(true);

    m_plateau[11][7].set_sortie_droite(true);
    m_plateau[11][7].set_sortie_gauche(true);

    m_plateau[11][10].set_sortie_droite(true);
    m_plateau[11][10].set_sortie_gauche(true);

    m_plateau[11][14].set_sortie_droite(true);
    m_plateau[11][14].set_sortie_gauche(true);

    //colonne 13
    m_plateau[12][0].set_sortie_droite(true);
    m_plateau[12][0].set_sortie_haut(true);

    m_plateau[12][7].set_sortie_bas(true);
    m_plateau[12][7].set_sortie_droite(true);
    m_plateau[12][7].set_sortie_gauche(true);

    m_plateau[12][8].set_sortie_bas(true);
    m_plateau[12][8].set_sortie_haut(true);

    m_plateau[12][9].set_sortie_bas(true);
    m_plateau[12][9].set_sortie_haut(true);

    m_plateau[12][10].set_sortie_gauche(true);
    m_plateau[12][10].set_sortie_haut(true);

    m_plateau[12][14].set_sortie_gauche(true);
    m_plateau[12][14].set_sortie_droite(true);

    //colonne 14
    m_plateau[13][0].set_sortie_droite(true);
    m_plateau[13][0].set_sortie_gauche(true);

    m_plateau[13][7].set_sortie_droite(true);
    m_plateau[13][7].set_sortie_gauche(true);

    m_plateau[13][14].set_sortie_droite(true);
    m_plateau[13][14].set_sortie_gauche(true);

    //colonne 15
    for(int i=1; i<14; i++)
    {
        m_plateau[14][i].set_sortie_bas(true);
        m_plateau[14][i].set_sortie_haut(true);
    }

    m_plateau[14][0].set_sortie_bas(true);
    m_plateau[14][0].set_sortie_gauche(true);

    m_plateau[14][7].set_sortie_gauche(true);

    m_plateau[14][14].set_sortie_gauche(true);
    m_plateau[14][14].set_sortie_haut(true);

    m_plateau[14][0].set_station(true);
    m_plateau[14][0].set_nom_station("Stalingrad");

    m_plateau[14][7].set_station(true);
    m_plateau[14][7].set_nom_station("Chatelet");

    m_plateau[14][14].set_station(true);
    m_plateau[14][14].set_nom_station("Nation");

}
/*********************************************************************************************************/



/**< CONSTRUCTEUR SURCHARGE >*****************************************************************************/
Plateau::Plateau(Case_plateau _plateau[15][15])
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            m_plateau[i][j] = _plateau[i][j];
        }
    }
}
/*********************************************************************************************************/



/**< DESTRUCTEUR >****************************************************************************************/
Plateau::~Plateau()
{}
/*********************************************************************************************************/



/**< GETTER DE CASE >*************************************************************************************/
Case_plateau Plateau::get_case_plateau(int i, int j) const
{
    return m_plateau[i][j];
}
/*********************************************************************************************************/


/**< AFFICHAGE DU PETIT PLATEAU POUR LA CONSOLE >*********************************************************/
void Plateau::affichage_plateau(std::vector<Joueur>vecteur_joueur, int x, int y)
{
    int i, j;

    for(j=0; j<15; j++)
    {
        for(i=0; i<15; i++)
        {
            for(size_t k=0; k<vecteur_joueur.size(); k++)
            {

                if(vecteur_joueur[k].get_pos_x() == i && vecteur_joueur[k].get_pos_y() == j)
                {
                    std::string nom = vecteur_joueur[k].getPseudo();

                    if(vecteur_joueur[k].get_pion() == "rouge")
                    {
                        Color(12, 0);
                    }
                    else if(vecteur_joueur[k].get_pion() == "orange")
                    {
                        Color(4, 0);
                    }
                    else if(vecteur_joueur[k].get_pion() == "jaune")
                    {
                        Color(14, 0);
                    }
                    else if(vecteur_joueur[k].get_pion() == "vert")
                    {
                        Color(10, 0);
                    }
                    else if(vecteur_joueur[k].get_pion() == "bleu")
                    {
                        Color(9, 0);
                    }
                    else if(vecteur_joueur[k].get_pion() == "violet")
                    {
                        Color(13, 0);
                    }
                    std::cout << nom[0] << " ";
                    Color(7, 0);
                }
            }
            if(m_plateau[i][j].get_station() == true)
            {
                Color(15, 0);
                if(m_plateau[i][j].get_nom_station() == "Etoile")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "E ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Trocadero")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "T ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Bir Hakeim")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "B ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Barbes")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "B ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Concorde")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "C ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Vaugirard")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "V ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Stalingrad")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "S ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Chatelet")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "C ";
                }
                else if(m_plateau[i][j].get_nom_station() == "Nation")
                {
                    if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                        std::cout << "N ";
                }
                Color(7, 0);
            }
            else if(m_plateau[i][j].get_sortie_bas() == true || m_plateau[i][j].get_sortie_haut() == true || m_plateau[i][j].get_sortie_droite() == true || m_plateau[i][j].get_sortie_gauche() == true)
            {
                if(verif_presence_joueur(i, j, vecteur_joueur) == false)
                    std::cout << "+ ";
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
/*********************************************************************************************************/



/**< VERIFICATION DE LA PRESENCE D'UN JOUEUR DANS UNE CASE >**********************************************/
bool Plateau::verif_presence_joueur(int i, int j, std::vector < Joueur> vecteur_joueurs)
{

    bool joueur_en_station = false;
    for(size_t k=0; k<vecteur_joueurs.size(); k++)
    {
        if(vecteur_joueurs[k].get_pos_x() == i && vecteur_joueurs[k].get_pos_y() == j)
        {
            joueur_en_station = true;
        }
    }

    return joueur_en_station;
}
/*********************************************************************************************************/




/**< GESTION DU DEPLACEMENT DU JOUEUR DE 1 SEULE CASE >***************************************************/
void Plateau::deplacement_elementaire(Case_plateau case_initial, Case_plateau case_d_arrivee, Joueur * joueur, bool& is_station, bool& autor, std::vector<Joueur>vecteur_joueur, int dx, int dy, int p)
{
    int autor_local = 0;
    size_t taille = vecteur_joueur.size();
    std::cout << std::endl;

    for(size_t k=0; k<taille; k++)
    {
        if(vecteur_joueur[k].getPseudo() != vecteur_joueur[p].getPseudo())
        {
            if(vecteur_joueur[p].get_pos_x() + dx == vecteur_joueur[k].get_pos_x())
            {
                if(vecteur_joueur[p].get_pos_y() + dy == vecteur_joueur[k].get_pos_y())
                {
                    autor_local = 0;

                    k = taille;
                }
                else
                {
                    autor_local++;

                }
            }
            else
            {
                autor_local++;

            }
        }
        else
        {
            autor_local++;

        }
    }

    //std::cout << "autor : " << autor_local << " , size : " << taille << std::endl;

    if(autor_local == int (taille))
    {
        case_d_arrivee.set_occupant(joueur);
        case_initial.set_occupant(NULL);
        is_station = case_d_arrivee.get_station();
        autor = true;
    }
    else
    {
        autor = false;
    }
}
/*********************************************************************************************************/


/**< DEPLACEMENT TOTAL DU JOUEUR >************************************************************************/
void Plateau::deplacement(int x, int y, int de, int & rendu_x, int & rendu_y, std::vector<Joueur>vecteur_joueur, int p)
{
    int i;
    int somme_x = 0, somme_y = 0;
    bool is_station = false;
    bool autor = true;
    std::string choix;

    //nombre de deplacement donné par le dé
    for(i=0; i<de; i++)
    {
        gotoligcol(20, 0);
        clear_prompt(50, 50);
        gotoligcol(20, 0);
        Plateau::affichage_plateau(vecteur_joueur, somme_x, somme_y);
        //si le passage du haut est ouvert

        //si on est sur une station, les déplacements restants sont rendus à 0
        if(is_station == true)
        {
            i = de;
        }
        else
        {
            if(m_plateau[x][y].get_sortie_haut())
            {
                std::cout << "Vous pouvez aller en haut." << std::endl;
            }
            //si le paasage du bas est ouvert
            if(m_plateau[x][y].get_sortie_bas())
            {
                std::cout << "Vous pouvez aller en bas." << std::endl;
            }
            if(m_plateau[x][y].get_sortie_droite())
            {
                std::cout << "Vous pouvez aller a droite." << std::endl;
            }
            if(m_plateau[x][y].get_sortie_gauche())
            {
                std::cout << "Vous pouvez aller a gauche." << std::endl;
            }
            std::cout << "Ou voulez vous aller ? : " ;
            std::cin >> choix ;

            if((choix == "z" || choix == "Z") && m_plateau[x][y].get_sortie_haut())
            {
                y--;
                somme_y--;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant(), is_station, autor, vecteur_joueur, 0, -1, p);
                if(!autor)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
            }
            else if((choix == "s" || choix == "S") && m_plateau[x][y].get_sortie_bas())
            {
                y++;
                somme_y++;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant(), is_station, autor, vecteur_joueur, 0, 1, p);
                if(!autor)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
            }
            else if((choix == "d" || choix == "D") && m_plateau[x][y].get_sortie_droite())
            {
                x++;
                somme_y++;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant(), is_station, autor, vecteur_joueur, 1, 0, p);
                if(!autor)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
            }
            else if((choix == "q" || choix == "Q") && m_plateau[x][y].get_sortie_gauche())
            {
                x--;
                somme_x--;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant(), is_station, autor, vecteur_joueur, -1, 0, p);
                if(!autor)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
            }

            else
            {
                std::cout << "Deplacement impossible" << std::endl;
                i--;
            }
            vecteur_joueur[p].set_pos_x (x);
            vecteur_joueur[p].set_pos_y (y);

        }
    }

    rendu_x = x;
    rendu_y = y;

}
/*********************************************************************************************************/
