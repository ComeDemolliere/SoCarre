//
//  txtJeu.cpp
//
//
//
//


#include "../core/Jeu.h"
#include "../core/Monde.h"

#include <iostream>

#include <time.h>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"




void txtAff(WinTXT & win, Jeu &jeu) {



    win.clear();

	//Déclaration du personnage et des obstacles
    const char perso='P';
    const char cube='#';
    const char tri='A';
	const char fin='F';
	
    int i;

    for(i=0;i<20;i++)
    {
        if(jeu.getListe()->iemeElement(i).getMortel()==1)//dessins des triangles ici 'A'
        {
            win.print(i,10,tri);
        }
        else
        {
            if(jeu.getListe()->iemeElement(i).getTaille()==1)//dessins des cubes de taille 1
            {
                win.print(i,10,cube);
            }

            if(jeu.getListe()->iemeElement(i).getTaille()==2)//dessins des cubes de taille 2
            {
                win.print(i,10,cube);
                win.print(i,9,cube);
            }
			if(jeu.getListe()->iemeElement(i).getFin()==1)//dessin du drapeau final ici 'F'
            {
                win.print(i,10,fin);
            }
        }

    }
    win.print(jeu.getPerso().getPosXPerso()+9,jeu.getPerso().getPosYPerso()+10,perso);//dessin du personnage


    win.draw();

}

void txtBoucle (Jeu &jeu)
{
	//Initialisation du temps pour ralentir le jeu
    clock_t debut;
    clock_t fin;
	
    unsigned int i=1;

	//Création d'une nouvelle fenetre en mode texte
    int dimXWin=50;
    int dimYWin=20;
    WinTXT win(dimXWin,dimYWin);
	
    bool ok=true;
    do {
        txtAff(win,jeu); //afficher le jeu tant que c'est bon


#ifdef _WIN32
        //Sleep(100);
#else
        //usleep(100000);
#endif // WIN32

		jeu.collision(ok);
        char c;
        c = win.getCh();
        switch (c)
        {
            case ' ':
                jeu.actionClavier('z');//Gère le saut du personnage

                break;

        }
        jeu.actionsAutomatiques(i);//Gère le déplacement du monde
        double attente=0;
        debut=clock();
        while(attente<12)//12 Pour windows/ 12000 pour ubuntu 
        {
            fin=clock();
            attente=(fin-debut)/10;
        }
        i++;

        if(i==jeu.getMonde().getForme().size())
        {
            i=1;
        }

    } while (ok);

}


