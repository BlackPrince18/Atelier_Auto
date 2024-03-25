#include <iostream>
#include "angajati.h"
#include "director.h"
#include "mecanic.h"
#include "asistent.h"

using namespace std;

Data initialize_data(int x, int y, int z)
{
    Data d;
    d.ziua = x;
    d.luna = y;
    d.an = z;

    return d;
}

void afisare_angajati(Angajat** vec, int dim)
{
    for(int i=0; i<dim; i++)
    {
        vec[i]->afisare();
    }
}

Angajat** adaugare_angajat(Angajat** vec, int& dim)
{
    Angajat** temp;
    dim++;
    temp = new Angajat*[dim];

    for(int i=0; i<dim-1; i++)
    {
        temp[i] = vec[i];
    }

    char verificare;
    inceput:
    cout<<"Director? Mecaninc? Asistent? (D/M/A)\n";
    cin>>verificare;

    if(verificare == 'D' || verificare == 'd')
    {
        temp[dim-1] = new Director;
        temp[dim-1]->citire();
        temp[dim-1]->setID(dim-1);
    }
    else if(verificare == 'M' || verificare == 'm')
    {
        temp[dim-1] = new Mecanic;
        temp[dim-1]->citire();
        temp[dim-1]->setID(dim-1);
    }
    else if(verificare == 'A' || verificare == 'a')
    {
        temp[dim-1] = new Asistent;
        temp[dim-1]->citire();
        temp[dim-1]->setID(dim-1);
    }
    else
    {
        cout<<"Caracterul introdus nu este corect!\n";
        goto inceput;
    }

    delete [] vec;

    return temp;
}

Angajat** stergere_angajat(Angajat** vec, int& dim, int ID)
{
    Angajat** temp;
    dim--;
    temp = new Angajat*[dim];

    for(int i=0; i<dim; i++)
    {
        if(i < ID)
        {
            temp[i] = vec[i];
        }
        else temp[i] = vec[i+1];
    }

    for(int i=0; i<dim; i++)
    {
        temp[i]->setID(i);
    }

    delete [] vec;

    return temp;
}





