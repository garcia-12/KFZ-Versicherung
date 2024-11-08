#include "LVSchein.h"
#include <iomanip>


LVSchein::LVSchein(int sNummer, string vName, string nName)
    :VSchein(sNummer, vName, nName)
{
    cout <<"Versicherungssumme ?"; cin>> vSumme;
    cout << "Versicherungsbeginn(Jahr) ?"; cin >> vBeginn;
    cout << "Lauftzeit ?"; cin>> laufzeit;
    beitragBerechnen(vSumme);
}

LVSchein::~LVSchein()
{

}

void LVSchein::anzeigen()
{
    cout << "Lebensversicherung ueber " << vSumme <<" Euro seit " << vBeginn << " mit Laufzeit von "
         << laufzeit << " Jahren"<<" und Monatsbeitrag von ";
    cout <<fixed<<setprecision(2)<< beitragBerechnen(vSumme)<<endl;
}

void LVSchein::anpassen()
{
    char option;
    double NeueSumme;
    cout <<"Versicherungssumme aendern ?"
            "\nJa(J) und Nein(N)";
    cin >> option;
    if (option == 'j' or option == 'J')
        cout << "Neue Versicherungssumme ?"; cin >> NeueSumme;
    cout <<"Neue LV-Summe: "<< NeueSumme <<endl;
    cout << "Der Monatsbeitrag der LV betraegt nun " << beitragBerechnen(NeueSumme)<< " EUro, zuvor waren es "
         << beitragBerechnen(vSumme) << " Euro"<<endl;

    vSumme = NeueSumme;
}

double LVSchein::beitragBerechnen(double vs)
{
    return ((3.52/100000.0)*vs);
}
