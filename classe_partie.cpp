#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
#include "header_principal.h"


/**< CONSTRUCTEUR >***************************************************************************************/
Partie::Partie()
    : m_nb_IA(0), m_nb_joueur(0), m_meurtrier(), m_joueurs(), m_IA(), m_deck_cartes(), m_board(), m_tour(0)
{}

Partie::Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes,  std::vector <Joueur> _joueurs, std::vector <IA> _IA, Plateau _board, int _tour)
    : m_nb_IA(0), m_nb_joueur(0), m_meurtrier (_meurtrier), m_joueurs(_joueurs), m_IA(_IA), m_deck_cartes(_deck_cartes), m_board(_board), m_tour(_tour)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Partie::~Partie() {}
/*********************************************************************************************************/


/**< SETTERS >********************************************************************************************/
void Partie::set_deck(std::vector <Carte_alibi> deck)
{
    m_deck_cartes = deck;
}
void Partie::set_meurtrier(Meurtrier tueur)
{
    m_meurtrier = tueur;
}
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
void Partie::set_nb_tour(int valeur)
{
    if(valeur>0)
        m_tour = valeur;
}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
int Partie::get_nb_IA() const
{
    return m_nb_IA;
}
int Partie::get_nb_joueurs() const
{
    return m_nb_joueur;
}
int Partie::get_nb_tot_joueur() const
{
    return (m_nb_joueur+m_nb_IA);
}
int Partie::get_nb_tour() const
{
    return m_tour;
}

std::vector <Joueur> Partie::get_joueurs() const
{
    return m_joueurs;
}
std::vector <IA> Partie::get_IA() const
{
    return m_IA;
}
std::vector <Carte_alibi> Partie::get_pioche() const
{
    return m_deck_cartes;
}

Meurtrier Partie::get_meurtrier() const
{
    return m_meurtrier;
}

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

Partie * Partie::get_pointeur()
{
    return this;
}
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



