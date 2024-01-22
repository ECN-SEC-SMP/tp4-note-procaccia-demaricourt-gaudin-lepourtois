#pragma once

#include <string.h>
using namespace std;

#include "constructible.hpp"
#include "zn.hpp"

class ZA : public Constructible, public ZN
{
private:
    string culture = "";

public:
    /* Constructors */
    ZA(int num, string prop, Polygone<float> forme, string culture = "", int pConstructible = 0);
    ZA(Parcelle &other, string culture = "", int pConstructible = 0);

    /* Override */
    float surfaceConstructible() const override;

    /* Setters */
    void setCulture(string culture);

    /* Getters */
    string getCulture() const;

    /* Friends */
    friend ostream &operator<<(ostream &os, ZA const &obj);
};