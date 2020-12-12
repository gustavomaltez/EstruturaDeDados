#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct Node *prox;
}Node;

Node *firstPosition = NULL;
int listLength = 0;

void addNewValue(int value, int position){

    Node *MyNewNode = malloc(sizeof(Node));
    MyNewNode->value = value;
    MyNewNode->prox = NULL;

    if(listLength == 0 && position == 0){ //if list is empty
        firstPosition = MyNewNode;
        listLength++;
    }else if(listLength > 0 && position <= listLength){
        //Add value on list start
        if(position == 0){
            MyNewNode->prox = firstPosition;
            firstPosition = MyNewNode;
            listLength++;
        }
    }
}

int main()
{
    

    return 0;
}