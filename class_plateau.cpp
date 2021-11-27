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

    if(autor_local == int(taille))
    {
        std::cout << "pas occupe";
        case_d_arrivee.set_occupant(joueur);
        case_initial.set_occupant(NULL);
        is_station = case_d_arrivee.get_station();
        autor = true;
    }
    else
    {
        std::cout << "occupe";
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


                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y-1], m_plateau[x][y-1].get_occupant(), is_station, autor, vecteur_joueur, 0, -1, p);
                if(autor == false)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
                else
                {
                    y--;
                    somme_y--;
                    vecteur_joueur[p].set_pos_x (x);
                    vecteur_joueur[p].set_pos_y (y);
                    rendu_x = x;
                    rendu_y = y;
                }
            }
            else if((choix == "s" || choix == "S") && m_plateau[x][y].get_sortie_bas())
            {


                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y+1], m_plateau[x][y+1].get_occupant(), is_station, autor, vecteur_joueur, 0, 1, p);
                if(autor == false)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
                else
                {
                    y++;
                    somme_y++;
                    vecteur_joueur[p].set_pos_x (x);
                    vecteur_joueur[p].set_pos_y (y);
                    rendu_x = x;
                    rendu_y = y;
                }
            }
            else if((choix == "d" || choix == "D") && m_plateau[x][y].get_sortie_droite())
            {


                deplacement_elementaire(m_plateau[x][y], m_plateau[x+1][y], m_plateau[x+1][y].get_occupant(), is_station, autor, vecteur_joueur, 1, 0, p);
                if(autor == false)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
                else
                {
                    x++;
                    somme_y++;
                    vecteur_joueur[p].set_pos_x (x);
                    vecteur_joueur[p].set_pos_y (y);
                    rendu_x = x;
                    rendu_y = y;
                }
            }
            else if((choix == "q" || choix == "Q") && m_plateau[x][y].get_sortie_gauche())
            {

                deplacement_elementaire(m_plateau[x][y], m_plateau[x-1][y], m_plateau[x-1][y].get_occupant(), is_station, autor, vecteur_joueur, -1, 0, p);
                if(autor == false)
                {
                    std::cout << "Deplacement impossible" << std::endl;
                    i--;
                }
                else
                {
                    x--;
                    somme_x--;
                    vecteur_joueur[p].set_pos_x (x);
                    vecteur_joueur[p].set_pos_y (y);
                    rendu_x = x;
                    rendu_y = y;
                }
            }

            else
            {
                std::cout << "Deplacement impossible" << std::endl;
                i--;
            }


        }
    }



}
/*********************************************************************************************************/


void Plateau::affichage_joueur_allegro(std::vector<Joueur>vecteur_joueur, BITMAP*& buffer)
{
    int x_allegro = 0, y_allegro = 0, x_console = 0, y_console = 0;
    std::string pion;

    for(size_t k=0; k<vecteur_joueur.size(); k++)
    {

        x_console = vecteur_joueur[k].get_pos_x();
        y_console = vecteur_joueur[k].get_pos_y();

        pion = vecteur_joueur[k].get_pion();

        std::string location = "data/bitmap/pion/", extension = ".bmp";

        std::string chemin = location +  pion;
        std::string fin = chemin + extension;
        const char * path = fin.c_str();
        BITMAP * image = chargerImage(path);

        conversion_coord(x_console, y_console, x_allegro, y_allegro);
        stretch_sprite(buffer, image, x_allegro-15, y_allegro-15, 30, 30);
    }
}


