/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_CHANCE_H_INCLUDED
#define HEADER_CHANCE_H_INCLUDED
/*********************************************************************************************************/

#include "header_carte.h"

/**< CLASSES >********************************************************************************************/
class Carte_chance
{
    private :

        ///variables privées
        bool m_malus;
        bool m_bonus;

        std::string m_description;

        int m_valeur;

    public :

        ///constructeurs
        Carte_chance(); //defaut
        Carte_chance(bool _malus, bool _bonus, std::string _description, int _valeur); //surchargé

        ///destructeur
        ~Carte_chance();

        ///methods
        //getters
        bool get_malus() const;
        bool get_bonus() const;

        std::string get_descritpion() const;

        int get_valeur() const;

        Carte_chance * get_pointeur();

        //setters
        void set_malus(bool valeur);
        void set_bonus(bool valeur);

        void set_descritpion(std::string chaine);

        void set_valeur(int valeur);

        void afficher_carac();

};
/*********************************************************************************************************/


#endif // HEADER_CHANCE_H_INCLUDED
