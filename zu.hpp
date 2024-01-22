#include "zau.hpp"

class ZU : public ZAU
{
private:
    float surfaceConstruite = 0;

public:
    /* Constructors */
    ZU(int num, string prop, Polygone<float> forme, float pConstructible = 0, float sConstruite = 0);
    ZU(Parcelle &other, float pConstructible = 0, float sConstruite = 0);

    /* Setters */
    float surfaceConstructible() const override;
    void setSurfaceConstruite(float surface);

    /* Getters */
    float getSurfaceConstruite() const;

    /* Friends */
    friend ostream &operator<<(ostream &os, ZU const &obj);
};