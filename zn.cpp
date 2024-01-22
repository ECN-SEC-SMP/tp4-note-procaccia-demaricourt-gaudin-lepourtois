#pragma once

#include <string>

#include "zn.hpp"

using namespace std;

ZN::ZN(int num, string prop, Polygone<float> forme, int pConstructible) : Parcelle(num, prop, forme, pConstructible) {}
ZN::ZN(Parcelle &other, int pConstructible) : Parcelle(other, pConstructible) {}

ostream &operator<<(ostream &os, ZN const &obj)
{
    os << "Parcelle n°" << to_string(obj.getNumero()) << ":" << endl;
    os << "   Type        : ZN" << endl;
    os << "   Polygone    : " << obj.getForme() << endl;
    os << "   Propriétaire: " << obj.getProprietaire() << endl;
    os << "   Surface     : " << to_string(obj.getSurface()) << endl;
    return os;
}