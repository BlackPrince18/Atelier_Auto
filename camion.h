#include "masini.h"
#pragma once

class Camion : public Masini
{
    float tonaj;
public:
    Camion()=default;
    Camion(int, int, int, char, float);
    ~Camion()=default;
    void afisare();
    void citire();
    int getAsigurare();
    void setID(int);
};
