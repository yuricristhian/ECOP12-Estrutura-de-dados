//CRUD looped list with dynamic memory allocation
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 20

typedef enum{false, true} bool;

typedef struct no{
    char nome[TAM_NOME];
    int matricula, turma;
    float coef;
    struct no *prox;
    struct no *ant;
}noAluno;

bool insereAluno(noAluno aluno);
void imprimeLista();
bool removeAluno(int mat);
int buscaMatricula(int mat);
void destroi();


noAluno *prim = NULL;
noAluno *ult = NULL;
int quant = 0;


int main()
{
    int aux, mat;
    noAluno student;

    for(;;){
        system("cls");
        printf("[ SUPER LISTA DE ALUNOS ]\n\n");
        printf(">> 1 para inserir um aluno na lista\n");
        printf(">> 2 para remover um aluno da lista\n");
        printf(">> 3 para listar todos alunos\n");
        printf(">> 4 para deletar a lista e fechar o programa\n");
        scanf("%d", &aux);
        getchar();

        if(aux == 1){
            printf("\nNome: ");
            gets(student.nome);
            printf("\nMatricula: ");
            scanf("%d", &student.matricula);
            printf("\nTurma: ");
            scanf("%d", &student.turma);
            printf("\nCoeficiente: ");
            scanf("%f", &student.coef);

            if(buscaMatricula(student.matricula) != -1){
                printf("\n\nESSA MATRICULA JA EXISTE NA LISTA!\n\n!");
                system("pause");
            }else{
                insereAluno(student);
            }
        }

        if(aux == 2){
            printf("\nMatricula a ser removida: ");
            scanf("%d", &mat);
            removeAluno(mat);
        }

        if(aux == 3){
            imprimeLista();
            printf("\n\n");
            system("pause");
        }

        if(aux == 4){
            destroi();
            system("cls");
            printf("\n[ LISTA DESTRUIDA ]\n\n");
            system("pause");
            break;
        }
    }
}

bool insereAluno(noAluno aluno){
    noAluno *aux = NULL;
    noAluno *atual = prim;
    noAluno *novo;

    novo = (noAluno *) malloc(sizeof(noAluno));

    if(prim == NULL){
        prim = novo;
        ult = novo;
        strcpy(novo->nome, aluno.nome);
        novo->matricula = aluno.matricula;
        novo->turma = aluno.turma;
        novo->coef = aluno.coef;
        novo->ant = novo;
        novo->prox = novo;
    }else{
        while(strcmp(atual->nome, aluno.nome) < 0){
            aux = atual;
            atual = atual->prox;
            if(atual == prim){      // there is only one element in the list
                break;
            }
        }

        if(aux == NULL){
            prim = novo;
            ult->prox = prim;
            ult->ant = prim;
            prim->prox = ult;
            prim->ant = ult;
        }else{
            aux->prox = novo;
            atual->ant = novo;

        }
        strcpy(novo->nome, aluno.nome);
        novo->matricula = aluno.matricula;
        novo->turma = aluno.turma;
        novo->coef = aluno.coef;
        novo->ant = aux;
        novo->prox = atual;

        if(atual == prim){
            ult = novo;
        }
    }
    quant++;
    return true;
}

void imprimeLista(){
    int i = 0;
    noAluno *atual = prim;

    if(atual != NULL){
        while(true){
            printf("Nome: %s", atual->nome);
            printf("\nMatricula: %d", atual->matricula);
            printf("\nTurma: %d", atual->turma);
            printf("\nCoeficiente: %.2f", atual->coef);
            printf("\n\n");
            atual = atual->prox;
            i++;
            if(atual == prim){
                break;
            }
        }
    }
}

bool removeAluno(int mat){
    noAluno *aux = NULL;
    noAluno *atual = prim;

    if(atual != NULL){
        while(atual->matricula != mat){
            aux = atual;
            atual = atual->prox;
            if(atual == prim){
                break;
            }
        }
        if(atual->matricula != mat){
            return false;
        }else{
            if(atual == prim){
                prim = atual->prox;
                ult->prox = prim;
                prim->ant = ult;
                free(atual);
            }else{
                aux->prox = atual->prox;
                atual->prox->ant = aux;
                if(atual == ult){
                    ult = aux;
                }
                free(atual);
            }
            quant--;
            return true;
        }
    }else{
        return false;
    }
}

int buscaMatricula(int mat){
    int i = 0;
    noAluno *atual = prim;

    if(atual != NULL){
        while(atual->matricula != mat){
            atual = atual->prox;
            i++;
            if(atual == prim){
                break;   //It means I went around the list
            }
        }
        if(atual->matricula != mat){
            return -1;
        }else{
            return i;
        }
    }else{
        return -1; //List empty
    }
}

void destroi(){
    noAluno *atual = prim;
    noAluno *apaga;

    if(atual != NULL){
        while(true){
            apaga = atual;
            atual = atual->prox;
            free(apaga);

            if(atual == ult){
                break;
            }
        }
        free(atual);
    }
}
