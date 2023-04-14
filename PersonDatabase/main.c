#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[30];
    unsigned int age;
    char job[30];
};
struct Person **iterator;
unsigned int counter=0;
unsigned int initsize=10;

void allocateDataBase()
{
    iterator = malloc(initsize* sizeof(struct Person));
    for (unsigned int i=0;i<initsize; i++)
    {
        iterator[i] = NULL;
    }

}

void reallocateDataBase()
{
    iterator = realloc(iterator, initsize * sizeof(struct Person));

}

void add()
{
    if (counter % 5==0 && (counter !=0 && counter !=5))
    {
        initsize +=5;
        reallocateDataBase();
    }
    iterator[counter] = (struct Person *)malloc(sizeof(struct Person));
    printf("\nName of this person: ");
    scanf("%s", iterator[counter]->name);
    printf("\nAge of this person: ");
    scanf("%u", &(iterator[counter]->age));
    printf("\nThis Person's job: ");
    scanf("%s", iterator[counter]->job);
    printf("\nThis person was successfully added in database");
    counter ++;
}


void list()
{
    if (counter==0)
    {
        printf("\nYou haven't added anyone in the database \n");
    }
    for (unsigned int i=0; i< counter; i++)
    {
        printf("\n\nThe Entered information for person: ");
        printf("%d", i+1);
        printf("\nname: ");
        printf("%s", iterator[i]->name);
        printf("\nage: ");
        printf("%d", iterator[i]->age);
        printf("\njob: ");
        printf("%s",iterator[i]->job);
    }
}

char showmenu()
{

    printf("\n\n\n");
    printf("Please choose an option from the menu:\n");
    printf("a:Add person \n");
    printf("l:List whole databas \n");
    printf("x:Exit the program \n");
    printf("d:Delete a person(sorry not available) \n");
    printf("\n");
    printf("\nEnter the chosen option: ");
    char ch;
    while (!(scanf("%c", &ch)) && ch !='a' && ch !='l' && ch !='x'  && ch !='d')
    {
        printf("\nError input try again: ");
        scanf(" %c", &ch);
    }
    return ch;
}

void freeDataBase()
{
    for (unsigned int i=0; i<initsize; i++)
    {
        if (iterator[i] != NULL)
        {
            free(iterator[i]);
            iterator[i]=0;
        }
    }
    free(iterator);
    iterator = 0;
}
int main()
{
    allocateDataBase();
    do
    {
        char choice=showmenu();
        switch (choice)
        {
        case 'a':
            add();
            break;
        case 'l':
            list();
            break;
        case 'd':
            printf("Not available!!!");
            break;
        case 'x':
            freeDataBase();
            return 0;
        }
    } while (1);
    return 0;
}
void allocateDataBase();
void reallocateDataBase();
void add();
void list();
char showmenu();
void freeDataBase();
