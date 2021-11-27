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
bool Participant::get_IA() const
{
    return m_IA;
}
std::string Participant::getPseudo() const
{
    return m_pseudo;
}
std::vector <Carte_alibi> Participant::get_main() const
{
    return m_main;
}
/*********************************************************************************************************/

/**< SETTERS >********************************************************************************************/
void Participant::setPseudo(std::string pseudo)
{
    m_pseudo = pseudo;
}
void Participant::recevoir_carte(Carte_alibi nouvelle_carte)
{
    m_main.push_back(nouvelle_carte);
}
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
    }
    while(Participant::verification_hypothese_perso(personnage) != true);

    std::cout << "\t Lieu : " << nom_station;


    do
    {
        std::cout << "\n\t Arme : ";
        std::cin >> arme;
    }
    while(Participant::verification_hypothese_arme(arme) != true);

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
    {
        //parcours de la main du joueur suivant
        tempo = hypothese.verification_carte(main_joueur[i]); //verification de l'égalité de la carte de la main avec l'hypothese
        if(tempo == true)
        {
            //si accord
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
        {
            //affichage au joueur suivant des cartes communes
            cartes_communes[i].afficher_carac();
        }

        do
        {
            //saisie blindée du nombre de cartes à afficher
            std::cout << std::endl << "Combien de carte souhaitez vous presenter a l'enqueteur ayant emis l'hypothese : ";
            std::cin >> nb_montrer;
        }
        while(nb_montrer>nb_commun  || nb_montrer<1);


        for(int i=0; i<nb_montrer; i++)
        {
            //pour le nombre de cartes à afficher
            do
            {
                //saisie blindée de la position de la carte à afficher
                std::cout << "Quelles cartes souhaitez vous montrer : ";
                std::cin >> carte_montree;
            }
            while(carte_montree>nb_commun || carte_montree<=0);

            tab_int_tempo.push_back(carte_montree-1);//stockage de la valeur dans un vecteur d'entiers
        }

        std::cout << "Les cartes choisies vont etre devoilees au joueur" << std::endl;
        system("pause");
        system("CLS");
        std::cout << "Le joueur suivant vous montre la/les cartes suivantes : " << std::endl;

        for(int j=0; j<nb_commun; j++)
        {
            //pour le nombre de cartes en commun
            for(size_t i =0; i<tab_int_tempo.size(); i++)
            {
                //pour le nombre de cartes à afficher et leur rang
                if(j == tab_int_tempo[i])
                    cartes_communes[j].afficher_carac(); //affichage des caractéristique de la carte
            }

        }
    }
    else
    {
        //sinon message
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
    {
        //parcours de la main du joueur suivant

        tempo = hypothese.verification_carte(main_joueur[i]); //verification de l'égalité de la carte de la main avec l'hypothese
        if(tempo == true)
        {
            //si accord
            cartes_communes.push_back(main_joueur[i]); //copie de la carte dans un vecteur temporaire
            nb_commun++; //incrementation
            result = true; //on a au moins 1 carte en commun avec l'hypothese
        }
    }

    if(result == true)
    {
        //si 1 carte en commun, affichage d'une carte au hazard dans le vecteur de cartes communes
        std::cout << std::endl << "Le joueur suivant vous montre la/les cartes suivantes : " << std::endl;
        cartes_communes[rand()%nb_commun].afficher_carac();

    }
    else
    {
        //sinon message
        std::cout << "Le joueur suivant n'a aucun des carte de votre hypothese" << std::endl;
    }
}
/*********************************************************************************************************/


/**< FONCTION POLYMORPHISME >*****************************************************************************/
void Participant::qui_je_suis()
{
    textout_ex(screen, font, "TYPE : Participant", 1000, 100, makecol(0, 0, 0), -1);
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
    : Participant(), m_nb_partie(0), m_nb_victoire(0), m_grade(""), m_dans_une_piece(true), m_autorisation_jeu(true), m_pos_x(0), m_pos_y(0), m_pion("")
{}

//constructeur surchargé
Joueur::Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade, std::vector <Carte_alibi> _main, bool _IA, bool _piece, bool _autorisation_jeu, int _x, int _y, std::string _pion)
    : Participant(_pseudo, _main, _IA), m_nb_partie(_nb_partie), m_nb_victoire(_nb_victoire), m_grade(_grade), m_dans_une_piece(_piece), m_autorisation_jeu(_autorisation_jeu), m_pos_x(_x), m_pos_y(_y), m_pion(_pion)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Joueur::~Joueur() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
bool Joueur::get_autorisation() const
{
    return m_autorisation_jeu;
}

int Joueur::getNbPartie() const
{
    return m_nb_partie;
}
int Joueur::getNbVictoire() const
{
    return m_nb_victoire;
}

std::string Joueur::getGrade() const
{
    return m_grade;
}
std::string Joueur::get_pion() const
{
    return m_pion;
}

int Joueur::get_pos_x() const
{
    return m_pos_x;
}
int Joueur::get_pos_y() const
{
    return m_pos_y;
}

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
{
    if(nbPartie>=0)
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

void Joueur::setGrade(std::string grade)
{
    m_grade = grade;
}
void Joueur::set_pion(std::string pion)
{
    m_pion = pion;
}

void Joueur::set_autorisation_jeu(bool valeur)
{
    m_autorisation_jeu = valeur;
}
/*********************************************************************************************************/


/**< RENDU DU POINTEUR SUR JOUEUR >***********************************************************************/
Joueur * Joueur::get_pointer()
{
    return this;
}
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
    {
        //parcours de la main du joueur
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
    std::cout << "C'est le tour de " << Joueur::getPseudo() << ", pion de couleur : " << Joueur::get_pion() << std::endl;
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

    deplacement = (rand()%12)+1;

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
        std::cout << "\t 4- Relire les hypotheses precedentes" << std::endl;
        std::cout << "\t 5- Passer le tour" << std::endl<<std::endl;
        std::cout << "\t 6- Menu pause" << std::endl;

        do
        {
            //saisie blindée de choix de l'utilisateur
            std::cout << std::endl <<"\t Choix : ";
            std::cin >> choix;
        }
        while(choix<1 || choix>6);
    }

    else
    {
        std::cout << std::endl;
        std::cout << "Actions possibles : " << std::endl;
        std::cout << "\t 1- Se deplacer" << std::endl;

        std::cout << "\t 3- Formuler une accusation" << std::endl;
        std::cout << "\t 4- Relire les hypotheses precedentes" << std::endl;
        std::cout << "\t 5- Passer le tour" << std::endl<<std::endl;
        std::cout << "\t 6- Menu pause" << std::endl;


        do
        {
            //saisie blindée de choix de l'utilisateur
            std::cout << std::endl <<"\t Choix : ";
            std::cin >> choix;
        }
        while(choix<1 || choix>6 || choix == 2);
    }

    return choix;
}
/*********************************************************************************************************/


/**< SAUVEGARDE DONNEES DU JOUEUR >***********************************************************************/
void Joueur::sauvegarde_joueur()
{
    //réception des données à enregistrer
    std::string pseudo = getPseudo();
    int nbPartie = getNbPartie();
    int nbVictoire = getNbVictoire();
    std::string grade = getGrade();

    //Definition du fichier à rechercher
    std::string const adresse("data/saves/players/");
    std::string const extension(".txt");
    std::string fichier;

    fichier = adresse + pseudo + extension;

    //ouverture du fichier en mode écriture sans supprimer ce qui est déjà écrit
    std::ofstream f;
    f.open(fichier);

    //test si le fichier est bien ouvert
    if(!f)
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    else
    {
        f << pseudo << "\t\t" << nbPartie << "\t\t" << nbVictoire << "\t\t" << "\t\t" << grade << std::endl;
    }
    f.close();
}
/*********************************************************************************************************/


/**< VERIFICATIONS DE SAISIES >***************************************************************************/
bool Participant::verification_hypothese_arme(std::string chaine)
{
    //si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Rails" || chaine == "Porte" || chaine == "Barre" || chaine == "Strapontin" || chaine == "Ticket" || chaine == "Tourniquet")
    {
        return true;
    }
    else
        return false;
}

bool Participant::verification_hypothese_lieu(std::string chaine)
{
    //si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Barbes" || chaine == "Concorde" || chaine == "Chatelet" || chaine == "Trocadero" || chaine == "Bir-Hakeim" || chaine == "Etoile" || chaine == "Vaugirard" || chaine == "Nation" || chaine == "Stalingrad")
    {
        return true;
    }
    else
        return false;
}

bool Participant::verification_hypothese_perso(std::string chaine)
{
    //si la chaine de caractere reçue est égale à la descrption d'une carte alibi on rend vrai sinon faux
    if(chaine == "Controleur" || chaine == "Conducteur" || chaine == "Passager" || chaine == "Colleur-affiches" || chaine == "Musicien" || chaine == "Securite")
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
    {//saisie blindée du personnage
        std::cout << "\t Personnage : ";
        std::cin >> personnage;
    }
    while(Participant::verification_hypothese_perso(personnage) != true);

    do
    {//saisie blindée du lieu
        std::cout << "\t Lieu : ";
        std::cin >> lieu;
    }
    while(Participant::verification_hypothese_lieu(lieu) != true);


    do
    {//saisie blindée de l'arme
        std::cout << "\t Arme : ";
        std::cin >> arme;
    }
    while(Participant::verification_hypothese_arme(arme) != true);

    //création des cartes composant l'hypothese
    Carte_alibi hypo_lieu(false, true, false, lieu);
    Carte_alibi hypo_arme(false, false, true, arme);
    Carte_alibi hypo_perso(true, false, false, personnage);

    //création de l'hyptohese
    Meurtrier hypothese (hypo_perso, hypo_arme, hypo_lieu);

    //rendu de l'hypothese
    return hypothese;
}
/*********************************************************************************************************/


/**< SAUVGARDE DES INFORMATION D'UN JOUEUR EN PARTIE >****************************************************/
void Joueur::sauvegarde_joueur_in_game(std::ofstream& fichier)
{//on recupere le fichier ouvert en parametre
    if(fichier.is_open())
    {//si ouvert

        ///SAUVEGARDE DES INFORMATIONS
        fichier << Joueur::getPseudo()<< "\t\t" << Joueur::get_pion() << "\t\t" << Joueur::getGrade() << "\t\t" << Joueur::getNbPartie() << "\t\t" << Joueur::getNbVictoire() << "\t\t" << Joueur::get_autorisation() << "\t\t" << Joueur::get_pos_x() << "\t\t" << Joueur::get_pos_y() << "\t\t" << m_main.size() << "\t\t";

        ///SAUVEGARDE DE LA MAIN
        for(size_t i=0; i<Joueur::m_main.size(); i++)
        {
            fichier << Joueur::m_main[i].get_lieu() << "\t\t" << Joueur::m_main[i].get_arme() << "\t\t" << Joueur::m_main[i].get_personnage() << "\t\t" << Joueur::m_main[i].get_caracteristique() << "\t\t";
        }
        fichier << "\n";
    }
}
/*********************************************************************************************************/


/**< AFFICHAGE SUR ALLEGRO DE LA MAIN DU JOUEUR >**********************************************************/
void Joueur::afficher_main_allegro()
{
    std::vector<BITMAP *> main_joueur;
    BITMAP * image_tempo;
    std::string racine = "data/bitmap/cartes/", extension = ".bmp", temp, location;
    BITMAP * buffer = creerBuffer(SCREEN_W, SCREEN_H, "buffer");

    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, makecol(255, 0, 255)); //création d'un buffer violet

    for(size_t i=0; i<m_main.size(); i++)
    {//pour le nb de cartes en mains
        temp = m_main[i].get_caracteristique(); //recup de la description de la carte

        //passage en minuscule de la description
        for(size_t j=0; j<temp.size(); j++)
        {
            temp[j]=tolower(temp[j]);
        }

        //formation du chemin vers l'illustration
        location = racine + temp;
        location = location + extension;

        const char * lieu = location.c_str();

        image_tempo = chargerImage(lieu);


        main_joueur.push_back(image_tempo); // ajout de la carte au vecteur de bitmap

        //affichage de toutes les cartes du vecteur dans le fentre allegro
        for(size_t j=0; j<main_joueur.size(); j++)
            stretch_sprite(buffer, main_joueur[j], 10+j*200, 550, main_joueur[j]->w/2, main_joueur[j]->h/2);

        //affichage sprite du buffer
        stretch_sprite(screen, buffer, 0, 0, SCREEN_W, SCREEN_H);

    }
    for(size_t i=0; i<m_main.size(); i++)
    {//destruction des cartes
        main_joueur.pop_back();
    }

    //destruction du buffer
    destroy_bitmap(buffer);
}
/*********************************************************************************************************/


