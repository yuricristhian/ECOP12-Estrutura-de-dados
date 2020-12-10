//Process queue on a CPU according to execution priority
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_FILAS 3
#define TAM_NOME 50

typedef enum {false, true} bool;

//structure of a process
typedef struct no{
    float tamanho;
    char nome[TAM_NOME];
    int prioridade;
    struct no *prox;
}noProcesso;

//queue of processes to be executed on the CPU
noProcesso *fila[NUM_FILAS];

//vector that indicates the existence of at least one process of that priority
bool prioridadesProcessos[10];

void inicializaVetorPrioridades(void);
void inicializaFila(void);
void insereFila(float tam, char nome[TAM_NOME], int prioridade);
void imprimeDados(void);
bool removeProcesso(int pos);

int main()
{
    int pos = -1;
    insereFila(1, "BrOfficeCalc", 3);
    insereFila(2.3, "CodeBlocks", 9);
    insereFila(0.5, "Calculadora", 1);
    insereFila(6.4, "Firefox", 7);
    insereFila(3.1, "PhpMyAdmin", 2);
    insereFila(2.9, "Kile", 4);
    insereFila(4.5, "Gimp", 9);
    insereFila(5.5, "BrOfficeWriter", 6);
    insereFila(5.8, "GCC", 2);

    for(;;){
        imprimeDados();
        printf("\n\nRemover processo da fila: ");
        scanf("%d", &pos);

        removeProcesso(pos);
        system("cls");
        imprimeDados();
    }
}

void inicializaFila(void){
    int i=0;
    for(i=0; i<NUM_FILAS; i++){
        fila[i] = NULL;
    }
}

void inicializaVetorPrioridades(void){
    int i=0;
    for(i=0; i<10; i++){
        prioridadesProcessos[i] = false;
    }
}

void insereFila(float tam, char nome[TAM_NOME], int prioridade){
    int i;
    int pos = -1;
    noProcesso *novo;
    noProcesso *atual;
    noProcesso *ant = NULL;

    novo = (noProcesso*) malloc(sizeof(noProcesso));

    //Get the position where the process should be inserted according to the priority
    if ((prioridade >= 0)&&(prioridade <= 3))
        pos = 0;
    if ((prioridade >= 4)&&(prioridade <= 6))
        pos = 1;
    if ((prioridade >= 7)&&(prioridade <= 9))
        pos = 2;

    //Current points to first position of the vector
    atual = fila[pos];

    //varre o vetor até encontrar a ultima posição
    while((atual != NULL)){
        ant = atual;
        atual = atual->prox;
    }
    if(ant == NULL){
        fila[pos] = novo;
    }else{
        //Updates the old pointers
        ant->prox = novo;
    }

    //Fill in the new
    strcpy(novo->nome, nome);
    novo->tamanho = tam;
    novo->prioridade = prioridade;
    novo->prox = atual;
}

void imprimeDados(void){
    int i = 0;
    float tam = 0;
    noProcesso *atual;

    for(i = 0; i<NUM_FILAS; i++){
        atual = fila[i];
        tam = 0;
        printf("--------------------------\n");
        printf("[        FILA %d          ]\n", i);
        printf("--------------------------\n\n");
        while(atual != NULL){
            tam += atual->tamanho;
            printf("Nome: %s\n", atual->nome);
            printf("Tamanho: %.2f\n", atual->tamanho);
            printf("Prioridade: %d\n\n", atual->prioridade);
            atual = atual->prox;
        }
        printf("Tamanho total da fila %d: %.2f\n\n", i, tam);
    }
}

bool removeProcesso(int pos){
    noProcesso *atual;

    atual = fila[pos];

    if(atual == NULL){
        return false;
    }else{
        fila[pos] = atual->prox;
        free(atual);
        return true;
    }
}
