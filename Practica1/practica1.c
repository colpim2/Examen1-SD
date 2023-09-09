#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
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
    int i, j, k, n = 10000;
    int **matrizA, **matrizB, **matrizC;
    LARGE_INTEGER S1, E2;

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
    
    //Llenando matrices
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0;
        }
    }
    
    //get_walltime(&S1);
    QueryPerformanceCounter(&S1);

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            for (k=0; k<n; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }

    /*for (j=0; j<n; j++){
        for (i=0; i<n; i++){
            for (k=0; k<n; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    /*for (i=0; i<n; i++){
        for (k=0; k<n; k++){
            for (j=0; j<n; j++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    /*for (k=0; k<n; k++){
        for (j=0; j<n; j++){
            for (i=0; i<n; i++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    /*for (j=0; j<n; j++){
        for (k=0; k<n; k++){
            for (i=0; i<n; i++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    /*for (k=0; k<n; k++){
        for (i=0; i<n; i++){
            for (j=0; j<n; j++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }*/

    QueryPerformanceCounter(&E2);
    //get_walltime(&E2);

    double elapsed_time = (double)(E2.QuadPart - S1.QuadPart)/frecuency.QuadPart;
    printf("Tiempo método ijk: %f s\n", elapsed_time);
    return 0;
}