#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}


void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}


void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

void Image::draw2 (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,&r,NULL);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}


sdlJeu::sdlJeu () : jeu()
{

    withSound=1;

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }


    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }


    int dimx, dimy;
    dimx=600;
    dimy=600;

       // Creation de la fenetre
    window = SDL_CreateWindow("SoCarre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }


    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    //IMAGES
    im_drapeau.loadFromFile("../data/drapeau.png",renderer);
    im_menu.loadFromFile("../data/menu.png",renderer);
    im_aide.loadFromFile("../data/aide.png",renderer);

    im_perso.loadFromFile("../data/personnage.png",renderer);
    im_bloc.loadFromFile("../data/bloc.png",renderer);
    im_triangle.loadFromFile("../data/triangle.png",renderer);
    im_fond.loadFromFile("../data/fond.png",renderer);
    im_sol.loadFromFile("../data/sol.jpg",renderer);


    //FONT
    font = TTF_OpenFont("../data/Pacifico.ttf",50);
    if (font == NULL) {
            cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
    }
    font_color.r = 221;font_color.g = 13;font_color.b = 52;
    font_im.setSurface(TTF_RenderText_Solid(font,"SoCarre",font_color));
    font_im.loadFromCurrentSurface(renderer);

        //Font Monde1
            record1 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            record1_color.r = 200;record1_color.g = 13;record1_color.b = 52;

            score1 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            score1_color.r = 51;score1_color.g = 204;score1_color.b = 255;

       //Font Monde2
            record2 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            record2_color.r = 200;record2_color.g = 13;record2_color.b = 52;

            score2 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            score2_color.r = 51;score2_color.g = 204;score2_color.b = 255;

        //Font Monde3
            record3 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            record3_color.r = 200;record3_color.g = 13;record3_color.b = 52;

            score3 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            score3_color.r = 51;score3_color.g = 204;score3_color.b = 255;

        //Font Monde4
            record4 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            record4_color.r = 200;record4_color.g = 13;record4_color.b = 52;

            score4 = TTF_OpenFont("../data/Pacifico.ttf",50);
            if (font == NULL) {
                    cout << "échec du chargement de Pacifico.ttf! erreur de SDL_TTF: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
            }
            score4_color.r = 51;score4_color.g = 204;score4_color.b = 255;

        //Musique
        musique = Mix_LoadMUS("../data/son.wav");
        Mix_VolumeMusic(MIX_MAX_VOLUME*2);
        Mix_AllocateChannels(10);
        son_mort = Mix_LoadWAV("../data/mort.wav");
        son_saut = Mix_LoadWAV("../data/saut.wav");
        Mix_VolumeChunk(son_mort, MIX_MAX_VOLUME);
        Mix_VolumeChunk(son_saut, MIX_MAX_VOLUME/15);
}



sdlJeu::~sdlJeu ()
{
    Mix_FreeChunk(son_mort);
    Mix_FreeChunk(son_saut);
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff (int pos_monde) {
	//Remplir l'écran d'une couleur
    SDL_SetRenderDrawColor(renderer, 200, 0, 125, 255);
    SDL_RenderClear(renderer);
    im_fond.draw2(renderer,0+pos_monde,0,2000+pos_monde,400);
    im_sol.draw(renderer,0,400,600,200);

    const Personnage& perso=jeu.getPerso();
    int i;
    for(i=0;i<20;i++)
    {
        if(jeu.getListe()->iemeElement(i).getMortel()==1)//dessins des triangles
        {
            im_triangle.draw(renderer,i*30,370,30,30);
        }
        else
        {
            if(jeu.getListe()->iemeElement(i).getTaille()==1)//dessins des blocs de 1
            {
                im_bloc.draw(renderer,i*30,370,30,30);

            }
            if(jeu.getListe()->iemeElement(i).getTaille()==2)//dessins des blocs de 2
            {
                im_bloc.draw(renderer,i*30,370,30,30);
                im_bloc.draw(renderer,i*30,340,30,30);
            }
            if(jeu.getListe()->iemeElement(i).getFin()==1)//dessin du drapeau final
            {
                im_drapeau.draw(renderer,i*30,310,60,90);
            }
        }
    }
    im_perso.draw(renderer,270,370+perso.getPosYPerso()*30,perso.getDimXPerso(),perso.getDimYPerso());//on dessine le personnage


    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 50;positionTitre.y = 150;positionTitre.w = 70;positionTitre.h = 50;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);
}

