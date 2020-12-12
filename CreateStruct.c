#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct no *prox;
};

int main()
{
    struct No *MyNewNode = malloc(sizeof(struct No));
    MyNewNode->valor = 123;
    printf("Value is: %d",MyNewNode->valor);
    return 0;
}