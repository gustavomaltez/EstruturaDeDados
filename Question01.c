#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 1;
    int *p = &x; //Define um ponteiro para p que armazena o endereço de x;
    printf("%d\n",*p);
    *p = x; //Define que p armazena o endereço de
    printf("%d\n",*p);
    int a = (*p);
    int *k = &a;
    x = a;
    printf("%d\n",*p);
    p = k;
    a = x;
    printf("%d\n",*p);
    return 0;
}