#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#define size 9
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void creationSudoku(int sudoku[size][size]){
    int alea=0;
    int restart = 0;
    int maxCount=0;
    int possible[size] = {1,2,3,4,5,6,7,8,9};

    for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                //update possible line
                reset(possible);
                restart = 0;
                for(int k=1; k<j+1; k++){
                    if(sudoku[i][j-k]!=0){
                        possible[(sudoku[i][j-k])-1]=0;
                    }
                }
                //update possible column
                for(int k=1; k<i+1; k++){
                    if(sudoku[i-k][j]!=0){
                        possible[(sudoku[i-k][j])-1]=0;
                    }
                }
                //update possible block
                if(i%3 != 0){
                    //left bottom
                    if(i%3==1 && j%3==0){
                        if(sudoku[i-1][j+1]!=0){
                            possible[(sudoku[i-1][j+1])-1]=0;
                        }
                        if(sudoku[i-1][j+2]!=0){
                            possible[(sudoku[i-1][j+2])-1]=0;
                        }

                    }
                    //center center
                    if(i%3==1 && j%3==1){
                        if(sudoku[i-1][j-1]!=0){
                            possible[(sudoku[i-1][j-1])-1]=0;
                        }
                        if(sudoku[i-1][j+1]!=0){
                            possible[(sudoku[i-1][j+1])-1]=0;
                        }
                    }
                    //center right
                    if(i%3==1 && j%3==2){
                        if(sudoku[i-1][j-1]!=0){
                            possible[(sudoku[i-1][j-1])-1]=0;
                        }
                        if(sudoku[i-1][j-2]!=0){
                            possible[(sudoku[i-1][j-2])-1]=0;
                        }
                    }
                    //bottom left
                    if(i%3==2 && j%3==0){
                        if(sudoku[i-1][j+1]!=0){
                            possible[(sudoku[i-1][j+1])-1]=0;
                        }
                        if(sudoku[i-1][j+2]!=0){
                            possible[(sudoku[i-1][j+2])-1]=0;
                        }
                        if(sudoku[i-2][j+1]!=0){
                            possible[(sudoku[i-2][j+1])-1]=0;
                        }
                        if(sudoku[i-2][j+2]!=0){
                            possible[(sudoku[i-2][j+2])-1]=0;
                        }
                    }
                    //bottom center
                    if(i%3==2 && j%3==1){
                        if(sudoku[i-1][j-1]!=0){
                            possible[(sudoku[i-1][j-1])-1]=0;
                        }
                        if(sudoku[i-1][j+1]!=0){
                            possible[(sudoku[i-1][j+1])-1]=0;
                        }
                        if(sudoku[i-2][j-1]!=0){
                            possible[(sudoku[i-2][j-1])-1]=0;
                        }
                        if(sudoku[i-2][j+1]!=0){
                            possible[(sudoku[i-2][j+1])-1]=0;
                        }
                    }
                    //bottom right
                    if(i%3==2 && j%3==2){
                        if(sudoku[i-1][j-1]!=0){
                            possible[(sudoku[i-1][j-1])-1]=0;
                        }
                        if(sudoku[i-1][j-2]!=0){
                            possible[(sudoku[i-1][j-2])-1]=0;
                        }
                        if(sudoku[i-2][j-1]!=0){
                            possible[(sudoku[i-2][j-1])-1]=0;
                        }
                        if(sudoku[i-2][j-2]!=0){
                            possible[(sudoku[i-2][j-2])-1]=0;
                        }
                    }
                }

                for(int i=0;i<size;i++){
                    if(possible[i]==0){
                        restart++;
                    }
                }
                if(restart==size){
                    j=0;
                    maxCount++;
                    if(maxCount==100){
                        i=0;
                    }
                    continue;
                }
                alea=rand()%9 + 1;
                while(possible[alea-1] == 0){
                    alea=rand()%9 + 1;
                }
                sudoku[i][j]=alea;
            }

    }
}

