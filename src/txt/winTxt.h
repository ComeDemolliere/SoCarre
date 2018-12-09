#ifndef WINTXT_H
#define WINTXT_H

class WinTXT {

private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief hauteur
    char* win;      //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D

public:

/**
    \brief Constructeur de la classe WinTXT, elle initialise une nouvelle fenetre
     avec les dimensions prises en param�tre
     \param dx : dimension de la fen�tre selon l'axe X
     \param dy : dimension de la fen�tre selon l'axe Y
*/
    WinTXT (int dx, int dy);

/**
    \brief Destructeur de la classe WinTXT
*/
    ~WinTXT();

/**
    \brief Cette fonction permet de nettoyer la fen�tre avec un caract�re pass�
    en param�tre
    \param c : caract�re qui permettra de nettoyer la fen�tre
*/
    void clear (char c=' ');

/**
    \brief Cette fonction permet d'afficher un certain caract�re pass� en
    param�tre � un endroit pr�cis de la fenetre
    \param x : entier correspondant � la position du caract�re � afficher
    selon l'axe X
    \param y : entier correspondant � la position du caract�re � afficher
    selon l'axe Y
    \param c : caract�re � afficher
*/
    void print (int x, int y, char c);

/**
    \brief Cette fonction permet d'afficher un pointeur sur un caract�re
    pass� en param�tre � un endroit pr�cis de la fenetre
    \param x : entier correspondant � la position du caract�re � afficher
    selon l'axe X
    \param y : entier correspondant � la position du caract�re � afficher
    selon l'axe Y
    \param c : caract�re � afficher
*/
    void print2 (int x, int y, char* c);

/**
    \brief Cette fonction permet de dessiner un caract�re � une position
    pr�cise pass�e en param�tre
    \param x : position du caract�re selon l'axe X
    \param y : position du caract�re selon l'axe Y
*/
    void draw (int x=0, int y=0);

/**
    \brief Cette fonction permet de mettre le jeu en pause gr�ce � une touche
*/
    void pause();

/**
    \brief Cette fonction permet de lire un caract�re si une touche est press�e
    \return Elle retourne un caract�re
*/
    char getCh();

};

void termClear ();

#endif
