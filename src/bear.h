#include "animal.h"
#include <iostream>

#ifndef BEAR_H_
#define BEAR_H_

class Bear: public Animal
{
    private:
    int compteur;

    public:
    virtual void deplace();
    virtual char nom();
    virtual string attaquer();

    //contructeur
    Bear();
    //destructeur
    ~Bear() {};
};

#endif

