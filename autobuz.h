#include "masini.h"
#pragma once

class Autobuz : public Masini
{
    int numar_locuri;
public:
    Autobuz()=default;
    Autobuz(int, int, int, char, int);
    ~Autobuz()=default;
    void afisare();
    void citire();
    int getAsigurare();
    void setID(int);
};
