#ifndef VSCHEIN_H
#define VSCHEIN_H

#include <string>
#include <vector>
#include <iostream>


using namespace std;

class VSchein //abstrakte Klasse
{
public:
    VSchein(int sNummer, string vName, string nName);
    virtual ~VSchein();
    virtual void anzeigen()  = 0;
    virtual void anpassen();
    int getScheinNr() const;
    string getVname() const;
    string getNname() const;
    bool nummerPruefen(int sNummer);

private:
    int scheinnummer;
    string vorname;
    string nachname;

protected:
        double monatsbeitrag;

};

#endif // VSCHEIN_H