/**< FONCTION POLYMORPHISME> *****************************************************************************/
void Joueur::qui_je_suis()
{//affichages indicatifs sur allegro
    std::string phrase_pseudo = "Pseudo : " + m_pseudo;
    const char * affichage_1 = phrase_pseudo.c_str();
    textout_ex(screen, font, affichage_1, 1000, 110, makecol(0, 0, 0), -1);

    textout_ex(screen, font, "TYPE : Joueur", 1000, 90, makecol(0, 0, 0), -1);

    std::string phrase_pion = "Pion : " + m_pion;
    const char * affichage_2 = phrase_pion.c_str();
    textout_ex(screen, font, affichage_2, 1000, 120, makecol(0, 0, 0), -1);
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


/**< FONCTION POLYMORPHISME> *****************************************************************************/
void IA::qui_je_suis()
{
    textout_ex(screen, font, "TYPE : IA", 1000, 90, makecol(0, 0, 0), -1);
    textout_ex(screen, font, "Les IA ne realise que des ", 1000, 110, makecol(0, 0, 0), -1);
    textout_ex(screen, font, "hypotheses et ne se ", 1000, 130, makecol(0, 0, 0), -1);
    textout_ex(screen, font, "deplacement pas sur le plateau", 1000, 140, makecol(0, 0, 0), -1);
}
/*********************************************************************************************************/



/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
