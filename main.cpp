#include "function.h"

int main()
{
    int x, optiune1;                                // Variabile auxiliare pentru a naviga in meniu
    int numar_angajati = 3, numar_masini = 3;
    int n1;                                         // Variabila auxiliara pentru verficarea ID-ului

//  Evidenta default angajati si masini

    Angajat** evidenta = new Angajat*[3];
    evidenta = initializare_angajati();

    Masini** masini = new Masini*[3];
    masini = initializare_masini();

meniu_principal:
    afisare_meniu_principal();

    cin>>optiune1;
    switch(optiune1)
    {
    case 1:

        system("cls");
        int optiune2;

meniu_angajati:
        afisare_meniu_angajati();

        cin>>optiune2;
        switch(optiune2)
        {
        case 0:
            system("cls");
            goto meniu_principal;

        case 1:
            system("cls");

            afisare_angajati(evidenta, numar_angajati);

            x = back_function();
            if(x) goto meniu_angajati;
            else return 0;

        case 2:
            system("cls");

            evidenta = adaugare_angajat(evidenta, numar_angajati);

            x = back_function();
            if(x) goto meniu_angajati;
            else return 0;

        case 3:
            system("cls");

            n1 = typeID(numar_angajati);
            evidenta = stergere_angajat(evidenta, numar_angajati, n1);

            x = back_function();
            if(x) goto meniu_angajati;
            else return 0;

        case 4:
            system("cls");

            n1 = typeID(numar_angajati);
            evidenta[n1]->citire();

            x = back_function();
            if(x) goto meniu_angajati;
            else return 0;
        }
    case 2:

        system("cls");
        int optiune3;

meniu_masini:
        afisare_meniu_masini();

        cin>>optiune3;
        switch(optiune3)
        {
        case 0:
            system("cls");
            goto meniu_principal;

        case 1:
            system("cls");

            afisare_masini(masini, numar_masini);

            x = back_function();
            if(x) goto meniu_masini;
            else return 0;

        case 2:
            system("cls");

            masini = adaugare_masina(masini, numar_masini);

            x = back_function();
            if(x) goto meniu_masini;
            else return 0;

        case 3:
            system("cls");

            n1 = typeID(numar_masini);
            masini = stergere_masina(masini, numar_masini, n1);

            x = back_function();
            if(x) goto meniu_masini;
            else return 0;
        case 4:
            system("cls");

            n1 = typeID(numar_masini);
            masini[n1]->citire();

            x = back_function();
            if(x) goto meniu_masini;
            else return 0;
        }
    }

    return 0;
}
