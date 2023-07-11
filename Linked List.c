#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct LList
{
    int value;
    struct LList *next;
};
struct LList *createLList(int *array,int size)
{
    struct LList *head=malloc(sizeof(struct LList));
    struct LList *current=malloc(sizeof(struct LList));
    head=current;
    for(int i=0;i<size;i++)
    {
        current->value=array[i];
        if((i+1)<size)
        {
            struct LList *node=malloc(sizeof(struct LList));
            current->next=node;
            current=current->next;
        }
        else
        {
            current->next=NULL;
        }
    }
    return head;
}
void printLList(struct LList *head)
{
    for(;head;head=head->next)
    {
        if(head->next)
        {
            printf("%d -> ",head->value);
        }
        else
        {
            printf("%d -> NULL",head->value);
        }
    }
}
void clearLList(struct LList *head)
{
    while(head)
    {
        struct LList *current=head;
        head=head->next;
        free(current);
    }
}
int main()
{
    srand(time(NULL));
    int size=rand()%20;
    int *array=calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        array[i]=rand()%100;
    }
    struct LList *head=createLList(array,size);
    printLList(head);
    clearLList(head);
    return 0;
}
