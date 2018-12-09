#ifndef _FORME
#define _FORME

class Forme
{
    private :
    //!< \class
        int taille; //!< \var taille : entier correspondant à la hauteur de la forme
        bool mortel; //!< \var mortel : booléen correspondant à la mortalité du personnage si il touche la forme
        bool fin; //!< \var fin : booléen correspondant à la finalité du monde

    public :

/**
    \brief Constructeur de la classe Forme, il initialise la taille
    de la forme à 0 et qu'elle n'est pas mortelle
*/
        Forme();

/**
    \brief Constructeur de la classe Forme, il initialise la forme
    avec une taille et une mortalité prise en paramètres
    \param t : taille de la forme à définir
    \param m : booléen correspondant à la mortalité de la forme à définir
*/
        Forme(const int & t,const bool & m);

/**
    \brief Constructeur de la classe Forme, il initialise la forme
    avec une taille et une mortalité prise en paramètres
    \param t : taille de la forme à définir
    \param m : booléen correspondant à la mortalité de la forme à définir
    \param f : booléen correspondant au fait que la forme soit la fin du monde
    ou non
*/
        Forme(const int & t,const bool & m, const bool & f);

/**
    \brief Destructeur de la classe Forme
*/
        ~Forme();

/**
    \brief Cette fonction joue le rôle de mutateur, elle modifie la taille
    de la forme avec l'entier pris en paramètre
    \param t : taille de la forme
*/
        void setTaille(const int & t);
/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    la taille de la forme
    \return Elle retourne un entier correspondant à la taille de la forme voulue
*/
        int getTaille()const;

/**
    \brief Cette fonction joue le rôle de mutateur, elle modifie la mortalité
    de la forme avec le booléen pris en paramètre
    \param m : mortalité de la forme
*/
        void setMortel(const bool &m);

/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    la mortalité de la forme
    \return Elle retourne un booléen correspondant à la mortalité
    de la forme voulue
*/
        bool getMortel()const;

/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    si l'élément est la fin du jeu
    \return Elle retourne un booléen correspondant à la fin ou non
    de la forme voulue
*/
        bool getFin()const;

/**
    \brief Cette fonction permet de tester les différentes
    fonctions de cette classe
*/
        void testRegression();

};

#endif
