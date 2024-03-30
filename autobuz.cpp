#include "autobuz.h"

Autobuz::Autobuz(int a, int b, int c, char d, int e): Masini(a, b, c, d), numar_locuri(e) {}

void Autobuz::afisare()
{
    cout<<"Autobuz:\n";
    cout<<"ID: "<<ID<<endl;
    cout<<"Kilometrii: "<<nr_kilometrii<<endl;
    cout<<"An: "<<an<<endl;
    cout<<"Motorizare: "<<im<<endl;
    cout<<"Numar locuri: "<<numar_locuri<<endl<<endl;
}

void Autobuz::citire()
{
    cout<<"Autobuz:\n";
    cout<<"Kilometrii: ";
    cin>>nr_kilometrii;
    cout<<"An: ";
    cin>>an;
    cout<<"Motorizare: ";
    cin>>im;
    cout<<"Numar locuri: ";
    cin>>numar_locuri;
}

int Autobuz::getAsigurare()
{
    auto now = chrono::system_clock::now();

    time_t now_time = chrono::system_clock::to_time_t(now);

    tm* local_time = localtime(&now_time);

    int c = (local_time->tm_year + 1900) - this->an;

    int asigurare = c * 200;

    if(im == 'D') asigurare = asigurare + 1000;
    if(nr_kilometrii > 100000 && nr_kilometrii <= 200000) asigurare = asigurare + 500;
    if(nr_kilometrii > 200000) asigurare = asigurare + 1000;

    return asigurare;
}

void Autobuz::setID(int n)
{
    this->ID = n;
}
