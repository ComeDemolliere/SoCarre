#ifndef WINTXT_H
#define WINTXT_H

class WinTXT {

private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief hauteur
    char* win;      //!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D

public:

/**
    \brief Constructeur de la classe WinTXT, elle initialise une nouvelle fenetre
     avec les dimensions prises en paramètre
     \param dx : dimension de la fenêtre selon l'axe X
     \param dy : dimension de la fenêtre selon l'axe Y
*/
    WinTXT (int dx, int dy);

/**
    \brief Destructeur de la classe WinTXT
*/
    ~WinTXT();

/**
    \brief Cette fonction permet de nettoyer la fenêtre avec un caractère passé
    en paramètre
    \param c : caractère qui permettra de nettoyer la fenêtre
*/
    void clear (char c=' ');

/**
    \brief Cette fonction permet d'afficher un certain caractère passé en
    paramètre à un endroit précis de la fenetre
    \param x : entier correspondant à la position du caractère à afficher
    selon l'axe X
    \param y : entier correspondant à la position du caractère à afficher
    selon l'axe Y
    \param c : caractère à afficher
*/
    void print (int x, int y, char c);

/**
    \brief Cette fonction permet d'afficher un pointeur sur un caractère
    passé en paramètre à un endroit précis de la fenetre
    \param x : entier correspondant à la position du caractère à afficher
    selon l'axe X
    \param y : entier correspondant à la position du caractère à afficher
    selon l'axe Y
    \param c : caractère à afficher
*/
    void print2 (int x, int y, char* c);

/**
    \brief Cette fonction permet de dessiner un caractère à une position
    précise passée en paramètre
    \param x : position du caractère selon l'axe X
    \param y : position du caractère selon l'axe Y
*/
    void draw (int x=0, int y=0);

/**
    \brief Cette fonction permet de mettre le jeu en pause grâce à une touche
*/
    void pause();

/**
    \brief Cette fonction permet de lire un caractère si une touche est pressée
    \return Elle retourne un caractère
*/
    char getCh();

};

void termClear ();

#endif
