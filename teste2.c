#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 1;
    int a = 134;
    int *p;
    *p = &x; //Define que p armazena o endereço de
    printf("%d\n",p);
    return 0;
}