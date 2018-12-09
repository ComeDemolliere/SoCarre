#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED


class Personnage
{
    private : //!< \class
        float posXPerso,posYPerso; /**< \var posXPerso : position du personnage
                                       selon l'axe X */
                                /**< \var posYPerso : position du personnage
                                 selon l'axe Y */
        int dimXPerso,dimYPerso; /**< \var dimXPerso : dimension du personnage
                                selon l'axe X */
                                /**< \var dimYPerso : dimension du personnage
                                selon l'axe Y */
        float posPersoPrec;     /**<  \var posPersoPrec : position précédente
                                 du personnage selon l'axe Y */
        float gravite;          /**< \var gravite : gravité du personnage
                                 lors de son saut */
        bool vivant;            /**< \var vivant : booléen indiquant
                                    l'état du vie ou mort du personnage */

    public:
        //Initialiser notre personnage
/**
    \brief Constructeur par defaut de la classe Personnage
*/
        Personnage();

/**
    \brief Constructeur de la classe Personnage avec la position
     et la dimension du personnage en parametre
     \param positionX : position du personnage selon l'axe X
     \param positionY : position du personnage selon l'axe Y
     \param dimensionX : dimension du personnage selon l'axe X
     \param dimensionY : dimension du personnage selon l'axe Y
*/
        Personnage(const int &positionX,const int &positionY,const int &dimensionX, const int &dimensionY);

/**
    \brief Destructeur de la classe Personnage
*/
        ~Personnage();

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la dimension du personnage selon l'axe X
    \return Elle retourne un entier qui correspond à la dimension
            du personnage selon l'axe X
*/
        int getDimXPerso()const;


/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la dimension du personnage sur l'axe X
    \param dimensionX : dimension qui remplacera la dimension actuelle
    du personnage selon l'axe X
*/
        void setDimXPerso(const int & dimensionX);

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la dimension du personnage selon l'axe Y
    \return Elle retourne un entier qui correspond à la dimension
            du personnage selon l'axe Y
*/
        int getDimYPerso()const;


/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la dimension du personnage sur l'axe Y
    \param dimensionY : dimension qui remplacera la dimension actuelle
    du personnage selon l'axe Y
*/
        void setDimYPerso(const int & dimensionY);



/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la position du personnage selon l'axe X
    \return Elle retourne un entier qui correspond à la position
    du personnage selon l'axe X
*/
        int getPosXPerso()const;


/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la position du personnage sur l'axe X avec la position
    en parametre
    \param positionX : position qui remplacera la position actuelle
    du personnage selon l'axe X
*/
        void setPosXPerso(const int & positionX);

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la position du personnage selon l'axe Y
    \return Elle retourne un entier qui correspond à la position
    du personnage selon l'axe Y
*/
        int getPosYPerso()const;

/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la position du personnage sur l'axe Y avec la position
    en parametre
    \param positionY : position qui remplacera la position actuelle
    du personnage selon l'axe Y
*/
        void setPosYPerso(const int & positionY);

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la position precedente du personnage selon l'axe Y
    \return Elle retourne un entier qui correspond à la position
    precedente du personnage selon l'axe Y
*/
        int getPosPersoPrec()const;

/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la position precedente du personnage sur l'axe Y
    avec la position en parametre
    \param position : position precedente qui remplacera la position
    du personnage selon l'axe Y
*/
        void setPosPersoPrec(const int & position);

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer la gravite du personnage
    \return Elle retourne un entier qui correspond à la gravite
    du personnage
*/
        int getGravite()const;

/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la gravite du personnage avec la gravite prise
    en parametre
    \param gra : gravite du personnage qui remplacera la gravite actuelle
*/
        void setGravite(const int &gra);

/**
    \brief Cette fonction joue le role d'accesseur, elle permet
    de recuperer le booleen correspondant a la notion de vie ou mort
    du personnage
    \return Elle retourne un booleen qui represente si le personnage est
    vivant ou mort
*/
        bool getVivant()const;

/**
    \brief Cette fonction joue le role de mutateur, elle permet
    de modifier la notion de vie ou mort du personnage
    \param viv : booleen qui remplace la notion de vie ou de mort
    du personnage
*/
        void setVivant(const bool & viv);

 /**
    \brief Cette fonction a pour but de gerer les mouvements
    du personnage en prenant un parametre un evenement precis
    \param event : touche selectionnee par l'utilisateur
 */
        void mouvementPerso(const char &event);

/**
    \brief Cette fonction permet de tester les differentes fonctions
    de cette classe
*/
        void testRegression();



};

#endif // PERSONNAGE_H_INCLUDED
