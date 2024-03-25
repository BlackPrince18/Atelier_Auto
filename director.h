#include "angajati.h"
#pragma once

class Director : public Angajat
{
public:
    Director();
    Director(int, char*, char*, Data, Data, float);
    Director(const Director&);
    Director& operator=(const Director&);
    void citire();
    void setID(int);
    ~Director();
    void afisare();
};

