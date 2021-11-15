#include "header_case.h"
#include "header_chance.h"

/*********************************************************************************************************/
void Case_plateau::afficher_deck_chance()
{
    for(auto elem : m_deck_chance)
    {
        elem.afficher_carac();
    }
}
/*********************************************************************************************************/


/*********************************************************************************************************/
void Case_plateau::generer_carte()
{

    for(int i =0; i<3; i++)
    {
        Carte_chance nouvelle (false, true, "avancer de 2 cases en plus ", 2);
        m_deck_chance.push_back(nouvelle);
    }
    for(int i =0; i<3; i++)
    {
        Carte_chance nouvelle(true, false, "reculer de 2 cases en arriere ", 2);
        m_deck_chance.push_back(nouvelle);
    }


    for(int i =0; i<2; i++)
    {
        Carte_chance nouvelle (false, true, "Le joueur de votre choix vous presente une carte au hasard", 1);
        m_deck_chance.push_back(nouvelle);
    }
    Carte_chance nouvelle_1 (false, true, "Le joueur de votre choix vous presente deux cartes au hasard", 2);
    m_deck_chance.push_back(nouvelle_1);



    for(int i =0; i<2; i++)
    {
        Carte_chance nouvelle (true, false, "Presentez une carte au hasard de votre main au joueur que vous choisissez", 1);
        m_deck_chance.push_back(nouvelle);
    }
    Carte_chance nouvelle_2 (true, false, "Presentez deux cartes au hasard de votre main au joueur que vous choisissez", 2);
    m_deck_chance.push_back(nouvelle_2);

    for(int i =0; i<6; i++)
    {
        Carte_chance nouvelle (false, false, "Vide, pas de chance", 0);
        m_deck_chance.push_back(nouvelle);
    }

    Carte_chance ultra_bonus (false, true, "Prenez connaissance d'une carte composant le crime", 1);
    m_deck_chance.push_back(ultra_bonus);

    random_shuffle(m_deck_chance.begin(), m_deck_chance.end());
    random_shuffle(m_deck_chance.begin(), m_deck_chance.end());
    random_shuffle(m_deck_chance.begin(), m_deck_chance.end());
}
/*********************************************************************************************************/


/**** Case Plateau */

//constructeur par default
Case_plateau::Case_plateau()
             :m_occupee(false), m_chance(false), m_sortie_haut(false), m_sortie_bas(false), m_sortie_gauche(false), m_sortie_droite(false), m_nom_station(""), m_deck_chance(), m_occupant(NULL)
{

}
//constructeur surchargé
Case_plateau::Case_plateau(bool _occupee, bool _chance, bool _sortie_haut, bool _sortie_bas, bool _sortie_gauche, bool _sortie_droite, std::string _nom_station, std::vector <Carte_chance> _deck_chance, Joueur * _occupant)
             :m_occupee(_occupee), m_chance(_chance), m_sortie_haut(_sortie_haut), m_sortie_bas(_sortie_bas), m_sortie_gauche(_sortie_gauche), m_sortie_droite(_sortie_droite), m_nom_station(_nom_station), m_deck_chance(_deck_chance),m_occupant(NULL)
             {

             }
//destructeur
Case_plateau::~Case_plateau()
{

}

//getter

bool Case_plateau::get_occupee() const
{
    return m_occupee;
}

bool Case_plateau::get_chance() const
{
    return m_chance;
}

bool Case_plateau::get_station() const
{
    return m_station;
}

bool Case_plateau::get_sortie_haut() const
{
    return m_sortie_haut;
}

bool Case_plateau::get_sortie_bas() const
{
    return m_sortie_bas;
}

bool Case_plateau::get_sortie_gauche() const
{
    return m_sortie_gauche;
}

bool Case_plateau::get_sortie_droite() const
{
    return m_sortie_droite;
}

std::string Case_plateau::get_nom_station() const
{
    return m_nom_station;
}

//setter

void Case_plateau::set_occupee(bool occupee)
{
    m_occupee = occupee;
}

void Case_plateau::set_chance(bool chance)
{
    m_chance = chance;
}

void Case_plateau::set_station(bool station)
{
    m_station = station;
}

void Case_plateau::set_sortie_haut(bool sortie_haut)
{
    m_sortie_haut = sortie_haut;
}

void Case_plateau::set_sortie_bas(bool sortie_bas)
{
    m_sortie_bas = sortie_bas;
}

void Case_plateau::set_sortie_droite(bool sortie_droite)
{
    m_sortie_droite = sortie_droite;
}

void Case_plateau::set_sortie_gauche(bool sortie_gauche)
{
    m_sortie_gauche = sortie_gauche;
}

void Case_plateau::set_occupant(Joueur * occupant)
{
    m_occupant = occupant;
}

void Case_plateau::set_nom_station(std::string nom)
{
    m_nom_station = nom;
}

Joueur* Case_plateau::get_occupant() const
{
    return m_occupant;
}
