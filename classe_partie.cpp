#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
#include "header_principal.h"

/**< CONSTRUCTEUR >***************************************************************************************/
Partie::Partie()
    : m_nb_IA(0), m_nb_joueur(0), m_meurtrier(), m_joueurs(), m_deck_cartes()
{}

Partie::Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs)
    : m_nb_IA(0), m_nb_joueur(0), m_meurtrier (_meurtrier), m_joueurs(_joueurs), m_deck_cartes(_deck_cartes)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Partie::~Partie() {}
/*********************************************************************************************************/


/**< SETTERS >********************************************************************************************/
void Partie::set_deck(std::vector <Carte_alibi> deck) { m_deck_cartes = deck; }
void Partie::set_meurtrier(Meurtrier tueur) { m_meurtrier = tueur; }
void Partie::set_nb_joueur(int valeur)
{
    if(valeur>=1 && valeur<=6)
        m_nb_joueur = valeur;
}
void Partie::set_nb_IA(int valeur)
{
    if(valeur>=0 && valeur<=5)
        m_nb_IA = valeur;
}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
int Partie::get_nb_IA() const { return m_nb_IA; }
int Partie::get_nb_joueurs() const { return m_nb_joueur; }
int Partie::get_nb_tot_joueur() const { return (m_nb_joueur+m_nb_IA); }

std::vector <Joueur> Partie::get_joueurs() const { return m_joueurs; }
std::vector <Carte_alibi> Partie::get_pioche() const{ return m_deck_cartes; }

Meurtrier Partie::get_meurtrier() const { return m_meurtrier; }

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

Partie * Partie::get_pointeur() { return this; }
/*********************************************************************************************************/

