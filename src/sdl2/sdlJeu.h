#ifndef SDLJEU_H_INCLUDED
#define SDLJEU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#include "../core/Jeu.h"

class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
/**
    \brief Constructeur par défaut de la classe Image, elle met ses différentes
    variables à NULL
*/
    Image () ;

/**
    \brief Cette fonction permet de charger une image à partir d'une image précise
    dont le chemin est passé en paramètre sur un rendu
    \param filename : chemin de l'image souhaitée
    \param renderer : rendu sur lequel l'image sera affichée
*/
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
/**
    \brief Cette fonction permet d'afficher un rendu texte sur la surface
    \param renderer : rendu que l'on souhaite afficher
*/
    void loadFromCurrentSurface (SDL_Renderer * renderer);

/**
    \brief Cette fonction permet de dessiner une image sur un rendu en
    choisissant ses dimensions
    \param renderer : rendu sur lequel on souhaite dessiner
    \param x : position du début de l'image sur l'axe X
    \param y : position du début de l'image sur l'axe Y
    \param w : position de la fin de l'image sur l'axe X
    \param h : position de la fin de l'image sur l'axe Y
*/

    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

/**
    \brief Cette fonction permet de dessiner une image sur un rendu en
    choisissant quelle partie de l'image il faut dessiner
    \param renderer : rendu sur lequel on souhaite dessiner
    \param x : position du début de l'image sur l'axe X
    \param y : position du début de l'image sur l'axe Y
    \param w : position de la fin de l'image sur l'axe X
    \param h : position de la fin de l'image sur l'axe Y
*/
    void draw2 (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);


/**
    \brief Cette fonction joue le rôle d'accesseur, elle permet de récupérer
    une texture SDL
    \return Elle renvoie la texture souhaitée
*/
    SDL_Texture * getTexture() const;
/**
    \brief Cette fonction joue le rôle de mutateur, elle permet de modifier
    une texture SDL avec celle passée en paramètre
    \param surf : texture permettant de modifier la texture actuelle
*/
    void setSurface(SDL_Surface * surf);
};


/**
    La classe gérant le jeu avec un affichage SDL
*/
class sdlJeu {

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    SDL_Color font_color;
    Image font_im;

    //Variable globale
    Image im_menu;
    Image im_aide;
    Image im_drapeau;
    Image im_perso;
    Image im_bloc;
    Image im_triangle;
    Image im_fond;
    Image im_sol;

    //Variable du monde 1
    TTF_Font * record1;
    SDL_Color record1_color;
    Image record1_im;

    TTF_Font * score1;
    SDL_Color score1_color;
    Image score1_im;

    //Variable du monde 2
    TTF_Font * record2;
    SDL_Color record2_color;
    Image record2_im;

    TTF_Font * score2;
    SDL_Color score2_color;
    Image score2_im;

    //Variable du monde 3
    TTF_Font * record3;
    SDL_Color record3_color;
    Image record3_im;

    TTF_Font * score3;
    SDL_Color score3_color;
    Image score3_im;

    //Variable du monde 3
    TTF_Font * record4;
    SDL_Color record4_color;
    Image record4_im;

    TTF_Font * score4;
    SDL_Color score4_color;
    Image score4_im;

    //variable sur le son
    bool withSound;
    Mix_Music *musique;
    Mix_Chunk *son_mort;
    Mix_Chunk *son_saut;

public :

/**
    \brief Constructeur par défaut de la classe sdlJeu, il initialise
    tout ce qui concerne la SDL2 ainsi que sa fenetre et de charger les différentes
    images
*/
    sdlJeu ();

/**
    \brief Destructeur de la classe sdlJeu, il fait appel à tous les destructeurs
    liés à la SDL2
*/
    ~sdlJeu ();

/**
    \brief Cette fonction permet d'afficher la fenetre SDL et d'y faire plusieurs
    actions tant que l'utilisateur n'a pas quitté la page
*/
    void sdlBoucle ();

/**
    \brief Cette fonction permet d'afficher le buffer, notamment le personnage,
    le monde, le fond
    \param pos_monde : position actuelle du monde selon l'axe X
*/
    void sdlAff (int pos_monde);

/**
    \brief Cette fonction permet d'afficher le menu au début du jeu, on peut
    y sélectionner son monde et d'y voir les scores des parties ainsi
    que les records
*/
    void sdlAffMenu ();

/**
    \brief Cette fonction permet de gérer le score lors d'une partie pour un
    monde précis qui est passé en paramètre
    \param score : entier correspondant au score qui est remis à jour
    \param monde : entier correspond au monde pour lequel on souhaite gérer le score
*/
    void GestionduScore(const int & score,const int & monde);

/**
    \brief Cette fonction permet de charger un monde, elle permet d'ouvrir les
    différents fichiers selon le monde passé en paramètre
    \param monde : entier correspond au monde que l'on souhaite charger
*/
    void chargerMonde(const int & monde);

};

#endif // SDLJEU_H_INCLUDED
