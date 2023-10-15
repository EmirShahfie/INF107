#include "star-database.h"

void printStar(FILE *file,const stars *star)
{
    int i = fprintf(file,"%6lld %3s %3d %+-5.2f %s\n",star->identifier,star->constellation,star->distance,star->magnitude,star->name);
    if (i < 0) 
    {
        perror("error");
        exit(EXIT_FAILURE); 
    }    
}

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
        append(list,&newStar);
    }
    
    return list;

    /*stars arrays[311];
    FILE *f = fopen(file, "r");
    if (f == NULL) exit(EXIT_FAILURE);
    for (int i = 0; i < 311; i++)
    {
        readStar(f,&arrays[i]);
        printStar(stdout,&arrays[i]);
    }
    fclose(f);*/
}

void test()
{
    /*char in1[] = "a:x";
    char *out1 = splitPrefix(in1, ':');
    printf("%s %s\n", in1, out1);

    char in2[] = "abcdefg";
    char *out2 = splitPrefix(in2, ':');
    printf("%s %s\n", in2, out2);

    char in3[] = "And:Alpheratz";
    char *out3 = splitPrefix(in3, ':');
    printf("%s %s\n", in3, out3); 

   
    printStar (stdout, &star);

    stars testStar;
    //FILE *f = fopen("output.txt", "w"); 
    scanf("{%lld,%s,%s,%d,%f}",&testStar.identifier,testStar.name,testStar.constellation,&testStar.distance,&testStar.magnitude);
    //initStar(&testStar);
    printStar(stdout,&testStar);*/

}