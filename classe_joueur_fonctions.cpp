#include "header_main.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_partie.h"
#include "header_personnage.h"

/**< CONSTRUCTEURS >**************************************************************************************/
//constructeurs par défault
Joueur::Joueur()
       : m_nb_partie(0), m_nb_victoire(0), m_grade(""), m_pseudo(""), m_pt_enqueteur(NULL)
{}

//constructeur surchargé
Joueur::Joueur(std::string _pseudo, int _nb_partie, int _nb_victoire, std::string _grade, Enqueteur * _pt_enqueteur)
       : m_nb_partie(_nb_partie), m_nb_victoire(_nb_victoire), m_grade(_grade), m_pseudo(_pseudo), m_pt_enqueteur(_pt_enqueteur)
{}
/*********************************************************************************************************/


/**< DESTRUCTEUR >****************************************************************************************/
Joueur::~Joueur() {}
/*********************************************************************************************************/


/**< GETTERS >********************************************************************************************/
int Joueur::getNbPartie() const { return m_nb_partie; }
int Joueur::getNbVictoire() const { return m_nb_victoire; }

std::string Joueur::getGrade() const { return m_grade; }
std::string Joueur::getPseudo() const { return m_pseudo; }
/*********************************************************************************************************/


/**< SETTERS>*********************************************************************************************/
void Joueur::setPseudo(std::string pseudo) { m_pseudo = pseudo; }

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
/*********************************************************************************************************/

/**< AFFICHAGE DONNEES DU JOUEUR >************************************************************************/
void Joueur::afficher_le_joueur()
{
    std::cout << "Pseudo : " << getPseudo() << std::endl;
    std::cout << "Nombre de Partie jouee : " << getNbPartie() << std::endl;
    std::cout << "Nombre de victoire : " << getNbVictoire() << std::endl;
    std::cout << "Grade : " << getGrade() << std::endl;
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