/**< PARAMETRAGE DE LA PARTIE >***************************************************************************/
void Partie::parametrer()
{
    int valeur =0, IA = 0, nb_IA =0;
    bool sortie = false;

    do
    {
        system("CLS");
        std::cout << "****** PARAMETRAGE DE LA PARTIE ******" << std::endl;

        std::cout << "Le nombre de joueurs minimum est 1 et maximum est 6"<<std::endl<<std::endl;
        do
        {
            //lecture blindée du nombre de joueurs
            std::cout << "Nombre de joueurs : ";
            std::cin >> valeur;
        }
        while(valeur>6 || valeur<1);


        do
        {
            //lecture blindée de la présence d'IA
            std::cout << "Souhaitez-vous jouer ave des IA [1 pour oui/0 pour non] : ";
            std::cin >> IA;
        }
        while(IA <0 || IA>1);

        if(IA == 1 && valeur != 6)
        {

            do
            {
                //lecture blindée du nombre d'IA
                std::cout << "Combien d'IA voulez-vous ajoutez (veuillez a respecter le nombre de joueurs max) : ";
                std::cin >> nb_IA;
            }
            while(nb_IA>5 || nb_IA<1);

        }


        if((valeur+nb_IA)<=6 && (valeur+nb_IA)>=3)
        {
            //verification du bon nombre de joueur tot dans la partie
            std::cout << nb_IA << " IA ont ete ajoutees a la partie" << std::endl;
            sortie = true; // sortie du ss-pg
        }
        else
        {
            //trop ou pas assez de joueurs
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

    random_shuffle(m_deck_cartes.begin(), m_deck_cartes.end()); //mélange des cartes de la pioche
    random_shuffle(m_joueurs.begin(), m_joueurs.end()); //mélange des joueurs

    for(size_t i=0; i<m_deck_cartes.size(); i++)
    {
        //parcours de la pioche
        for(int j=0; j<Partie::get_nb_joueurs(); j++)
        {
            //parcours des joueurs
            if(i<m_deck_cartes.size())
            {
                //si l'index i est inférieur à la taille du vecteur de cartes
                m_joueurs[j].recevoir_carte(m_deck_cartes[i]); //distribution
                i++; //incrémentation
            }
        }
        for(int j=0; j<Partie::get_nb_IA(); j++)
        {
            //parcours des joueurs
            if(i<m_deck_cartes.size())
            {
                //si l'index i est inférieur à la taille du vecteur de cartes
                m_IA[j].recevoir_carte(m_deck_cartes[i]); //distribution
                i++; //incrémentation
            }
        }
        if(i<m_deck_cartes.size()) //si i est tj inférieur à la taille du vecteur
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
    {
        //pour le nombre d'IA demandée
        pseudo = nom + std::to_string(i); //génération du nom de l'IA en fonction de l'index
        IA nouveau(pseudo, vide, true);
        m_IA.push_back(nouveau); //ajout de l'ia dans le vecteur de joueurs
    }
}
/*********************************************************************************************************/


/**< CREATION DES NOUVEAU JOUEURS >***********************************************************************/
void Partie::creer_joueurs()
{
    std::string pseudo, pion;
    std::vector <Carte_alibi> vide;

    for(int i=0; i<Partie::get_nb_joueurs(); i++)
    {
        //pour le nombre joueur demandés
        system("CLS");

        int ancien_profil = 0;


        do
        {
            std::cout << "****** JOUEURS DE LA PARTIE ******" << std::endl;
            std::cout << "Voulez-vous recuperer un profil precedemment utilise ? [1 pour oui/0 pour non] : ";
            std::cin >> ancien_profil;
        }
        while(ancien_profil>1 || ancien_profil<0);



        if(ancien_profil == 1)
        {
            m_joueurs.push_back(Partie::recuperation());
        }

        else
        {
            do
            {
                //saisie blindée du pseudo pour eviter les doublons
                std::cout << std::endl <<"****** NOUVEAU JOUEUR ******" << std::endl;
                std::cout << "Pseudo : ";
                std::cin >> pseudo;

            }
            while(Partie::doublon_pseudo(pseudo) == false);

            Joueur nouveau (pseudo, 0,0, "novice", vide, false, false, true, 0, 0, pion);

            m_joueurs.push_back(nouveau); //ajout dans le vecteur
        }


        //initialisation des coordonnées
        if(i==0)
        {
            //etoile
            m_joueurs[i].set_pos_x(0);
            m_joueurs[i].set_pos_y(0);
        }
        if(i==1)
        {
            //
            m_joueurs[i].set_pos_x(14);
            m_joueurs[i].set_pos_y(7);
        }
        if(i==2)
        {
            m_joueurs[i].set_pos_x(0);
            m_joueurs[i].set_pos_y(14);
        }
        if(i==3)
        {
            m_joueurs[i].set_pos_x(7);
            m_joueurs[i].set_pos_y(7);
        }
        if(i==4)
        {
            m_joueurs[i].set_pos_x(14);
            m_joueurs[i].set_pos_y(0);
        }
        if(i==5)
        {
            m_joueurs[i].set_pos_x(14);
            m_joueurs[i].set_pos_y(14);
        }

        system("pause");
    }
}
/*********************************************************************************************************/


/**< RECUPERER UN PROFIL DE JOUEUR DEJA UTILISER >********************************************************/
Joueur Partie::recuperation()
{
    std::vector <Carte_alibi> vide;
    std::string nom_sauvegarde, fichier;
    std::string const location = "data/saves/players/";

    std::cout << std::endl << "****** RECUPERATION D'UN ANCIEN PROFIL ******" << std::endl << std::endl;
    std::cout << "Voici la liste des profils de joueurs qui ont etes sauvegarder lors des partie precedentes : " << std::endl;
    system("dir data\\saves\\players");
    std::cout << std::endl << "Veuillez saisir le nom du profil que vous souhaitez recuperer (extension comprise) : " << std::endl;


    std::cin >> nom_sauvegarde;
    fichier = location+nom_sauvegarde;


    std::string pseudo, grade, vid;
    int nbPartie, nbVictoire;

    //ouverture du fichier en mode écriture sans supprimer ce qui est déjà écrit
    std::ifstream f;
    f.open(fichier);

    //test si le fichier est bien ouvert
    if(!f)
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    else
    {
        //récupération des divers éléments de la sauvegarde
        f >> pseudo;
        f >> nbPartie;
        f >> nbVictoire;
        f >> grade;

    }

    //création du nouveau joueur
    Joueur nouveau (pseudo, nbPartie, nbVictoire, grade, vide, false, true, true, 0, 0, vid);

    f.close(); //fermeture du fichier
    return nouveau;//rnedu du nouveau joueur
}
/*********************************************************************************************************/


/*********************************************************************************************************/
void Partie::initialisation()
{
    int temp;

    //incrémentation du nombre de parties jouées par les joueurs
    for(int i=0; i<Partie::get_nb_joueurs(); i++)
    {
        temp = m_joueurs[i].getNbPartie();
        m_joueurs[i].setNbPartie(temp+1);
    }

    //sauvegarde des profils de joueur
    for(size_t k=0; k<m_joueurs.size(); k++)
    {
        m_joueurs[k].sauvegarde_joueur();
    }

    //supression de l'ancienne liste d'hypothèses
    system("del \"data\\saves\\game\\guess.txt\"");
}
/*********************************************************************************************************/


/**< VERIFICATION DES DOUBLONS DE PSEUDO >****************************************************************/
bool Partie::doublon_pseudo(std::string chaine)
{
    bool rendu = true;

    for(const auto& elem : m_joueurs)
    {
        //parcours du vecteur de joueurs
        if(chaine == elem.getPseudo())
        {
            //si les deux chaine sont égales
            rendu = false; //doublon
        }
    }
    return rendu; //rendu du resultat
}
/*********************************************************************************************************/


/**< CHOIX DES PIONS >************************************************************************************/
void Partie::choix_pion()
{
    system("CLS");
    std::cout << "****** CHOIX DES PIONS ******" << std::endl;
    std::cout << std::endl << "Les couleurs disponibles sont : rouge, orange, jaune, vert, bleu, violet." << std::endl << "Il est impossible de prendre la meme couleur de pion qu'un autre joueur !" << std::endl << std::endl;

    for(int i=0; i<m_nb_joueur; i++)
    {
        //pour le nombre de joueur
        std::string pion;
        bool rendu_1 = true, rendu_2 = true;
        do
        {
            // demande de saisie de la couleur du pion blindée
            std::cout << m_joueurs[i].getPseudo() << " veuillez choisir votre pion : ";
            std::cin >> pion;
            rendu_1 = doublon_pion(pion); //verfi doublon
            rendu_2 = couleur_pion(pion); //verif orthographe

            if(rendu_1 == true && rendu_2 == true)
                m_joueurs[i].set_pion(pion); // si les verifications d'orthographe et si le pion n'est pas deja utilisé
        }
        while(rendu_1 == false || rendu_2 == false);
    }
}
/*********************************************************************************************************/


/**< VERIFICATION DE LA PRESENCE D'UN SEULE ET UNIQUE PION DE LA MEME COULEUR >***************************/
bool Partie::doublon_pion(std::string chaine)
{
    bool rendu = true;

    for(const auto& elem : m_joueurs)
    {
        //parcours du vecteur de joueurs
        if(chaine == elem.get_pion())
        {
            //si les deux chaine sont égales
            rendu = false; //doublon
        }
    }
    return rendu; //rendu du resultat
}
/*********************************************************************************************************/


/*********************************************************************************************************/
bool Partie::couleur_pion(std::string chaine)
{
    //rouge, orange, jaune, vert, bleu, violet
    bool rendu = false;

    if(chaine == "rouge" || chaine == "orange" || chaine == "jaune" || chaine == "vert" || chaine == "bleu" || chaine == "violet")
    {
        //test de l'ecriture
        rendu = true; // si correct rendre vrai
    }

    return rendu; //rendu du resultat
}
/*********************************************************************************************************/


/**< CREATION DES CARTES ALIBI >**************************************************************************/
std::vector <Carte_alibi> Partie::creer_deck_armes()
{
    ///carte armes

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_armes;

    //création des cartes
    Carte_alibi couteau (false, false, true, "Rails");
    Carte_alibi chandelier (false, false, true, "Porte");
    Carte_alibi clef (false, false, true, "Barre");
    Carte_alibi masse (false, false, true, "Strapontin");
    Carte_alibi corde (false, false, true, "Ticket");
    Carte_alibi tourniquet (false, false, true, "Tourniquet");

    //ajout des cartes dans le vecteur d'armes
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

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_lieux;

    //création des cartes
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

    //déclaration du vecteur
    std::vector <Carte_alibi> deck_personnage;

    //création des cartes
    Carte_alibi controleur (true, false, false, "Controleur");
    Carte_alibi conducteur (true, false, false, "Conducteur");
    Carte_alibi agent_secu (true, false, false, "Securite");
    Carte_alibi sdf (true, false, false, "Colleur-affiches");
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
    //création de 3 entier aléatoires
    int rand_1 = rand()%6;
    int rand_2 = rand()%6;
    int rand_3 = rand()%6;

    //création d'un nouveau meurtrier en piochant alétoirement un alibi dans chaque pioche
    Meurtrier murderer(deck_personnages[rand_1], deck_armes[rand_2], deck_lieux[rand_3]);

    //suppression de la carte utlisée pour le meurtrier dans chaque pioche
    deck_personnages.erase(deck_personnages.begin()+ rand_1);
    deck_lieux.erase(deck_lieux.begin()+ rand_2);
    deck_armes.erase(deck_armes.begin()+ rand_3);

    return murderer; //rendu du meurtrier
}
/*********************************************************************************************************/


/**< REALISER UNE ACCUSATION AVEC VERIFICATION AUTOMATIQUE ET EXCLUSION DU JOUEUR >***********************/
bool Partie::accusation_finale(int i)
{
    Meurtrier accusation = m_joueurs[i].formuler_accusation();//recuperation de l(hypothese du joueur
    bool sortie = m_meurtrier.verification_victoire(accusation);//vecrification de l'hypothese et du meurtrier de la partie

    if(sortie == false)
    {
        //l'accusation est fausse
        m_joueurs[i].set_autorisation_jeu(false);//on bloque le jeu du joueur
        std::cout << "L'accusation realisee est fausse " << m_joueurs[i].getPseudo() << " ne peut plus jouer, dommage... " << std::endl;//message
    }

    else
    {
        //accusation correcte
        std::cout << "L'accusation est correcte, vous avez elucide le crime, votre victoire a ete sauvegardee" << std::endl;
        int tempo = m_joueurs[i].getNbVictoire();
        m_joueurs[i].setNbVictoire(tempo+1);
    }

    return sortie;
}
/*********************************************************************************************************/


/**< REALISER UNE HYPOTHESE ET VERIFICATION AVEC LE JOUEUR SUIVANT >**************************************/
void Partie::hypothese_finale(int i, std::string nom_station)
{
    int suivant;
    bool suivant_IA = false;



    Meurtrier hypothese = m_joueurs[i].formuler_hypothese(nom_station);//recuperation de l'hypothèse du joueur

    if(i == Partie::get_nb_joueurs()-1)
    {
        //si l'hypothèse est réalisée par le dernier joueur du vecteur
        suivant = 0;//le joueur suivant est le premier du vecteur
        suivant_IA = true;
    }
    else
    {
        //sinon
        suivant = i+1;//stockage de l'index du joueur suivant
    }

    //test pour savoir si le joueur suivant possède une carte de l'hypothèse formuler
    if(m_joueurs[suivant].get_IA() == false && suivant_IA == false)
        m_joueurs[suivant].validation_hypothese_joueur(m_joueurs[suivant].get_main(), hypothese);
    else if(m_IA[suivant].get_IA() == true && suivant_IA == true)
        m_IA[suivant].verification_hypothese_IA(m_IA[suivant].get_main(), hypothese);


    const std::string location = "data/saves/game/guess.txt";
    std::ofstream fichier;
    fichier.open(location, std::ofstream::app);
    if(!fichier)
    {}
    else
    {
        fichier <<  hypothese.get_perso() <<"\t\t" <<  hypothese.get_lieu() <<"\t\t" <<  hypothese.get_arme() <<"\n";
        fichier.close();
    }
}
/*********************************************************************************************************/


/**< TOUR D'UNE IA >**************************************************************************************/
void Partie::tour_IA(int i)
{
    int suivant;
    bool suivant_IA = false;

    //création des différentes cartes alibi dans des pioches séparées
    std::vector <Carte_alibi> deck_lieux = Partie::creer_deck_lieux();
    std::vector <Carte_alibi> deck_armes = Partie::creer_deck_armes();
    std::vector <Carte_alibi> deck_personnages = Partie::creer_deck_personnage();

    clear_bitmap(screen);
    BITMAP * background = chargerImage("data/bitmap/plateau/background.bmp");
    rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, makecol(177, 177, 177));
    stretch_sprite(screen, background, 0, 0, 950, 525);//(background, screen, 0, 0, background->w, background->h, 0, 0, 950, 525);

    afficher_type(m_IA[i]);

    //génération d'une hypothese
    Meurtrier hypothese_IA = Partie::creer_meurtrier(deck_personnages, deck_lieux, deck_armes);

    //affichage du tour de l'IA;
    system("CLS");
    std::cout << "C'est le tour de " << m_IA[i].getPseudo() << std::endl;
    std::cout << "L'" << m_IA[i].getPseudo() << " realise une hypothese : " << std::endl;

    hypothese_IA.afficher_meurtrier();//affichage de l'hypothese

    if(i == Partie::get_nb_IA()-1)
    {
        //si l'hypothèse est réalisée par le dernier joueur du vecteur
        suivant = 0;//le joueur suivant est le premier du vecteur
        suivant_IA = false;
    }
    else
    {
        //sinon
        suivant = i+1;//stockage de l'index du joueur suivant
        suivant_IA = true;
    }

    if(m_IA[suivant].get_IA() == true && suivant_IA == true)
        m_IA[suivant].verification_hypothese_IA(m_IA[suivant].get_main(), hypothese_IA);
    else if(m_joueurs[suivant].get_IA() == false && suivant_IA == false)
        m_joueurs[suivant].validation_hypothese_joueur(m_joueurs[suivant].get_main(), hypothese_IA);

}
/*********************************************************************************************************/


/**< TOUR D'UN JOUEUR >***********************************************************************************/
bool Partie::tour_joueur(int i, bool & exit)
{
    bool sortie = false, out = false;
    int deplacement = 0, choix = 0, retour_x = 0, retour_y = 0;

    if(m_joueurs[i].get_autorisation() == true)
    {
        //si le joueur à la droit de jouer
        while(out == false && exit == false)
        {
            ///AFFICHAGE ALLEGRO

            Case_plateau case_du_joueur = m_board.get_case_plateau(m_joueurs[i].get_pos_x(), m_joueurs[i].get_pos_y()); //recuperation de la case actuelle du joueur


            bool joueur_en_station = case_du_joueur.get_station();
            std::string nom_station = case_du_joueur.get_nom_station();

            actualiser_allegro(i);

            choix = m_joueurs[i].jouer_tour(deplacement, joueur_en_station, nom_station); //recuperation du choix d'action du joueur et de son déplacement

            std::cout << std::endl;

            switch(choix)
            {
            case 1: //déplacement
                m_board.deplacement(m_joueurs[i].get_pos_x(), m_joueurs[i].get_pos_y(), deplacement, retour_x, retour_y, m_joueurs, i);
                m_joueurs[i].set_pos_x(retour_x);
                m_joueurs[i].set_pos_y(retour_y);
                out = true;
                break;


            case 2: //hypothèse
                Partie::hypothese_finale(i, case_du_joueur.get_nom_station());
                out = true;
                break;

            case 3: //réaliser une accusation
                sortie = Partie::accusation_finale(i);
                out = true;
                break;

            case 4://historique des guess
                system("start notepad \"data\\saves\\game\\guess.txt\"");
                out = true;
                break;

            case 5: //passer son tour
                out = true;
                break;

            case 6://menu pause
                exit = Partie::pause();

            }
            if(choix == 1)
            {
                actualiser_allegro(i);
            }

        }

    }
    else
    {
        //le joueur est interdit de jouer, affichage d'un message
        system("CLS");
        std::cout << "Desole " << m_joueurs[i].getPseudo() << " tu ne peux toujours pas jouer !" << std::endl;
    }
    return sortie; //rendre vrai si victoire
}
/*********************************************************************************************************/

void Partie::actualiser_allegro(int i)
{
    clear_bitmap(screen); //nettoyage de l'ecran
    show_mouse(NULL); //suppression de la sourie

    BITMAP * background = chargerImage("data/bitmap/plateau/background.bmp"); //cargerment du plateau
    BITMAP * buffer_1 = creerBuffer(SCREEN_W, SCREEN_H, "buffer");

    rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, makecol(177, 177, 177)); //affichage du fond
    rectfill(buffer_1, 0, 0, SCREEN_W, SCREEN_H, makecol(255, 0, 255));

    stretch_sprite(screen, background, 0, 0, 950, 525); // affichage du plateau //(background, screen, 0, 0, background->w, background->h, 0, 0, 950, 525);

    afficher_type(m_joueurs[i]); //affichage allegro de ses informations
    m_board.affichage_joueur_allegro(m_joueurs, buffer_1);

    stretch_sprite(screen, buffer_1, 0, 0, SCREEN_W, SCREEN_H);
    m_joueurs[i].afficher_main_allegro(); //affichage de la main du joueur

    show_mouse(screen); //affichage de la souris

    destroy_bitmap(buffer_1);
    destroy_bitmap(background);
}



/**< MENU PAUSE >*****************************************************************************************/
bool Partie::pause()
{
    int choix_utilisateur;
    bool rendu = false;

    ///AFFICHAGE ALLEGRO
    BITMAP * background = chargerImage("data/bitmap/menu/pause.bmp");
    stretch_blit(background, screen, 0, 0, background->w, background->h, 0, 0, SCREEN_W, SCREEN_H);
    show_mouse(screen);
    destroy_bitmap(background);

    do
    {
        do
        {
            //blindage
            system("CLS"); //nettoyage ecran

            std::cout<<"\t\t   ________    __  ____________  ____ "   << std::endl;
            std::cout<<"\t\t  / ____/ /   / / / / ____/ __ \\/ __ \\"  << std::endl;
            std::cout<<"\t\t / /   / /   / / / / __/ / / / / / / /"   << std::endl;
            std::cout<<"\t\t/ /___/ /___/ /_/ / /___/ /_/ / /_/ / "   << std::endl;
            std::cout<<"\t\t\\____/_____/\\____/_____/_____/\\____/  "   << std::endl;
            std::cout<<"                                      "   << std::endl;
            std::cout<<"\t\t       ____  ___  __________          "   << std::endl;
            std::cout<<"\t\t      / __ \\/   |/_  __/ __ \\         "   << std::endl;
            std::cout<<"\t\t     / /_/ / /| | / / / /_/ /         "   << std::endl;
            std::cout<<"\t\t    / _, _/ ___ |/ / / ____/          "   << std::endl;
            std::cout<<"\t\t   /_/ |_/_/  |_/_/ /_/               "   << std::endl << std::endl << std::endl;



            //affichage
            std::cout << "\t\t           MENU PAUSE           " << std::endl << std::endl << std::endl;
            std::cout << "\t\t  1- Reprendre                  " << std::endl << std::endl;
            std::cout << "\t\t  2- Sauvegarder                " << std::endl << std::endl;
            std::cout << "\t\t  3- Sauvegarder et quitter     " << std::endl << std::endl;
            std::cout << "\t\t  4- Quitter                    " << std::endl << std::endl;

            std::cout << std::endl << "\t\t\t Choix : ";

            //saisie
            std::cin>>choix_utilisateur;

        }
        while(choix_utilisateur>4 || choix_utilisateur<1);

        switch(choix_utilisateur)
        {
        case 1 ://reprendre
            break;

        case 2 ://suavegarder
            sauvegarde_partie();
            break;

        case 3 ://sauvegarder et quitter
            sauvegarde_partie();
            rendu = true;
            break;

        case 4 ://quitter
            rendu = true;
            break;
        }
    }
    while(choix_utilisateur == 2);

    return rendu;
}
/*********************************************************************************************************/


/**< BOUCLE DE JEU >**************************************************************************************/
void Partie::lancer_partie ()
{
    bool sortie = false, out = false;

    while(sortie == false)
    {
        //boucle de jeu

        for(int i=0; i<Partie::get_nb_tot_joueur(); i++)
        {
            //parcours pour le nombre total de joueur
            if(i<Partie::get_nb_joueurs())
            {
                //si l'index i est un joueur
                sortie = tour_joueur(i, out); //tour du joueur

                if(sortie == true)
                {
                    //en cas de victoire
                    //incrementation du nombre de victoire du gagnant
                    int temp = m_joueurs[i].getNbVictoire();
                    m_joueurs[i].setNbVictoire((temp +1));
                    incrementation_victoire();

                    //sauvegarde de sa victoire
                    sauvegarde_victoire(m_joueurs[i].getPseudo(), m_meurtrier.get_perso(), m_meurtrier.get_lieu(), m_meurtrier.get_arme(), m_tour);

                    //sauvegarde des profils de joueurs
                    for(size_t k=0; k<m_joueurs.size(); k++)
                    {
                        m_joueurs[k].sauvegarde_joueur();
                    }
                    i = 100;//sortie de boucle

                }
                if(out == true)
                {
                    //quitter le jeu sans victoire
                    i = 100;
                    sortie = true;
                }

            }
            else if(i<Partie::get_nb_tot_joueur() && i>=Partie::get_nb_joueurs() && Partie::get_nb_IA() != 0)
            {
                //si l'index i est une IA
                int index = i-Partie::get_nb_joueurs(); //calcul de l'index de l'IA
                tour_IA(index); //tour de l'IA
            }
            system("pause");
        }
        m_tour++;
    }
}
/*********************************************************************************************************/





/**< SAUVEGARDE CONFIGURATION >***************************************************************************/
void Partie::sauvegarde_config()
{
    //ouverture du fichier
    std::ofstream fichier;
    fichier.open("data/saves/game/config.txt");

    if(fichier.is_open())
    {
        //si fichier est ouvert
        fichier << Partie::m_nb_joueur << "\t\t" << Partie::m_nb_IA << "\t\t" << Partie::m_tour; //sauvegarde des paramètres de parties
        fichier.close();//fermeture du fichier
    }
}
///
void Partie::recup_config()
{
    int nb_joueurs, nb_IA, tour;
    std::ifstream fichier;

    fichier.open("data/saves/game/config.txt");

    if(fichier.is_open())
    {
        fichier >> nb_joueurs;
        fichier >> nb_IA;
        fichier >> tour;
        fichier.close();

        Partie::set_nb_tour(tour);
        Partie::set_nb_joueur(nb_joueurs);
        Partie::set_nb_IA(nb_IA);
    }
}
/*********************************************************************************************************/


/**< SAUVEGARDE PARTIE >**********************************************************************************/
void Partie::sauvegarde_partie()
{
    rectfill(screen, 0, 0, SCREEN_W, 30, makecol(0, 255, 0));
    textout_ex(screen, font, "            sauvegarde effectuee ! ", 30, 10, makecol(255,255,255), -1);

    Partie::sauvegarde_config();
    Partie::sauvegarder_joueurs();
    Partie::sauvegarde_meurtrier();
}
///
void Partie::recuperation_tot_partie()
{
    Partie::recup_config();
    Partie::recuperation_joueurs();
    Partie::recuperation_meurtrier();
}
/*********************************************************************************************************/


/**< SAUVEGARDE MEURTRIER >*******************************************************************************/
void Partie::recuperation_meurtrier()
{
    std::ifstream fichier;

    fichier.open("data/saves/game/meurtrier.txt");

    bool bool_arme_1, bool_lieu_1, bool_perso_1, bool_arme_2, bool_lieu_2, bool_perso_2, bool_arme_3, bool_lieu_3, bool_perso_3;
    std::string spec_1, spec_2, spec_3;

    if(fichier.is_open())
    {
        fichier >> bool_arme_1;
        fichier >> bool_lieu_1;
        fichier >> bool_perso_1;
        fichier >> spec_1;

        Carte_alibi arme (false, false, true, spec_1);

        fichier >> bool_arme_2;
        fichier >> bool_lieu_2;
        fichier >> bool_perso_2;
        fichier >> spec_2;

        Carte_alibi lieu (false, true, false, spec_2);

        fichier >> bool_arme_3;
        fichier >> bool_lieu_3;
        fichier >> bool_perso_3;
        fichier >> spec_3;

        Carte_alibi perso (true, false, false, spec_3);

        Meurtrier builder (perso, arme, lieu);

        m_meurtrier = builder;
        fichier.close();
    }
}
///
void Partie::sauvegarde_meurtrier()
{
    m_meurtrier.sauvegarde();
}
/*********************************************************************************************************/


/**< SAUVEGARDE JOUEURS >*********************************************************************************/
void Partie::recuperation_joueurs()
{
    std::string nom_sauvegarde, fichier;

    std::string const location = "data/saves/game/joueur_in_game.txt";

    std::string pseudo, grade, carac, pion;
    int nbPartie, autorisation, nbVictoire, pos_x, pos_y, nb_cartes, lieu, arme, personnage;

    //ouverture du fichier en mode écriture sans supprimer ce qui est déjà écrit
    std::ifstream f;
    f.open(location);

    //test si le fichier est bien ouvert
    if(!f)
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    else
    {

        for(int i=0; i<m_nb_joueur; i++)
        {
            std::vector <Carte_alibi> main_joueur;
            //récupération des divers éléments de la sauvegarde
            f >> pseudo;
            f >> pion;
            f >> grade;
            f >> nbPartie;
            f >> nbVictoire;
            f >> autorisation;
            f >> pos_x;
            f >> pos_y;

            f >> nb_cartes;

            for(int i=0; i<nb_cartes; i++)
            {
                f >> lieu;
                f >> arme;
                f >> personnage;
                f >> carac;

                main_joueur.push_back(Carte_alibi (personnage, lieu, arme, carac));
            }

            m_joueurs.push_back (Joueur (pseudo, nbPartie, nbVictoire, grade, main_joueur, false, false, autorisation, pos_x, pos_y, pion));
        }
        f.close();
    }
}
///
void Partie::sauvegarder_joueurs()
{
    //test si le fichier est bien ouvert

    std::ofstream save;

    save.open("data/saves/game/joueur_in_game.txt");

    if(save.is_open())
    {
        for(int i=0; i<Partie::get_nb_joueurs(); i++)
        {
            m_joueurs[i].sauvegarde_joueur_in_game(save);

        }
        save.close();
    }
}
/*********************************************************************************************************/


/**< SAUVEGARDE VICTOIRES >*******************************************************************************/
void Partie::historique_victoire(int nb_sauv)
{
    std::string const location = "data/saves/victory/passed_victories.txt";
    std::ifstream fichier;
    std::string pseudo, personnage, lieu, arme;
    int tour;

    fichier.open(location, std::ifstream::in);

    if(!fichier)
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    else
    {
        system("CLS");
        for(int i=0; i<nb_sauv; i++)
        {
            fichier >> pseudo;
            fichier >> personnage;
            fichier >> lieu;
            fichier >> arme;
            fichier >> tour;

            std::cout << "Le joueur : " << pseudo << " a gagne en " << tour << " tours en retrouvant le crime suivant : le " << personnage << " a tue a " << lieu << " avec " << arme << "\n";
        }
        fichier.close();
    }
}
///
int Partie::nombre_victoire()
{
    std::string const location = "data/saves/victory/victories_number.txt";
    int nb_victoires = 0;
    std::ifstream fichier;

    fichier.open(location, std::ifstream::in);

    if(!fichier)
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    else
    {
        fichier >> nb_victoires;

        fichier.close();
    }
    return(nb_victoires);
}
///
void Partie::sauvegarde_victoire(std::string pseudo, std::string personnage, std::string lieu, std::string arme, int tour)
{
    std::string const location = "data/saves/victory/passed_victories.txt";
    std::ofstream fichier;

    fichier.open(location, std::ofstream::app);
    if(!fichier)
    {

    }
    else
    {
        fichier << pseudo << "\t\t" << personnage << "\t\t" << lieu << "\t\t" << arme << "\t\t" << tour+1 << "\n";
        fichier.close();
    }
}
///
void Partie::incrementation_victoire()
{
    std::string const location = "data/saves/victory/victories_number.txt";
    int nb_victoires = 0;

    std::ifstream fichier;

    fichier.open(location, std::ifstream::in);

    if(!fichier)
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    else
    {
        fichier >> nb_victoires;

        fichier.close();
    }

    std::ofstream fichier_2;

    fichier_2.open(location);

    if(!fichier_2)
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    else
    {
        fichier_2 << (nb_victoires+1);

        fichier_2.close();
    }
}
/*********************************************************************************************************/


/**< FONCTION POLYMORPHISME QUI AFFICHE LE TYPE DE JOUEUR >***********************************************/
void Partie::afficher_type(Participant& a)
{
    a.qui_je_suis();
}
/*********************************************************************************************************/
