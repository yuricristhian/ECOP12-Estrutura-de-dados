//CRUD double linked list with dynamic memory allocation
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 20
#define TAM_TEL 10

typedef enum {false, true} bool;

typedef struct no{
    char nome[TAM_NOME];
    char tel[TAM_TEL];
    struct no *ant;
    struct no *prox;
} noDuplo;

noDuplo *prim = NULL;
noDuplo *ult = NULL;

int quant = 0;

bool insereElem(noDuplo cont);
bool removeElem(noDuplo cont);
int buscaElem(noDuplo cont);
void imprimeAgenda();
void destroy();


int main()
{
    int aux;
    noDuplo contato;

    for(;;){
        system("cls");
        printf("[ SUPER AGENDA TELEFONICA ]\n\n");
        printf(">> 1 para inserir um contato na agenda\n");
        printf(">> 2 para remover um contato na agenda\n");
        printf(">> 3 para listar todos contatos da agenda\n");
        printf(">> 4 para sair da agenda\n");
        scanf("%d", &aux);
        getchar();

        if(aux == 1){

            printf("\nNome: ");
            gets(contato.nome);
            printf("\nTelefone: ");
            gets(contato.tel);

            if(buscaElem(contato) != -1){
                printf("\n\nESSE NOME JA EXISTE NA LISTA!\n\n!");
                system("pause");
            }else{
                insereElem(contato);
            }
        }

        if(aux == 2){
            printf("\nNome a ser removido: ");
            gets(contato.nome);
            removeElem(contato);
        }

        if(aux == 3){
            imprimeAgenda();
            printf("\n\n");
            system("pause");
        }

        if(aux == 4){
            destroy();
            break;
        }
    }
}

bool insereElem(noDuplo cont){
    noDuplo *aux = NULL;
    noDuplo *atual = prim;
    noDuplo *novo;

    novo = (noDuplo*) malloc(sizeof(noDuplo));

    while((atual != NULL) && (strcmp(atual->nome, cont.nome) < 0)){
        aux = atual;
        atual = atual->prox;
    }
    if(aux == NULL){
        prim = novo;
    }else{
        aux->prox = novo;
    }
    if(atual == NULL){
        ult = novo;
    }else{
        atual->ant = novo;
    }
    strcpy(novo->nome, cont.nome);
    strcpy(novo->tel, cont.tel);
    novo->prox = atual;
    novo->ant = aux;
    quant++;
    return true;
}

bool removeElem(noDuplo cont){
    noDuplo *aux = NULL;
    noDuplo *atual = prim;

    while((atual != NULL) && (strcmp(atual->nome, cont.nome) != 0)){
        aux = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return false;
    }else{
        if(atual == prim){
            prim = atual->prox;
        }else{
            aux->prox = atual->prox;
        }
        if(atual == ult){
            ult = aux;
        }else{
            atual->prox->ant = aux;
        }
        free(atual);
        quant--;
        return true;
    }
}

int buscaElem(noDuplo cont){
    int i = 0;
    noDuplo *atual = prim;

    while((atual != NULL) && (strcmp(atual->nome, cont.nome) != 0)){
        atual = atual->prox;
        i++;
    }
    if(atual == NULL){
        return -1;
    }else{
        return i;
    }
}

void destroy(){
    noDuplo *atual = prim;
    noDuplo *apaga;

    while(atual != NULL){
        apaga = atual;
        atual = atual->prox;
        free(apaga);
    }
}

void imprimeAgenda(){
    int i = 0;
    noDuplo *atual = prim;
    while(atual != NULL){
        printf("\nNome: %s", atual->nome);
        printf("\nTelefone: %s", atual->tel);
        printf("\n");
        atual = atual->prox;
        i++;
    }
}
