#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair
{
    //encoded char
    char c;
    //occurrences of `c`
    unsigned int n;
} Pair;

typedef struct Encoded
{
    unsigned int length;
    Pair* arr;
} Encoded;

unsigned int size = 0;
unsigned int indx = 0;

Pair* pairs;

int validateEntry(char* str);
void allocateMemory();
void deallocHEAP();

Encoded* encode(char* text)
{
    unsigned int thelength = strlen(text);
    size = thelength;
    allocateMemory();
    unsigned int cnt = 1;
    if (pairs==NULL)
    {
        printf("memory allocation failed!");
        deallocHEAP();
        exit(1);
    }

    for (unsigned int i=1; i<thelength; i++)
    {
        char current=text[i];
        if (current==text[i-1])
        {
            cnt++;
        }
        else if (current!=text[i-1])
        {
            pairs[indx].c=text[i-1];
            pairs[indx].n=cnt;
            indx++;
            cnt = 1;
        }
    }
    unsigned int lengthpairs =indx+1;
    pairs[indx].c=text[thelength-1];
    pairs[indx].n=cnt;
    Encoded* theresult;
    theresult = malloc(sizeof(struct Encoded) * size);
    theresult->length=lengthpairs;
    theresult->arr=pairs;
    return theresult;
}

char* decode(Encoded text)
{
    char* result;
    unsigned int lenght=0;
    for (unsigned int i=0; i<text.length;i++)
    {
        for (unsigned int j=0;j<text.arr[i].n;j++)
        {
            result[lenght]=text.arr[i].c;
            lenght++;
        }
    }
    result[lenght] = '\0';
    return result;
}
int validateEntry(char* str)
{
    unsigned int i=0;
    while (str[i]!='\0')
    {
        if (str[i]<'a' || str[i]>'z')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void allocateMemory()
{
    pairs=malloc(sizeof(struct Pair) * size);
}
void deallocHEAP()
{
    free(pairs);
    pairs=0;
}

int main()
{

    char text[255];
    scanf("%s", text);
    if (validateEntry(text))
    {

        Encoded *enc=encode(text);
        for (unsigned int i = 0;i< enc->length;i++)
        {
            printf("(%c,",enc->arr[i].c);
            printf("%u)",enc->arr[i].n);
        }
        printf("->%s\n", decode(*enc));
        printf("\n");
    }
    else
    {
        printf("Incorrect input!\n");
        return 0;
    }
    deallocHEAP();
    return 0;
}