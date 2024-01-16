#pragma once
#include <string.h>
#include "Polygone.hpp"

class Parcelle{
    private:
        string type;
        int numero;
        string proprietaire;
        float surface;
        Polygone<int,float> forme;
        int pConstructible;
    public:
        Parcelle(int num, string prop,  Polygone<int,float> forme);
        Parcelle(Parcelle parc);
        int getNumero(void);
        string getProprietaire(void);
        float getSurface(void);
        Polygone<int,float> getForme(void);
        string getType(void);
        void setNumero(int n);
        void setProprietaire(string prop);
        void setForme(Polygone<int,float> forme);
        void setType(string type);
};