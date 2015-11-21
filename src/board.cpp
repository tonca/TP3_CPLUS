#include "board.h"
#include "animal.h"
#include "rock.h"
#include "lion.h"
#include "bear.h"
#include "wolf.h"
#include <stdlib.h>
#include <iostream>
#include <vector>



//contructor de une board initialisée avec les animaux
Board::Board()
{
    //nombre animaux pour chaque type
    int n_anim = N_SIZE*N_SIZE/(4*N_TYPE);

    for(int i=0; i<N_SIZE; i++)
    {
        for(int j=0; j<N_SIZE; j++)
        {
            board[i][j].clear();
        }
    }
    for(int i=0; i<n_anim; i++)
    {
        int a=rand()%N_SIZE,b=rand()%N_SIZE;
        while(!board[a][b].empty())
        {
            a=rand()%N_SIZE;
            b=rand()%N_SIZE;
        }
        board[a][b].push_back(new Rock());
    }

    for(int i=0; i<n_anim; i++)
    {
        int a=rand()%N_SIZE,b=rand()%N_SIZE;
        while(!board[a][b].empty())
        {
            a=rand()%N_SIZE;
            b=rand()%N_SIZE;
        }
        board[a][b].push_back(new Lion());
    }
    for(int i=0; i<n_anim; i++)
    {
        int a=rand()%N_SIZE,b=rand()%N_SIZE;
        while(!board[a][b].empty())
        {
            a=rand()%N_SIZE;
            b=rand()%N_SIZE;
        }
        board[a][b].push_back(new Bear());
    }
    for(int i=0; i<n_anim; i++)
    {
        int a=rand()%N_SIZE,b=rand()%N_SIZE;
        while(!board[a][b].empty())
        {
            a=rand()%N_SIZE;
            b=rand()%N_SIZE;
        }
        board[a][b].push_back(new BinomeM_Wolf());
    }

}

//methode a appeler pour chaque case pour bouger les animaux, quand il sont un seul par case
void Board::deplaceAnimal(int i, int j)
{
    //si la case n'est pas vide et si l'animal n'a pas bouge
    if(!board[i][j].empty() && !board[i][j].front()->getaBouge())
    {
        Animal* animal = board[i][j].front();

        animal->deplace();

        //les deplacements relatifs
        int dY = animal->getY();
        int dX = animal->getX();

        if(dY!=0 || dX!=0)
        {
            //nouvelles coordonnees
            int newI = (i+dY+N_SIZE)%N_SIZE;
            int newJ = (j+dX+N_SIZE)%N_SIZE;

            //on insert l'animal dans la nouvelle case
            board[newI][newJ].push_back(animal);

            //on elimine l'animal de la vieille case
            board[i][j][0]=board[i][j].back();
            board[i][j].resize(board[i][j].size()-1);


        }
    }
}

void Board::deplace()
{
    for(int i(0); i<N_SIZE; i++)
    {
        for(int j(0); j<N_SIZE; j++)
        {
            deplaceAnimal(i,j);
        }
    }
    return;

}

//il donne en sortie l'index du perdant
int Board::combatCouple(int i, int j,int combA, int combB)
{
    //on initialise la sortie
    int p=-1;

    //on designe les attaques des animaux combattants
    //les attaques doivent etre differents
    string a = board[i][j][combA]->attaquer();
    string b = board[i][j][combB]->attaquer();
    while(a == b)
    {
        a = board[i][j][combA]->attaquer();
        b = board[i][j][combB]->attaquer();
    }

    //les differentes combinaisons possibles...
    if(a == "PIERRE")
    {
        if(b == "FEUILLE") p=combA;
        else p=combB;
    }
    if(a == "FEUILLE")
    {
        if(b == "CISEAUX") p=combA;
        else p=combB;
    }
    if(a == "CISEAUX")
    {
        if(b == "PIERRE") p=combA;
        else p=combB;
    }

    return p;
}

void Board::combat()
{
    //pour chaque case
    for(int i(0); i<N_SIZE; i++)
    {
        for(int j(0); j<N_SIZE; j++)
        {
            //on memorise la taille du vecteur
            int size = board[i][j].size();

            //si n'est pas vide
            if(size!=0)
            {
                //on fait combattre size-1 couple aleatories d'animaux
                for(int l=0; l<size-1; l++)
                {
                    //on trouve des indices random differents
                    int a=rand()%(size-l),b=rand()%(size-l);
                    while(a==b)
                    {
                        a = rand()%(size-l);
                        b = rand()%(size-l);
                    }
                    int p = combatCouple(i,j,a,b);
                    //board[i][j][p]->suicide();
                    board[i][j][p] = board[i][j][size-l-1];
                }

                board[i][j].resize(1);

                //pour reintialiser toutes les flags aBouge à false
                board[i][j][0]->attaquer();
            }
        }
    }
}

//il doit etre appellé toujours après la fonction combatCase(),
//de façon que il y ait un seul animal par case
void Board::affiche()
{
    for(int i(0); i<N_SIZE; i++) cout << "====";
    cout <<"="<< endl;

    for(int i=0; i<N_SIZE; i++)
    {
        cout << "| ";
        for(int j=0; j<N_SIZE; j++)
        {
            if(board[i][j].empty()) cout << "_";
            else cout << board[i][j].front()->nom();

            cout << " | ";
        }
        cout << endl;
    }

    for(int i(0); i<N_SIZE; i++) cout << "====";
    cout <<"="<< endl;
}

//fonction pour afficher les statistiques
void Board::stat()
{
    int R(0),L(0),B(0),W(0);
    for(int i=0; i<N_SIZE; i++)
    {
        for(int j=0; j<N_SIZE; j++)
        {
            if(!board[i][j].empty())
                switch(board[i][j].front()->nom())
                {
                case 'R' :
                    R++;
                    break;
                case 'L' :
                    L++;
                    break;
                case 'B' :
                    B++;
                    break;
                case 'W' :
                    W++;
                    break;
                }
        }
    }
    int dead = N_SIZE*N_SIZE/(4*N_TYPE)-W;
    cout<<"-----------"<<endl;
    cout << "-Rock : "<<R<<" -";
    cout<<"\n-Lion : "<<L<<" -";
    cout<<"\n-Bear : "<<B<<" -";
    cout<<"\n-Wolf : "<<W<<" -";
    cout<<"\n-Dead Wolves : "<<dead<<endl;
    cout<<"-----------"<<endl;

}
