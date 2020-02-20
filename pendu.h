#ifndef PENDU_H_INCLUDED
#define PENDU_H_INCLUDED

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

void pendu(){
     char motSecret[] = "TEST";
    char motActuel[] = "****";
    char historique[100] = {0};
    char letter;
    bool vu = false;
    int compt =0,compt1 = 0,turn = 0;
    printf("Bienvenue dans le Pendu !\n\n");
    printf("MOT A DEVINER : %s\n",motActuel);

    while(compt < sizeof(motSecret)){
        turn++;
        letter = lireCaractere();
        historique[turn]='a';
        printf("Historique : %s\n",strlen(historique));
        for(int i=0;i<strlen(historique);i++){
            if(letter == historique[i]){
                //printf("Vous avez deja demande cette lettre ! :o\n");
                //vu = true;
                //break;
            }
        }
        if(!vu){
            for(int i=0;i<sizeof(motSecret);i++){
                if(letter == motSecret[i]){
                    motActuel[i] = motSecret[i];
                    compt++;
                    compt1++;
                }
            }
            if(compt1 == 0){
                printf("Cette lettre : %c n est pas dans le mot :(\n",letter);
            }
            else{
                printf("Cette lettre : %c est dans le mot %d fois !\n",letter,compt1);
            }
        }

        printf("Tour : %d\n,Compt : %d\n Compt1: %d\n Letter: %c\n",turn,compt,compt1,letter);
        printf("MOT A DEVINER : %s\n",motActuel);
        compt1 = 0;
        vu = false;
    }

    printf("Vous avez gagne en %d tours, BRAVO ! :) ",turn);

}


#endif // PENDU_H_INCLUDED
