// Aluno: Gustavo Moraes Maltez
// Matrícula: 497273
// Turma: Estrutura de dados 2020 (T01)

#include<stdlib.h>
#include<stdio.h>

int tam = 0;
int lista[100]; //simular a minha lista

void add(int valor, int posicao){
    //nao pode aceitar posicoes invalidas = cria espaços
    if(posicao <= tam){
        int i;
        for(i=tam; i>posicao; i--){
            lista[i]=lista[i-1];
        }
        lista[posicao] = valor;
        tam++;
        
    }else{
        printf("Posição inválida! :/\n");
    }
    
}

//TRECHO DA ATIVIDADE - Aluno: Gustavo Moraes Maltez
int remover(int posicao){
    int lixo = lista[posicao];
    int i = posicao;

    if(posicao <= tam){
        while(i < tam){
            lista[i] = lista[i+1];
            i++;
        }
        tam--;    
    }else{
        printf("Posicao inexistente!\n");
    }
    return lixo;
}
//FIM DO TRECHO DA ATIVIDADE - Aluno: Gustavo Moraes Maltez

void imprimir(){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", lista[i]);
    }
}

int main(){
    add(7,0);
    add(9,1);
    add(5,0);
    add(4,1);
    imprimir();
    printf("LISTA APOS REMOVER O ELEMENTO NA POSICAO 0:\n");
    remover(0);
    imprimir();
    printf("LISTA APOS REMOVER O ELEMENTO NA POSICAO 1:\n");
    remover(1);
    imprimir();
}
