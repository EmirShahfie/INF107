#include "star-list.h"

node *emptyList(){
    return NULL;
}

node *append(node *list, stars *myStar){
    node *new = (node *) malloc(sizeof(node));
    if (new == NULL) {
        fprintf(stderr, "Error: could not allocate memory for new node\n");
        return NULL;
    }

    memcpy(&new->starNode, myStar, sizeof(stars));

    if (list == NULL) {
        list = new;
        new->next = NULL;
    } else {
        node *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        new->next = NULL;
    }
    return list;
}

void freeList(node *list){
    while(list != NULL){
        node *temp = list->next;
        free(list);
        list = temp;
    }
}