#include "animal.h"
#include <iostream>

#ifndef WOLF_H_
#define WOLF_H_

const int PHASE1 = 150;
const int PHASE2 = 400;

class BinomeM_Wolf: public Animal
{
    private:
    int compteur;

    public:
    virtual void deplace();
    virtual char nom();
    virtual string attaquer();

    //contructeur
    BinomeM_Wolf();
    //destructeur
    ~BinomeM_Wolf() {};
};

#endif

