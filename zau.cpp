#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "Polygone.hpp"
#include "zau.hpp"

using namespace std;

ZAU::ZAU(int num, string prop, Polygone<float> forme, float pConstructible) : Parcelle(num, prop, forme, pConstructible)
{
}
ZAU::ZAU(Parcelle &other, float pConstructible) : Parcelle(other, pConstructible)
{
}

float ZAU::surfaceConstructible() const
{
    return ((getPConstructible() / 100) * this->getSurface());
}

float ZAU::surfaceConstructible() const
{
    return ((getPConstructible() / 100) * this->getSurface());
}

ostream &operator<<(ostream &os, ZAU const &obj)
{
    os << "Parcelle n°" << to_string(obj.getNumero()) << ":" << endl;
    os << "   Type                 : ZAU" << endl;
    os << "   Polygone             : " << obj.getForme() << endl;
    os << "   Propriétaire         : " << obj.getProprietaire() << endl;
    os << "   Surface              : " << to_string(obj.getSurface()) << endl;
    os << "   pConstructible       : " << to_string(obj.getPConstructible()) << "%" << endl;
    os << "   Surface constructible: " << to_string(obj.surfaceConstructible()) << endl;
    return os;
}