#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void imprimir(){
    No *aux = inicio;
    int valor = 0;

    for (int i = 0; i < tamanhoDaLista; i++)
    {
        printf("%d\n",aux->valor);
        
        if(aux->valor % 2 == 0 && aux->valor > 0){
            valor+=aux->valor;
        }

        aux = aux->prox;
    }
    
    printf("Resultado: %f\n", pow(valor,2));
}

float questao2(){
    No *aux = inicio;
    int soma = 0;

    //Percorre toda a lista
    for (int i = 0; i < tamanhoDaLista; i++)
    {   
        //Verifica se o número é um par positivo
        if(aux->valor % 2 == 0 && aux->valor > 0)
            soma+=aux->valor;

        //Avança aux para o próximo nó
        aux = aux->prox;
    }
    
    //Retorna o resultado da soma ao quadrado
    return pow(soma,2);
}

void remover(int pos){
    if(pos >= 0 && pos <= tamanhoDaLista){

        if(pos <= tamanhoDaLista){ //Remover no meio da lista

        }

    }else{
        printf("Position invalid");
    }
}
int main(){
    adicionarNaLista(2,0);
    adicionarNaLista(4,1);
    adicionarNaLista(6,2);
    adicionarNaLista(8,3);
    adicionarNaLista(10,4);
    adicionarNaLista(7,5);
    adicionarNaLista(19,6);
    imprimir();


    return 0;
}
