#include "animal.h"
#include <iostream>

#ifndef LION_H_
#define LION_H_

class Lion: public Animal
{
    private:
    int compteur;

    public:
    virtual void deplace();
    virtual char nom();
    virtual string attaquer();

    //contructeur
    Lion();
    //destructeur
    ~Lion() {};
};

#endif
