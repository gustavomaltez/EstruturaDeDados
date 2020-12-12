#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct Node *prox;
}Node;

Node *firstPosition = NULL;
int listLength = 0;

void addNewValue(int value){

    Node *MyNewNode = malloc(sizeof(Node));
    MyNewNode->value = value;
    MyNewNode->prox = NULL;

    if(listLength == 0){
        firstPosition = novo;
        listLength++;
    }else{

    }
}

int main()
{
    

    return 0;
}