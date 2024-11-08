#include "KFZSchein.h"
#include <iomanip>

KFZSchein::KFZSchein(int sNummer, string vName, string nName)
    :VSchein(sNummer, vName, nName)
{
    cout << "Kennzeichen ?"; cin.ignore(10, '\n'); getline(cin, kfzkennzeichen);
    cout << "Versicherungsbeginn(Jahr) ?"; cin>> vBeginn;
    schadensfreieJahre = 2024 - vBeginn;
    if(schadensfreieJahre < 0)
        schadensfreieJahre = 0;

    KFZSchein::beitragBerechnen(schadensfreieJahre);
}

KFZSchein::~KFZSchein()
{

}

void KFZSchein::anzeigen()
{
    cout << "KFZ-Versicherung: " << kfzkennzeichen << " seit " << vBeginn
         <<"mit der SF-Klasse SF"<<schadensfreieJahre<<" und Monatsbeitrag von ";
    cout << fixed<< setprecision(2)<< beitragBerechnen(schadensfreieJahre)<<" Euro" <<  endl;

}

void KFZSchein::anpassen()
{
    char option;
    cout << "U: Unfall melden"
            "\nW: Fahrzeug wechseln" ;
    cin >> option;
    if (option == 'W' or option == 'w'){
        cout << "Neues KFZ-Kennzeichen ?"; cin.ignore(10, '\n'); getline(cin, kfzkennzeichen);
        cout << "Versicherung auf " << kfzkennzeichen << " umgeschrieben" << endl;
    }
    else if (option == 'U' or option == 'u'){
        int neue_schadensfreieJahre = schadensfreieJahre;
        neue_schadensfreieJahre -= 6;
        if(neue_schadensfreieJahre < 0)
            neue_schadensfreieJahre = 0;
        cout << "Rueckstufung in SF" << neue_schadensfreieJahre<< " erfolgt: Monatsbeitrag stieg von ";
        cout << fixed << setprecision(2) << beitragBerechnen(schadensfreieJahre) << " Euro auf ";
        cout << fixed << setprecision(2)<< beitragBerechnen(neue_schadensfreieJahre) << " Euro"<< endl;
    }
}

double KFZSchein::beitragBerechnen(int sf)
{
    const double Tarif = 68.74;
    if(sf == 0)
        return Tarif*1.5;
    else if(sf == 1)
        return Tarif;
    else if(sf==2)
        return Tarif*0.85;
    else if(sf==3)
        return Tarif*0.7;
    else if (sf==4)
        return Tarif*0.55;
    else
        return Tarif*((50 - sf)/100.0);
}
