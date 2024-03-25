#include "angajati.h"
#pragma once

class Mecanic: public Angajat
{
public:
    Mecanic();
    Mecanic(int, char*, char*, Data, Data, float);
    Mecanic(const Mecanic&);
    Mecanic& operator=(const Mecanic&);
    ~Mecanic();
    void afisare();
    void citire();
    void setID(int);
};
