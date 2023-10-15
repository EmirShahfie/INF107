#include "star-list.h"

node *emptyList(){
    return NULL;
}

void append(node *list, stars *myStar){
    node *new = (node *) malloc(sizeof(node));
    node *current = (node *) malloc(sizeof(node));
    
    memcpy ( &list->starNode, &myStar, sizeof(stars) );    
    
    if(list == NULL){
        list->next = NULL;
    }
    else{
        current = list;
        while (current->next != NULL)
        {
            current = current->next;
        }
        memcpy ( &new->starNode, &myStar, sizeof(stars) );
        current->next = new;
        new->next = NULL;    
    }
}

void freeList(node *list){
    while(list != NULL){
        node *temp = list->next;
        free(list);
        list = temp;
    }
}