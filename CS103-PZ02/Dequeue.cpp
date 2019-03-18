//
//  Dequeue.cpp
//  CS103-PZ02
//
//  Created by Jelena on 12/26/16.
//  Copyright © 2016 Jelena. All rights reserved.
//

#include "Dequeue.hpp"
#include <iostream>

Dequeue::Dequeue()
{
    prvi = poslednji = NULL;
}


Dequeue::~Dequeue()
{
    pacijent *p1, *p2;
    for (p1 = prvi; p1; )
    {
        p2 = p1;
        p1 = p1->next;
        delete p2;
    }
}
int Dequeue::dodajNaKraj(pacijent *p)
{
    if(p == NULL)
    {
        return 0;
    }
    if(prvi)
    {
        poslednji->next = p;
        poslednji = p;
    }
    else
    {
        prvi = poslednji = p;
    }
    p->next = NULL;
    
    return 1;
}
int Dequeue::dodajNaPocetak(pacijent *p)
{
    if(p == NULL)
    {
        return 0;
    }
    if(prvi)
    {
        p->next = prvi;
        prvi = p;
    }
    else
    {
        prvi = poslednji = p;
        p->next = NULL;
    }
    return 1;
}
pacijent * Dequeue::getPacijent(void)
{
    pacijent * p;
    if(prvi)
    {
        p = prvi;
        prvi = prvi->next;
    }
    else
    {
        p = NULL;
    }
    
    return p;
}
pacijent * Dequeue::ukloniPacijenta(pacijent * p)
{
    pacijent * p1, *p2 = NULL;
    
    for(p1 = prvi; p1; p1 = p1->next)
    {
        if(strcmp(p1->brZdravstveneKnjizice, p->brZdravstveneKnjizice) == 0)
        {
            if(p1 == prvi)
            {
                prvi = prvi->next;
            }
            if(p1 == poslednji)
            {
                poslednji = p2;
            }
            if(p2)
            {
                p2->next = p1->next;
            }
            
            return p1;
        }
        
        p2 = p1;
    }
    return NULL;
}
void Dequeue::stampaj()
{
    pacijent *temp;
    if(prvi)
    {
        std::cout << "Pacijenti koji cekaju: " << std::endl;
        for(temp = prvi; temp; temp = temp->next)
        {
            std::cout << std::endl << temp->ime;
            std::cout << " " << temp->prezime;
            std::cout << " " << temp->brZdravstveneKnjizice;
        }
    }
    else
    {
        std::cout << std::endl << "Nema pacijenata koji cekaju." << std::endl;
    }
}
