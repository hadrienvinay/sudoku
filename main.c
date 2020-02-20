#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sudoku.h"


int main()
{
    /*int sudoku[size][size]={{0,0,0, 0,0,0, 9,0,7},
                            {0,4,0, 0,0,0, 0,0,0},
                            {1,0,0, 0,0,9, 0,4,0},

                            {7,0,0, 0,0,0, 3,0,1},
                            {0,0,1, 0,8,0, 4,0,0},
                            {5,0,8, 0,0,0, 0,0,2},

                            {0,9,0, 4,0,0, 0,0,8},
                            {0,0,0, 1,2,0, 5,7,0},
                            {8,0,7, 6,0,0, 2,0,0}};*/
    int sudoku[size][size]={{0,0,0, 8,0,0, 2,0,0},
                            {0,4,0, 0,0,0, 0,0,5},
                            {7,0,0, 0,0,0, 3,0,0},

                            {0,0,5, 0,0,1, 0,0,0},
                            {0,0,3, 0,2,7, 0,0,0},
                            {0,2,0, 4,0,0, 0,6,0},

                            {9,0,0, 0,0,5, 0,0,8},
                            {0,8,0, 2,0,0, 0,0,6},
                            {0,0,0, 6,0,0, 0,1,0}};

    int *ptr=&sudoku[0][0];
    int possible[size] = {1,2,3,4,5,6,7,8,9};


    srand(time(NULL));   // Initialization, should only be called once.

    system("COLOR R");
    printf("----------------\n");
    printf("SODUKU RESOLVER : \n");
    printf("----------------\n");

    creationSudoku(sudoku);
    niveau(ptr,4);
    jeu(sudoku,possible,ptr);
    return 0;
}
