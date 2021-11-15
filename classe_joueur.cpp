#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_meurtrier.h"
#include "header_principal.h"


/*********************************************************************************************************/
/**< PARTICIPANT >****************************************************************************************/
/*********************************************************************************************************/

/**< CONSTRUCTEURS >**************************************************************************************/
Participant::Participant()
            :m_pseudo(""), m_main(), m_IA(false)
{}

Participant::Participant(std::string _pseudo, std::vector <Carte_alibi> _main, bool _IA)
            :m_pseudo(_pseudo), m_main(_main), m_IA(_IA)
{}
/*********************************************************************************************************/

/**< DESTRUCTEURS >***************************************************************************************/
Participant::~Participant()
{}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Participant::get_IA() const { return m_IA; }
std::string Participant::getPseudo() const { return m_pseudo; }
std::vector <Carte_alibi> Participant::get_main() const { return m_main; }
/*********************************************************************************************************/

/**< SETTERS >********************************************************************************************/
void Participant::setPseudo(std::string pseudo) { m_pseudo = pseudo; }
void Participant::recevoir_carte(Carte_alibi nouvelle_carte) { m_main.push_back(nouvelle_carte); }
/*********************************************************************************************************/


/**< FORMULATION D'UNE HYPOTHESE >************************************************************************/
Meurtrier Participant::formuler_hypothese(std::string nom_station)
{
    std::string arme, personnage;
    std::cout << "Nouvelle hypothese : " << std::endl;

    do
    {
        std::cout << "\t Personnage : ";
        std::cin >> personnage;
    }while(Participant::verification_hypothese_perso(personnage) != true);

    std::cout << "\t Lieu : " << nom_station;


    do
    {
        std::cout << "\t Arme : ";
        std::cin >> arme;
    }while(Participant::verification_hypothese_arme(arme) != true);

    Carte_alibi hypo_lieu(false, true, false, nom_station);
    Carte_alibi hypo_arme(false, false, true, arme);
    Carte_alibi hypo_perso(true, false, false, personnage);

    Meurtrier hypothese (hypo_perso, hypo_arme, hypo_lieu);

    return hypothese;
}
/*********************************************************************************************************/


/*********************************************************************************************************/
void Participant::validation_hypothese_joueur(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese)
{
    bool tempo = false, result = false;

    int nb_commun = 0, nb_montrer = 0, carte_montree=0;

    std::vector <Carte_alibi> cartes_communes;
    std::vector <int > tab_int_tempo;

    for(size_t i=0; i<main_joueur.size(); i++)
    {//parcours de la main du joueur suivant
        tempo = hypothese.verification_carte(main_joueur[i]); //verification de l'égalité de la carte de la main avec l'hypothese
        if(tempo == true)
        {//si accord
            cartes_communes.push_back(main_joueur[i]); //copie de la carte dans un vecteur temporaire
            nb_commun++; //incrementation
            result = true; //on a au moins 1 carte en commun avec l'hypothese
        }
    }

    if(result == true)
    {

        std::cout <<"L'affichage suivant va presenter les cartes du joueur suivant, joueur ayant emis l'hypothese veuillez, vous eloigner de l'ecran" << std::endl;
        system("pause");
        system("CLS");
        std::cout << Participant::getPseudo() << " les cartes en commun que vous avez avec l'hypothese emise par le joueur sont : " << std::endl;

        for(size_t i=0; i<cartes_communes.size(); i++)
        {//affichage au joueur suivant des cartes communes
            cartes_communes[i].afficher_carac();
        }

        do
        {//saisie blindée du nombre de cartes à afficher
            std::cout << std::endl << "Combien de carte souhaitez vous presenter a l'enqueteur ayant emis l'hypothese : ";
            std::cin >> nb_montrer;
        }while(nb_montrer>nb_commun  || nb_montrer<1);


        for(int i=0; i<nb_montrer; i++)
        {//pour le nombre de cartes à afficher
            do
            {//saisie blindée de la position de la carte à afficher
                std::cout << "Quelles cartes souhaitez vous montrer : ";
                std::cin >> carte_montree;
            }while(carte_montree>nb_commun || carte_montree<=0);

            tab_int_tempo.push_back(carte_montree-1);//stockage de la valeur dans un vecteur d'entiers
        }

        std::cout << "Les cartes choisies vont etre devoilees au joueur" << std::endl;
        system("pause");
        system("CLS");
        std::cout << "Le joueur suivant vous montre la/les cartes suivantes : " << std::endl;

        for(int j=0; j<nb_commun; j++)
        {//pour le nombre de cartes en commun
            for(size_t i =0; i<tab_int_tempo.size(); i++)
            {//pour le nombre de cartes à afficher et leur rang
                if(j == tab_int_tempo[i])
                    cartes_communes[j].afficher_carac(); //affichage des caractéristique de la carte
            }

        }
    }
    else
    {//sinon message
                std::cout << "Le joueur suivant n'a aucun des carte de votre hypothese" << std::endl;
    }
}
/*********************************************************************************************************/


