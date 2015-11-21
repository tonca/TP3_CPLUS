#include "animal.h"
#include "board.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand (time(NULL));

    Board board;
    int n_cycles = 1000;

    board.affiche();

    board.stat();

    for(int i(0); i<n_cycles; i++)
    {
        board.deplace();

        board.combat();

        //board.affiche();
        board.stat();
        cout<<"tour :"<<i<<endl;
    }

    return 0;
}
