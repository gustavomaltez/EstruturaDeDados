#include <stdio.h>
#include <stdlib.h>

// struct No{
//     int valor;
//     struct No *prox;
// };

//Usando typedef
typedef struct{
    int valor;
    struct No *prox;
}No;

int main()
{
    No *MyNewNode = malloc(sizeof(No));
    
    MyNewNode->valor = 123;
    MyNewNode->prox  =  NULL;
    printf("Value is: %d",MyNewNode->valor);
    return 0;
}