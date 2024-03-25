#include "angajati.h"
#pragma once

class Asistent: public Angajat
{
public:
    Asistent();
    Asistent(int, char*, char*, Data, Data, float);
    Asistent(const Asistent&);
    Asistent& operator=(const Asistent&);
    ~Asistent();
    void afisare();
    void citire();
    void setID(int);
};