/*********************************************************************************************************/
void Participant::verification_hypothese_IA(std::vector <Carte_alibi> main_joueur, Meurtrier hypothese)
{
    bool tempo = false, result = false;

    int nb_commun = 0;

    std::vector <Carte_alibi> cartes_communes;
    std::vector <int > tab_int_tempo;

    for(size_t i=0; i<main_joueur.size(); i++)
    {//parcours de la main du joueur suivant

        tempo = hypothese.verification_carte(main_joueur[i]); //verification de l'égalité de la carte de la main avec l'hypothese
        if(tempo == true)
        {//si accord
            cartes_communes.push_back(main_joueur[i]); //copie de la carte dans un vecteur temporaire
            nb_commun++; //incrementation
            result = true; //on a au moins 1 carte en commun avec l'hypothese
        }
    }

    if(result == true)
    {//si 1 carte en commun, affichage d'une carte au hazard dans le vecteur de cartes communes
        std::cout << std::endl << "Le joueur suivant vous montre la/les cartes suivantes : " << std::endl;
        cartes_communes[rand()%nb_commun].afficher_carac();

    }
    else
    {//sinon message
        std::cout << "Le joueur suivant n'a aucun des carte de votre hypothese" << std::endl;
    }
}
/*********************************************************************************************************/

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/











/*********************************************************************************************************/
/**< JOUEUR >*********************************************************************************************/
/*********************************************************************************************************/

/**< CONSTRUCTEURS >**************************************************************************************/
//constructeurs par défault
Joueur::Joueur()
       : Participant(), m_nb_partie(0), m_nb_victoire(0), m_grade(""), m_dans_une_piece(false), m_autorisation_jeu(true), m_pos_x(0), m_pos_y(0)
{}

//constructeur surchargé
Joueur::Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade, std::vector <Carte_alibi> _main, bool _IA, bool _piece, bool _autorisation_jeu, int _x, int _y)
       : Participant(_pseudo, _main, _IA), m_nb_partie(_nb_partie), m_nb_victoire(_nb_victoire), m_grade(_grade), m_dans_une_piece(_piece), m_autorisation_jeu(_autorisation_jeu), m_pos_x(_x), m_pos_y(_y)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Joueur::~Joueur() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Joueur::get_autorisation() const { return m_autorisation_jeu; }


int Joueur::getNbPartie() const { return m_nb_partie; }
int Joueur::getNbVictoire() const { return m_nb_victoire; }

std::string Joueur::getGrade() const { return m_grade; }

int Joueur::get_pos_x() const { return m_pos_x;}
int Joueur::get_pos_y() const { return m_pos_y;}

void Joueur::set_pos_x(int x)
{
    if(x >= 0 && x < 15)
        m_pos_x = x;
    else
        m_pos_x = 0;
}

void Joueur::set_pos_y(int y)
{
    if(y >= 0 && y < 15)
        m_pos_y = y;
    else
        m_pos_y = 0;
}
/*********************************************************************************************************/


