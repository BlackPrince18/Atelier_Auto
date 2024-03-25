#include "angajati.h"

Angajat::Angajat()
{
    ID = 0;
    Nume = NULL;
    Prenume = NULL;
    Data_Nasterii.ziua = 0;
    Data_Nasterii.luna = 0;
    Data_Nasterii.an = 0;
    Data_Angajarii.ziua = 0;
    Data_Nasterii.luna = 0;
    Data_Nasterii.an = 0;
    Coeficient_Salariat = 0;
}

Angajat::Angajat(int x, char* str1, char* str2, Data date1, Data date2, float coef): ID(x), Data_Angajarii(date1), Data_Nasterii(date2), Coeficient_Salariat(coef)
{
    if(str1 != NULL)
    {
        Nume = new char[strlen(str1)+1];
        strcpy(Nume, str1);
    }
    else Nume = NULL;

    if(str2 != NULL)
    {
        Prenume = new char[strlen(str2)+1];
        strcpy(Prenume, str2);
    }
    else Prenume = NULL;
}

Angajat::Angajat(const Angajat& temp): ID(temp.ID), Data_Nasterii(temp.Data_Nasterii), Data_Angajarii(temp.Data_Angajarii), Coeficient_Salariat(temp.Coeficient_Salariat)
{
    if(temp.Nume != NULL)
    {
        Nume = new char[strlen(temp.Nume)+1];
        strcpy(Nume, temp.Nume);
    }
    else Nume = NULL;

    if(temp.Prenume != NULL)
    {
        Prenume = new char[strlen(temp.Prenume)+1];
        strcpy(Prenume, temp.Prenume);
    }
    else Prenume = NULL;
}

Angajat& Angajat::operator=(const Angajat& temp)
{
    if(this != &temp)
    {
        ID = temp.ID;
        Data_Nasterii = temp.Data_Nasterii;
        Data_Angajarii = temp.Data_Angajarii;
        Coeficient_Salariat = temp.Coeficient_Salariat;

        if(temp.Nume != NULL)
        {
            Nume = new char[strlen(temp.Nume)+1];
            strcpy(Nume, temp.Nume);
        }
        else Nume = NULL;

        if(temp.Prenume != NULL)
        {
            Prenume = new char[strlen(temp.Prenume)+1];
            strcpy(Prenume, temp.Prenume);
        }
        else Prenume = NULL;

        return *this;
    }
    else return *this;
}

Angajat::~Angajat()
{
    delete [] Nume;
    delete [] Prenume;
}
