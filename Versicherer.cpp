#include "Versicherer.h"

Versicherer::Versicherer()
{

}

Versicherer::~Versicherer()
{
    for(unsigned int i= 0; i <versicherungen.size(); i++){
        delete versicherungen[i];
    }
    versicherungen.clear();
    cout<< "Bis Bald!"<<endl;
}

void Versicherer::dialog()
{
    while (true){
        char eingabe;
        cout << "1: Versicherung anlegen" << endl;
        cout << "2: Versicherungsdetails ausgeben" << endl;
        cout << "3: Alle Versicherungen anzeigen"<<endl;
        cout << "4: Versicherung loeschen"<<endl;
        cout << "5: Versicherung anpassen"<<endl;
        cout << "0: Programm beenden" << endl;
        cin >> eingabe;
        switch(eingabe){
        case '1':{         // Versicherung anlegen
            string vTyp, vName, nName;
            int nummer;
            cout <<"Scheinummer? ";
            cin>> nummer;
            int sNummer = nummerPruefen(nummer);

            cout <<"Vorname?"; cin>> vName;
            cout << "Nachname?"; cin>> nName;

            while(true){
                cout << "K fuer KFZ-Versicherung oder L fuer Lebensversicherung? ";
                cin >> vTyp;

                if (vTyp == "K" || vTyp == "k"){
                    KFZSchein* kfz = new KFZSchein(sNummer, vName, nName);
                    versicherungen.push_back(kfz);
                    cout << "KFZ-Versicherung wurde angelegt" <<endl;
                    break;
                }
                else if (vTyp == "L" || vTyp == "l"){
                    LVSchein* lvs = new LVSchein(sNummer, vName, nName);
                    versicherungen.push_back(lvs);
                    cout << "Lebensversicherung wurde angelegt" <<endl;
                    break;
                }
                else{
                    cout << "Ungueltige Eingabe" << endl;
                }
            }

        }
        break;
        case '2':{         // Versicherungsdetails ausgeben
            int sNummer;
            cout << "scheinnummer?"; cin>> sNummer;

            bool found = false;
            for(VSchein* vs: versicherungen){
                if(sNummer == vs->getScheinNr()){
                    found = true;
                    cout << "Scheinummer: " << vs->getScheinNr() << endl;
                    cout << "VersicherungsNr. "<< vs->getScheinNr() << " fuer " << vs->getVname() << " "<< vs->getNname() <<endl;
                    vs->anzeigen();
                    break;
                }
            }
            if (found == false)
                cout << "Versicherungsschein existiert nicht"<<endl;

//            cout << "------------------------------------------------------"<<endl;
        }
        break;
        case '3':{
            for(VSchein* vs: versicherungen){
                cout << "Scheinummer: " << vs->getScheinNr() << endl;
                cout << "VersicherungsNr. "<< vs->getScheinNr() << " fuer " << vs->getVname() << " "<< vs->getNname() <<endl;
                vs->anzeigen();

                cout << "------------------------------------------------------"<<endl;
            }
        }
        break;
        case '4':{
            int snummer, position =-1;
            cout<< "Scheinummer? " ;
            cin>>snummer;
            bool found = false;
            for(unsigned int i = 0; i < versicherungen.size(); i++){
                position++;
                if(snummer == versicherungen[i]->getScheinNr()){
                    found = true;
                    versicherungen.erase(versicherungen.begin() + (position-1));
                    cout <<"Versicherung Nr. "<< snummer << " wurde geloescht"<<endl<<endl;
                    break;
                }
            }

            if(found == false)
                cout <<"Keine Versicherung zu dieser Nummer gefunden"<<endl<<endl;



        }
        break;
        case '5':{
            int scheinummer;
            cout << "Scheinnummer ? ";
            cin>> scheinummer;
            for(VSchein* vs : versicherungen){
                if(scheinummer == vs->getScheinNr())
                    vs->anpassen();
            }
        }break;
        case '0':         // Programm beenden
            return;
            break;
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}

int Versicherer::nummerPruefen(int sNummer)
{
    while (true) {
        for (VSchein* vsc : versicherungen){
            if(sNummer == vsc->getScheinNr()){
                cout << "Scheinsnummer existiert bereit. Bitte neu eingeben: " <<endl;
                cin>>sNummer;
                break;
            }
        }
        break;
    }
    return sNummer;

}
