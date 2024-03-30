#include "angajati.h"
#pragma once

class Masini
{
protected:
    int ID;
    int nr_kilometrii;
    int an;
    char im;
public:
    Masini()=default;
    Masini(int, int, int, char);
    ~Masini()=default;
    virtual void afisare()=0;
    virtual void citire()=0;
    virtual int getAsigurare()=0;
    virtual void setID(int)=0;
};
