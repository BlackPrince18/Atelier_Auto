#include "mecanic.h"

Mecanic::Mecanic(): Angajat() {}

Mecanic::Mecanic(int a, char* b, char* c, Data d, Data e, float f): Angajat(a, b, c, d, e, f) {}

Mecanic::Mecanic(const Mecanic& temp): Angajat(temp) {}

Mecanic& Mecanic::operator=(const Mecanic& temp) { Angajat::operator=(temp); return *this; }

void Mecanic::citire()
{
    char buffer[256];
    cout<<"Mecanic:\n";

    introducere_nume:
    cout<<"Nume: "; cin>>buffer;
    if(buffer == NULL || strlen(buffer) > 31)
    {
        cout<<"Numele introdus nu este compatibil!\n";
        goto introducere_nume;
    }
    else
    {
        this->Nume = new char[strlen(buffer)+1];
        strcpy(this->Nume, buffer);
    }

    introducere_prenume:
    cout<<"Prenume: "; cin>>buffer;
    if(buffer == NULL || strlen(buffer) > 31)
    {
        cout<<"Numele introdus nu este compatibil!\n";
        goto introducere_prenume;
    }
    else
    {
        this->Prenume = new char[strlen(buffer)+1];
        strcpy(this->Prenume, buffer);
    }

    introducere_dataa:
    cout<<"Data angajarii: "; cin>>this->Data_Angajarii.ziua>>this->Data_Angajarii.luna>>this->Data_Angajarii.an;

    int a, b, c;
    auto now = chrono::system_clock::now();

    time_t now_time = chrono::system_clock::to_time_t(now);

    tm* local_time = localtime(&now_time);

    a = local_time->tm_mday;
    b = local_time->tm_mon + 1;
    c = local_time->tm_year + 1900;

    if(c - this->Data_Angajarii.an <= 0)
    {
        if(b - this->Data_Angajarii.luna <=0 && a - this->Data_Angajarii.ziua < 0)
        {
            cout<<"Data angajarii nu poate fi o data din viitor!";
            goto introducere_dataa;
        }
    }

    introducere_datan:
    cout<<"Data nasterii: "; cin>>this->Data_Nasterii.ziua>>this->Data_Nasterii.luna>>this->Data_Nasterii.an;

    if(this->Data_Angajarii.an - this->Data_Nasterii.an < 18)
    {
        cout<<"Angajatul introdus nu a avut 18 ani impliniti in ziua angajarii!\n";
        goto introducere_datan;
    }
    else if(this->Data_Angajarii.an - this->Data_Nasterii.an == 18)
    {
        if(this->Data_Angajarii.luna - this->Data_Nasterii.luna > 0)
        {
            cout<<"Angajatul introdus nu a avut 18 ani impliniti in ziua angajarii!\n";
            goto introducere_datan;
        }
        else if(this->Data_Angajarii.ziua - this->Data_Nasterii.ziua < 0)
        {
            cout<<"Angajatul introdus nu a avut 18 ani impliniti in ziua angajarii!\n";
            goto introducere_datan;
        }
    }

    this->Coeficient_Salariat = 1.5;
}

void Mecanic::afisare()
{
    cout<<"Mecanic:\n";
    cout<<"ID: "<<ID<<endl;
    cout<<"Nume: "<<Nume<<endl;
    cout<<"Prenume: "<<Prenume<<endl;
    printf("Data_Nasterii: %02d.%02d.%d\n", Data_Nasterii.ziua, Data_Nasterii.luna, Data_Nasterii.an);
    printf("Data_Angajarii: %02d.%02d.%d\n", Data_Angajarii.ziua, Data_Angajarii.luna, Data_Angajarii.an);
    cout<<"Coeficient_Salariat: "<<Coeficient_Salariat<<endl<<endl;
}

void Mecanic::setID(int n)
{
    this->ID = n;
}

float Mecanic::getSalariu()
{
    auto now = chrono::system_clock::now();

    time_t now_time = chrono::system_clock::to_time_t(now);

    tm* local_time = localtime(&now_time);

    int ani_vechime = local_time->tm_year + 1900 - this->Data_Angajarii.an;

    if(ani_vechime == 0)
        return this->Coeficient_Salariat * 1000;
    else return ani_vechime * this->Coeficient_Salariat * 1000;
}

Mecanic::~Mecanic() { delete [] Nume; delete [] Prenume; }
