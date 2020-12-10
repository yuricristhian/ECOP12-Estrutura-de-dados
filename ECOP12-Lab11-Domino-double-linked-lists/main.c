//Domino game using double linked lists
//Author: Yuri Cristhian da Cruz
//IDE: Codeblocks
//Compiler: GCC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int face1;
    int face2;
    struct no *prox;
} noPeca;
noPeca *priPlayer1 = NULL;
noPeca *priPlayer2 = NULL;
noPeca *priMesa = NULL;

int c1=0, c2=0;

int inicializa()
{
    int i, j, sor;

    noPeca *ant1 = NULL;
    noPeca *ant2 = NULL;
    noPeca *atual1 = NULL;
    noPeca *atual2 = NULL;

    srand((unsigned)time(NULL));




    for(i=0; i<7; i++)
    {
        for(j=i; j<7; j++)
        {
            noPeca *novo = (noPeca *)malloc(sizeof(noPeca));

            novo ->face1 = i;
            novo ->face2 = j;
            novo ->prox = NULL;

            sor = rand()%2;
            if(c1 == 14){
                sor = 1;
            }
            if(c2 == 14){
                sor = 0;
            }

            if((i==6)&&(j==6))
            {
                priMesa = novo;
            }
            else if((c1+c2) < 27)
            {
                if((sor == 0) && (c1 <= 14)) // if player 1 is drawn
                {
                    if(atual1 == NULL) // first domino piece
                    {
                        priPlayer1 = novo;
                        atual1= priPlayer1;
                    }
                    else
                    {
                        ant1 = atual1;
                        ant1->prox = novo;
                        atual1 = novo;
                    }
                    c1++;
                }
                if((sor == 1) && (c2 <= 14)) // if player 1 is drawn
                {
                    if(atual2 == NULL) // first domino piece
                    {
                        priPlayer2 = novo;
                        atual2 = priPlayer2;
                    }
                    else // any other piece
                    {
                        ant2 = atual2;
                        ant2->prox = novo;
                        atual2 = novo;
                    }
                    c2++;
                }
            }
        }
    }
    if(c1==14)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void imprime(noPeca *atual)
{
    while(atual != NULL)
    {
        printf("[%d:%d] ",atual->face1,atual->face2);
        atual = atual->prox;
    }
}

noPeca *removePlayer1(int face)
{
    noPeca *ant1 = NULL;
    noPeca *atual1 = priPlayer1;

    while((atual1 != NULL) && (atual1->face1 != face) && (atual1->face2 != face))
    {
        ant1 = atual1;
        atual1 = atual1->prox;
    }
    if(atual1 == NULL)
    {
        return NULL;
    }
    else
    {
        c1--;
        //removal in the first position of the list
        if(atual1 == priPlayer1)
        {
            priPlayer1=atual1->prox;
        }//end if
        else
        {
            //removal in any position on the list
            ant1->prox = atual1->prox;
        }//end else

        return atual1; //returns the pointer of the first piece
        free(atual1);  //eliminating from memory
    }
}

noPeca *removePlayer2(int face)
{
    noPeca *ant2 = NULL;
    noPeca *atual2 = priPlayer2;

    while((atual2 != NULL) && (atual2->face1 != face) && (atual2->face2 != face))
    {
        ant2 = atual2;
        atual2 = atual2->prox;
    }
    if(atual2 == NULL)
    {
        return NULL;
    }
    else
    {
        c2--;
        //removal in the first position of the list
        if(atual2 == priPlayer2)
        {
            priPlayer2 = atual2->prox;
        }//end if
        else
        {
            //removal in any position on the list
            ant2->prox = atual2->prox;
        }//end else

        return atual2; //returns the pointer of the first piece
        free(atual2);  //eliminating from memory
    }
}


void insereInicioMesa(noPeca *inpec)
{
    noPeca *aux = NULL;
    aux = priMesa;
    priMesa = inpec;
    priMesa -> prox = aux;
}

void insereFimMesa(noPeca *fimpec)
{
    noPeca *ant = NULL;
    noPeca *atual = priMesa;

    while(atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = fimpec;
    atual = fimpec;
    fimpec->prox = NULL;
}

int quantMesa(){
    noPeca* atual = priMesa;
    int quant = 0;

    while(atual != NULL){
        quant++;
        atual = atual->prox;
    }
    return quant;
}

int main(int argc, char ** argv)
{
	printf("---------------------------------------------------------------------------------------------\n");
    printf("                                           PlayerO DE DOMINO                                    \n");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\n");

    int quant = 0, ant = 0, contador = 0;

    int ini = 6, fim = 6;       //main
    int Player = inicializa();
    noPeca * aux;
    while ((priPlayer1 != NULL) && (priPlayer2 != NULL))
    {
        quant = quantMesa();

        if(ant == quant){
            contador++;
        }
        ant = quant;

        if(contador == 5){
            break;
        }

        printf("Player1=");
        imprime(priPlayer1);
        printf("\n");
        printf("Player2=");
        imprime(priPlayer2);
        printf("\n");
        printf("\n");
        printf("mesa=");
        imprime(priMesa);
        printf("\n");
        getchar();
        if (Player == 0)
        {
            aux = removePlayer1(ini);
            if (aux != NULL)
            {
                insereInicioMesa(aux);
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
            }
            else
            {
                aux = removePlayer1(fim);
                if (aux != NULL)
                {
                    insereFimMesa(aux);
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                }
            }
            Player = 1;
        }
        else
        {
            aux = removePlayer2(ini);
            if (aux != NULL)
            {
                insereInicioMesa(aux);
                if (aux->face1 == ini)
                {
                    ini = aux->face2;
                }
                else
                {
                    ini = aux->face1;
                }
            }
            else
            {
                aux = removePlayer2(fim);
                if (aux != NULL)
                {
                    insereFimMesa(aux);
                    if (aux->face1 == fim)
                    {
                        fim = aux->face2;
                    }
                    else
                    {
                        fim = aux->face1;
                    }
                }
            }
            Player = 0;
        }
    }
    printf("\n\n");
    printf("----------------------------------------------------------------------------------------\n");
    if(c1 == 0){
        printf("                             GANHADOR: Player 1\n");
    }else if(c2 == 0){
        printf("                             GANHADOR: Player 2\n");
    }else if(c1 < c2){
        printf("                             GANHADOR: Player 1\n");
    }else if(c1 > c2){
        printf("                             GANHADOR: Player 2\n");
    }else if(c1 == c2){
        printf("                                   EMPATE\n");
    }
    printf("----------------------------------------------------------------------------------------\n");
    return 0;
    system("pause");
    system("pause");
}
