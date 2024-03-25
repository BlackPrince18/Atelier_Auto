#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <ctime>
#pragma once

using namespace std;

struct Data
{
    int ziua;
    int luna;
    int an;
};

typedef struct Data Data;

class Angajat
{
protected:
    int ID;
    char* Nume;
    char* Prenume;
    Data Data_Nasterii;
    Data Data_Angajarii;
    float Coeficient_Salariat;
public:
    Angajat();
    Angajat(int, char*, char*, Data, Data, float);
    Angajat(const Angajat&);
    Angajat& operator=(const Angajat&);
    virtual ~Angajat();
    virtual void afisare()=0;
    virtual void citire()=0;
    virtual void setID(int)=0;
};

