/*
(2 p) 5. Să se scrie procedurile de inserare şi ştergere nod într-o, respectiv, dintr-o listă circulară cu dublă înlănţuire şi nod marcaj,
 care implementează următoarea strategie: se inserează la dreapta nodului marcaj şi se şterge de la stânga sa;
 cum se poate interpreta această modalitate de modificare a listei ?
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
    nou->next =  start->next;
    start->next ->prev=nou;
    start->next= nou;
    nou->prev= start;
}
return start;
}

list* stergere(list* start)
{
  if (start->next==start)
    {
        printf(" %d este nod marcaj,nu poate fi sters\n\n",start->data);
        return start;
    }
else
    {
    list* temp=start->prev;
    start->prev->prev->next=start;
    start->prev=start->prev->prev;
    free(temp);
    }

return start;
}

int main()
{
    list *start=NULL;
    int n,key,i,optiune;
    printf(" Cate elemente doresti sa aiba lista?\n Raspuns : ");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++)
            start=push(start);
    printf("\n");
    printf(" Lista ta: ");
    afisare( start);
    printf("\n\n");

    do
    {
      printf(" Ce doresti sa faci?\n [1] Sa adaugi un element.\n [2] Sa stergi un element.\n");
      printf(" Raspuns : ");
      scanf("%d",&optiune);
      printf("\n");

      switch(optiune)
        {
      case 1:
        start=push(start);
        printf("\n");
        printf("Lista : ");
        afisare(start);
        printf("\n\n");
        break;

      case 2:
        start=stergere(start);
        printf("\n");
        printf("Lista : ");
        afisare(start);
        printf("\n\n");
        break;

        default:
        printf("Optiune invalida");
        break;
        }
    }while(optiune >=1 && optiune<=2);

return 0;
}
