#include <iostream>
#include "Jeu.h"
#include <cassert>
#include <fstream>
using namespace std;

Jeu::Jeu():monde(1)
{
    Forme vide1 (0,0);
    posActuellePerso=0;
    int i=0;
    while (i<20)
    {
        l.ajouterEnQueue(vide1);
        i++;

    }

}

Jeu::~Jeu()
{
    l.vider();
}

const Personnage& Jeu::getPerso()const
{
    return perso;
}

const Monde& Jeu::getMonde()const
{
    return  monde;
}

void Jeu::setMonde(const Monde & mo)
{
    monde=mo;
}

void Jeu::setPerso(const Personnage & personnage)
{
    perso=personnage;
}

Liste* Jeu::getListe()
{
    return &l;
}

void Jeu::setListe(const Liste & li)
{
    l=li;
}

void Jeu::collision(bool & continuer)
{
    if(l.iemeElement(10).getMortel()==1)
    {
        if(perso.getPosYPerso()==0)
           {
               perso.setVivant(false);
               continuer=0;
           }
    }
    else
    {
        if((l.iemeElement(10).getTaille()==1)&&(perso.getPosYPerso()>-1))
           {
               perso.setVivant(false);
               continuer=0;
           }
        if((l.iemeElement(10).getTaille()==2)&&(perso.getPosYPerso()>-2))
           {
               perso.setVivant(false);
               continuer=0;
           }
         if(l.iemeElement(9).getFin()==1)
           {
               perso.setVivant(true);
               continuer=0;
           }
    }
    if(l.iemeElement(9).getMortel()==1)
    {

        if(perso.getPosYPerso()==0 || perso.getPosYPerso()==-1)
           {
               perso.setVivant(false);
               continuer=0;
           }
    }

}

void Jeu::actionsAutomatiques(const int &i)
{

    if (perso.getPosYPerso()<0 && ((perso.getPosPersoPrec()>perso.getPosYPerso()) && perso.getPosYPerso()>=-3+posActuellePerso))
    {
        perso.setPosPersoPrec(perso.getPosYPerso());
        perso.setPosYPerso(perso.getPosYPerso()-perso.getGravite());
    }

    if ((perso.getPosYPerso()<=-4+posActuellePerso) || ((perso.getPosPersoPrec())<(perso.getPosYPerso())&& (perso.getPosYPerso()<0)))
    {
        if(l.iemeElement(10).getTaille()==1)
        {
            if(perso.getPosYPerso()==-1 && perso.getPosPersoPrec()<perso.getPosYPerso())
            {
                perso.setPosYPerso(-1);
                perso.setPosPersoPrec(-2);
                posActuellePerso=-1;
            }
            else
            {
                perso.setPosPersoPrec(perso.getPosYPerso());
                perso.setPosYPerso(perso.getPosYPerso()+perso.getGravite());
                posActuellePerso++;
            }
        }
        if(l.iemeElement(10).getTaille()==2)
        {
            if(perso.getPosYPerso()==-2 && perso.getPosPersoPrec()<perso.getPosYPerso())
            {
                perso.setPosYPerso(-2);
                perso.setPosPersoPrec(-3);
                posActuellePerso=-2;
            }
            else
            {
                perso.setPosPersoPrec(perso.getPosYPerso());
                perso.setPosYPerso(perso.getPosYPerso()+perso.getGravite());
                posActuellePerso++;
            }
        }
        if(l.iemeElement(10).getTaille()==0)
        {
            if(perso.getPosYPerso()==-1 && perso.getPosPersoPrec()<perso.getPosYPerso())
            {
                perso.setPosYPerso(0);
                perso.setPosPersoPrec(-1);
                posActuellePerso=0;
            }
            else
            {
                perso.setPosPersoPrec(perso.getPosYPerso());
                perso.setPosYPerso(perso.getPosYPerso()+perso.getGravite());
                posActuellePerso++;
            }
        }
    }
    if(i==-1)
    {
        l.supprimerTete();
    }
    else{
        l.supprimerTete();
        l.ajouterEnQueue(monde.getFormePosI(monde.getEntierPosI(i)));
        }
}


void Jeu::actionClavier(const char &carac)
{
    if((perso.getPosYPerso()==0)||(perso.getPosYPerso()==posActuellePerso))
    {
        if(carac=='z')
        {
            perso.mouvementPerso('z');
        }
    }
}

void Jeu::reinitJeu(Monde & mo)
{
    l.vider();
    monde=mo;
    Forme vide1 (0,0);
    posActuellePerso=0;
    int i=0;
    while (i<20)
    {
        l.ajouterEnQueue(vide1);
        i++;

    }

}

void Jeu::testRegression()
{
    assert(posActuellePerso>=0);
    monde.testRegression();
    perso.testRegression();

    unsigned int i;
    for(i=1;i<5;i++)
    {
        Monde mo(i);
        reinitJeu(mo);
        assert(posActuellePerso>=0);
        monde.testRegression();
        perso.testRegression();
    }

    cout<<"test regression Jeu ok"<<endl;
}

