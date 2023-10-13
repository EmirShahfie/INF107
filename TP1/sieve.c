#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool elements[100];

void sieve(){
    for (int i = 0; i < 100; i++)
    {
        elements[i] = true;
    }
    for (int j = 2; j < 100 ; j++)
    {
        for (int k = j + 1 ; k < 100; k++)
        {
            if (k % j == 0) elements[j] = false;
        }
    }  
}

int main(){
    for (int h = 0; h < 100; h++)
    {
       if (elements[h] == true)
       {
            printf("%d", h); 
       }
    }
    return EXIT_SUCCESS;
}