#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H

#include "VSchein.h"

#include <string>
#include <vector>
#include <iostream>


using namespace std;

class KFZSchein: public VSchein
{
public:
    KFZSchein(int sNummer, string vName, string nName);
    virtual ~KFZSchein();
    void anzeigen()  override;
    void anpassen() override;
    double beitragBerechnen(int sf);

private:
    string kfzkennzeichen;
    int vBeginn;
    int schadensfreieJahre;
};

#endif // KFZSCHEIN_H
