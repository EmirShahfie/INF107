#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNegative(int a){
    int b = a >> 31;
    return  b;
}

int main(){
    printf("%d\n",isNegative(-2555));
    printf("%d\n",isNegative(2555));
    printf("%d\n",isNegative(21));   
    return EXIT_SUCCESS;
}