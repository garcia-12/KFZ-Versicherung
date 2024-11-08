#ifndef LVSCHEIN_H
#define LVSCHEIN_H
#include "VSchein.h"

#include <string>
#include <vector>
#include <iostream>


using namespace std;
class LVSchein :public VSchein
{
public:
    LVSchein(int sNummer, string vName, string nName);
    virtual ~LVSchein();
    void anzeigen()  override;
    void anpassen() override;
    double beitragBerechnen(double vs);

private:
    double vSumme;
    int vBeginn;
    int laufzeit;
};

#endif // LVSCHEIN_H