/**< CREATION D'UNE NOUVELLE PARTIE >*********************************************************************/
void Partie::creer_partie()
{
    //cr�ation des diff�rentes cartes alibi dans des pioches s�par�es
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
    random_shuffle(deck_final.begin(), deck_final.end()); //melange de la pioche 2eme fois pour �tre bien sur

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



/**< PARAMETRAGE DE LA PARTIE >***************************************************************************/
void Partie::parametrer()
{
    int valeur =0, IA =0, nb_IA =0;
    bool sortie = false;

    do
    {
        system("CLS");
        std::cout << "****** PARAMETRAGE DE LA PARTIE ******" << std::endl;

        std::cout << "Le nombre de joueurs minimum est 1 et maximum est 6"<<std::endl<<std::endl;
        do
        {//lecture blind�e du nombre de joueurs
            std::cout << "Nombres de joueurs : ";
            std::cin >> valeur;
        }
        while(valeur>6 || valeur<1);


        do
        {//lecture blind�e de la pr�sence d'IA
            std::cout << "Souhaitez-vous jouer ave des IA [1 pour oui/0 pour non] : ";
            std::cin >> IA;
        }
        while(IA <0 || IA>1);

        if(IA == 1 && valeur != 6)
        {

            do
            {//lecture blind�e du nombre d'IA
                std::cout << "Combien d'IA voulez-vous ajoutez (veuillez a respecter le nombre de joueurs max) : ";
                std::cin >> nb_IA;
            }
            while(nb_IA>5 || nb_IA<1);

        }


        if((valeur+nb_IA)<=6 && (valeur+nb_IA)>=3)
        {//verification du bon nombre de joueur tot dans la partie
            std::cout << nb_IA << " IA ont ete ajoutees a la partie" << std::endl;
            sortie = true; // sortie du ss-pg
        }
        else
        {//trop ou pas assez de joueurs
            std::cout << "Il y a un probleme dans le parametrage de la partie, veuillez respecter un minimum de 3 joueurs et un maximum de 6 joueurs" << std::endl;
        }

    }//on boucle tant que la saisie n'est pas satisfaisante
    while(sortie == false);

    //set du nombre de joueurs et d'IA
    Partie::set_nb_joueur(valeur);
    Partie::set_nb_IA(nb_IA);

    std::cout << "**************************************" << std::endl;
    system("pause");
}
/*********************************************************************************************************/

/**< DISTRIBUTION DES CARTES >****************************************************************************/
void Partie::distribuer()
{
    system("CLS");

    random_shuffle(m_deck_cartes.begin(), m_deck_cartes.end()); //m�lange des cartes de la pioche
    random_shuffle(m_joueurs.begin(), m_joueurs.end()); //m�lange des joueurs

    for(size_t i=0; i<m_deck_cartes.size(); i++)
    {//parcours de la pioche
        for(int j=0; j<Partie::get_nb_tot_joueur(); j++)
        {//parcours des joueurs
            if(i<m_deck_cartes.size())
            {//si l'index i est inf�rieur � la taille du vecteur de cartes
                m_joueurs[j].recevoir_carte(m_deck_cartes[i]); //distribution
                i++; //incr�mentation
            }
        }
        if(i<m_deck_cartes.size()) //si i est tj inf�rieur � la taille du vecteur
            i--;
    }

    m_deck_cartes.clear();
    std::cout << "Les cartes ont ete distribuees et l'ordre des joueurs melange !" << std::endl;
    system("pause");
}
/*********************************************************************************************************/


/**< CREATION DES IA >************************************************************************************/
void Partie::creer_IA()
{
    std::vector <Carte_alibi> vide;
    std::string nom = "IA ", pseudo;

    for(int i=0; i<Partie::get_nb_IA(); i++)
    {//pour le nombre d'IA demand�e
        pseudo = nom + std::to_string(i); //g�n�ration du nom de l'IA en fonction de l'index
        Joueur nouveau (pseudo, 0, 0, "novice", vide, true, false, true); //cr�ation de l'objet IA
        m_joueurs.push_back(nouveau); //ajout de l'ia dans le vecteur de joueurs
    }
}
/*********************************************************************************************************/


/**< CREATION DES NOUVEAU JOUEURS >***********************************************************************/
void Partie::creer_joueurs()
{
    std::string pseudo, pion;
    std::vector <Carte_alibi> vide;
    for(int i=0; i<get_nb_joueurs(); i++)
    {//pour le nombre joueur demand�s
        system("CLS");

        std::cout << "****** NOUVEAU JOUEUR ******" << std::endl;

        do
        {//saisie blind�e du pseudo pour eviter les doublons
            std::cout << "Pseudo : ";
            std::cin >> pseudo;

        }
        while(Partie::doublon_pseudo(pseudo) == false);

        ///faire saisir du pion

        Joueur nouveau(pseudo, 0,0, "novice", vide, false, false, true); //cr�ation de l'objet joueur

        m_joueurs.push_back(nouveau); //ajout dans le vecteur

        system("pause");
    }
}
/*********************************************************************************************************/



/**< VERIFICATION DES DOUBLONS DE PSEUDO >****************************************************************/
bool Partie::doublon_pseudo(std::string chaine)
{
    bool rendu = true;

    for(const auto& elem : m_joueurs)
    {//parcours du vecteur de joueurs
        if(chaine == elem.getPseudo())
        {//si les deux chaine sont �gales
            rendu = false; //doublon
        }
    }
    return rendu; //rendu du resultat
}
/*********************************************************************************************************/

/**< CREATION DES CARTES ALIBI >**************************************************************************/
std::vector <Carte_alibi> Partie::creer_deck_armes()
{
    ///carte armes

    //d�claration du vecteur
    std::vector <Carte_alibi> deck_armes;

    //cr�ation des cartes
    Carte_alibi couteau (false, false, true, "Rails");
    Carte_alibi chandelier (false, false, true, "Porte");
    Carte_alibi clef (false, false, true, "Barre");
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
{
    ///cartes lieux

    //d�claration du vecteur
    std::vector <Carte_alibi> deck_lieux;

    //cr�ation des cartes
    Carte_alibi etoile (false, true, false, "Etoile");
    Carte_alibi birak (false, true, false, "Bir-Hakeim");
    Carte_alibi troca (false, true, false, "Trocadero");
    Carte_alibi chatelet (false, true, false, "Chatelet");
    Carte_alibi concorde (false, true, false, "Concorde");
    Carte_alibi barbes (false, true, false, "Barbes");
    Carte_alibi nation (false, true, false, "Nation");
    Carte_alibi vaugirard(false, true, false, "Vaugirard");
    Carte_alibi stalingrad (false, true, false, "Stalingrad");

    //ajout des cartes dans le vecteur
    deck_lieux.push_back(etoile);
    deck_lieux.push_back(birak);
    deck_lieux.push_back(troca);
    deck_lieux.push_back(chatelet);
    deck_lieux.push_back(concorde);
    deck_lieux.push_back(barbes);
    deck_lieux.push_back(nation);
    deck_lieux.push_back(vaugirard);
    deck_lieux.push_back(stalingrad);

    return deck_lieux; //rendu du vecteur
}


std::vector <Carte_alibi> Partie::creer_deck_personnage()
{
    ///cartes personnages

    //d�claration du vecteur
    std::vector <Carte_alibi> deck_personnage;

    //cr�ation des cartes
    Carte_alibi controleur (true, false, false, "Controleur");
    Carte_alibi conducteur (true, false, false, "Conducteur");
    Carte_alibi agent_secu (true, false, false, "Securite");
    Carte_alibi sdf (true, false, false, "SDF");
    Carte_alibi passager (true, false, false, "Passager");
    Carte_alibi musicien (true, false, false, "Musicien");


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
    //cr�ation de 3 entier al�atoires
    int rand_1 = rand()%6;
    int rand_2 = rand()%6;
    int rand_3 = rand()%6;

    //cr�ation d'un nouveau meurtrier en piochant al�toirement un alibi dans chaque pioche
    Meurtrier murderer(deck_personnages[rand_1], deck_armes[rand_2], deck_lieux[rand_3]);

    //suppression de la carte utlis�e pour le meurtrier dans chaque pioche
    deck_personnages.erase(deck_personnages.begin()+ rand_1);
    deck_lieux.erase(deck_lieux.begin()+ rand_2);
    deck_armes.erase(deck_armes.begin()+ rand_3);

    return murderer; //rendu du meurtrier
}
/*********************************************************************************************************/


/**< REALISER UNE ACCUSATION AVEC VERIFICATION AUTOMATIQUE ET EXCLUSION DU JOUEUR >***********************/
bool Partie::accusation_finale(int i)
{
    Meurtrier accusation = m_joueurs[i].formuler_hypothese();//recuperation de l(hypothese du joueur
    bool sortie = m_meurtrier.verification_victoire(accusation);//vecrification de l'hypothese et du meurtrier de la partie

    if(sortie == false)
    {//l'accusation est fausse
        m_joueurs[i].set_autorisation_jeu(false);//on bloque le jeu du joueur
        std::cout << "L'accusation r�alis�e est fausse " << m_joueurs[i].getPseudo() << " ne peut plus jouer, dommage... " << std::endl;//message
    }

    else
    {//accusation correcte
    }

    return sortie;
}
/*********************************************************************************************************/


/**< REALISER UNE HYPOTHESE ET VERIFICATION AVEC LE JOUEUR SUIVANT >**************************************/
void Partie::hypothese_finale(int i)
{
    int suivant;
    Meurtrier hypothese = m_joueurs[i].formuler_hypothese();//recuperation de l'hypoth�se du joueur

    if(i == Partie::get_nb_tot_joueur()-1)
    {//si l'hypoth�se est r�alis�e par le dernier joueur du vecteur
        suivant = 0;//le joueur suivant est le premier du vecteur
    }
    else
    {//sinon
        suivant = i+1;//stockage de l'index du joueur suivant
    }

    //test pour savoir si le joueur suivant poss�de une carte de l'hypoth�se formuler
    if(m_joueurs[suivant].get_IA() == false)
        m_joueurs[suivant].validation_hypothese_joueur(m_joueurs[suivant].get_main(), hypothese);
    else
        m_joueurs[suivant].verification_hypothese_IA(m_joueurs[suivant].get_main(), hypothese);
}
/*********************************************************************************************************/


/**< TOUR D'UNE IA >**************************************************************************************/
void Partie::tour_IA(int i)
{
    int suivant;

    //cr�ation des diff�rentes cartes alibi dans des pioches s�par�es
    std::vector <Carte_alibi> deck_lieux = Partie::creer_deck_lieux();
    std::vector <Carte_alibi> deck_armes = Partie::creer_deck_armes();
    std::vector <Carte_alibi> deck_personnages = Partie::creer_deck_personnage();

    //g�n�ration d'une hypothese
    Meurtrier hypothese_IA = Partie::creer_meurtrier(deck_personnages, deck_lieux, deck_armes);

    //affichage du tour de l'IA;
    system("CLS");
    std::cout << "C'est le tour de " << m_joueurs[i].getPseudo() << std::endl;
    std::cout << "L'" << m_joueurs[i].getPseudo() << " realise une hypothese : " << std::endl;

    hypothese_IA.afficher_meurtrier();//affichage de l'hypothese

    if(i == Partie::get_nb_tot_joueur())
    {//si l'hypoth�se est r�alis�e par le dernier joueur du vecteur
        suivant = 0;//le joueur suivant est le premier du vecteur
    }
    else
    {//sinon
        suivant = i+1;//stockage de l'index du joueur suivant
    }

    if(m_joueurs[suivant].get_IA() == false)
        m_joueurs[suivant].validation_hypothese_joueur(m_joueurs[suivant].get_main(), hypothese_IA);
    else
        m_joueurs[suivant].verification_hypothese_IA(m_joueurs[suivant].get_main(), hypothese_IA);

}
/*********************************************************************************************************/


/**< TOUR D'UN JOUEUR >***********************************************************************************/
bool Partie::tour_joueur(int i)
{
    bool sortie;
    int deplacement = 0, choix = 0;

    if(m_joueurs[i].get_autorisation() == true)
    {//si le joueur � la droit de jouer

        choix = m_joueurs[i].jouer_tour(&deplacement); //recuperation du choix d'action du joueur et de son d�placement

        std::cout << std::endl;

        switch(choix)
        {
            case 1: //d�placement
                {

                }
                break;


            case 2: //hypoth�se
                Partie::hypothese_finale(i);
                break;

            case 3: //r�aliser une accusation
                sortie = Partie::accusation_finale(i);
                break;

            case 4: //passer son tour
                {

                }
                break;

        }
    }
    else
    {//le joueur est interdit de jouer, affichage d'un message
        std::cout << "Desole " << m_joueurs[i].getPseudo() << " tu ne peux toujours pas jouer !" << std::endl;
    }
    return sortie;
}
/*********************************************************************************************************/


/**< BOUCLE DE JEU >**************************************************************************************/
void Partie::lancer_partie ()
{
    int i;
    bool sortie = false;

    while(sortie == false)
    {//boucle de jeu

        //remise � 0 des variables sp�cifiques aux joueurs
        i=0;

        while(i<Partie::get_nb_tot_joueur() && sortie == false)
        {//parcours du vecteur de joueurs et sortie � la fin du parcours ou en cas de victoire

            ///JOUEUR
            if(m_joueurs[i].get_IA() == false)
            {//si le joueur est une personne
                sortie = tour_joueur(i);
            }

            ///IA
            else if(m_joueurs[i].get_IA() == true)
            {//le joueur est un IA
                tour_IA(i);
            }

            i++;
            system("pause");
        }
    }
}
/*********************************************************************************************************/


