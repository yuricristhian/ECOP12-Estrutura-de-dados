//CRUD linked list with dynamic memory allocation
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noAluno{
    char nome[40];
    int matricula;
    char disc[40];
    int coef;
    struct noAluno *prox;
}aluno;

typedef enum {false, true} bool;

aluno *prim = NULL;
aluno *ult = NULL;
int quant = 0;

bool insereAluno(aluno student);
void imprimeLista();
bool removeAluno(char nomeRemove[40]);


int main()
{
    int i=0;
    char nomeAux[40];
    aluno aux;

    for(i=0; i<3; i++){
        printf("\nNome: ");
        scanf("%s", aux.nome);
        printf("\nMatricula: ");
        scanf("%d", &aux.matricula);
        printf("\nDisciplina: ");
        scanf("%s", aux.disc);
        printf("\nCoeficiente: ");
        scanf("%d", &aux.coef);
        aux.prox = 0;

        if(buscaNome(aux.nome) == -1){ //there is no such element in the list
            insereAluno(aux);
        }
        system("cls");
    }
    imprimeLista();

    printf("\n\nDigite um nome para remocao: ");
    scanf("%s", &nomeAux);

    removeAluno(nomeAux);

    imprimeLista();

    void destroiLista();

}

bool insereAluno(aluno student){
    aluno *ant = NULL;
    aluno *atual = prim;

    aluno *novo = (aluno *)malloc(sizeof(aluno)); //Allocates a memory region of the size of the student struct
    while((atual!=NULL) && (strcmp(atual->nome, student.nome)<0)){  //Arranges alphabetically
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL){
        prim = novo;
    }else{
        ant->prox = novo;
    }

    strcpy(novo->nome, student.nome);
    strcpy(novo->disc, student.disc);
    novo->matricula = student.matricula;
    novo->coef = student.coef;
    novo->prox = atual;

    if (atual == NULL){
        ult = novo;
        quant++;
        return 1;
    }
}

bool removeAluno(char nomeRemove[40]){
    aluno *ant = NULL;
    aluno *atual = prim;

    while ((atual != NULL) && (strcmp(atual->nome, nomeRemove))){
        ant = atual;
        atual = atual->prox;
    }

    if (atual == prim){
        prim = atual->prox;
    }else{
        ant->prox = atual->prox;
        if(atual == ult){
            ult = ant;
        }
        free(atual);
        quant--;
        return 1;
    }
}

void imprimeLista(){
    int i = 0;
    aluno *atual = prim;
    while(atual != NULL){
        printf("\n\nNome: %s", atual->nome);
        printf("\nMatricula:: %d", atual->matricula);
        printf("\nDiscplina: %s", atual->disc);
        printf("\nCoeficiente: %d", atual->coef);
        atual = atual->prox;
        i++;
    }
    printf("\n");
}

int buscaNome(char pesquisa[40]){
    int i = 0;
    aluno *atual = prim;
    while((atual != NULL) && (atual->nome != pesquisa)){    //Scans the list for the name
        atual = atual->prox;
        i++;
    }
    if(atual == NULL){  //There is no element in the list
        return -1;      
    }
    else{
        return i;
    }
}

void destroiLista(){
    aluno *atual=prim;
    aluno *apaga;

    while(atual != NULL){
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}



