#pragma once

#include <string>
#include <vector>

#include "Polygone.hpp"

using namespace std;

class Parcelle
{
private:
    int numero;
    string proprietaire;
    float surface;
    Polygone<float> forme;
    int pConstructible;

public:
    /* Constructors */
    Parcelle(int num, string prop, Polygone<float> forme, int pConstructible);
    Parcelle(Parcelle &other, int pConstructible);

    /* Getters */
    int getNumero(void) const;
    string getProprietaire(void) const;
    float getSurface(void) const;
    Polygone<float> getForme(void) const;
    int getPConstructible(void) const;

    /* Setters */
    void setNumero(int n);
    void setProprietaire(string prop);
    void setForme(Polygone<float> _forme);
    void setPConstructible(int pConstructible);
};