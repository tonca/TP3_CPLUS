#include "bear.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Bear::Bear()
{
    x = 0;
    y = 0;
    compteur = 0;
    aBouge=false;
}

void Bear::deplace()
{
    if(compteur<4)
    {
        x=1;
        y=0;
    }
    else if(compteur<8)
        {
            x=0;
            y=1;
        }
        else if(compteur<12)
            {
                x=-1;
                y=0;
            }
            else
            {
                x=0;
                y=-1;
            }
    compteur = (compteur+1)%16;
    aBouge = true;

    return;
}

char Bear::nom()
{
    return 'B';
}

string Bear::attaquer()
{
    aBouge=false;

    return "FEUILLE";
}

