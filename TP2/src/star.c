#include "star.h"

void initStar(stars *starstructure)
{
    starstructure->identifier = 0;
    starstructure->distance = 0;
    starstructure->magnitude = 0.0;
    for (int i = 0; i < 21; i++)
    {
        starstructure->name[i] = '\0';
    }
    for (int j = 0; j < 4; j++)
    {
        starstructure->constellation[j] = '\0';
    }
}

void printStar(FILE *file,const stars *star)
{
    int i = fprintf(file,"%6lld %3s %3d %+-5.2f %s\n",star->identifier,star->constellation,star->distance,star->magnitude,star->name);
    if (i < 0) 
    {
        perror("error");
        exit(EXIT_FAILURE); 
    }    
}
