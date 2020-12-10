//Simple linked list with predefined vector
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include "stdio.h"
#include "listaEncadeada.h"

void main(void){

    noAluno aux;
    int i, pesquisa;

    inicializaLista();

    for(i=0; i<4; i++){
        printf("Aluno: ");
        scanf("%s", aux.nome);
        printf("\nMatricula: ");  
        scanf("%d", &aux.matricula);
        printf("\nIMC: ");
        scanf("%f", &aux.IMC);
        aux.prox = 0;

        if(buscaAluno(aux.matricula) == -1){ //It means that there is no such element in the list
            insereAluno(aux);
        }
        system("cls");
    }

    imprimeLista();

    printf("\nBusque um numero de matricula: ");
    scanf("%d", &pesquisa);

    pesquisa = buscaAluno(pesquisa);
    imprimeDados(pesquisa);



}