void niveau(int *plateau,int level){
    int caseVides = 0;
    int random=0;
    switch(level){
    case 1:
        caseVides=20;
        break;
    case 2:
        caseVides=35;
        break;
    case 3:
        caseVides=50;
        break;
    case 4:
        caseVides=60;
        break;
    default:
        caseVides=0;
        break;
    }
    for(int i=0;i<caseVides;i++){
        random = rand()%81;
        if(*(plateau+random)!=0){
            *(plateau+random)=0;
        }
        else i--;
    }

}

void affiche(int *plateau){
    printf("\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",*(plateau + i * size + j));
            if(j==2 || j==5){
                printf("| ");
            }
        }
        printf("\n");
        if(i==2 || i==5){
            printf("---------------------\n");
        }
    }
    printf("\n\n");

}

void viewUpdate(int a, int b, int *plateau){

    for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==a && j==b){
                    printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET ,*(plateau + i * size + j)); //Display Hello in red
                }
                else if(*(plateau + i * size + j)==0) {
                    printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET ,*(plateau + i * size + j)); //Display Hello in red
                }
                else{
                    printf("%d ",*(plateau + i * size + j));
                }
                if(j==2 || j==5){
                    printf("| ");
                }
            }
            printf("\n");
            if(i==2 || i==5){
                printf("---------------------\n");
            }
        }
        printf("\n\n");

}

bool checkEnd(int *plateau){
    bool finish = true;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(*(plateau + i * size + j)==0){
                finish = false;
                return finish;
            }
        }
    }
    return finish;
}

void updatePossible(int *pos, int *possible){
    if(*pos!=0){
        possible[*pos-1]=0;
    }
}

void reset(int *possible){
    for(int i=0;i<size;i++){
        possible[i] = i+1;
    }
}

int uniquePossibility(int *possible){
    int cpt = 0;
    int select = 0;
    for (int i=0;i<size;i++){
       // printf("Possible : %d\n",possible[i]);
        if(possible[i]!= 0){
            cpt++;
            select = i+1;
        }
    }
    if(cpt==1){
        //printf("Unique found : %d\n",select);
        return select;
    }
    else {
        return 0;
    }
}

