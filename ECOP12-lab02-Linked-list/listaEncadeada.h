#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef enum{false, true} bool;

typedef struct {
    char nome[20];
    int matricula;
    float IMC;
    int prox;
}noAluno;

void inicializaLista(void);
void imprimeLista(void);
bool insereAluno(noAluno student);
int buscaAluno(int chave);
void imprimeDados(int pos);


#endif // LISTAENCADEADA_H_INCLUDED
