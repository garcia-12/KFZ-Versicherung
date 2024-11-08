#include "VSchein.h"


VSchein::VSchein(int sNummer, string vName, string nName)
    :scheinnummer(sNummer), vorname(vName), nachname(nName)
{

}

VSchein::~VSchein()
{

}

void VSchein::anpassen()
{

}


int VSchein::getScheinNr() const
{
    return scheinnummer;
}

string VSchein::getVname() const
{
    return vorname;
}

string VSchein::getNname() const
{
    return nachname;
}
