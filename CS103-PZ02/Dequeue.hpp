//
//  Dequeue.hpp
//  CS103-PZ02
//
//  Created by Jelena on 12/26/16.
//  Copyright © 2016 Jelena. All rights reserved.
//

#ifndef Dequeue_hpp
#define Dequeue_hpp

#include <stdio.h>

#endif /* Dequeue_hpp */

#define MAX 20

struct pacijent
{
    pacijent *next;
    char ime[MAX];
    char prezime[MAX];
    char brZdravstveneKnjizice[MAX];
};

class Dequeue
{
public:
    Dequeue(void);
    ~Dequeue(void);
    int dodajNaKraj(pacijent *p);
    int dodajNaPocetak(pacijent *p);
    pacijent *getPacijent(void);
    pacijent *ukloniPacijenta(pacijent *p);
    void stampaj(void);
protected:
    pacijent *pacijenti[MAX];
    pacijent *prvi, *poslednji;
};
