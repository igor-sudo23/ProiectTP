#include <stdio.h>
#include <stdlib.h>
#include "joc.h"

void Afisare_Meniu(){
    printf("Meniu:\n");
    printf("1.Singleplayer\n");
    printf("2.Multiplayer\n");
    printf("3.Exit\n");
}

void Selectare_Matrice(){
    printf("\n");
    printf("Forma matricei:\n");
    printf("1.Matrice 3x3\n");
    printf("2.Matrice 4x4\n");
    printf("3.Matrice 5x5\n");
    printf("4.Matrice 6x6\n");
}

void Afisare_Dificultate(){
    printf("\n");
    printf("Dificultatea:\n");
    printf("1.Easy\n");
    printf("2.Medium\n");
    printf("3.Hard\n");
}

int** Creare_Matrice(int n){
    int** mat;
    if((mat=(int**)malloc(n*sizeof(int*)))==NULL){
        perror("Eroare de initializare\n");
        exit(-1);
    }
    for(int i=0;i<n;i++){
        if((mat[i]=(int*)malloc(n*sizeof(int)))==NULL){
        perror("Eroare de initializare\n");
        exit(-1);
    }
    }
    printf("Matrice de forma %dx%d creata cu succes\n",n,n);
    return mat;
}

int** Setarea_Matrice(int** mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    return mat;
}

void Afisarea_Matrice(int** mat,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            printf("%d |", mat[i][j]);
        }
        printf("%d", mat[i][j]);
        printf("--------------------");
    }

}
//Control();
//Miscare();
