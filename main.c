#include <stdio.h>
#include <stdlib.h>
#include "joc.h"

int main(){
    int selectie,dificutate,dimensiune;
    Afisare_Meniu();
    if((scanf("%d",&selectie)!=1)||(selectie>3)){
        printf("Nu ati selectat corect\n");
        exit(-1);
    }
    switch(selectie){
        case 3:
            printf("Ati selectat sa iesiti din joc\n");
            exit(-1);
        case 2:
            Afisare_Dificultate();
            if((scanf("%d",&dificutate)!=1)||(dificutate>3)){
                printf("Nu ati selectat corect\n");
                exit(-1);
            }
    }
    Selectare_Matrice();
    if((scanf("%d",&selectie)!=1)||(selectie>4)){
        printf("Nu ati selectat corect\n");
        exit(-1);
    }
    switch(selectie){
        case 1:
            dimensiune=3;
            break;
        case 2:
            dimensiune=4;
            break;
        case 3:
            dimensiune=5;
            break;
        case 4:
            dimensiune=6;
            break;
    }
    int** mat;
    mat=Creare_Matrice(dimensiune);
    Afisarea_Matrice(mat,dimensiune);
    return 0;
}
