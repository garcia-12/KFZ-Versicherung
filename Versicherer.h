#ifndef VERSICHERER_H
#define VERSICHERER_H

#include "VSchein.h"
#include "KFZSchein.h"
#include "LVSchein.h"

#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Versicherer
{
public:
    Versicherer();
    ~Versicherer();
    void dialog();
    int nummerPruefen(int sNummer);

private:
    std::vector <VSchein*> versicherungen;
};

#endif // VERSICHERER_H
