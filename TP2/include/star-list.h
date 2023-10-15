#ifndef STAR_LIST_H
#define STAR_LIST_H

#include "star.h"

typedef struct node_t{
    stars starNode;
    struct node_t * next;
}node;

extern node *emptyList();

extern void append(node *list, stars *myStar);

extern void freeList(node *list);

#endif