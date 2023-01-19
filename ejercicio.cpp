#include <stdio.h>
int b;
int funcion_test(int a){
    a=b+a;
    return a;
}

int main(){
    int a =2;
    b=5;
    a=funcion_test(b-a);

    printf("a= %d, b=%d", a,b);
}