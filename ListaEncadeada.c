#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct Node *prox;
}Node;

Node *firstPosition = NULL;
int listLength = 0;

void addNewValue(int value){
    if(listLength == 0){

    }else{
        
    }
}

int main()
{
    Node *MyNewNode = malloc(sizeof(Node));
    MyNewNode->value = 123;
    MyNewNode->prox = NULL;
    printf("Value is: %d\n",MyNewNode->value);

    firstPosition = novo;

    return 0;
}