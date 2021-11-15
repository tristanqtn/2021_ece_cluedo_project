#include "header_plateau.h"
#include "header_joueur.h"

/**** Plateau ******/

//constructeur par default
Plateau::Plateau()
{
    ///NUMEROTATION PLATEAU[COLONNE][LIGNE]

    //case vide
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
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
    for(int i=1;i<14;i++){
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
    for(int i=0;i<15;i++){
        if(i==1){
            i=11;
        }
        m_plateau[2][i].set_sortie_bas(true);
        m_plateau[2][i].set_sortie_haut(true);
    }
    m_plateau[2][2].set_sortie_haut(true);
    m_plateau[2][10].set_sortie_bas(true);

    m_plateau[2][0].set_sortie_gauche(true);
    m_plateau[2][1].set_sortie_droite(true);
    m_plateau[2][10].set_sortie_droite(true);
    m_plateau[2][14].set_sortie_droite(true);
    m_plateau[2][14].set_sortie_gauche(true);

    //colonne 4
    for(int i=1;i<15;i++){
        if(i==2){
            i=10;
        }
        else if(i==11){
            i=14;
        }
        m_plateau[3][i].set_sortie_droite(true);
        m_plateau[3][i].set_sortie_gauche(true);
    }

    //colonne 5
    for(int i=1;i<15;i++){
        if(i==2){
            i=10;
        }
        else if(i==11){
            i=14;
        }
        m_plateau[4][i].set_sortie_droite(true);
        m_plateau[4][i].set_sortie_gauche(true);
    }

    //colonne 6
    m_plateau[5][1].set_sortie_gauche(true);
    m_plateau[5][1].set_sortie_bas(true);

    m_plateau[5][2].set_sortie_haut(true);
    m_plateau[5][2].set_sortie_bas(true);

    m_plateau[5][3].set_sortie_haut(true);
    m_plateau[5][3].set_sortie_droite(true);

    m_plateau[5][10].set_sortie_droite(true);
    m_plateau[5][10].set_sortie_gauche(true);

    m_plateau[5][14].set_sortie_droite(true);
    m_plateau[5][14].set_sortie_gauche(true);

    //colonne 7
    m_plateau[6][3].set_sortie_gauche(true);
    m_plateau[6][3].set_sortie_droite(true);

    m_plateau[6][6].set_sortie_droite(true);
    m_plateau[6][6].set_sortie_bas(true);

    m_plateau[6][7].set_sortie_haut(true);
    m_plateau[6][7].set_sortie_bas(true);

    m_plateau[6][8].set_sortie_haut(true);
    m_plateau[6][8].set_sortie_bas(true);

    m_plateau[6][9].set_sortie_haut(true);
    m_plateau[6][9].set_sortie_gauche(true);

    m_plateau[6][7].set_sortie_droite(true);
    m_plateau[6][7].set_sortie_gauche(true);

    //colonne 8
    for(int i=1;i<6;i++){
        m_plateau[7][i].set_sortie_bas(true);
        m_plateau[7][i].set_sortie_haut(true);
    }
    ///
    ///ICI
    ///
    m_plateau[7][0].set_sortie_bas(true);

    m_plateau[7][3].set_sortie_gauche(true);

    m_plateau[7][6].set_sortie_droite(true);
    m_plateau[7][6].set_sortie_gauche(true);
    m_plateau[7][6].set_sortie_haut(true);

    m_plateau[7][14].set_sortie_droite(true);
    m_plateau[7][14].set_sortie_gauche(true);

    m_plateau[7][0].set_nom_station("Barbes");
    m_plateau[7][0].set_station(true);

    m_plateau[7][7].set_nom_station("Concorde");
    m_plateau[7][7].set_station(true);

    m_plateau[7][14].set_nom_station("Vaugirard");
    m_plateau[7][14].set_station(true);

    //colonne 9
    m_plateau[8][6].set_sortie_droite(true);
    m_plateau[8][6].set_sortie_gauche(true);

    m_plateau[8][14].set_sortie_droite(true);
    m_plateau[8][14].set_sortie_gauche(true);

    //colonne 10
    m_plateau[9][6].set_sortie_droite(true);
    m_plateau[9][6].set_sortie_gauche(true);

    m_plateau[9][14].set_sortie_droite(true);
    m_plateau[9][14].set_sortie_gauche(true);
///
///ICI
///
    //colonne 11
    m_plateau[10][6].set_sortie_droite(true);
    m_plateau[10][6].set_sortie_gauche(true);

    m_plateau[10][9].set_sortie_bas(true);
    m_plateau[10][9].set_sortie_droite(true);

    m_plateau[10][10].set_sortie_bas(true);
    m_plateau[10][10].set_sortie_haut(true);

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
    m_plateau[11][6].set_sortie_droite(true);
    m_plateau[11][6].set_sortie_gauche(true);

    m_plateau[11][9].set_sortie_droite(true);
    m_plateau[11][9].set_sortie_gauche(true);

    m_plateau[11][14].set_sortie_droite(true);
    m_plateau[11][14].set_sortie_gauche(true);

    //colonne 13
    m_plateau[12][6].set_sortie_bas(true);
    m_plateau[12][6].set_sortie_droite(true);
    m_plateau[12][6].set_sortie_gauche(true);

    m_plateau[12][7].set_sortie_bas(true);
    m_plateau[12][7].set_sortie_haut(true);

    m_plateau[12][8].set_sortie_bas(true);
    m_plateau[12][8].set_sortie_haut(true);

    m_plateau[12][9].set_sortie_gauche(true);
    m_plateau[12][9].set_sortie_haut(true);

    m_plateau[12][14].set_sortie_gauche(true);
    m_plateau[12][14].set_sortie_droite(true);

    //colonne 14
    m_plateau[13][6].set_sortie_droite(true);
    m_plateau[13][6].set_sortie_gauche(true);

    m_plateau[13][14].set_sortie_droite(true);
    m_plateau[13][14].set_sortie_gauche(true);

    //colonne 15
    for(int i=1;i<14;i++){
        m_plateau[14][i].set_sortie_bas(true);
        m_plateau[14][i].set_sortie_haut(true);
    }

    m_plateau[0][0].set_sortie_bas(true);

    m_plateau[14][0].set_sortie_gauche(true);

    m_plateau[14][14].set_sortie_gauche(true);
    m_plateau[14][14].set_sortie_haut(true);
    m_plateau[14][14].set_sortie_haut(true);

    m_plateau[14][0].set_station(true);
    m_plateau[14][0].set_nom_station("Stalingrad");

    m_plateau[14][7].set_station(true);
    m_plateau[14][7].set_nom_station("Chatelet");

    m_plateau[14][14].set_station(true);
    m_plateau[14][14].set_nom_station("Nation");

}

Plateau::Plateau(Case_plateau _plateau[15][15])
{
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            m_plateau[i][j] = _plateau[i][j];
        }
    }
}