void sdlJeu::sdlAffMenu()
{
    im_menu.draw(renderer,0,0,600,600);
    //GestionduScore(score);

    //score monde1
    SDL_Rect rec_score1;
    rec_score1.x = 370;rec_score1.y = 150;rec_score1.w = 30;rec_score1.h = 70;
    SDL_RenderCopy(renderer,score1_im.getTexture(),NULL,&rec_score1);

    SDL_Rect positionrecord1;
    positionrecord1.x = 500;positionrecord1.y = 150;positionrecord1.w = 30;positionrecord1.h = 70;
    SDL_RenderCopy(renderer,record1_im.getTexture(),NULL,&positionrecord1);

    //score monde2
    SDL_Rect rec_score2;
    rec_score2.x = 370;rec_score2.y = 240;rec_score2.w = 30;rec_score2.h = 70;
    SDL_RenderCopy(renderer,score2_im.getTexture(),NULL,&rec_score2);

    SDL_Rect positionrecord2;
    positionrecord2.x = 500;positionrecord2.y = 240;positionrecord2.w = 30;positionrecord2.h = 70;
    SDL_RenderCopy(renderer,record2_im.getTexture(),NULL,&positionrecord2);

    //score monde3
    SDL_Rect rec_score3;
    rec_score3.x = 370;rec_score3.y = 330;rec_score3.w = 30;rec_score3.h = 70;
    SDL_RenderCopy(renderer,score3_im.getTexture(),NULL,&rec_score3);

    SDL_Rect positionrecord3;
    positionrecord3.x = 500;positionrecord3.y = 330;positionrecord3.w = 30;positionrecord3.h = 70;
    SDL_RenderCopy(renderer,record3_im.getTexture(),NULL,&positionrecord3);

    //score monde4
    SDL_Rect rec_score4;
    rec_score4.x = 370;rec_score4.y = 430;rec_score4.w = 30;rec_score4.h = 70;
    SDL_RenderCopy(renderer,score4_im.getTexture(),NULL,&rec_score4);

    SDL_Rect positionrecord4;
    positionrecord4.x = 500;positionrecord4.y = 430;positionrecord4.w = 30;positionrecord4.h = 70;
    SDL_RenderCopy(renderer,record4_im.getTexture(),NULL,&positionrecord4);

    SDL_RenderPresent(renderer);
}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
    SDL_Event events_menu;

	bool quit_jeu = true;
	bool quit = true;
	unsigned int pos=0;
	int score_monde1=0;
	int score_monde2=0;
	int score_monde3=0;
	int score_monde4=0;

	//Création des mondes
        Monde monde1(1);
        Monde monde2(2);
        Monde monde3(3);
        Monde monde4(4);

    //Initialisation des scores et records
        GestionduScore(0,1);
        GestionduScore(0,2);
        GestionduScore(0,3);
        GestionduScore(0,4);

    int pos_monde=0;
    int monde=0;

    Uint32 t = SDL_GetTicks(), nt;

	// tant que ce n'est pas la fin ...
	if(withSound)
    {
        Mix_RewindMusic();
        Mix_PlayMusic(musique,-1);
    }

	while (quit) {

        while (SDL_PollEvent(&events_menu)) {
			switch(events_menu.type)
            {
                case SDL_QUIT: //si l'utilisateur appuie sur la croix

                quit = 0;
                break;

                case SDL_MOUSEBUTTONUP: //pour faire une action selon une touche
                {
                    //MONDE 1
                    if (events_menu.button.x>=10 && events_menu.button.y>=170 && events_menu.button.x<=250 && events_menu.button.y<=230)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        Mix_PauseMusic();
                        jeu.reinitJeu(monde1);
                        monde=1;
                        chargerMonde(monde);

                        quit_jeu=1;

                        pos=0;
                        score_monde1=0;
                        pos_monde=0;


                        while(quit_jeu)
                        {
                            while (SDL_PollEvent(&events)) {
                                switch(events.type)
                                {
                                case SDL_QUIT: //si l'utilisateur appuie sur la croix
                                    quit_jeu=0;
                                    quit = 0;
                                    break;

                                case SDL_KEYDOWN: //pour faire une action selon une touche
                                    {
                                        if (events.key.keysym.sym == SDLK_SPACE || events.key.keysym.sym == SDLK_UP)
                                        {
                                            if (jeu.getPerso().getPosYPerso()==-jeu.getListe()->iemeElement(9).getTaille())
                                            {
                                                if(withSound)Mix_PlayChannel(2, son_saut, 0);
                                            }
                                            jeu.actionClavier('z');
                                        }

                                        default:break;
                                    }
                                }
                            }

                            nt = SDL_GetTicks();
                            if (nt-t>80)
                            {
                                jeu.actionsAutomatiques(pos);
                                t = nt;
                                pos++;
                                score_monde1++;
                                pos_monde=pos_monde+2;
                            }
                            jeu.collision(quit_jeu);

                            // on affiche le jeu sur le buffer caché
                            sdlAff(pos_monde);

                            if (jeu.getMonde().getForme().size()==pos)
                            {
                                pos=0;
                            }
                            // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                            SDL_RenderPresent(renderer);
                        }
                        if(jeu.getPerso().getVivant()==1)
                        {
                           GestionduScore(100,monde);
                           cout<<"Bravo, tu as gagne"<<endl;
                        }
                        if(jeu.getPerso().getVivant()==0)
                        {
                            if(withSound)Mix_PlayChannel(1, son_mort, 0);
                            GestionduScore(score_monde1,monde);
                            cout<<"Tu as perdu, retente ta chance"<<endl;
                            cout<<(int)(((float)score_monde1/(jeu.getMonde().getForme().size()-5))*100)<<"%"<<endl;
                        }
                        if(withSound)
                        {
                            Mix_RewindMusic();
                            Mix_PlayMusic(musique,-1);
                        }
                        break;
                    }

                    //MONDE 2
                    if (events_menu.button.x>=10 && events_menu.button.y>=270 && events_menu.button.x<=300 && events_menu.button.y<=320)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        Mix_PauseMusic();
                        jeu.reinitJeu(monde2);
                        monde=2;
                        chargerMonde(monde);

                        quit_jeu=1;
                        pos=0;
                        score_monde2=0;
                        pos_monde=0;

                        while(quit_jeu)
                        {
                            while (SDL_PollEvent(&events)) {
                                switch(events.type)
                                {
                                case SDL_QUIT: //si l'utilisateur appuie sur la croix
                                    quit_jeu=0;
                                    quit = 0;
                                    break;

                                case SDL_KEYDOWN: //pour faire une action selon une touche
                                    {
                                        if (events.key.keysym.sym == SDLK_SPACE || events.key.keysym.sym == SDLK_UP)
                                        {
                                            if (jeu.getPerso().getPosYPerso()==-jeu.getListe()->iemeElement(9).getTaille())
                                            {
                                                if(withSound)Mix_PlayChannel(2, son_saut, 0);
                                            }
                                            jeu.actionClavier('z');
                                        }

                                        default:break;
                                    }
                                }
                            }

                            nt = SDL_GetTicks();
                            if (nt-t>80)
                            {
                                jeu.actionsAutomatiques(pos);
                                t = nt;
                                pos++;
                                score_monde2++;
                                pos_monde=pos_monde+2;
                            }

                            jeu.collision(quit_jeu);
                            sdlAff(pos_monde);

                            if (jeu.getMonde().getForme().size()==pos)
                            {
                                pos=0;
                            }
                            // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                            SDL_RenderPresent(renderer);
                        }
                        if(jeu.getPerso().getVivant()==1)
                        {
                            GestionduScore(100,monde);
                            cout<<"Bravo, tu as gagne"<<endl;
                        }
                        if(jeu.getPerso().getVivant()==0)
                        {
                            if(withSound)Mix_PlayChannel(1, son_mort, 0);
                            GestionduScore(score_monde2,monde);
                            cout<<"Tu as perdu, retente ta chance"<<endl;
                            cout<<(int)(((float)score_monde2/(jeu.getMonde().getForme().size()-5))*100)<<"%"<<endl;
                        }
                        if(withSound)
                        {
                            Mix_RewindMusic();
                            Mix_PlayMusic(musique,-1);
                        }
                        break;
                    }

                    //MONDE 3
                    if (events_menu.button.x>=10 && events_menu.button.y>=360 && events_menu.button.x<=200 && events_menu.button.y<=420)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        Mix_PauseMusic();
                        quit_jeu=1;
                        monde=3;
                        jeu.reinitJeu(monde3);
                        chargerMonde(monde);
                        pos=0;
                        score_monde3=0;
                        pos_monde=0;
                        while(quit_jeu)
                        {
                            while (SDL_PollEvent(&events)) {
                                switch(events.type)
                                {
                                case SDL_QUIT: //si l'utilisateur appuie sur la croix
                                    quit_jeu=0;
                                    quit = 0;
                                    break;

                                case SDL_KEYDOWN: //pour faire une action selon une touche
                                    {
                                        if (events.key.keysym.sym == SDLK_SPACE || events.key.keysym.sym == SDLK_UP)
                                        {
                                            if (jeu.getPerso().getPosYPerso()==-jeu.getListe()->iemeElement(9).getTaille())
                                            {
                                                if(withSound)Mix_PlayChannel(2, son_saut, 0);
                                            }
                                            jeu.actionClavier('z');
                                        }

                                        default:break;
                                    }
                                }
                            }

                            nt = SDL_GetTicks();
                            if (nt-t>80)
                            {
                                jeu.actionsAutomatiques(pos);
                                t = nt;
                                pos++;
                                score_monde3++;
                                pos_monde=pos_monde+2;
                            }
                            jeu.collision(quit_jeu);
                            sdlAff(pos_monde);

                            if (jeu.getMonde().getForme().size()==pos)
                            {
                                pos=0;
                            }
                            // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                            SDL_RenderPresent(renderer);
                        }
                        if(jeu.getPerso().getVivant()==1)
                        {
                           GestionduScore(score_monde3,100);
                           cout<<"Bravo, tu as gagne"<<endl;
                        }
                        if(jeu.getPerso().getVivant()==0)
                        {
                            if(withSound)Mix_PlayChannel(1, son_mort, 0);
                            GestionduScore(score_monde3,monde);
                            cout<<"Tu as perdu, retente ta chance"<<endl;
                            cout<<(int)(((float)score_monde3/(jeu.getMonde().getForme().size()-5))*100)<<"%"<<endl;
                        }
                        if(withSound)
                        {
                            Mix_RewindMusic();
                            Mix_PlayMusic(musique,-1);
                        }
                        break;
                    }

                    //MONDE 4
                    if (events_menu.button.x>=10 && events_menu.button.y>=440 && events_menu.button.x<=300 && events_menu.button.y<=500)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        Mix_PauseMusic();
                        unsigned int vitesse=100;
                        quit_jeu=1;
                        monde=4;
                        jeu.reinitJeu(monde4);
                        chargerMonde(monde);
                        pos=0;
                        score_monde4=0;
                        pos_monde=0;
                        while(quit_jeu)
                        {
                            while (SDL_PollEvent(&events)) {
                                switch(events.type)
                                {
                                case SDL_QUIT: //si l'utilisateur appuie sur la croix
                                    quit_jeu=0;
                                    quit = 0;
                                    break;

                                case SDL_KEYDOWN: //pour faire une action selon une touche
                                    {
                                        if (events.key.keysym.sym == SDLK_SPACE || events.key.keysym.sym == SDLK_UP)
                                        {
                                            if (jeu.getPerso().getPosYPerso()==-jeu.getListe()->iemeElement(9).getTaille())
                                            {
                                                if(withSound)Mix_PlayChannel(2, son_saut, 0);
                                            }
                                            jeu.actionClavier('z');
                                        }

                                        default:break;
                                    }
                                }
                            }

                            nt = SDL_GetTicks();
                            if (nt-t>vitesse)
                            {
                                jeu.actionsAutomatiques(pos);
                                t = nt;
                                pos++;
                                score_monde4++;
                                if(pos_monde<=500)pos_monde=pos_monde+2;
                            }
                            jeu.collision(quit_jeu);
                            sdlAff(pos_monde);

                            if (jeu.getMonde().getForme().size()==pos)
                            {
                                pos=0;
                                if(vitesse>50)vitesse=vitesse-10;
                            }
                            // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                            SDL_RenderPresent(renderer);
                        }
                        if(jeu.getPerso().getVivant()==0)
                        {
                            if(withSound) Mix_PlayChannel(1, son_mort, 0);
                            GestionduScore(score_monde4,monde);
                            cout<<"Tu as perdu, retente ta chance"<<endl;
                            cout<<(int)(((float)score_monde4/(jeu.getMonde().getForme().size()-5))*100)<<"%"<<endl;
                        }
                        if(withSound)
                        {
                            Mix_RewindMusic();
                            Mix_PlayMusic(musique,-1);
                        }
                        break;
                    }

                    //QUITTER
                    if (events_menu.button.x>=480 && events_menu.button.y>=550 && events_menu.button.x<=595 && events_menu.button.y<=580)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        quit=0;
                        break;
                    }

                    //SON (ON/OFF)
                    if (events_menu.button.x>=20 && events_menu.button.y>=540 && events_menu.button.x<=70 && events_menu.button.y<=580)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        if(withSound)
                        {
                            Mix_PauseMusic();
                            withSound=0;
                            im_menu.loadFromFile("../data/menu_sans_son.png",renderer);
                        }
                        else
                        {
                            withSound=1;
                            im_menu.loadFromFile("../data/menu.png",renderer);
                        }
                        if(withSound)
                        {
                            Mix_RewindMusic();
                            Mix_PlayMusic(musique,-1);
                        }
                        break;
                    }

                    if (events_menu.button.x>=490 && events_menu.button.y>=50 && events_menu.button.x<=575 && events_menu.button.y<=80)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        quit_jeu=1;
                        while(quit_jeu)
                        {
                            im_aide.draw(renderer,0,0,600,600);
                            while (SDL_PollEvent(&events_menu))
                            {
                                switch(events_menu.type)
                                {
                                    case SDL_QUIT: //si l'utilisateur appuie sur la croix
                                    {
                                        quit = 0;
                                        quit_jeu=0;
                                        break;
                                    }

                                    case SDL_MOUSEBUTTONUP: //pour faire une action selon une touche
                                    {
                                        if (events_menu.button.x>=30 && events_menu.button.y>=560 && events_menu.button.x<=130 && events_menu.button.y<=580)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                                        {
                                            quit_jeu=0;
                                            break;
                                        }
                                    }
                                    case SDL_KEYDOWN:
                                    {
                                        quit_jeu=0;
                                        break;
                                    }
                                }
                            }
                            SDL_RenderPresent(renderer);
                        }
                    }

                    default:break;
                }
                case SDL_KEYDOWN:
                {
                    if (events_menu.key.keysym.sym == SDLK_ESCAPE)//SDLK_ESCAPE Pour fermer en cliquant sur 'exit', SPACE pour 'espace'
                    {
                        quit=0;
                        break;
                    }
                }
            }
        }
        sdlAffMenu();
	}
}

