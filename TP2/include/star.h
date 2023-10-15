#ifndef STAR_H
#define STAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct star{
    long long identifier; // numeric star identifier
    char name[21]; // name of the star in the form of a string
    char constellation[4]; // name of the star's constellation
    int distance; // star's distance from Earth in Parsecs
    float magnitude; // star's magnitude
}stars;

extern void initStar(stars *starstructure);

extern void printStar(FILE *file,const stars *star);

#endif