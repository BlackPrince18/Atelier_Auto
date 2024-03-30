#include "camion.h"

Camion::Camion(int a, int b, int c, char d, float e): Masini(a, b, c, d), tonaj(e) {}

void Camion::afisare()
{
    cout<<"Camion:\n";
    cout<<"ID: "<<ID<<endl;
    cout<<"Kilometrii: "<<nr_kilometrii<<endl;
    cout<<"An: "<<an<<endl;
    cout<<"Motorizare: "<<im<<endl;
    cout<<"Tonaj: "<<tonaj<<endl<<endl;
}

void Camion::citire()
{
    cout<<"Camion:\n";
    cout<<"Kilometrii: ";
    cin>>nr_kilometrii;
    cout<<"An: ";
    cin>>an;
    cout<<"Motorizare: ";
    cin>>im;
    cout<<"Tonaj: ";
    cin>>tonaj;
}

int Camion::getAsigurare()
{
    auto now = chrono::system_clock::now();

    time_t now_time = chrono::system_clock::to_time_t(now);

    tm* local_time = localtime(&now_time);

    int c = (local_time->tm_year + 1900) - this->an;

    int asigurare = c * 300;

    if(im == 'D') asigurare = asigurare + 1000;
    if(nr_kilometrii > 800000) asigurare = asigurare + 7000;

    return asigurare;
}

void Camion::setID(int n)
{
    this->ID = n;
}
