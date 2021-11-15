#include "header_chance.h"
#include "header_case.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Carte_chance::Carte_chance()
             :m_malus(false), m_bonus(false), m_description(""), m_valeur(0)
{}

Carte_chance::Carte_chance(bool _malus, bool _bonus, std::string _description, int _valeur) //surchargé
             :m_malus( _malus), m_bonus(_bonus), m_description(_description), m_valeur(_valeur)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Carte_chance::~Carte_chance() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Carte_chance::get_bonus() const { return m_bonus; }
bool Carte_chance::get_malus() const { return m_malus; }

std::string Carte_chance::get_descritpion() const { return m_description; }

int Carte_chance::get_valeur () const {return m_valeur; }

Carte_chance * Carte_chance::get_pointeur() { return this; }
/*********************************************************************************************************/


/**< SETTERS >********************************************************************************************/
void Carte_chance::set_bonus(bool valeur) { m_bonus = valeur; }
void Carte_chance::set_malus(bool valeur) { m_malus = valeur; }

void Carte_chance::set_descritpion(std::string chaine) { m_description = chaine; }

void Carte_chance::set_valeur (int valeur) { m_valeur = valeur; }
/*********************************************************************************************************/



/**< AFFICHAGE DES CARACTERISTIQUES D'UNE CARTE CHANCE >**************************************************/
void Carte_chance::afficher_carac()
{
    if(Carte_chance::get_bonus() == false)
        std::cout << "Malus ";

    else if(Carte_chance::get_bonus() == true)
        std::cout << "Bonus ";

    std::cout << ": " << Carte_chance::get_descritpion() << " valeur : " << Carte_chance::get_valeur() << std::endl;

}
/*********************************************************************************************************/

