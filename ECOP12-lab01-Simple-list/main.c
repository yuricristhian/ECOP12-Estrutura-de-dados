//Simple list
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3                           

typedef enum{false, true} bool;             //Defines the bool variable as a Boolean variable
typedef struct {
    char name[20];
}noNome;            

int buscaNome(char nome[20]);
bool insereNome(char nome[20]);
void imprimeLista();

noNome lista[MAX];
int dispo=0;


int main()
{
    int i=0;
    char auxName[20];                       

    for(i=0; i < MAX; i++){                 //As long as i is less than MAX, insert name
        printf("Nome: ");
        scanf("%s", auxName);               
        if (buscaNome(auxName) == -1){      //means that there is no such element in the list, if any, it does not let the element repeat
            insereNome(auxName);
        }else{
            i--;
        }
    }
    imprimeLista();

    printf("\nPesquise um nome: ");
    scanf("%s", auxName);

    i = buscaNome(auxName);
    printf("\n\n [Posicao: %d Nome: %s ]", i, lista[i].name);
    printf("\n\n\n");


    return 1;
}

int buscaNome(char nome[20]){
    int i = 0;

    //Scan the vector until you find an element that is not below in alphabetical order
    while((i<dispo) && ((strcmp(lista[i].name, nome)<0))){    
        i++;
    }
    //If the name sought is the same as the vector element, it returns the position of the element
    if((i<dispo) && (strcmp(lista[i].name, nome)) == 0){
        return i;
    }else{
        return -1;
    }
}

bool insereNome(char nome[20]){
    int i = dispo;

    if (dispo > MAX){       //Full vector
        return false;
    }else{
        while((i>0) && (strcmp(lista[i-1].name, nome) > 0)){ //Arranges the vector in alphabetical order
            lista[i] = lista[i-1]; 
            i--;
        }
        strcpy(lista[i].name, nome);
        dispo++;
        return true;
    }
}

void imprimeLista(){
    int i=0;
    while(i < dispo){
        printf("\n[(%2d) = %s]", i, lista[i].name);
        i++;
    }
    printf("\n");
}


