#ifndef MONDE_H_INCLUDED
#define MONDE_H_INCLUDED

#include "Liste.h"
#include <iostream>
using namespace std;
#include <vector>

class Monde
{
    private:
    //!< \class
        vector<Forme> stock;//!< \var stock : tableau Vector des différentes Formes possibles
        vector<int> tab; //!< \var tab : tableau Vector représentant le monde
    public:

/**
    \brief Constructeur de la classe Monde, il initialise le monde défini par
    l'entier passé en paramètre
    \param i : entier correspondant à un entier
*/
        Monde(const int &i);

/**
    \brief Destructeur de la classe Monde
*/
        ~Monde();

/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de
    récupérer les entiers correspondant aux formes constituant le monde
    \return Elle retourne un tableau d'entiers correspondant aux formes
*/
        vector<int> getForme()const;

/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    une forme à un indice précis passé en paramètre
    \param i : indice correspondant à la forme voulue
    \return Elle retourne la forme du tableau située à l'indice i
*/
        const Forme& getFormePosI(const int & i)const;

/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    l'entier correspondant à la forme à un indice précis passé en paramètre
    \param i : indice correspondant à la forme voulue
    \return Elle retourne l'entier correspondant à une forme précise située à
    l'indice i dans le tableau
*/
        int getEntierPosI(const int & i) const;//return tab[i]

/**
    \brief Cette fonction permet de tester les différentes
    fonctions de cette classe
*/
        void testRegression();
};



#endif // MONDE_H_INCLUDED
