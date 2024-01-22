#pragma once
#include <string.h>
#include "Polygone.hpp"

/*============================*/
/*         Parcelle()         */
/*============================*/
class Parcelle{
    private:
        string type;
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
        string getType(void) const;
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<int> _forme);
        virtual void setType(string t);

        friend ostream& operator<<(ostream& s, Parcelle const& p);
};