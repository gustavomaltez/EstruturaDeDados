#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

No *inicio = NULL;
int tamanhoDaLista = 0;

void adicionarNaLista(int valor, int pos){

    if(pos >= 0 && pos <= tamanhoDaLista){ //Verifica se a posição está no range da lista

        //Cria um novo nó
        No *novoNo = malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->prox = NULL;

        if(tamanhoDaLista == 0){ //Lista está vazia
            inicio = novoNo; //Define que o inicio é o novo nó (Pq ele é o único nó da lista)
            tamanhoDaLista++; //Aumenta o tamanho da lista
        }else if(pos == 0){ //Adiciona no inicio da lista quando a lista já tem algum elemento
            novoNo->prox = inicio;
            inicio = novoNo;
        }else if(pos <= tamanhoDaLista){ //Adicionar no fim da lista ou no meio da lista

            No *aux = inicio; //Cria um ponteiro aux

            for(int i = 0; i < pos - 1; i++){ //Percorre toda a lista ate chegar no último elemento
                aux = aux->prox; //Atualiza o valor de aux conforme a posição da lista
            }
            //Veja que aux é o elemento antes da posição que queremos adicionar
            //ISSO BASICAMENTE FAZ PENULTIMO-DA-LISTA -> NOVO -> RESTANTE-DA-LISTA
            novoNo->prox = aux->prox; //Faz o novo nó apontar pro restante da lista
            aux->prox = novoNo; // Faz o nó antes do novo nó apontar para o novo nó
            tamanhoDaLista++; //Aumenta o tamanho da lista
        }
    }else{
        printf("Pos invalida!");
    }
}

int main(){
    adicionarNaLista(8,0);
    adicionarNaLista(7,1);
    adicionarNaLista(9,2);
    adicionarNaLista(92,3);
    adicionarNaLista(93,2);

    return 0;
}
