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

public:
    /* Constructors */
    Parcelle(int num, string prop, Polygone<float> forme);
    Parcelle(Parcelle &other);

    /* Getters */
    int getNumero(void) const;
    string getProprietaire(void) const;
    float getSurface(void) const;
    Polygone<float> getForme(void) const;

    /* Setters */
    void setNumero(int n);
    void setProprietaire(string prop);
    void setForme(Polygone<float> forme);
};