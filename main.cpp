#include "angajati.h"
#include "director.h"
#include "mecanic.h"
#include "asistent.h"
#include "function.h"

int main()
{
    Angajat **evidenta;         // Vector pentru evidenta angajatilor
    int numar_angajati = 3;
    int optiune1;               // Optiune pentru a naviga in meniul principal
    int id_counter = 0;         // Contor pentru a incrementa id-ul;

//  Evidenta default

    evidenta = new Angajat*[5];
    Data d2 = initialize_data(24, 2, 1996);
    Data d1 = initialize_data(12, 5, 2012);
    evidenta[0] = new Director(id_counter, "Andrei", "Ionescu", d1, d2, 2);
    evidenta[1] = new Mecanic(id_counter+1, "Mario", "Vlad", d1, d2, 1.5);
    evidenta[2] = new Asistent(id_counter+2, "Mihai", "Georgian", d1, d2, 1);

//  Meniul Principal

    meniu_principal:
    cout<<"\t\tManagement Atelier Auto"<<endl<<endl;
    cout<<"1.\tAngajati"<<endl;
    cout<<"2.\tMasini"<<endl;
    cout<<"3.\tActivitatea Atelierului"<<endl;
    cout<<"4.\tRaportare"<<endl;

    cin>>optiune1;
    switch(optiune1)
    {
    case 1:
        system("cls");

        int optiune2;       // Optiune pentru a naviga in meniul de angajati

        meniu_angajati:
        cout<<"\t\tAngajati"<<endl<<endl;
        cout<<"1.\tAfisare angajati"<<endl;
        cout<<"2.\tAdaugare angajati"<<endl;
        cout<<"3.\tStergere angajati"<<endl;
        cout<<"4.\tEditare angajat"<<endl<<endl;
        cout<<"Apasa tasta '0' pentru meniul principal!\n";
        cin>>optiune2;
        switch(optiune2)
        {
        case 0:
            system("cls");
            goto meniu_principal;
        case 1:
            system("cls");

            afisare_angajati(evidenta, numar_angajati);

            cout<<"Inapoi -> B\n";
            char c1;
            cin>>c1;
            if(c1 == 'B' || c1 == 'b')
            {
                system ("cls");
                goto meniu_angajati;
            }
            break;
        case 2:
            system("cls");

            evidenta = adaugare_angajat(evidenta, numar_angajati);

            char c2;
            cout<<"Inapoi -> B\n";
            cin>>c2;
            if(c2 == 'B' || c2 == 'b')
            {
                system ("cls");
                goto meniu_angajati;
            }
            break;
        case 3:
            system("cls");

            int n1;
            introducere_id1:
            cout<<"Introduceti ID-ul angajatului: ";
            cin>>n1;

            if(n1 > numar_angajati || n1 < 0)
            {
                cout<<"ID-ul introdus nu este in baza de date!\n";
                goto introducere_id1;
            }

            evidenta = stergere_angajat(evidenta, numar_angajati, n1);

            cout<<"Inapoi -> B\n";
            cin>>c2;
            if(c2 == 'B' || c2 == 'b')
            {
                system ("cls");
                goto meniu_angajati;
            }
            break;
        case 4:
            system("cls");

            int n2;
            introducere_id2:
            cout<<"Introduceti ID-ul angajatului: ";
            cin>>n2;

            if(n2 > numar_angajati || n2 < 0)
            {
                cout<<"ID-ul introdus nu este in baza de date!\n";
                goto introducere_id2;
            }

            evidenta[n2]->citire();

            cout<<"Inapoi -> B\n";
            cin>>c2;
            if(c2 == 'B' || c2 == 'b')
            {
                system ("cls");
                goto meniu_angajati;
            }
            break;
        }
    }

    return 0;
}
