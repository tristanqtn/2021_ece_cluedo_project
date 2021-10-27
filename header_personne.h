/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PERSONNE_H_INCLUDED
#define HEADER_PERSONNE_H_INCLUDED
/*********************************************************************************************************/


/**< CLASSES >********************************************************************************************/
class Personne
{
    private:
        std::string m_nom;
        std::string m_prenom;

    public:

        Personne();
        Personne(std::string _nom, std::string _prenom);
        ~Personne();

        std::string get_nom() const;
        std::string get_prenom() const;

        void set_nom(std::string value);
        void set_prenom(std::string value);

        void affichage() const;
};
/*********************************************************************************************************/


#endif // HEADER_PERSONNE_H_INCLUDED
