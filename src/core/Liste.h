#ifndef _LISTE
#define _LISTE

#include "Forme.h"

struct Cellule {
    Forme info;
    Cellule * suivant;
    Cellule * precedent;
};

class Liste {
public:
    /* Données membres */
    /* =============== */
    //!< \class
    Cellule * prem; //!< \var prem : première cellule de la liste
    Cellule * last; //!< \var last : dernière cellule de la liste

    /* Fonctions membres */
    /* ================= */
/**
    \brief Constructeur de la classe Liste, il initialise la liste à vide
*/
    Liste ();
    /* Postcondition : la liste est initialement vide */


/**
    \brief Destructeur de la classe Liste, il permet de libérer la mémoire
    allouée dynamiquement
*/
    ~Liste ();
    /* Postcondition : la mémoire allouée sur le tas est libérée */


/**
    \brief Cette fonction joue le rôle d'opérateur, elle permet de copier une liste
    dans une autre
    \param l : liste à copier dans la liste initiale
*/
    Liste& operator = (const Liste & l);
    /* Postcondition : la liste correspond à une copie de l (mais les 2 listes sont totalement indépendantes l'une de l'autre) */


/**
    \brief Cette fonction a pour but de vider la liste afin qu'elle n'ait plus
    aucune cellule
*/
    void vider ();
    /* Postcondition : la liste ne contient plus aucune cellule */


/**
    \brief Cette fonction a pour but de renseigner si la liste est vide ou non
    \return Elle retourne un booléen qui est vrai si la liste est vide et faux sinon
*/
    bool estVide () const;
    /* Résultat : vrai si liste vide, faux sinon */


/**
    \brief Cette fonction a pour but de renvoyer le nombre d'éléments de la liste
    \return Elle retourne un entier qui correspond au nombre d'éléments contenus
    dans la liste
*/
    unsigned int nbElements () const;
    /* Résultat : nombre d'éléments contenus dans la liste */


/**
    \brief Cette fonction a pour but de renvoyer la forme contenue à un
    indice précis de la liste
    \param indice : indice de la cellule de la liste
    \return Elle retourne un objet de la classe Forme
*/
    Forme iemeElement (unsigned int indice) const;
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'éléments
       Résultat : valeur de l'élément à l'indice en paramètre, sachant que les éléments sont numérotes à partir de 0 */


/**
    \brief Cette fonction a pour but de modifier l'élément à l'indice passé en
    paramètre avec la forme passée également en paramètre
    \param indice : entier correspondant à l'indice de la cellule à modifier
    \param f : objet de la classe Forme
*/
    void modifierIemeElement (unsigned int indice,Forme f);
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'éléments
       Postcondition : e remplace l'élément à l'indice en paramètre, sachant que les éléments sont numérotes à partir de 0 */


/**
    \brief Cette fonction a pour but d'ajouter un objet de la classe Forme
    au début de la liste
    \param f : objet de la classe Forme
*/
    void ajouterEnTete (Forme f);
    /* Postcondition : e est ajouté en tête de liste */


/**
    \brief Cette fonction a pour but d'ajouter un objet de la classe Forme
    à la fin de la liste
    \param f : objet de la classe Forme
*/
    void ajouterEnQueue (Forme f);
    /* Postcondition : e est ajouté en fin de liste */

/**
    \brief Cette fonction a pour but de supprimer la cellule
    au début de la liste

*/
    void supprimerTete ();
    /* Precondition : la liste n'est pas vide
       Postcondition : la liste perd son premier élément */

/**
    \brief Cette fonction a pour but d'insérer un objet de la classe Forme
    à un indice précis de la liste
    \param f : objet de la classe Forme à ajouter
    \param indice : position dans la liste où l'on souhaite ajouter l'objet
*/
    void insererElement (Forme f, unsigned int indice);
    /* Preconditions : 0 <= indice <= nombre d'éléments
       Postconditions : une copie indépendante de e est insérée de sorte qu'elle occupe la position d'indice en paramètre */

};

#endif
