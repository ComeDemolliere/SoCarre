#include "Forme.h"
#include "Liste.h"

#include <iostream>
using namespace std;
#include <stdlib.h>

Liste::Liste () {
    prem = NULL;
    last = NULL;
}

Liste& Liste::operator = (const Liste & l) {
    vider();
    Cellule * temp = l.prem;
    while (temp != NULL) {
        ajouterEnQueue(temp->info);
        temp = temp->suivant;
    }
    return *this;
}

Liste::~Liste () {
  vider();
}

void Liste::vider () {
    while (!estVide()) supprimerTete();
}

bool Liste::estVide () const {
    return prem == NULL;
}

unsigned int Liste::nbElements () const {
    unsigned int nb = 0;
    Cellule * temp = prem;
    while (temp != NULL) {
        nb++;
        temp = temp->suivant;
    }
    return nb;
}

Forme Liste::iemeElement (unsigned int indice) const {
  Cellule * temp = prem;
  for (unsigned int j = 0; j < indice; j++) {
      temp = temp->suivant;
      if (temp == NULL) {cout << "Erreur Liste::iemeElement : indice trop grand"; exit(1);}
  }
  return temp->info;
}

void Liste::modifierIemeElement (unsigned int indice, Forme f) {
  Cellule * temp = prem;
  for (unsigned int j = 0; j < indice; j++) {
      temp = temp->suivant;
      if (temp == NULL) {cout << "Erreur Liste::iemeElement : indice trop grand"; exit(1);}
  }
  temp->info = f;
}

void Liste::ajouterEnTete (Forme f) {
  Cellule * temp = new Cellule;
  temp->info = f;
  temp->suivant = prem;
  temp->precedent = NULL;

  // Attention au cas d'une liste qui etait vide
  if (estVide()) last = temp;
  else prem->precedent = temp;

  prem = temp;
}

void Liste::supprimerTete () {
  Cellule * temp = prem;
  prem = prem->suivant;
  if(prem != NULL) prem->precedent = NULL;
  else last = NULL;
  delete temp;
}

void Liste::ajouterEnQueue (Forme f) {
  if (estVide()) ajouterEnTete(f);
  else {
      Cellule * temp = new Cellule;
      temp->info = f;
      temp->suivant = NULL;
      temp->precedent = last;

      last->suivant = temp;
      last = temp;
    }
}


void Liste::insererElement (Forme f, unsigned int indice) {
  Cellule *c, *nouv;

  if (estVide() || (indice == 0)) ajouterEnTete(f);
  else if (indice == nbElements()) ajouterEnQueue(f);
  else {
      // 1 <= indice < nombre d'elements
      c = prem;
      for (unsigned int i = 0; i < indice; i++) c = c->suivant;
      // c pointe sur la cellule avant laquelle il faut inserer e
      nouv = new Cellule;
      nouv->info = f;
      nouv->suivant = c;
      nouv->precedent = c->precedent;

      c->precedent->suivant = nouv;
      c->precedent = nouv;
    }
}