//destructeur
Plateau::~Plateau()
{
}

//getter
Case_plateau Plateau::get_case_plateau(int i, int j) const
{
    return m_plateau[i][j];
}

//setter
void Plateau::set_plateau(Case_plateau _plateau[15][15])
{
    int i, j;

    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            m_plateau[i][j] = _plateau[i][j];
        }
    }
}
/*
//fonction pour ajouter un joueur a une case
void Plateau::ajouter_joueur(Case_plateau case_plateau, Joueur * joueur)
{
    case_plateau.set_occupant(joueur);
}

//fonction pour supprimer un joueur d'une case
void Plateau::supprimer_joueur(Case_plateau case_plateau)
{
    case_plateau.set_occupant(NULL);
}*/

void Plateau::deplacement_elementaire(Case_plateau case_initial, Case_plateau case_d_arrivee, Joueur * joueur)
{
    case_d_arrivee.set_occupant(joueur);
    case_initial.set_occupant(NULL);

}

//fonction de deplacement
void Plateau::deplacement(int x, int y, int de, int & rendu_x, int & rendu_y)
{
    int i;
    std::string choix;

    //nombre de deplacement donné par le dé
    for(i=0;i<de;i++)
    {
            //si le passage du haut est ouvert
            if(m_plateau[x][y].get_sortie_haut()){
                std::cout << "Vous pouvez aller en haut." << std::endl;
            }
            //si le paasage du bas est ouvert
            if(m_plateau[x][y].get_sortie_bas()){
                std::cout << "Vous pouvez aller en bas." << std::endl;
            }
            if(m_plateau[x][y].get_sortie_droite()){
                std::cout << "Vous pouvez aller a droite." << std::endl;
            }
            if(m_plateau[x][y].get_sortie_gauche()){
                std::cout << "Vous pouvez aller a gauche." << std::endl;
            }
            std::cout << "Ou voulez vous aller ? : " ;
            std::cin >> choix ;

            if(choix == "haut" && m_plateau[x][y].get_sortie_haut()){
                y--;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant());
            }
            else if(choix == "bas" && m_plateau[x][y].get_sortie_bas()){
                y++;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant());
            }
            else if(choix == "droite" && m_plateau[x][y].get_sortie_droite()){
                x++;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant());
            }
            else if(choix == "gauche" && m_plateau[x][y].get_sortie_gauche()){
                x--;
                deplacement_elementaire(m_plateau[x][y], m_plateau[x][y], m_plateau[x][y].get_occupant());
                }

            else{
                std::cout << "Deplacement impossible" << std::endl;
                i--;
            }
    }

    rendu_x = x;
    rendu_y = y;
}



