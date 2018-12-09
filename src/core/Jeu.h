#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Personnage.h"
#include "Monde.h"
class Jeu
{
    private:
        Personnage perso; //!< \class
                    //! \var perso : objet de la classe Personnage
        Monde monde; //! < \var monde : objet de la classe Monde
        Liste l; //! < \var l : objet de la classe Liste
        int posActuellePerso; //! < \var posActuellePerso : entier correspondant à la place du personnage actuelle selon l'axe X

    public:

/**
    \brief Constructeur par defaut de la classe Jeu, il permet de creer
*/
        Jeu();

/**
    \brief Destructeur de la classe Jeu, il vide la liste correspondant aux formes du jeu
*/
        ~Jeu();

/**
    \brief Cette fonction joue le role d'accesseur,
    elle permet de recuperer le personnage du jeu
    \return Elle retourne les informations du personnage du jeu
*/
        const Personnage& getPerso()const;


/**
    \brief Cette fonction joue le role de mutateur,
    elle permet de modifier le personnage du jeu avec
    le personnage pris en parametre
    \param personnage : personnage modifiant celui du jeu
*/
        void setPerso(const Personnage & personnage);


/**
    \brief Cette fonction joue le role d'accesseur,
    elle permet de recuperer le monde du jeu
    \return Elle retourne les informations du monde du jeu
*/
        const Monde& getMonde()const;


/**
    \brief Cette fonction joue le role de mutateur,
    elle permet de modifier le monde du jeu avec
    le monde pris en parametre
    \param mo : monde modifiant celui du jeu
*/
        void setMonde(const Monde & mo);


/**
    \brief Cette fonction joue le role d'accesseur,
    elle permet de recuperer la liste des formes du jeu
    \return Elle retourne les informations de la liste du jeu
*/
        Liste* getListe();


/**
    \brief Cette fonction joue le role de mutateur,
    elle permet de modifier la liste du jeu avec
    la liste prise en parametre
    \param l : liste modifiant celle du jeu
*/
        void setListe(const Liste & l);

/**
    \brief Cette fonction joue le role d'accesseur, elle
    permet de recuperer la position actuelle du personnage
    \return Elle retourne un entier qui correspond à la position
    actuelle du personnage
*/

        int getPosActuellePerso()const;

/**
    \brief Cette fonction joue le role de mutateur, elle
    permet de modifier la position actuelle du personnage
    \param pos : entier correspondant à la position du personnage
    à modifier
*/
        void setPosActuellePerso(const int & pos);


/**
    \brief Cette fonction a pour but de gerer les
    collisions du personnage avec les differents obstacles
*/
        void collision(bool & continuer);



/**
    \brief Cette fonction a pour but de generer les actions
    automatiques du jeu au cours de la session de jeu
    \param i : indice permettant d'itérer le jeu
*/
        void actionsAutomatiques(const int &i);


/**
    \brief Cette fonction a pour but de gerer les
    diverses actions liees au clavier comme le saut
    \param carac : touche du clavier pressée par l'utilisateur
*/
        void actionClavier(const char &carac);

/**
    \brief Cette fonction permet de reinitialiser le jeu,
    elle remet le monde du jeu à son debut
	\param mo : monde que l'on souhaite reinitialiser
*/
        void reinitJeu(Monde & mo);

/**
    \brief Cette fonction permet de tester les differentes
    fonctions de cette classe
*/
        void testRegression();

};

#endif // JEU_H_INCLUDED
