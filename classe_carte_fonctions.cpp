#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
//surchargé
Carte_alibi::Carte_alibi(bool _personnage, bool _lieu, bool _arme, std::string _spec)
            :m_personnage (_personnage), m_lieu (_lieu), m_arme (_arme), m_caracteristique(_spec)
{}

//défault
Carte_alibi::Carte_alibi()
            :m_personnage (), m_lieu(), m_arme(), m_caracteristique("")
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Carte_alibi::~Carte_alibi() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Carte_alibi::get_personnage() const { return m_personnage; } //suspect
bool Carte_alibi::get_lieu() const { return m_lieu; } //lieu
bool Carte_alibi::get_arme() const { return m_arme; } //arme

std::string Carte_alibi::get_caracteristique() const { return m_caracteristique; } //definition
/*********************************************************************************************************/


/**<  AFFICHER ELEMENT DE LA CARTE >**********************************************************************/
void Carte_alibi::afficher_carac() const
{
    if(get_personnage() == true)
    {//affichage d'un suspect
        std::cout << "Carte suspect : " << get_caracteristique() << std::endl;
    }
    else if(get_arme() == true)
    {//affichage d'une arme
        std::cout << "Carte arme : " << get_caracteristique() << std::endl;
    }
    else if(get_lieu() == true)
    {//affichage d'un lieu
        std::cout << "Carte lieu : " << get_caracteristique() << std::endl;
    }
    else
    {//cas normalement impossible
        std::cout << "ERROR" << std::endl;
    }
}
/*********************************************************************************************************/


/**< CREATION DES CARTES ALIBI >**************************************************************************/
std::vector <Carte_alibi> creer_deck_armes()
{///carte armes

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_armes;

    //création des cartes
    Carte_alibi couteau (false, false, true, "rails");
    Carte_alibi chandelier (false, false, true, "porte");
    Carte_alibi clef (false, false, true, "barre du metro");
    Carte_alibi masse (false, false, true, "strapontin");
    Carte_alibi corde (false, false, true, "ticket");
    Carte_alibi tourniquet (false, false, true, "tourniquet");


    //ajout des cartes dans le vecteur
    deck_armes.push_back(couteau);
    deck_armes.push_back(chandelier);
    deck_armes.push_back(clef);
    deck_armes.push_back(masse);
    deck_armes.push_back(corde);
    deck_armes.push_back(tourniquet);

    return deck_armes; //rendu du vecteur
}


std::vector <Carte_alibi> creer_deck_lieux()
{///cartes lieux

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_lieux;

    //création des cartes
    Carte_alibi etoile (false, true, false, "Charle de Gaulle - Etoile");
    Carte_alibi birak (false, true, false, "Bir-Hakeim");
    Carte_alibi troca (false, true, false, "Trocadero");
    Carte_alibi chatelet (false, true, false, "Chatelet-Les-Halles");
    Carte_alibi concorde (false, true, false, "Concorde");
    Carte_alibi barbes (false, true, false, "Barbes");


    //ajout des cartes dans le vecteur
    deck_lieux.push_back(etoile);
    deck_lieux.push_back(birak);
    deck_lieux.push_back(troca);
    deck_lieux.push_back(chatelet);
    deck_lieux.push_back(concorde);
    deck_lieux.push_back(barbes);

    return deck_lieux; //rendu du vecteur
}


std::vector <Carte_alibi> creer_deck_personnage()
{///cartes personnages

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_personnage;

    //création des cartes
    Carte_alibi controleur (false, true, false, "Controleur");
    Carte_alibi conducteur (false, true, false, "Conducteur");
    Carte_alibi agent_secu (false, true, false, "Agent de securite");
    Carte_alibi sdf (false, true, false, "SDF");
    Carte_alibi passager (false, true, false, "passager");
    Carte_alibi musicien (false, true, false, "musicien ambulant");


    //ajout des cartes dans le vecteur
    deck_personnage.push_back(controleur);
    deck_personnage.push_back(conducteur);
    deck_personnage.push_back(agent_secu);
    deck_personnage.push_back(sdf);
    deck_personnage.push_back(passager);
    deck_personnage.push_back(musicien);

    return deck_personnage; //rendu du vecteur
}
/*********************************************************************************************************/
