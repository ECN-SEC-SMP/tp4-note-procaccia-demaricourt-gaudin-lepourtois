#pragma once
#include <string.h>
#include "Polygone.hpp"

/*============================*/
/*         Parcelle()         */
/*============================*/
class Parcelle{
    private:
        int numero;
        string proprietaire;
        float surface;
        Polygone<int> forme;
        int pConstructible;
    public:
        Parcelle(int num, string prop,  Polygone<int> forme);
        Parcelle(Parcelle& parc);
        int getNumero(void) const;
        string getProprietaire(void) const;
        float getSurface(void) const;
        Polygone<int> getForme(void) const;
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<int> _forme);

        friend ostream& operator<<(ostream& s, Parcelle const& p);
};