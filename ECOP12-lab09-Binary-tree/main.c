//Binary tree for storage and data searches
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef enum {false, true} bool;
typedef enum {preordem, inordem, posordem} modoCaminhamento;

typedef struct no{
  char cep[9];
  char uf[3];
  char cidade[31];
  char logradouro[61];
  struct no *esq;
  struct no *dir;
}noCEP;

noCEP *arvBinaria;

int quant;

void inserirNoArvoreBinaria(FILE *arq){
    char linha[200];
    char *substring;
    int i;
    noCEP *ant = NULL;
    noCEP *atual = arvBinaria;
    noCEP *novo;

    //allocate the new in memory
    novo = (noCEP *) malloc(sizeof(noCEP));

    //read the complete line and fill in the data in the new CEP code
    fgets(linha, 200, arq);

    //separate tokens by delimiter \t
    substring = strtok(linha, "\t");

    //obtem o cep
    if(substring != NULL) {
      strcpy(novo->cep, substring);
    }
    substring = strtok(NULL, "\t");

    //get uf
    if(substring != NULL)
      strcpy(novo->uf, substring);

    substring = strtok(NULL, "\t");

    //get cuty
    if(substring != NULL)
      strcpy(novo->cidade, substring);

    substring = strtok(NULL, "\t");

    //get the street
    if(substring != NULL)
      strcpy(novo->logradouro, substring);

    //starts the left and right pointers with null again
    novo->esq = NULL;
    novo->dir = NULL;

    while((atual!=NULL)&&(strcmp(novo->cep, atual->cep)!=0)){ //Find the insertion position
        ant = atual;
        if(strcmp(novo->cep, atual->cep) < 0)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }
    //first tree element (root)
    if (ant==NULL){
        arvBinaria = novo;

    }else{
        if(atual==NULL){
            //Which side to insert?
            if(strcmp(novo->cep, ant->cep) < 0){
                ant->esq = novo;
            }
            else{
                ant->dir = novo;
            }
        }
    }
}

void imprimeNoCEP(noCEP *no){
    printf("CEP: %s\n", no->cep);
    printf("UF: %s\n", no->uf);
    printf("Cidade: %s\n", no->cidade);
    printf("Logradouro: %s\n",no->logradouro);

}

void imprimePreOrdemArvBB(noCEP *n){
    if(n!=NULL && quant<10){
        imprimeNoCEP(n); quant++;
        imprimePreOrdemArvBB(n->esq);
        imprimePreOrdemArvBB(n->dir);
    }
}

void imprimeEmOrdemArvBB(noCEP *n){
    if(n!=NULL && quant<10)
    {
        imprimeEmOrdemArvBB(n->esq);
        imprimeNoCEP(n);
        quant++;
        imprimeEmOrdemArvBB(n->dir);
    }
}

void imprimePosOrdemArvBB(noCEP*n){
    if(n!=NULL && quant<10)
    {
        imprimePosOrdemArvBB(n->esq);
        imprimePosOrdemArvBB(n->dir);
        imprimeNoCEP(n); quant++;
    }
}

void buscarArvoreBinaria(noCEP * noAtual, char cepProcurado[9]){

    //CEP not found
    if(noAtual == NULL){
        printf(">> CEP nao encontrado!\n");
    }else{
        if(strcmp(cepProcurado, noAtual->cep) == 0){
            printf("\n>> CEP encontrado: \n");
            imprimeNoCEP(noAtual);
        }else if(strcmp(cepProcurado, noAtual->cep) < 0){
            // searches the left subtree
            buscarArvoreBinaria(noAtual->esq, cepProcurado);
        }else{
            //searches the right subtree
            buscarArvoreBinaria(noAtual->dir, cepProcurado);
        }
    }
}

int main(int argc, char *argv[]){
  FILE *arq;
  int opcaoMenu;
  char cepProcurado[9];
  noCEP *cepEncontrado;

  //initializes the tree
  arvBinaria = NULL;

  //the file is read and inserted the elements in the tree
  arq = fopen("baseCep.txt", "r");

  if(!arq){
    printf("O arquivo nao pode ser aberto.\n");
    exit(1);
  }//end if(!arq)

  printf("\nInserindo elementos na arvore... \n");
  while(!feof(arq)){
    //for each line in the file called p
    //the binary tree insertion function
    inserirNoArvoreBinaria(arq);
  }//end while(!feof(arq))
  fclose(arq);

  //menu for walking on the ceps tree
  opcaoMenu = 1;
  while(opcaoMenu != 4){
    quant = 0;

    printf("|Selecione uma das opcoes do menu: |\n");
    printf("|1 - Pre-ordem                     |\n");
    printf("|2 - Em-ordem                      |\n");
    printf("|3 - Pos-ordem                     |\n");
    printf("|4 - Sair                          |\n\n");
    printf(">");

    scanf("%d", &opcaoMenu);
    switch(opcaoMenu){
      case 1:
         printf("----------------------\n");
         printf("Imprime em pre-ordem: \n");
         printf("----------------------\n\n");
         imprimePreOrdemArvBB(arvBinaria);
         printf("\n");
         break;

      case 2:
         printf("---------------------\n");
         printf("Imprime em in-ordem: \n");
         printf("---------------------\n\n");
         imprimeEmOrdemArvBB(arvBinaria);
         printf("\n");
         break;

      case 3:
         printf("----------------------\n");
         printf("Imprime em pos-ordem: \n");
         printf("----------------------\n\n");
         imprimePosOrdemArvBB(arvBinaria);
         printf("\n");
         break;

      case 4:
         printf("Saindo do menu impressoes: ");
         break;
    }//end switch
  }//end while(opcaoMenu != 4)

  // called search for a CEP code
  printf("\n>>> Busca por um cep: \n");
  printf(">> Digite um cep: ");
  scanf("%s", cepProcurado);
  buscarArvoreBinaria(arvBinaria,cepProcurado);

  printf("Encerrando o programa...\n");

  free(arvBinaria);

  system("PAUSE");
  return 0;
}//end main
