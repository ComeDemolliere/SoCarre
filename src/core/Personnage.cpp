#include <iostream>
#include "Personnage.h"
#include <cassert>
using namespace std;

Personnage::Personnage()
{
        posXPerso=0;
        posYPerso=0;
        posPersoPrec=0;
        dimXPerso=30;
        dimYPerso=30;
        gravite=1;
        vivant=true;

}

Personnage::Personnage(const int &positionX,const int &positionY, const int &dimensionX, const int &dimensionY)
{
        posXPerso=positionX;
        posYPerso=positionY;
        dimXPerso=dimensionX;
        dimYPerso=dimensionY;
        posPersoPrec=posYPerso;
        gravite=1;
        vivant=true;

}

Personnage::~Personnage()
{


}

int Personnage::getDimXPerso()const
{
    return dimXPerso;
}

void Personnage::setDimXPerso(const int &dimensionX)
{
    assert (dimensionX>=0);
    dimXPerso=dimensionX;
}

int Personnage::getDimYPerso()const
{
    return dimYPerso;
}

void Personnage::setDimYPerso(const int &dimensionY)
{
    //assert(dimensionY >=0);
    dimYPerso=dimensionY;
}

int Personnage::getPosXPerso()const
{
    return posXPerso;
}

void Personnage::setPosXPerso(const int &positionX)
{
    //assert (positionX>=0);
    posXPerso=positionX;
}

int Personnage::getPosYPerso()const
{
    return posYPerso;
}

void Personnage::setPosYPerso(const int &positionY)
{
    //assert (positionY>=0);
    posYPerso=positionY;
}

int Personnage::getPosPersoPrec()const
{
    return posPersoPrec;
}

void Personnage::setPosPersoPrec(const int &position)
{
    //assert (position >= 0);
    posPersoPrec=position;
}

int Personnage::getGravite()const
{
    return gravite;
}

void Personnage::setGravite(const int &gra)
{
    posYPerso=gra;
}

bool Personnage::getVivant()const
{
    return vivant;
}

void Personnage::setVivant(const bool & viv)
{
    vivant=viv;
}


void Personnage::mouvementPerso(const char &event)
{
    switch(event)
        {
        case 'z':
            posYPerso-=gravite;
            posPersoPrec=0;
            break;
        }
}

void Personnage::testRegression()
{

    assert(dimXPerso>=0);
    assert(dimYPerso>=0);
    assert(gravite>=0);
    assert(vivant==0 || vivant==1);
    int i;
    for (i=0;i<100;i++)
    {
        setDimXPerso(i);
        assert(dimXPerso==i);
        assert(getDimXPerso()==i);

        setDimYPerso(i);
        assert(dimYPerso==i);
        assert(getDimYPerso()==i);

    }

    for (i=-50;i<50;i++)
    {
        setPosXPerso(i);
        assert(posXPerso==i);
        assert(getPosXPerso()==i);

        setPosYPerso(i);
        assert(posYPerso==i);
        assert(getPosYPerso()==i);

        setPosPersoPrec(i);
        assert(posYPerso==i);
        assert(getPosYPerso()==i);

    }

    setVivant(true);
    assert(vivant==true);
    assert(getVivant()==vivant);

    setVivant(0);
    assert(vivant==0);
    assert(getVivant()==vivant);

    int pos=posYPerso;
    mouvementPerso('z');
    assert(posYPerso==pos-1);
    assert(posPersoPrec==0) ;

    cout<<"test regression Personnage ok"<<endl;
}

