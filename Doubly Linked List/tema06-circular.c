/*
(2 p) 4. Să se scrie procedurile de inserare, respectiv, ştergere a unui nod cu o cheie dată într-o,
 respectiv, dintr-o listă circulară cu dublă înlănţuire şi nod marcaj.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int data;
  struct list* next;
  struct list* prev;
}list;

void afisare( list*   start )
{
   list* temp =  start;
  while(temp->next!=start)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  printf("%d ",temp->data);
}

list* push(list*  start)
{
    int val;
    printf(" Ce valoare vrei sa introduci?\n Raspuns: ");
    scanf("%d",&val);

    list* nou= (list*)malloc(sizeof(list));
    nou->data = val;
    nou->next = nou->prev = NULL;

    if ( start == NULL)
    {
        nou->next = nou->prev = nou;
        start = nou;
    }
else
{
    list* last =  start->prev;
    nou->next =  start;
    start->prev = nou;
    nou->prev = last;
    last->next = nou;
}
return start;
}

list* stergere(list* start,int key)
{
  if (start->data==key)
    {
        printf(" %d este nod marcaj,nu poate fi sters\n\n",key);
        return start;
    }
else
    {
    list* temp=start;
    while(temp->next!=start&& temp->next->data!=key) temp=temp->next;

if(temp->next!=start)
    {
      list* sterg=temp->next;
      temp->next->next->prev=temp;
      temp->next=temp->next->next;
      free(sterg);
    }
else  printf("\n Valoarea nu se afla in lista\n");
}
return start;
}

int main()
{
    list *start=NULL;
    int n,key,i;
    printf(" Cate elemente doresti sa aiba lista?\n Raspuns : ");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++)
            start=push(start);
    printf("\n");
    printf(" Lista ta: ");
    afisare( start);
    printf("\n");
    for(i=0;i<n;i++)
        {printf("\n");
         printf(" Ce valoare vrei sa stergi?\n Raspuns : ");
         scanf("%d",&key);
         start=stergere(start,key);
         printf(" Lista ta: ");
         afisare( start);
         printf("\n");}
       return 0;
    }
