#include "Forme.h"
#include <iostream>
#include <cassert>
using namespace std;
Forme::Forme()
{
    taille=0;
    mortel=false;
    fin=false;
}

Forme::Forme(const int & t,const bool & m)
{
    taille=t;
    mortel=m;
    fin=false;
}

Forme::Forme(const int & t,const bool & m, const bool & f)
{
    taille=t;
    mortel=m;
    fin=f;
}

Forme::~Forme()
{

}

void Forme::setTaille(const int & t)
{
    taille=t;
}

int Forme::getTaille()const
{
    return taille;
}

void Forme::setMortel(const bool & m)
{
    mortel=m;
}

bool Forme::getMortel() const
{
    return mortel;
}

bool Forme::getFin() const
{
    return fin;
}

void Forme::testRegression()
{
    assert(taille>=0);
    assert(mortel==0 || mortel==1);
    assert(fin==0 || fin==1);

    int i;
    for (i=0;i<100;i++)
    {
        setTaille(i);
        assert(taille==i);
        assert(getTaille()==taille);

    }

    setMortel(true);
    assert(mortel==true);
    assert(getMortel()==mortel);

    setMortel(0);
    assert(mortel==0);
    assert(getMortel()==mortel);

    assert(getFin()==1 || getFin()==0);
    assert(getFin()==fin);

    cout<<"test regression Forme ok"<<endl;
}
