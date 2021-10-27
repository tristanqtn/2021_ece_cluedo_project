#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Partie::Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs)
       :m_meurtrier (_meurtrier), m_deck_cartes(_deck_cartes), m_joueurs(_joueurs)
{}


Partie::Partie()
       :m_meurtrier(), m_deck_cartes(), m_joueurs()
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Partie::~Partie() {}
/*********************************************************************************************************/


/**< SETTERS >********************************************************************************************/
void Partie::set_deck(std::vector <Carte_alibi> deck) { m_deck_cartes = deck; }
void Partie::set_meurtrier(Meurtrier tueur) { m_meurtrier = tueur; }
/*********************************************************************************************************/


/**< CREATION D'UNE NOUVELLE PARTIE >*********************************************************************/
void Partie::creer_partie()
{
    //création des différentes cartes alibi dans des pioches séparées
    std::vector <Carte_alibi> deck_lieux = creer_deck_lieux();
    std::vector <Carte_alibi> deck_armes = creer_deck_armes();
    std::vector <Carte_alibi> deck_personnages = creer_deck_personnage();
    std::vector <Carte_alibi> deck_final; //deck pour assemblage final des pioches

    Meurtrier meurtrier_tempo = creer_meurtrier(deck_personnages, deck_lieux, deck_armes);

    deck_final.insert(deck_final.end(), deck_armes.begin(), deck_armes.end()); //ajout de la pioche d'armes dans la pioche finale
    deck_final.insert(deck_final.end(), deck_lieux.begin(), deck_lieux.end()); //ajout de la pioche de lieux dans la pioche finale
    deck_final.insert(deck_final.end(), deck_personnages.begin(), deck_personnages.end()); //ajout de la pioche de suspect dans la pioche finale

    //nettoyage des vecteurs
    deck_armes.clear();
    deck_personnages.clear();
    deck_lieux.clear();

    random_shuffle(deck_final.begin(), deck_final.end()); //melange de la pioche
    random_shuffle(deck_final.begin(), deck_final.end()); //melange de la pioche 2eme fois pour être bien sur

    Partie::set_deck(deck_final);
    Partie::set_meurtrier(meurtrier_tempo);
}
/*********************************************************************************************************/


/**< AFFICHAGE DE LA PIOCHE DE CARTES ALIBI >*************************************************************/
void Partie::afficher_deck() const
{
    for(auto const& elem : m_deck_cartes)
    {
        elem.afficher_carac();
    }
}
/*********************************************************************************************************/


/**< AFFICHAGE DU MEURTRIER >*****************************************************************************/
void Partie::afficher_meurtrier() const
{
    m_meurtrier.afficher_meurtrier();
}
/*********************************************************************************************************/


/**< RETOURNER UNE SEULE CARTE DE LA PIOCHE >*************************************************************/
Carte_alibi Partie::get_carte(int valeur) const
{
    if(valeur<int (m_deck_cartes.size()))
    {
        return m_deck_cartes[valeur];
    }

    else
    {
        Carte_alibi nouvelle;
        return nouvelle;
    }
}
/*********************************************************************************************************/


/**< RETOURNER TOUTES LES CARTES DE LA PIOCHE >***********************************************************/
std::vector <Carte_alibi> Partie::get_pioche() const
{
    return m_deck_cartes;
}
/*********************************************************************************************************/

