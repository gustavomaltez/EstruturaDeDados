#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct Node *prox;
}Node;

int main()
{
    Node *MyNewNode = malloc(sizeof(Node));
    MyNewNode->value = 123;
    printf("Value is: %d\n",MyNewNode->value);

    return 0;
}