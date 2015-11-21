#include "lion.h"
#include <stdlib.h>

using namespace std;

Lion::Lion()
{
    x = 0;
    y = 0;
    aBouge = false;
    compteur = rand();
}

void Lion::deplace()
{
    if(compteur%2==0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        x = 0;
        y = 1;
    }
    aBouge = true;
    compteur++;
    return;
}

char Lion::nom()
{
    return 'L';
}

string Lion::attaquer()
{
    aBouge=false;

    if(rand()%2==0) return "FEUILLE";
    else return "CISEAUX";
}

