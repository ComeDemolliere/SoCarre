#include <iostream>
#include "Monde.h"
#include<stdlib.h>
#include <cassert>
#include <fstream>
#include <sstream>
using namespace std;

Monde::Monde(const int & i)
{
    tab.clear();
    stock.push_back(Forme(0,0));
    stock.push_back(Forme(1,0));
    stock.push_back(Forme(2,0));
    stock.push_back(Forme(0,true));
    stock.push_back(Forme(0,0,true));

    if (i==1)
    {
        string const nomFichier("../data/monde1.txt");
        ifstream fichier(nomFichier.c_str());
        if(fichier)
        {
            //L'ouverture s'est bien passée, on peut donc lire
            string ligne;


            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                int var = atoi(ligne.c_str());
                tab.push_back(var);
            }
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }

    if (i==2)
     {
        string const nomFichier("../data/monde2.txt");
        ifstream fichier(nomFichier.c_str());
        if(fichier)
        {
            //L'ouverture s'est bien passée, on peut donc lire
            string ligne;


            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                int var = atoi(ligne.c_str());
                tab.push_back(var);
            }
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }
    if (i==3)
     {
        string const nomFichier("../data/monde3.txt");
        ifstream fichier(nomFichier.c_str());
        if(fichier)
        {
            //L'ouverture s'est bien passée, on peut donc lire
            string ligne;


            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                int var = atoi(ligne.c_str());
                tab.push_back(var);
            }
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }
    if (i==4)
     {
        string const nomFichier("../data/monde4.txt");
        ifstream fichier(nomFichier.c_str());
        if(fichier)
        {
            //L'ouverture s'est bien passée, on peut donc lire
            string ligne;


            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                int var = atoi(ligne.c_str());
                tab.push_back(var);
            }
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }
}


Monde::~Monde()
{



}

vector<int> Monde::getForme()const
{
    return tab;
}

const Forme& Monde::getFormePosI(const int & i)const
{
    return stock[i];
}

int Monde::getEntierPosI(const int & i)const
{
    return tab[i];
}

void Monde::testRegression()
{
    unsigned int i;

    for(i=0;i<tab.size();i++)
    {
        stock[tab[i]].testRegression();
        assert(getEntierPosI(i)==tab[i]);
    }

    assert(getForme().size()==tab.size());

    cout<<"test regression Monde ok"<<endl;
}
