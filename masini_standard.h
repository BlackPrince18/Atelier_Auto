#include "masini.h"
#pragma once

class Masini_standard : public Masini
{
    string transimisie;
public:
    Masini_standard()=default;
    Masini_standard(int, int, int, char, string);
    ~Masini_standard()=default;
    void afisare();
    void citire();
    int getAsigurare();
    void setID(int);
};

