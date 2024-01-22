#pragma once
#include "Parcelle.hpp"

/*============================*/
/*         Parcelle()         */
/*============================*/
///// Constructors /////
Parcelle::Parcelle(int num, string prop, Polygone<int> forme) {
  this->numero = num;
  this->proprietaire = prop;
  this->forme = forme;
}

Parcelle::Parcelle(Parcelle &parc) {
  this->numero = parc.getNumero();
  this->proprietaire = parc.getProprietaire();
  this->forme = parc.getForme();
  this->surface = parc.getSurface();
}

///// Getters /////
int Parcelle::getNumero(void) const { return numero; }

string Parcelle::getProprietaire(void) const { return proprietaire; }

float Parcelle::getSurface(void) const { return surface; }

Polygone<int> Parcelle::getForme(void) const { return forme; }


///// Setters /////
void Parcelle::setNumero(int n) { numero = n; }

void Parcelle::setProprietaire(string prop) { proprietaire = prop; }

void Parcelle::setForme(Polygone<int> _forme) { forme = _forme; }



// Overload of << operator
ostream &operator<<(ostream &s, Parcelle const &p) {
  cout << "Informations de la parcelle : " << endl
       << "Numero : " << p.getNumero() << endl
       << "Proprietaire : " << p.getProprietaire() << endl
       << "Surface : " << p.getSurface() << endl
       << "Forme : " << p.getForme() << endl;
  return s;
}