void jeu(int sudoku[size][size],int *possible, int *ptr){

    bool finish=false;
    bool gameOver=false;
    int possibleTampon=0;
    int possibleSolutions[size]={1,2,3,4,5,6,7,8,9};
    int possibleSolutionsTampon[size]={1,2,3,4,5,6,7,8,9};
    int possibleSolutionsTampon2[size]={1,2,3,4,5,6,7,8,9};
    int turn=0;
    int count2;
    int copieSudoku[size][size];

    //copie initial soduku
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            copieSudoku[i][j]=sudoku[i][j];
        }
    }
    int multipleSolution=0;
    affiche(ptr);
    while(!finish && !gameOver){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(sudoku[i][j]==0){
                    multipleSolution++;
                   // printf("---- %d : %d;%d --------\n",multipleSolution,i,j);
                    //horizontal check
                    for(int k=0;k<size;k++){
                        updatePossible(&sudoku[i][k],possible);
                    }
                    possibleTampon=uniquePossibility(possible);
                    if(possibleTampon){
                        for(int k=0;k<size;k++){
                        updatePossible(&sudoku[k][j],possible);
                        }
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //vertical check
                    for(int k=0;k<size;k++){
                        updatePossible(&sudoku[k][j],possible);
                    }
                    if(uniquePossibility(possible)){
                        sudoku[i][j]=uniquePossibility(possible);
                        reset(possible);
                        viewUpdate(i,j,ptr);
                        turn++;
                        multipleSolution=0;
                        continue;
                    }
                    //square check
                    //0
                    if((j/3 == 0) && (i/3 == 0)){
                        updatePossible(ptr,possible);
                        updatePossible(ptr+1,possible);
                        updatePossible(ptr+2,possible);
                        updatePossible(ptr+9,possible);
                        updatePossible(ptr+10,possible);
                        updatePossible(ptr+11,possible);
                        updatePossible(ptr+18,possible);
                        updatePossible(ptr+19,possible);
                        updatePossible(ptr+20,possible);

                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //1
                    else if((j/3 == 1) && (i/3 == 0)){
                        updatePossible(ptr+3,possible);
                        updatePossible(ptr+4,possible);
                        updatePossible(ptr+5,possible);
                        updatePossible(ptr+12,possible);
                        updatePossible(ptr+13,possible);
                        updatePossible(ptr+14,possible);
                        updatePossible(ptr+21,possible);
                        updatePossible(ptr+22,possible);
                        updatePossible(ptr+23,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //2
                    else if((j/3 == 2) && (i/3 == 0)){
                        updatePossible(ptr+6,possible);
                        updatePossible(ptr+7,possible);
                        updatePossible(ptr+8,possible);
                        updatePossible(ptr+15,possible);
                        updatePossible(ptr+16,possible);
                        updatePossible(ptr+17,possible);
                        updatePossible(ptr+24,possible);
                        updatePossible(ptr+25,possible);
                        updatePossible(ptr+26,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //3
                    else if((j/3 == 0) && (i/3 == 1)){
                        updatePossible(ptr+27,possible);
                        updatePossible(ptr+28,possible);
                        updatePossible(ptr+29,possible);
                        updatePossible(ptr+36,possible);
                        updatePossible(ptr+37,possible);
                        updatePossible(ptr+38,possible);
                        updatePossible(ptr+45,possible);
                        updatePossible(ptr+46,possible);
                        updatePossible(ptr+47,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //4
                    else if((j/3 == 1) && (i/3 == 1)){
                        updatePossible(ptr+30,possible);
                        updatePossible(ptr+31,possible);
                        updatePossible(ptr+32,possible);
                        updatePossible(ptr+39,possible);
                        updatePossible(ptr+40,possible);
                        updatePossible(ptr+41,possible);
                        updatePossible(ptr+48,possible);
                        updatePossible(ptr+49,possible);
                        updatePossible(ptr+50,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //5
                    else if((j/3 == 2) && (i/3 == 1)){
                        updatePossible(ptr+33,possible);
                        updatePossible(ptr+34,possible);
                        updatePossible(ptr+35,possible);
                        updatePossible(ptr+42,possible);
                        updatePossible(ptr+43,possible);
                        updatePossible(ptr+44,possible);
                        updatePossible(ptr+51,possible);
                        updatePossible(ptr+52,possible);
                        updatePossible(ptr+53,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //6
                    else if((j/3 == 0) && (i/3 == 2)){
                        updatePossible(ptr+54,possible);
                        updatePossible(ptr+55,possible);
                        updatePossible(ptr+56,possible);
                        updatePossible(ptr+63,possible);
                        updatePossible(ptr+64,possible);
                        updatePossible(ptr+65,possible);
                        updatePossible(ptr+72,possible);
                        updatePossible(ptr+73,possible);
                        updatePossible(ptr+74,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //7
                    else if((j/3 == 1) && (i/3 == 2)){
                        updatePossible(ptr+57,possible);
                        updatePossible(ptr+58,possible);
                        updatePossible(ptr+59,possible);
                        updatePossible(ptr+66,possible);
                        updatePossible(ptr+67,possible);
                        updatePossible(ptr+68,possible);
                        updatePossible(ptr+75,possible);
                        updatePossible(ptr+76,possible);
                        updatePossible(ptr+77,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //8
                    else if((j/3 == 2) && (i/3 == 2)){
                        updatePossible(ptr+60,possible);
                        updatePossible(ptr+61,possible);
                        updatePossible(ptr+62,possible);
                        updatePossible(ptr+69,possible);
                        updatePossible(ptr+70,possible);
                        updatePossible(ptr+71,possible);
                        updatePossible(ptr+78,possible);
                        updatePossible(ptr+79,possible);
                        updatePossible(ptr+80,possible);
                        if(uniquePossibility(possible)){
                            sudoku[i][j]=uniquePossibility(possible);
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }
                    //check unique solutions in a square
                    for(int a=0;a<size;a++){
                        possibleSolutions[a]=possible[a];
                        possibleSolutionsTampon[a]=possibleSolutions[a];
                        possibleSolutionsTampon2[a]=possibleSolutions[a];
                    }
                    for(int x=0;x<size/3;x++){
                        for(int y=0;y<size/3;y++){
                            //printf("%d - %d ; %d -- %d ; %d\n",*(ptr+y + x*size + j + i*size - j%3 - i%3*size),i,j,x,y);
                            if(*(ptr+y + x*size + j + i*size - j%3 - i%3*size)==0){
                                for(int k=0;k<size;k++){
                                    //printf("H - %d\n",*(ptr+y + x*size + j + i*size - j%3 - (i%3)*size - y -(j/3)*3 + k));
                                    updatePossible((ptr+y + x*size + j + i*size - j%3 - (i%3)*size - y -(j/3)*3 + k),possibleSolutionsTampon);
                                }
                                for(int k=0;k<size;k++){
                                    //printf("V - %d\n",*(ptr+y + x*size + j + i*size - j%3 - (i%3)*size - x*size -(i/3)*3*size + k*size));
                                    updatePossible((ptr+y + x*size + j + i*size - j%3 - (i%3)*size - x*size -(i/3)*3*size + k*size),possibleSolutionsTampon);
                                }
                                //update and reset possible tabs
                                for(int a=0;a<size;a++){
                                    possibleSolutions[a]+=possibleSolutionsTampon[a];
                                    possibleSolutionsTampon[a] = possibleSolutionsTampon2[a];
                                }
                            }

                        }
                    }
                    for(int a=0;a<size;a++){
                        if(possibleSolutions[a] == possible[a]*2 && possible[a] != 0){
                            sudoku[i][j]=possible[a];
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            turn++;
                            multipleSolution=0;
                            continue;
                        }
                    }

                    //case of multiple possibility in one block
                    if(multipleSolution>90){
                        multipleSolution=0;
                        int countTurn = 0;
                        int guess = 0;
                        int tabGuess[size];
                        for(int l=0;l<size;l++){
                            if(possible[l]!= 0){
                                countTurn++;
                                tabGuess[countTurn-1]=possible[l];
                            }
                        }
                        guess = rand()%(countTurn+1);
                        //if two options take one
                        if(countTurn==0){
                           //printf("AYE AYE RESTART %d - %d - %d\n",i,j,sudoku[i][j]);
                           //gameOver=true;
                           for(int i=0;i<size;i++){
                                for(int j=0;j<size;j++){
                                    sudoku[i][j]=copieSudoku[i][j];
                                }
                            }
                            i=rand()%9;
                            j=rand()%9;

                        }
                        else if(countTurn==2){
                            //printf("GUESS count=2 - %d\n",multipleSolution);
                            guess=tabGuess[rand()%2];
                            sudoku[i][j]=guess;
                            reset(possible);
                            viewUpdate(i,j,ptr);
                            count2=0;
                            multipleSolution=0;
                            turn++;
                        }
                        else{
                           count2++;
                           //printf("%d.\n",countTurn);

                           if(count2>81){
                                //printf("GUESS cout2 > 81 - %d\n",multipleSolution);
                                sudoku[i][j]=guess;
                                reset(possible);
                                viewUpdate(i,j,ptr);
                                count2=0;
                                multipleSolution=0;
                                turn++;
                           }
                        }
                    }
                reset(possible);
                }
            }
        }
        finish = checkEnd(ptr);

    }
    affiche(ptr);
    printf("\n\nFini en %d Etapes !\n",turn,finish);

}


#endif // SUDOKU_H_INCLUDED
