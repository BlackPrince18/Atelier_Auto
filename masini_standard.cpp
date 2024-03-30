#include "masini_standard.h"

Masini_standard::Masini_standard(int a, int b, int c, char d, string e): Masini(a, b, c, d), transimisie(e) {}

void Masini_standard::afisare()
{
    cout<<"Masina Standard:\n";
    cout<<"ID: "<<ID<<endl;
    cout<<"Kilometrii: "<<nr_kilometrii<<endl;
    cout<<"An: "<<an<<endl;
    cout<<"Motorizare: "<<im<<endl;
    cout<<"Transimisie: "<<transimisie<<endl<<endl;
}

void Masini_standard::citire()
{
    cout<<"Masina Standard:\n";
    cout<<"Kilometrii: ";
    cin>>nr_kilometrii;
    cout<<"An: ";
    cin>>an;
    cout<<"Motorizare: ";
    cin>>im;
    cout<<"Transimisie: ";
    cin>>transimisie;
}

int Masini_standard::getAsigurare()
{
    auto now = chrono::system_clock::now();

    time_t now_time = chrono::system_clock::to_time_t(now);

    tm* local_time = localtime(&now_time);

    int c = (local_time->tm_year + 1900) - this->an;

    int asigurare = c * 100;

    if(im == 'D') asigurare = asigurare + 500;
    if(nr_kilometrii > 200000) asigurare = asigurare + 500;

    return asigurare;
}

void Masini_standard::setID(int n)
{
    this->ID = n;
}
