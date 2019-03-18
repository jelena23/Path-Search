//
//  main.cpp
//  CS103-PZ02
//
//  Created by Jelena on 12/26/16.
//  Copyright © 2016 Jelena. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include "Dequeue.hpp"

pacijent * prijemPacijenata(void)
{
    pacijent * p = new pacijent;
    
    std::cout << std::endl <<"Unesite podatke o pacijentu: " << std::endl;
    std::cout << std::endl << "Unesite ime pacijenta: " << std::endl;
    std::cin.getline(p->ime, sizeof(p->ime));
    std::cout << std::endl <<"Unesite prezime pacjenta: " << std::endl;
    std::cin.getline(p->prezime, sizeof(p->prezime));
    std::cout << std::endl << "Unesite broj zdravstvene knjizice pacijenta: " << std::endl;
    std::cin.getline(p->brZdravstveneKnjizice, sizeof(p->brZdravstveneKnjizice));
    
    return p;
}


void stampajPacijenta(pacijent *p)
{
    if(p == NULL)
    {
        std::cout << std::endl << "Nema pacijenata koji trenutno cekaju." << std::endl;
        return;
    }
    std::cout << std::endl <<"Podaci o pacijentu: " << std::endl;
    std::cout << "Ime pacijenta: " << p->ime << std::endl;
    std::cout << "Prezime pacijenta: " << p->prezime << std::endl;
    std::cout << "Broj zdravstvene knjizice: " << p->brZdravstveneKnjizice << std::endl;
}


int ReadNumber()
{
    char buffer[20];
    std::cin.getline(buffer, sizeof(buffer));
    return atoi(buffer);
}


void meni(Dequeue * q)
{
    int izbor = 0, success;
    pacijent * p, *p1;
    while(izbor != 6)
    {

        std::cout << std::endl;
        std::cout << "Unesite broj zeljene opcije: " << std::endl;
        std::cout << "1.  Dodajte nekriticnog pacijenta: " << std::endl;
        std::cout << "2.  Dodajte kriticnog pacijenta " << std::endl;
        std::cout << "3.  Prozovi pacijenta" << std::endl;
        std::cout << "4.  Uklonite pacijenta koji je pregledan " << std::endl;
        std::cout << "5.  Prikazi sve pacijente koji cekaju" << std::endl;
        std::cout << "6.  Izlaz\n" << std::endl;
        
        izbor = ReadNumber();
        
        switch (izbor)
        {
            case 1:
                p = prijemPacijenata();
                if(p)
                {
                    success = q->dodajNaKraj(p);
                    if(success)
                    {
                        std::cout << std::endl << "Pacijent je dodat: " << std::endl;
                        stampajPacijenta(p);
                    }
                    else
                    {
                        std::cout << std::endl << "Pacijent nije dodat jer je red popunjen: " << std::endl;
                        stampajPacijenta(p);
                        delete p;
                    }
                    getchar();
                }
                break;
                
            case 2:
                p = prijemPacijenata();
                if(p)
                {
                    success = q->dodajNaPocetak(p);
                    
                    if(success)
                    {
                        std::cout << std::endl << "Pacijent je dodat: " << std::endl;
                        stampajPacijenta(p);
                    }
                    else
                    {
                        std::cout << std::endl << "Pacijent nije dodat jer je red popunjen: " << std::endl;
                        stampajPacijenta(p);
                        delete p;
                    }
                    getchar();
                }
                break;
                
            case 3:
                p = q->getPacijent();
                if(p)
                {
                    std::cout << std::endl << "Prozovi pacijenta: " << std::endl;
                    stampajPacijenta(p);
                    delete p;
                }
                else
                {
                    std::cout << "Nema pacijenata koji cekaju." << std::endl;
                }
                getchar();
                break;
                
            case 4:
                p = prijemPacijenata();
                if(p)
                {
                    p1 = q->ukloniPacijenta(p);
                    if(p1)
                    {
                        std::cout << std::endl << "Pacijent je uklonjen: " << std::endl;
                        delete p;
                    }
                    else
                    {
                        std::cout << std::endl << "Pacijent nije pronadjen." << std::endl;
                        p1 = p;
                    }
                    stampajPacijenta(p1);
                    delete p1;
                    getchar();
                }
                break;
                
            case 5:
                q->stampaj();
                getchar();
                break;
        }
    }
}
int main()
{
    Dequeue q[1];
    meni(q);
}
