/**      EXAMEN 1: SAXPY
*@author:
*- Barrios López Francisco
*- Castillo Montes Pamela
*@date: 09 - 09 - 2023
**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

/* Código Base */
    //#include<sys/time.h>      

    /*void get_walltime(time_t * wvTime){
        *wvTime = time(NULL);
    }*/

    /*void get_walltime(LARGE_INTEGER *wvTime){
        QueryPerformanceCounter(&wvTime);
    }*/

    /*void get_walltime(double* wvTime){
        struct timeval tp;
        gettimeofday(&tp, NULL);
        *wvTime = (tp.tv_sec + tp.tv_usec/1000000.0);
    }*/

int main (int argc, char* argv []){
    int i, j, k, n = 1000;             //Definición tamaño matriz
    int **matrizA, **matrizB, **matrizC;
    LARGE_INTEGER S1, E2;

    //Frecuencia de reloj: Uso en cronometraje
    LARGE_INTEGER frecuency;
    QueryPerformanceFrequency(&frecuency);

    // Inicializando matrices
    matrizA = (int **)malloc(n*sizeof(int *));
    matrizB = (int **)malloc(n*sizeof(int *));
    matrizC = (int **)malloc(n*sizeof(int *));
    for (i=0; i<n; i++)
        *(matrizA + i) = (int *)malloc(n*sizeof(int *));

    for (i=0; i<n; i++)
        *(matrizB + i) = (int *)malloc(n*sizeof(int *));

    for (i=0; i<n; i++)
        *(matrizC + i) = (int *)malloc(n*sizeof(int *));
    
    //Llenando aleatorio de matrices (0 a 6)
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0;
        }
    }
    
    //get_walltime(&S1);        //Código Base
    QueryPerformanceCounter(&S1);   //Inicio de cronometro

    /* Combinaciones */
    // Descomentar combinación a ocupar

    //Combinación i-j-k  
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            for (k=0; k<n; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }

    //Combinación j-i-k 
    /*for (j=0; j<n; j++){
        for (i=0; i<n; i++){
            for (k=0; k<n; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    //Combinación i-k-j
    /*for (i=0; i<n; i++){
        for (k=0; k<n; k++){
            for (j=0; j<n; j++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    //Combinación k-j-i
    /*for (k=0; k<n; k++){
        for (j=0; j<n; j++){
            for (i=0; i<n; i++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    //Combinación j-k-i
    /*for (j=0; j<n; j++){
        for (k=0; k<n; k++){
            for (i=0; i<n; i++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    //Combinación k-i-j 
    /*for (k=0; k<n; k++){
        for (i=0; i<n; i++){
            for (j=0; j<n; j++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    QueryPerformanceCounter(&E2);       //Fin de cronometro
    //get_walltime(&E2);        //Código base

    //Tiempo de ejecución
    double elapsed_time = (double)(E2.QuadPart - S1.QuadPart)/frecuency.QuadPart;
    printf("Tiempo m%ctodo ijk: %f s\n",130 ,elapsed_time);
    return 0;
}