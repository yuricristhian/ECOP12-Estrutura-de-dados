//Examples of using dynamic memory allocation and pointers
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include "time.h"



int main(){
    int **a;
    int **b;
    int **c;
    int i,j;

    
    a =(int**) malloc(10*sizeof(int*)); //Allocates 10 int memory locations (matrix lines) 
    for(i=0; i<10; i++){
        a[i]=(int*)malloc(20*sizeof(int)); //Allocates 20 int memory locations (array columns)
    };

    b =(int**) malloc(10*sizeof(int*));
    for(i=0; i<10; i++){
        b[i]=(int*)malloc(20*sizeof(int));
    };

    c =(int**) malloc(10*sizeof(int*));
    for(i=0; i<10; i++){
        c[i]=(int*)malloc(20*sizeof(int));
    };

    //Generates a matrix with random numbers and stores it in the allocated memory
    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            a[i][j]=rand()%10;
            b[i][j]=rand()%10;
        }
    };

    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    };

    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    };

    printf("\n");
    printf("\n");

    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    };

    printf("\n");
    printf("\n");

    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    };

    //Erase the arrays, releasing the allocated memory
    for(i=0; i<10; i++){
        free(a[i]);
    }
    free(a);

    for(i=0; i<10; i++){
        free(b[i]);
    }
    free(b);

    for(i=0; i<10; i++){
        free(c[i]);
    }
    free(c);


    printf("\n");
    return 0;
}
