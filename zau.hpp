#include "Parcelle.hpp"
#include "constructible.hpp"

class ZAU : public Constructible, public Parcelle
{
public:
    /* Constructors */
    ZAU(int num, string prop, Polygone<float> forme, float pConstructible = 0);
    ZAU(Parcelle &other, float pConstructible = 0);

    /* Setters */
    float surfaceConstructible() const override;

    /* Friends */
    friend ostream &operator<<(ostream &os, ZAU const &obj);
};