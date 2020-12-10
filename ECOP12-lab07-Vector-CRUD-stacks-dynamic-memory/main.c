//Vector CRUD of stacks with dynamic memory allocation
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

//Simulation of an ATM CRUD using a stack vector with dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct no{
    int valor;
    struct no *prox;
}noCedula;

noCedula *pilha[7];                      //One stack for each value of cedula
int valorNota[7] = {1,2,5,10,20,50,100}; //Values ​​of existing cedulas

void abastecePilha(int quant, int v);
void inicializaPilha();
void imprimeSomaCedulas();
bool saqueDisponivel(int valor);
bool saque(int valor);




void main(void)
{
    int aux;
    int quant, valor;
    quant = 0;
    valor = 0;

    inicializaPilha();

    for(;;){
        system("cls");
        printf("----------------------------------\n");
        printf("[     SUPER CAIXA ELETRONICO     ]\n");
        printf("----------------------------------\n");
        printf("\n");

        printf(">> 1 para realizar um deposito.\n");
        printf(">> 2 para exibir cedulas disponiveis.\n");
        printf(">> 3 para sacar um valor.\n\n");
        scanf("%d", &aux);
        getchar();

        if(aux == 1){
            system("cls");
            printf("----------------------------------\n");
            printf("[        REALIZAR DEPOSITO       ]\n");
            printf("----------------------------------\n");
            printf("\n");

            printf("Quantidade de notas: ");
            scanf("%d", &quant);
            printf("\nValor de cada nota: ");
            scanf("%d", &valor);

            abastecePilha(quant, valor);
        }

        if(aux == 2){
            system("cls");
            imprimeSomaCedulas();
            system("pause");
        }

        if(aux == 3){
            system("cls");
            printf("----------------------------------\n");
            printf("[              SAQUE             ]\n");
            printf("----------------------------------\n");
            printf("\n");

            printf("Qual valor deseja sacar: ");
            scanf("%d", &valor);

            if(saque(valor) == true){
                printf("\n[ SAQUE REALIZADO COM SUCESSO  ]\n\n");
            }else{
                printf("\n[     SALDO INDISPONIVEL       ]\n\n");
            }
            imprimeSomaCedulas();
            system("pause");

        }
    }
}

void inicializaPilha(){
    int i=0;
    for(i=0; i<7; i++){
        pilha[i] = NULL;    
    }
}

void abastecePilha(int quant, int v){
    int i;
    int pos;
    noCedula *novo;

    switch(v){
        case 1: pos=0; break;
        case 2: pos=1; break;
        case 5: pos=2; break;
        case 10: pos=3; break;
        case 20: pos=4; break;
        case 50: pos=5; break;
        case 100:pos=6; break;
        default: pos = -1;
    }
    if (pos == -1){
        printf("\n\nValor de cedula invalido!");
        system("pause");
    }else{
        for(i=0; i<quant; i++){
            novo = (noCedula *) malloc(sizeof(noCedula));
            novo->valor = v;
            novo->prox = pilha[pos];
            pilha[pos] = novo;
        }
    }
}

void imprimeSomaCedulas(){
    printf("------------------------------\n");
    printf("[      SALDO DISPONIVEL      ]\n");
    printf("------------------------------\n");
    printf("\n");
    noCedula *atual;
    int i;
    float soma=0;
    float total = 0;

    for(i=0;i<7; i++){
        atual = pilha[i];
        soma = 0;
        while(atual!=NULL){
            soma += atual->valor;
            atual = atual->prox;
        }
        total += soma;
        printf("saldo em notas de %d = %.2f\n", valorNota[i], soma);
    }
    printf("\n");
    printf("Valor total: %.2f", total);
    printf("\n");
    printf("\n");
}

bool saqueDisponivel(int valor){
    int i;
    noCedula *atual;
    for(i=6; i >=0; i--){
        atual = pilha[i];
        while((atual!=NULL) && ((valor / valorNota[i]) >= 1)){
            valor -= atual->valor;
            atual = atual->prox;
        }
    }
    if(valor == 0){
        return true;
    }else{
        return false;
    }
}

bool saque(int valor){
    int i;
    noCedula *atual;
    if(saqueDisponivel(valor)==true){
        for(i=6; i >=0; i--){
            atual = pilha[i];
            while((pilha[i]!=NULL)&&((valor / valorNota[i]) >= 1)){
                valor -= atual->valor;
                atual = atual->prox;
                free(pilha[i]);
                pilha[i] = atual;
            }
        }
        return true;
    }else{
        return false;
    }
}