/**< SETTERS>*********************************************************************************************/
void Joueur::setNbPartie(int nbPartie)
{   if(nbPartie>=0)
        m_nb_partie = nbPartie;
    else
        m_nb_partie = 0;
}

void Joueur::setNbVictoire(int nbVictoire)
{
    if(nbVictoire>=0)
        m_nb_victoire = nbVictoire;
    else
        m_nb_victoire = 0;
}

void Joueur::setGrade(std::string grade) { m_grade = grade; }

void Joueur::set_autorisation_jeu(bool valeur) { m_autorisation_jeu = valeur; }
/*********************************************************************************************************/


/**< RENDU DU POINTEUR SUR JOUEUR >***********************************************************************/
Joueur * Joueur::get_pointer() { return this; }
/*********************************************************************************************************/


/**< AFFICHAGE DONNEES DU JOUEUR >************************************************************************/
void Joueur::afficher_le_joueur()
{
    std::cout << "Pseudo : " << getPseudo() << std::endl;
    std::cout << "Nombre de Partie jouee : " << getNbPartie() << std::endl;
    std::cout << "Nombre de victoire : " << getNbVictoire() << std::endl;
    std::cout << "Grade : " << getGrade() << std::endl;
    std::cout << std::endl;
    Joueur::afficher_tour();
}
/*********************************************************************************************************/


/**< AFFICHAGE DE LA MAIN DU JOUEUR >*********************************************************************/
void Joueur::afficher_tour() const
{
    std::cout << "****** MAIN DE L'ENQUETEUR ******" << std::endl;

    for(const auto& elem : m_main)
    {//parcours de la main du joueur
        elem.afficher_carac(); //affichage de chaques cartes
    }
    std::cout << "*********************************" << std::endl;
}
/*********************************************************************************************************/


/**< TOUR D'UN JOUEUR >***********************************************************************************/
int Joueur::jouer_tour(int& deplacement, bool joueur_en_station, std::string nom_station)
{
    int choix;
    system("CLS");
    std::cout << "C'est le tour de " << Joueur::getPseudo() << std::endl;
    if(nom_station == "trajet")
        std::cout << "Vous etes dans un wagon entrain de vous deplacer" << std::endl;
    else
        std::cout << "Vous etes dans la station : " << nom_station << std::endl;
    std::cout << "Le de roule";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << ".";

    deplacement = (rand()%6)+1;

    std::cout << "\tle resultat est : " << deplacement << std::endl;
    std::cout << std::endl;
    Joueur::afficher_tour();

    if(joueur_en_station == true)
    {
        std::cout << std::endl;
        std::cout << "Actions possibles : " << std::endl;
        std::cout << "\t 1- Se deplacer" << std::endl;
        std::cout << "\t 2- Formuler une hypothese" << std::endl;
        std::cout << "\t 3- Formuler une accusation" << std::endl;
        std::cout << "\t 4- Passer le tour" << std::endl;

        do
        {//saisie blindée de choix de l'utilisateur
            std::cout << std::endl <<"\t Choix : ";
            std::cin >> choix;
        }while(choix<1 || choix>4);
    }

    else
    {
        std::cout << std::endl;
        std::cout << "Actions possibles : " << std::endl;
        std::cout << "\t 1- Se deplacer" << std::endl;
        std::cout << "\t 2- Formuler une accusation" << std::endl;
        std::cout << "\t 3- Passer le tour" << std::endl;

        do
        {//saisie blindée de choix de l'utilisateur
            std::cout << std::endl <<"\t Choix : ";
            std::cin >> choix;
        }while(choix<1 || choix>3);
    }



    return choix;
}
/*********************************************************************************************************/


