#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Partie::Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs)
       :m_nb_joueur(0), m_meurtrier (_meurtrier), m_deck_cartes(_deck_cartes), m_joueurs(_joueurs)
{}


Partie::Partie()
       :m_nb_joueur(0), m_meurtrier(), m_deck_cartes(), m_joueurs()
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
    std::vector <Carte_alibi> deck_lieux = Partie::creer_deck_lieux();
    std::vector <Carte_alibi> deck_armes = Partie::creer_deck_armes();
    std::vector <Carte_alibi> deck_personnages = Partie::creer_deck_personnage();
    std::vector <Carte_alibi> deck_final; //deck pour assemblage final des pioches

    Meurtrier meurtrier_tempo = Partie::creer_meurtrier(deck_personnages, deck_lieux, deck_armes);

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

/*********************************************************************************************************/
void Partie::set_nb_joueur(int valeur)
{
    if(valeur>=3 && valeur<=6)
        m_nb_joueur = valeur;
}
/*********************************************************************************************************/

/*********************************************************************************************************/
int Partie::get_nb_joueur() const
{
    return m_nb_joueur;
}
/*********************************************************************************************************/

/*********************************************************************************************************/
void Partie::parametrer()
{
    int valeur;

    system("CLS");
    std::cout << "****** PARAMETRAGE DE LA PARTIE ******" << std::endl;

    std::cout << "Nombres de joueurs (3 a 6) : ";
    do
    {
        std::cin >> valeur;
    }while(valeur <3 || valeur>6);

    Partie::set_nb_joueur(valeur);

    std::cout << "**************************************" << std::endl;

}
/*********************************************************************************************************/

/*********************************************************************************************************/
void Partie::distribuer()
{
    system("CLS");
    for(size_t i=0; i<m_deck_cartes.size(); i++)
    {
        for(int j=0; j<Partie::get_nb_joueur(); j++)
        {
            m_joueurs[j].add_card(m_deck_cartes[i]);
            i++;
        }
        i--;
    }

    m_deck_cartes.clear();

    std::cout << "Les cartes ont ete distribuees !" << std::endl;
    system("pause");
}
/*********************************************************************************************************/



/**< CREATION DES NOUVEAU JOUEURS >***********************************************************************/
void Partie::creer_joueurs()
{
    std::string pseudo, pion;

    for(int i=0; i<Partie::get_nb_joueur(); i++)
    {
        system("CLS");

        std::cout << "****** NOUVEAU JOUEUR ******" << std::endl;

        do
        {
            std::cout << "Pseudo : ";
            std::cin >> pseudo;

        }while(Partie::doublon_pseudo(pseudo) == false);

        Joueur nouveau(pseudo, 0,0, "novice");

        m_joueurs.push_back(nouveau);

        system("pause");
    }
}
/*********************************************************************************************************/



/**< VERIFICATION DES DOUBLONS DE PSEUDO >****************************************************************/
bool Partie::doublon_pseudo(std::string chaine)
{
    bool rendu = true;

    for(const auto& elem : m_joueurs)
    {
        if(chaine == elem.getPseudo())
        {
            rendu = false;
        }
    }
    return rendu;
}
/*********************************************************************************************************/

/**< CREATION DES CARTES ALIBI >**************************************************************************/
std::vector <Carte_alibi> Partie::creer_deck_armes()
{///carte armes

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_armes;

    //création des cartes
    Carte_alibi couteau (false, false, true, "Rails");
    Carte_alibi chandelier (false, false, true, "Porte");
    Carte_alibi clef (false, false, true, "Barre de metro");
    Carte_alibi masse (false, false, true, "Strapontin");
    Carte_alibi corde (false, false, true, "Ticket");
    Carte_alibi tourniquet (false, false, true, "Tourniquet");


    //ajout des cartes dans le vecteur
    deck_armes.push_back(couteau);
    deck_armes.push_back(chandelier);
    deck_armes.push_back(clef);
    deck_armes.push_back(masse);
    deck_armes.push_back(corde);
    deck_armes.push_back(tourniquet);

    return deck_armes; //rendu du vecteur
}


std::vector <Carte_alibi> Partie::creer_deck_lieux()
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


std::vector <Carte_alibi> Partie::creer_deck_personnage()
{///cartes personnages

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_personnage;

    //création des cartes
    Carte_alibi controleur (true, false, false, "Controleur");
    Carte_alibi conducteur (true, false, false, "Conducteur");
    Carte_alibi agent_secu (true, false, false, "Agent de securite");
    Carte_alibi sdf (true, false, false, "SDF");
    Carte_alibi passager (true, false, false, "Passager");
    Carte_alibi musicien (true, false, false, "Musicien ambulant");


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


/**< CREATION DU MEURTRIER >******************************************************************************/
Meurtrier Partie::creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes)
{
    //création de 3 entier aléatoires
    int rand_1 = rand()%6;
    int rand_2 = rand()%6;
    int rand_3 = rand()%6;

    //création d'un nouveau meurtrier en piochant alétoirement un alibi dans chaque pioche
    Meurtrier murderer(deck_personnages[rand_1], deck_lieux[rand_2], deck_armes[rand_3]);

    //suppression de la carte utlisée pour le meurtrier dans chaque pioche
    deck_personnages.erase(deck_personnages.begin()+ rand_1);
    deck_lieux.erase(deck_lieux.begin()+ rand_2);
    deck_armes.erase(deck_armes.begin()+ rand_3);

    return murderer; //rendu du meurtrier
}
/*********************************************************************************************************/

void Partie::lancer_partie ()
{
    while(1)
    {
        for(int i=0; i<m_nb_joueur; i++)
        {
            m_joueurs[i].jouer_tour();
        }
    }

}
