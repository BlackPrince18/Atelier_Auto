#include "angajati.h"
#include "director.h"
#include "mecanic.h"
#include "asistent.h"
#include "masini.h"
#include "masini_standard.h"
#include "camion.h"
#include "autobuz.h"

using namespace std;

Data initialize_data(int x, int y, int z)
{
    Data d;
    d.ziua = x;
    d.luna = y;
    d.an = z;

    return d;
}

void afisare_meniu_principal()
{
    cout<<"\t\tManagement Atelier Auto"<<endl<<endl;
    cout<<"1.\tAngajati"<<endl;
    cout<<"2.\tMasini"<<endl;
    cout<<"3.\tActivitatea Atelierului"<<endl;
    cout<<"4.\tRaportare"<<endl;
}

void afisare_meniu_angajati()
{
    cout<<"\t\tAngajati"<<endl<<endl;
    cout<<"1.\tAfisare angajati"<<endl;
    cout<<"2.\tAdaugare angajati"<<endl;
    cout<<"3.\tStergere angajati"<<endl;
    cout<<"4.\tEditare angajat"<<endl<<endl;
    cout<<"Apasa tasta '0' pentru meniul principal!\n";
}

void afisare_meniu_masini()
{
    cout<<"\t\tMasini"<<endl<<endl;
    cout<<"1.\tAfisare masini"<<endl;
    cout<<"2.\tAdaugare masini"<<endl;
    cout<<"3.\tStergere masini"<<endl;
    cout<<"4.\tEditare masini"<<endl<<endl;
    cout<<"Apasa tasta '0' pentru meniul principal!\n";
}

Angajat** initializare_angajati()
{
    Angajat** vec;
    vec = new Angajat*[3];

    Data d2 = initialize_data(24, 2, 1996);
    Data d1 = initialize_data(12, 5, 2012);
    vec[0] = new Director(0, "Andrei", "Ionescu", d1, d2, 2);
    vec[1] = new Mecanic(1, "Mario", "Vlad", d1, d2, 1.5);
    vec[2] = new Asistent(2, "Mihai", "Georgian", d1, d2, 1);

    return vec;
}

Masini** initializare_masini()
{
    Masini** vec;
    vec = new Masini*[3];

    vec[0] = new Masini_standard(0, 194520, 2010, 'D', "Manual");
    vec[1] = new Autobuz(1, 528008, 2015, 'B', 24);
    vec[2] = new Camion(2, 843020, 2013, 'D', 41.5);

    return vec;
}

void afisare_angajati(Angajat** vec, int dim)
{
    for(int i=0; i<dim; i++)
    {
        vec[i]->afisare();
    }
}

void afisare_masini(Masini** vec, int dim)
{
    for(int i=0; i<dim; i++)
    {
        vec[i]->afisare();
    }
}

int back_function()
{
    cout<<"Inapoi -> B\n";
    char c1;
    cin>>c1;
    if(c1 == 'B' || c1 == 'b')
    {
        system ("cls");
        return 1;
    }
    else return 0;
}

int typeID(int n)
{
    int a;

introducere_id1:
    cout<<"Introduceti ID-ul: ";
    cin>>a;

    if(a > n-1 || a < 0)
    {
        cout<<"ID-ul introdus nu este in baza de date!\n";
        goto introducere_id1;
    }

    return a;
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

Masini** adaugare_masina(Masini** vec, int& dim)
{
    Masini** temp;
    dim++;
    temp = new Masini*[dim];

    for(int i=0; i<dim-1; i++)
    {
        temp[i] = vec[i];
    }

    char verificare;
    inceput:
    cout<<"Masina Standard? Autobuz? Camion? (M/A/C)\n";
    cin>>verificare;

    if(verificare == 'M' || verificare == 'm')
    {
        temp[dim-1] = new Masini_standard;
        temp[dim-1]->citire();
        temp[dim-1]->setID(dim-1);
    }
    else if(verificare == 'A' || verificare == 'a')
    {
        temp[dim-1] = new Autobuz;
        temp[dim-1]->citire();
        temp[dim-1]->setID(dim-1);
    }
    else if(verificare == 'C' || verificare == 'c')
    {
        temp[dim-1] = new Camion;
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

Masini** stergere_masina(Masini** vec, int& dim, int ID)
{
    Masini** temp;
    dim--;
    temp = new Masini*[dim];

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





