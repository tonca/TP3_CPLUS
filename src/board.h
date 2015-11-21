#include "animal.h"
#include <vector>
#ifndef TP3_BOARD_H
#define TP3_BOARD_H

class Board
{
    private:
    static const int N_SIZE = 82;
    static const int N_TYPE = 4;

    cases board[N_SIZE][N_SIZE];
    void deplaceAnimal(int y, int x);
    int combatCouple(int i, int j, int combA, int CombB);

    public:

    void deplace();
    void combat();
    void affiche();
    void stat();

    //constucteur avec les animaux
    Board();

};

#endif
