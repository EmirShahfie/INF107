#include "star-database.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        fprintf (stderr,"error");
        exit(EXIT_FAILURE);
    }

    node *list = (node *) malloc(sizeof(node));
    node *ptr = (node *) malloc(sizeof(node));    

    list = readAllStar(argv[1]);
    ptr = list;
    while(ptr != NULL){
        printStar(stdout,&ptr->starNode);
        ptr = ptr->next;
    }
    freeList(list);
    return EXIT_SUCCESS;
}