void sdlJeu::GestionduScore(const int & score_jeu,const int & monde)
{

    int pourcentage = 0;
    if(score_jeu==100) pourcentage=100;
    else pourcentage = (int)(((float)score_jeu/(jeu.getMonde().getForme().size()-5))*100);

    if(monde==1)
    {
        string const nomFichierScore("../data/score.txt");
        ofstream fichier1(nomFichierScore.c_str(),ios::trunc);
        if (fichier1)
        {
            fichier1<<pourcentage;
            fichier1.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en ecriture"<<endl;

        ifstream fichier2(nomFichierScore.c_str());
        if(fichier2)
        {
            string ligne;
            getline(fichier2,ligne);
            score1_im.setSurface(TTF_RenderText_Solid(score1,ligne.c_str(),score1_color));
            score1_im.loadFromCurrentSurface(renderer);
            fichier2.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en lecture"<<endl;

        const char* mscore;

        string const nomFichier1("../data/meilleurscore.txt");
		ifstream fichier1_record(nomFichier1.c_str());
		if (fichier1_record)
		{
			string ligne;
			getline(fichier1_record,ligne);
			int Mscore=atoi(ligne.c_str());

			if (pourcentage>Mscore)
			{

				cout << "Record battu ! : "<<pourcentage<<endl;
				//fichier1.close();
				ofstream fichier2_record(nomFichier1.c_str(),ios::trunc);
				if (fichier2_record)
				{
					fichier2_record<<pourcentage;
					//récupération du score
					ifstream fichier_score(nomFichierScore.c_str());
                    if(fichier_score)
                    {
                        string ligne2;
                        getline(fichier_score,ligne2);
                        record1_im.setSurface(TTF_RenderText_Solid(record1,ligne2.c_str(),record1_color));
                        record1_im.loadFromCurrentSurface(renderer);
                        fichier_score.close();
                    }
				}
				else {cout<<"Erreur d'ouverture du fichier record.txt en ecriture"<<endl;}

			}
			else
			{
				mscore=(ligne.c_str());
				record1_im.setSurface(TTF_RenderText_Solid(record1,mscore,record1_color));
                record1_im.loadFromCurrentSurface(renderer);
			}
			fichier1_record.close();
		}
		else {cout << "Erreur d'ouverture du fichier record.txt en lecture"<<endl;}
    }

    if(monde==2)
    {
        string const nomFichierScore2("../data/score2.txt");
        ofstream fichier1(nomFichierScore2.c_str(),ios::trunc);
        if (fichier1)
        {
            fichier1<<pourcentage;
            fichier1.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en ecriture"<<endl;

        ifstream fichier2(nomFichierScore2.c_str());
        if(fichier2)
        {
            string ligne;
            getline(fichier2,ligne);
            score2_im.setSurface(TTF_RenderText_Solid(score2,ligne.c_str(),score2_color));
            score2_im.loadFromCurrentSurface(renderer);
            fichier2.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en lecture"<<endl;

        const char* mscore;

        string const nomFichier1("../data/meilleurscore2.txt");
		ifstream fichier1_record(nomFichier1.c_str());
		if (fichier1_record)
		{
			string ligne;
			getline(fichier1_record,ligne);
			int Mscore=atoi(ligne.c_str());

			if (pourcentage>Mscore)
			{

				cout << "Record battu ! : "<<pourcentage<<endl;
				ofstream fichier2_record(nomFichier1.c_str(),ios::trunc);
				if (fichier2_record)
				{
					fichier2_record<<pourcentage;
					ifstream fichier_score(nomFichierScore2.c_str());
                    if(fichier_score)
                    {
                        string ligne2;
                        getline(fichier_score,ligne2);
                        record2_im.setSurface(TTF_RenderText_Solid(record2,ligne2.c_str(),record2_color));
                        record2_im.loadFromCurrentSurface(renderer);
                        fichier_score.close();
                    }
				}
				else {cout<<"Erreur d'ouverture du fichier record.txt en ecriture"<<endl;}

			}
			else
			{
				mscore=(ligne.c_str());
				record2_im.setSurface(TTF_RenderText_Solid(record2,mscore,record2_color));
                record2_im.loadFromCurrentSurface(renderer);
			}
			fichier1_record.close();
		}
		else {cout << "Erreur d'ouverture du fichier record.txt en lecture"<<endl;}
    }

    if(monde==3)
    {
        string const nomFichierScore3("../data/score3.txt");
        ofstream fichier1(nomFichierScore3.c_str(),ios::trunc);
        if (fichier1)
        {
            fichier1<<pourcentage;
            fichier1.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en ecriture"<<endl;

        ifstream fichier2(nomFichierScore3.c_str());
        if(fichier2)
        {
            string ligne;
            getline(fichier2,ligne);
            score3_im.setSurface(TTF_RenderText_Solid(score3,ligne.c_str(),score3_color));
            score3_im.loadFromCurrentSurface(renderer);
            fichier2.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en lecture"<<endl;

        const char* mscore;

        string const nomFichier1("../data/meilleurscore3.txt");
		ifstream fichier1_record(nomFichier1.c_str());
		if (fichier1_record)
		{
			string ligne;
			getline(fichier1_record,ligne);
			int Mscore=atoi(ligne.c_str());

			if (pourcentage>Mscore)
			{

				cout << "Record battu ! : "<<pourcentage<<endl;
				ofstream fichier2_record(nomFichier1.c_str(),ios::trunc);
				if (fichier2_record)
				{
					fichier2_record<<pourcentage;
					ifstream fichier_score(nomFichierScore3.c_str());
                    if(fichier_score)
                    {
                        string ligne2;
                        getline(fichier_score,ligne2);
                        record3_im.setSurface(TTF_RenderText_Solid(record3,ligne2.c_str(),record3_color));
                        record3_im.loadFromCurrentSurface(renderer);
                        fichier_score.close();
                    }
				}
				else {cout<<"Erreur d'ouverture du fichier record.txt en ecriture"<<endl;}

			}
			else
			{
				mscore=(ligne.c_str());
				record3_im.setSurface(TTF_RenderText_Solid(record3,mscore,record3_color));
                record3_im.loadFromCurrentSurface(renderer);
			}
			fichier1_record.close();
		}
		else {cout << "Erreur d'ouverture du fichier record.txt en lecture"<<endl;}
    }

    if(monde==4)
    {
        string const nomFichierScore4("../data/score4.txt");
        ofstream fichier1(nomFichierScore4.c_str(),ios::trunc);
        if (fichier1)
        {
            fichier1<<pourcentage;
            fichier1.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en ecriture"<<endl;

        ifstream fichier2(nomFichierScore4.c_str());
        if(fichier2)
        {
            string ligne;
            getline(fichier2,ligne);
            score4_im.setSurface(TTF_RenderText_Solid(score4,ligne.c_str(),score4_color));
            score4_im.loadFromCurrentSurface(renderer);
            fichier2.close();
        }
        else cout<<"Erreur d'ouverture du fichier Score.txt en lecture"<<endl;

        const char* mscore;

        string const nomFichier1("../data/meilleurscore4.txt");
		ifstream fichier1_record(nomFichier1.c_str());
		if (fichier1_record)
		{
			string ligne;
			getline(fichier1_record,ligne);
			int Mscore=atoi(ligne.c_str());

			if (pourcentage>Mscore)
			{

				cout << "Record battu ! : "<<pourcentage<<endl;
				ofstream fichier2_record(nomFichier1.c_str(),ios::trunc);
				if (fichier2_record)
				{
					fichier2_record<<pourcentage;
					ifstream fichier_score(nomFichierScore4.c_str());
                    if(fichier_score)
                    {
                        string ligne2;
                        getline(fichier_score,ligne2);
                        record4_im.setSurface(TTF_RenderText_Solid(record4,ligne2.c_str(),record4_color));
                        record4_im.loadFromCurrentSurface(renderer);
                        fichier_score.close();
                    }
				}
				else {cout<<"Erreur d'ouverture du fichier record.txt en ecriture"<<endl;}

			}
			else
			{
				mscore=(ligne.c_str());
				record4_im.setSurface(TTF_RenderText_Solid(record4,mscore,record4_color));
                record4_im.loadFromCurrentSurface(renderer);
			}
			fichier1_record.close();
		}
		else {cout << "Erreur d'ouverture du fichier record.txt en lecture"<<endl;}
    }
}

void sdlJeu::chargerMonde(const int & monde)
{
    if (monde==1)
    {
        im_perso.loadFromFile("../data/personnage.png",renderer);
        im_bloc.loadFromFile("../data/bloc.png",renderer);
        im_triangle.loadFromFile("../data/triangle.png",renderer);
        im_fond.loadFromFile("../data/fond.png",renderer);
        im_sol.loadFromFile("../data/sol.jpg",renderer);
    }
    if (monde==2)
    {
        im_perso.loadFromFile("../data/personnage2.png",renderer);
        im_bloc.loadFromFile("../data/bloc2.png",renderer);
        im_triangle.loadFromFile("../data/triangle2.png",renderer);
        im_fond.loadFromFile("../data/fond2.png",renderer);
        im_sol.loadFromFile("../data/sol2.png",renderer);
    }
    if (monde==3)
    {
        im_perso.loadFromFile("../data/personnage3.png",renderer);
        im_bloc.loadFromFile("../data/bloc3.png",renderer);
        im_triangle.loadFromFile("../data/triangle3.png",renderer);
        im_fond.loadFromFile("../data/fond3.png",renderer);
        im_sol.loadFromFile("../data/sol3.png",renderer);
    }
    if (monde==4)
    {
        im_perso.loadFromFile("../data/personnageR.png",renderer);
        im_bloc.loadFromFile("../data/blocR.png",renderer);
        im_triangle.loadFromFile("../data/triangleR.png",renderer);
        im_fond.loadFromFile("../data/fondR.png",renderer);
        im_sol.loadFromFile("../data/solR.png",renderer);
    }
}
