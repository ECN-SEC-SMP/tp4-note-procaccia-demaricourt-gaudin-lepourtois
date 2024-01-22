#pragma once

#include "Parcelle.hpp"

class ZN : public Parcelle
{
public:
    /* Constructors */
    ZN(int num, string prop, Polygone<int> forme, int pConstructible = 0);
    ZN(Parcelle &other, int pConstructible = 0);

    /* Getter */
    int getPConstructible() const;

    /* Setter */
    void setPConstructible(int pConstructible);

    /* Friends */
    friend ostream &operator<<(ostream &os, ZN const &obj);
};