#include "star-database.h"

char *splitPrefix(char *s, char delimiter)
{
    int i = 0;
    while (*(s+i) != '\0')
    {
        if (*(s+i) == delimiter)
        {
            *(s+i) = '\0';
            return s+i+1;
            break;
        }
        else i++;
    }
    return NULL;
}

bool readStar(FILE *f, stars *etoile)
{
    long id;
    float distance, magnitude;
    char s[25];
    int i = fscanf(f,"%ld , %24s , %f , %f",&id,s,&distance,&magnitude);
    if (!i)
    {
        fprintf (stderr,"error");
        exit(EXIT_FAILURE);
    }
    else if (i == EOF)
    {
        initStar(etoile);
        return false;
    }
    else
    {
        initStar(etoile);
        char *d = splitPrefix(s,':');

        strncpy(etoile->name,d,sizeof(etoile->name));
        strncpy(etoile->constellation,s,sizeof(etoile->constellation));
        etoile->identifier = id;
        etoile->distance = distance;
        etoile->magnitude = magnitude;
        return true;
    }
    return NULL;
}

node *readAllStar(const char *file)
{
    FILE *f = fopen(file, "r");
    
    node *list = emptyList();
    stars newStar;

    while(readStar(f,&newStar)){
        list = append(list,&newStar);
    }
    
    return list;
}
