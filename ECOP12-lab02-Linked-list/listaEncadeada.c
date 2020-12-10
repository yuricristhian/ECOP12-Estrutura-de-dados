#include<stdio.h>
#include<string.h>
#include "listaEncadeada.h"

#define MAX 4

noAluno aluno[MAX];
noAluno student;

int prim = -1;
int dispo = 0;
int quant = 0;

void inicializaLista(void){
    int i;
    for(i = 0; i < (MAX); i++){
        aluno[i].prox = i+1;
        if (i==3){
            aluno[i].prox = -1;
        }
    }
}

void imprimeLista(){
    int i=0;        
    int pos = prim;
    while(pos != -1){
        printf("\nAluno: %s", aluno[i].nome);
        printf("\nMatricula: %d", aluno[i].matricula);
        printf("\nIMC: %f", aluno[i].IMC);
        printf("\n\n");
        pos = aluno[pos].prox;
        i++;
    }
    printf("\n");
}

bool insereAluno(noAluno student){
    int ant, atual, novo;
    if (dispo == -1){
        return false;
    }else{
        ant = -1;
        atual = prim;
        novo = dispo;
        //Organizes the vector in ascending order according to the registration number
        while((atual != -1)&&(aluno[atual].matricula < student.matricula)){    
            ant = atual;
            atual = aluno[atual].prox;
        }
        dispo = aluno[dispo].prox;

        if(ant == -1){
            prim = novo;
        }else{
            aluno[ant].prox = novo;
        }

        aluno[novo]=student;
        aluno[novo].prox = atual;
        quant++;
        return true;
    }
}

int buscaAluno(int chave){
    int pos = prim;
    while((pos != -1)&&(aluno[pos].matricula != chave)){
        pos = aluno[pos].prox;
    }
    return pos;
}

void imprimeDados(int pos){
    printf("Nome: %s\n",aluno[pos].nome);
    printf("Matricula: %d\n",aluno[pos].matricula);
    printf("IMC: %f\n",aluno[pos].IMC);
    printf("Posicao: %d", pos);
}