//conversion des coordonnÃ©es console pour l'allegro
void Plateau::conversion_coord(int x_console, int y_console, int& x_allegro, int& y_allegro)
{
    //colonne gauche
    if(x_console == 0)
    {
        ///etoile
        if(y_console == 0)
        {
            x_allegro = 320;
            y_allegro = 205;
        }
        else if(y_console == 1)
        {
            x_allegro = 310;
            y_allegro = 215;
        }
        else if(y_console == 2)
        {
            x_allegro = 300;
            y_allegro = 220;
        }
        else if(y_console == 3)
        {
            x_allegro = 293;
            y_allegro = 227;
        }
        else if(y_console == 4)
        {
            x_allegro = 286;
            y_allegro = 235;
        }
        else if(y_console == 5)
        {
            x_allegro = 278;
            y_allegro = 245;
        }
        else if(y_console == 6)
        {
            x_allegro = 278;
            y_allegro = 245;
        }
        ///troca
        else if(y_console == 7)
        {
            x_allegro = 271;
            y_allegro = 254;
        }
        else if(y_console == 8)
        {
            x_allegro = 270;
            y_allegro = 268;
        }
        else if(y_console == 9)
        {
            x_allegro = 270;
            y_allegro = 271;
        }
        else if(y_console == 10)
        {
            x_allegro = 272;
            y_allegro = 271;
        }
        else if(y_console == 11)
        {
            x_allegro = 274;
            y_allegro = 281;
        }
        else if(y_console == 12)
        {
            x_allegro = 275;
            y_allegro = 285;
        }
        else if(y_console == 13)
        {
            x_allegro = 276;
            y_allegro = 290;
        }
        ///bir-hakeim
        else if(y_console == 14)
        {
            x_allegro = 278;
            y_allegro = 296;
        }
    }

    //colonne droite
    if(x_console == 14)
    {
        ///stalingrad
        if(y_console == 0)
        {
            x_allegro = 581;
            y_allegro = 151;
        }
        else if(y_console == 1)
        {
            x_allegro = 567;
            y_allegro = 194;
        }
        else if(y_console == 2)
        {
            x_allegro = 549;
            y_allegro = 194;
        }
        else if(y_console == 3)
        {
            x_allegro = 542;
            y_allegro = 213;
        }
        else if(y_console == 4)
        {
            x_allegro = 528;
            y_allegro = 233;
        }
        else if(y_console == 5)
        {
            x_allegro = 521;
            y_allegro = 245;
        }
        else if(y_console == 6)
        {
            x_allegro = 512;
            y_allegro = 261;
        }
        ///chatelet
        else if(y_console == 7)
        {
            x_allegro = 504;
            y_allegro = 275;
        }
        else if(y_console == 8)
        {
            x_allegro = 518;
            y_allegro = 281;
        }
        else if(y_console == 9)
        {
            x_allegro = 535;
            y_allegro = 286;
        }
        else if(y_console == 10)
        {
            x_allegro = 554;
            y_allegro = 293;
        }
        else if(y_console == 11)
        {
            x_allegro = 579;
            y_allegro = 301;
        }
        else if(y_console == 12)
        {
            x_allegro = 614;
            y_allegro = 313;
        }
        else if(y_console == 13)
        {
            x_allegro = 640;
            y_allegro = 321;
        }
        ///nation
        else if(y_console == 14)
        {
            x_allegro = 660;
            y_allegro = 330;
        }
    }

    //ligne en haut
    else if(y_console == 0)
    {
        ///etoile
        if(x_console == 0)
        {
            x_allegro = 320;
            y_allegro = 205;
        }
        else if(x_console == 1)
        {
            x_allegro = 356;
            y_allegro = 188;
        }
        else if(x_console == 2)
        {
            x_allegro = 356;
            y_allegro = 188;
        }
        else if(x_console == 3)
        {
            x_allegro = 380;
            y_allegro = 177;
        }
        else if(x_console == 4)
        {
            x_allegro = 405;
            y_allegro = 162;
        }
        else if(x_console == 5)
        {
            x_allegro = 431;
            y_allegro = 149;
        }
        else if(x_console == 6)
        {
            x_allegro = 459;
            y_allegro = 138;
        }
        ///barbes
        else if(x_console == 7)
        {
            x_allegro = 500;
            y_allegro = 120;
        }
        else if(x_console == 8)
        {
            x_allegro = 516;
            y_allegro = 118;
        }
        else if(x_console == 9)
        {
            x_allegro = 527;
            y_allegro = 118;
        }
        else if(x_console == 10)
        {
            x_allegro = 542;
            y_allegro = 121;
        }
        else if(x_console == 11)
        {
            x_allegro = 554;
            y_allegro = 127;
        }
        else if(x_console == 12)
        {
            x_allegro = 563;
            y_allegro = 137;
        }
        else if(x_console == 13)
        {
            x_allegro = 571;
            y_allegro = 144;
        }
        ///stalingrad
        else if(x_console == 14)
        {
            x_allegro = 581;
            y_allegro = 151;
        }
    }

    //ligne en bas
    else if(y_console == 14)
    {
        ///bir-hakeim
        if(x_console == 0)
        {
            x_allegro = 278;
            y_allegro = 296;
        }
        else if(x_console == 1)
        {
            x_allegro = 282;
            y_allegro = 314;
        }
        else if(x_console == 2)
        {
            x_allegro = 282;
            y_allegro = 323;
        }
        else if(x_console == 3)
        {
            x_allegro = 281;
            y_allegro = 334;
        }
        else if(x_console == 4)
        {
            x_allegro = 280;
            y_allegro = 352;
        }
        else if(x_console == 5)
        {
            x_allegro = 282;
            y_allegro = 362;
        }
        else if(x_console == 6)
        {
            x_allegro = 290;
            y_allegro = 376;
        }
        ///vaugirard
        else if(x_console == 7)
        {
            x_allegro = 303;
            y_allegro = 384;
        }
        else if(x_console == 8)
        {
            x_allegro = 347;
            y_allegro = 393;
        }
        else if(x_console == 9)
        {
            x_allegro = 395;
            y_allegro = 404;
        }
        else if(x_console == 10)
        {
            x_allegro = 453;
            y_allegro = 414;
        }
        else if(x_console == 11)
        {
            x_allegro = 539;
            y_allegro = 409;
        }
        else if(x_console == 12)
        {
            x_allegro = 603;
            y_allegro = 381;
        }
        else if(x_console == 13)
        {
            x_allegro = 642;
            y_allegro = 353;
        }
        ///nation
        else if(x_console == 14)
        {
            x_allegro = 660;
            y_allegro = 330;
        }
    }

    //reste
    else if(x_console == 7)
    {
        //barbes
        if(y_console == 0)
        {
            x_allegro = 500;
            y_allegro = 120;
        }
        else if(y_console == 1)
        {
            x_allegro = 478;
            y_allegro = 141;
        }
        else if(y_console == 2)
        {
            x_allegro = 462;
            y_allegro = 155;
        }
        else if(y_console == 3)
        {
            x_allegro = 452;
            y_allegro = 141;
        }
        else if(y_console == 4)
        {
            x_allegro = 435;
            y_allegro = 186;
        }
        else if(y_console == 5)
        {
            x_allegro = 421;
            y_allegro = 203;
        }
        else if(y_console == 6)
        {
            x_allegro = 403;
            y_allegro = 219;
        }
        //concorde
        else if(y_console == 7)
        {
            x_allegro = 383;
            y_allegro = 240;
        }
    }

    else if(y_console == 7)
    {
        //chatelet
        if(x_console == 7)
        {
            x_allegro = 504;
            y_allegro = 275;
        }
        else if(x_console == 8)
        {
            x_allegro = 481;
            y_allegro = 268;
        }
        else if(x_console == 9)
        {
            x_allegro = 466;
            y_allegro = 263;
        }
        else if(x_console == 10)
        {
            x_allegro = 453;
            y_allegro = 259;
        }
        else if(x_console == 11)
        {
            x_allegro = 434;
            y_allegro = 255;
        }
        else if(x_console == 12)
        {
            x_allegro = 417;
            y_allegro = 249;
        }
        else if(x_console == 13)
        {
            x_allegro = 401;
            y_allegro = 245;
        }
        //concorde
        else if(x_console == 14)
        {
            x_allegro = 383;
            y_allegro = 240;
        }
    }

    //concorde - > etoile
    else if(y_console == 4)
    {
        //concorde
        if(x_console == 6)
        {
            x_allegro = 371;
            y_allegro = 229;
        }
        else if(x_console == 5)
        {
            x_allegro = 366;
            y_allegro = 228;
        }
    }
    else if(x_console == 5)
    {
        if(y_console == 3)
        {
            x_allegro = 361;
            y_allegro = 222;
        }
    }
    else if(y_console == 2)
    {
        if(x_console == 5)
        {
            x_allegro = 352;
            y_allegro = 216;
        }
        else if(x_console == 4)
        {
            x_allegro = 352;
            y_allegro = 213;
        }
        else if(x_console == 3)
        {
            x_allegro = 352;
            y_allegro = 209;
        }
        else if(x_console == 2)
        {
            x_allegro = 350;
            y_allegro = 203;
        }
    }
    else if(x_console == 2 && y_console == 1)
    {
        x_allegro = 348;
        y_allegro = 201;
    }
    //ok
    //concorde -> bir

    else if(x_console == 7)
    {
        if(y_console == 6)
        {
            x_allegro = 372;
            y_allegro = 248;
        }
        else if(y_console == 8)
        {
            x_allegro = 367;
            y_allegro = 251;
        }
        else if(y_console == 9)
        {
            x_allegro = 363;
            y_allegro = 255;
        }
        else if(y_console == 10)
        {
            x_allegro = 357;
            y_allegro = 258;
        }
    }
    else if(y_console == 10)
    {
        if(x_console == 5)
        {
            x_allegro = 352;
            y_allegro = 262;
        }
        else if(x_console == 4)
        {
            x_allegro = 343;
            y_allegro = 269;
        }
        else if(x_console == 3)
        {
            x_allegro = 337;
            y_allegro = 275;
        }
        else if(x_console == 2)
        {
            x_allegro = 329;
            y_allegro = 280;
        }
    }
    else if(x_console == 2)
    {
        if(y_console == 11)
        {
            x_allegro = 316;
            y_allegro = 290;
        }
        else if(y_console == 12)
        {
            x_allegro = 305;
            y_allegro = 300;
        }
        else if(y_console == 13)
        {
            x_allegro = 291;
            y_allegro = 310;
        }
    }
    //ok

    //vaugirard -> chatelet
    else if(x_console == 10)
    {
        if(y_console == 13)
        {
            x_allegro = 385;
            y_allegro = 388;
        }
        else if(y_console == 12)
        {
            x_allegro = 395;
            y_allegro = 376;
        }
        if(y_console == 11)
        {
            x_allegro = 406;
            y_allegro = 357;
        }
        if(y_console == 10)
        {
            x_allegro = 431;
            y_allegro = 350;
        }
    }
    else if(y_console == 10 && x_console == 11)
    {
        x_allegro = 462;
        y_allegro = 351;
    }
    else if(x_console == 12)
    {
        if(y_console == 10)
        {
            x_allegro = 481;
            y_allegro = 346;
        }
        if(y_console == 9)
        {
            x_allegro = 501;
            y_allegro = 318;
        }
        if(y_console == 8)
        {
            x_allegro = 503;
            y_allegro = 296;
        }
    }
    //ok
}
/*********************************************************************************************************/

