//
//  main_txt.cpp
//
//
//
//
//

#include <iostream>
#include "winTxt.h"
#include "txtJeu.h"
#include "../core/Jeu.h"
#include "../core/Personnage.h"
#include "../core/Monde.h"
#include <fstream>
using namespace std;

int main ()
{
    termClear();
    Jeu jeu;
    txtBoucle(jeu);
    termClear();
    cout<<"Fin du jeu"<<endl;
    cout<<"perso vivant : "<<jeu.getPerso().getVivant()<<endl;
    return 0;

}



