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

typedef struct node_t{
    stars starNode;
    struct node_t * next;
}node;

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

node *readAllStars(const char *file)
{
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", file);
        return NULL;
    }
    node *list = emptyList();
    stars newStar;

    while(readStar(f,&newStar)){
        list = append(list,&newStar);
    }
    fclose(f);
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

int main(int argc, char *argv[])
{
    //test();
    if (argc != 2) 
    {
        fprintf (stderr,"error");
        exit(EXIT_FAILURE);
    }
    
    node *list = readAllStars(argv[1]);
    node *ptr = list;
    while(ptr != NULL){
        printStar(stdout,&ptr->starNode);
        ptr = ptr->next;
    }
    freeList(list);
    return EXIT_SUCCESS;
}