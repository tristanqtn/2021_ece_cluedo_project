/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PERSONNAGE_H_INCLUDED
#define HEADER_PERSONNAGE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_carte.h"
/*********************************************************************************************************/


/**< CLASSES >********************************************************************************************/
///Meurtirer
class Meurtrier
{
    private :
        Carte_alibi m_carte_personnage;
        Carte_alibi m_carte_arme;
        Carte_alibi m_carte_lieu;

    public :

        Meurtrier();
        Meurtrier(Carte_alibi _carte_personnage,Carte_alibi  _carte_arme,Carte_alibi  _carte_lieu);
        ~Meurtrier();

        void afficher_meurtrier() const;
};
///



///ENQUETEUR
class Enqueteur
{
    private :
        std::vector <Carte_alibi> m_main;
        std::string m_pion;
        std::string m_nom;
        std::string m_prenom;

    public :

        Enqueteur();
        Enqueteur(std::vector <Carte_alibi> _main, std::string _pion, std::string _nom, std::string _prenom);
        ~Enqueteur();

        void afficher_main() const;
        void afficher_ID() const;

        std::string get_pion() const;
        std::string get_prenom() const;
        std::string get_nom() const;

        std::vector <Carte_alibi> get_main() const;

        Enqueteur * get_pointer();

};
/*********************************************************************************************************/

#endif // HEADER_PERSONNAGE_H_INCLUDED
