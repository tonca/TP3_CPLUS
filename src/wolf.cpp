#include "wolf.h"
#include <stdlib.h>

using namespace std;

BinomeM_Wolf::BinomeM_Wolf()
{
    x = 0;
    y = 0;
    aBouge = false;
    compteur = 0;
}

void BinomeM_Wolf::deplace()
{
    if(compteur<PHASE1)
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
    }
    else if(compteur<PHASE2)
    {
        y=-1;
        x=0;
    }
    else {
        x=-1;
        y=0;
    }
    aBouge = true;
    compteur++;
    return;
}

char BinomeM_Wolf::nom()
{
    return 'W';
}

string BinomeM_Wolf::attaquer()
{
    aBouge=false;

    if(compteur<PHASE1)
    {
        if(rand()%5000==0) return "CISEAUX";
        else return "FEUILLE";
    }
    else if(compteur<PHASE2)
    {
        if(rand()%5000==0) return "PIERRE";
        else return "CISEAUX";
    }
    else
    {
        if(rand()%5000==0) return "FEUILLE";
        else return "PIERRE";
    }
}


