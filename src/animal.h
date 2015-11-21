#include <iostream>
#include <vector>

using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal
{

protected:
    //les entiers contient les valeurs relatifs du deplacement
    int x;
    int y;

    bool aBouge;

public:
    //destructeur
    virtual ~Animal() {};

    virtual void deplace()=0;
    virtual char nom()=0;
    virtual string attaquer()=0;

    int getX()
    {
        return x;
    };
    int getY()
    {
        return y;
    };
    bool getaBouge()
    {
        return aBouge;
    };



    void suicide()
    {
        this->~Animal();
    };
};

class Coordonnees
{
public:
    int x; // entre 0 et 82
    int y; // entre 0 et 82
};


typedef vector<Animal*> cases;




#endif /* ANIMAUX_H_ */
