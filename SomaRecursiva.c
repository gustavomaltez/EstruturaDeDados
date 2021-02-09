// ALUNO: GUSTAVO MORAES MALTEZ
// MATRÍCULA: 497273
// ATIVIDADE SOMA RECURSIVA EM LISTA ENCADEADA

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

No *inicio = NULL;
int tamanhoDaLista = 0;

void adicionarNaLista(int valor, int pos){

    if(pos >= 0 && pos <= tamanhoDaLista){ 

        No *novoNo = malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->prox = NULL;

        if(tamanhoDaLista == 0){ 
            inicio = novoNo; 
            tamanhoDaLista++; 
        }else if(pos == 0){ 
            novoNo->prox = inicio;
            inicio = novoNo;
        }else if(pos <= tamanhoDaLista){ 

            No *aux = inicio; 

            for(int i = 0; i < pos - 1; i++)
                aux = aux->prox; 

            novoNo->prox = aux->prox; 
            aux->prox = novoNo; 
            tamanhoDaLista++; 
        }
    }else{
        printf("Pos invalida!");
    }
}

void imprimir(){
    No *aux = inicio;

    printf("LISTA: ");

    for(int i = 0; i < tamanhoDaLista; i++){
        printf("%d ",aux->valor);
        aux = aux->prox;
    }
}

/* CÓDIGO REFERENTE A QUESTÃO */
int somaRecursiva(No *no){
    if(no != NULL)
        return no->valor + somaRecursiva(no->prox); 
}
/* FIM DO CÓDIGO REFERENTE A QUESTÃO */

int main(){
    adicionarNaLista(1,0);
    adicionarNaLista(2,1);
    adicionarNaLista(3,2);
    adicionarNaLista(4,3);
    adicionarNaLista(5,4);
    imprimir();
    printf("\nSOMA: %d",somaRecursiva(inicio));
    
    return 0;
}
