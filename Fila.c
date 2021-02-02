// ATIVIDADE FILA EM C 
// ALUNO: GUSTAVO MORAES MALTEZ
// MATRÍCULA 497273

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;

int tam = 0;

void add(int valor){
    //Cria um novo nó
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;

    //Aponta o início para novo se a lista estiver vazia
    if(tam == 0){
        inicio = novo;   
    }else{ //Caso contrario aponta o último nó para o novo
        fim->prox = novo;
    }

    //Aponta o fim para o último nó adicionado
    fim = novo;
    tam++;
}

int remover(){
    //Cria um nó lixo e armazena seu valor para retorno
    NO *lixo = inicio;
    int valor_removido = lixo->valor;

    //Aponta o início para o nó posterior a ele
    inicio = inicio->prox;

    //Remove o nó da memória e decrementa o tamanho da lista
    free(lixo);
    tam--;

    //Retorna o valor removido
    return valor_removido;
}

void imprimir(){
    //Cria um nó para percorrer a lista
    NO *aux = inicio;

    //Percorre toda a lista impriminto todos os valores
    for(int i = 0; i < tam; i++){
        printf("%d ",aux->valor);
        aux = aux->prox;
    }
}

int main(){
    add(1);
    add(2);
    remover();
    add(3);
    add(4);
    remover();
    add(5);
    add(6);
    remover();
    remover();
    add(7);
    add(8);
    add(9);
    add(10);
    remover();
    add(11);
    add(12);
    add(13);
    remover();
    add(14);
    add(15);
    remover();
    add(16);
    remover();
    add(17);
    add(18);
    add(19);
    add(20);
    remover();
    remover();
    imprimir();
    return 0;
}