#include "animal.h"
#include <iostream>

#ifndef ROCK_H_
#define ROCK_H_

class Rock: public Animal
{
    virtual void deplace();
    virtual char nom();
    virtual string attaquer();

    //destructeur
    ~Rock() {};
};

#endif