/**< SAUVEGARDE DONNEES DU JOUEUR >***********************************************************************/
void Joueur::sauvegarde()
{
    //réception des données à enregistrer
    std::string pseudo = getPseudo();
    int nbPartie = getNbPartie();
    int nbVictoire = getNbVictoire();
    std::string grade = getGrade();

    //Definition du fichier à rechercher
    std::string const fichier("sauvegarde joueur.txt");

    //ouverture du fichier en mode écriture sans supprimer ce qui est déjà écrit
    std::ofstream f(fichier.c_str(), std::ios::app);

    //test si le fichier est bien ouvert
    if(!f)
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    else
    {
        f << nbPartie << "\t\t" << nbVictoire << "\t\t" << pseudo << "\t\t" << grade << std::endl;
    }
}
/*********************************************************************************************************/


/**< RECUPERATION DES DONNEES D'UN JOUEUR SAUVEGARDE >****************************************************/
void Joueur::lecture_sauvegarde()
{
    std::string pseudo, grade;
    int nbPartie, nbVictoire;

    //Definition du fichier à rechercher
    std::string const fichier("sauvegarde joueur.txt");

    //ouverture du fichier en mode écriture sans supprimer ce qui est déjà écrit
    std::ifstream f(fichier);

    //test si le fichier est bien ouvert
    if(!f)
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    else
    {
        //récupération des divers éléments de la sauvegarde
        f >> nbPartie;
        f >> nbVictoire;
        f >> pseudo;
        f >> grade;
    }
    setNbPartie(nbPartie);
    setNbVictoire(nbVictoire);
    setPseudo(pseudo);
    setGrade(grade);
}
/*********************************************************************************************************/


/**< VERIFICATIONS DE SAISIES >***************************************************************************/
bool Participant::verification_hypothese_arme(std::string chaine)
{//si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Rails" || chaine == "Porte" || chaine == "Barre" || chaine == "Strapontin" || chaine == "Ticket" || chaine == "Tourniquet")
    {
        return true;
    }
    else
        return false;
}

bool Participant::verification_hypothese_lieu(std::string chaine)
{//si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Barbes" || chaine == "Concorde" || chaine == "Chatelet" || chaine == "Trocadero" || chaine == "Bir-Hakeim" || chaine == "Etoile" || chaine == "Vaugirard" || chaine == "Nation" || chaine == "Stalingrad")
    {
        return true;
    }
    else
        return false;
}

bool Participant::verification_hypothese_perso(std::string chaine)
{//si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Controleur" || chaine == "Conducteur" || chaine == "Passager" || chaine == "SDF" || chaine == "Musicien" || chaine == "Securite")
    {
        return true;
    }
    else
        return false;
}
/*********************************************************************************************************/


/**< FORMULATION D'UNE ACCUSATION >************************************************************************/
Meurtrier Joueur::formuler_accusation()
{
    std::string lieu, arme, personnage;
    std::cout << "Nouvelle hypothese : " << std::endl;

    do
    {
        std::cout << "\t Personnage : ";
        std::cin >> personnage;
    }while(Participant::verification_hypothese_perso(personnage) != true);

    do
    {
        std::cout << "\t Lieu : ";
        std::cin >> lieu;
    }while(Participant::verification_hypothese_lieu(lieu) != true);


    do
    {
        std::cout << "\t Arme : ";
        std::cin >> arme;
    }while(Participant::verification_hypothese_arme(arme) != true);

    Carte_alibi hypo_lieu(false, true, false, lieu);
    Carte_alibi hypo_arme(false, false, true, arme);
    Carte_alibi hypo_perso(true, false, false, personnage);

    Meurtrier hypothese (hypo_perso, hypo_arme, hypo_lieu);

    return hypothese;
}
/*********************************************************************************************************/

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/











/*********************************************************************************************************/
/**< IA >*************************************************************************************************/
/*********************************************************************************************************/

/**< CONSTRUCTEURS >**************************************************************************************/
IA::IA()
   :Participant()
{}

IA::IA(std::string _pseudo, std::vector <Carte_alibi> _main, bool _IA)
            :Participant(_pseudo, _main, _IA)
{}
/*********************************************************************************************************/

/**< DESTRUCTEURS >***************************************************************************************/
IA::~IA()
{}
/*********************************************************************************************************/

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
