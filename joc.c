#include <stdio.h>
#include <stdlib.h>
#include "joc.h"


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


