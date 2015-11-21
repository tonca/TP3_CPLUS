#include "rock.h"

using namespace std;

void Rock::deplace()
{
    x = 0;
    y = 0;
    aBouge = true;
    return;
}

char Rock::nom()
{
    return 'R';
}

string Rock::attaquer()
{
    aBouge=false;

    return "PIERRE";
}
