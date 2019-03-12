/*
(2 p) 3. Se numeşte DEQUE (de la Double Ended Queue) o structură liniară în care inserările şi ştergerile se pot face la
 oricare din cele două  capete, dar în nici un alt loc din coadă.
   Considerând structura DEQUE implementată cu ajutorul unei liste liniare cu dublă înlănţuire, să se scrie procedurile de inserare
şi ştergere la ambele capete ale ei; să se utilizeze aceste proceduri într-un program care afişază un meniu în vederea selectării
procedurii dorite din cele patru posibile.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int data;
  struct list* next;
  struct list* prev;
}list;

 list* adaug_inceput(list* head)
{
    int elem;
    printf(" [1] Ce element doresti sa adaugi la inceput? \n Raspuns : ");
    scanf("%d",&elem);

    list* nou=(list*)malloc(sizeof(list));
    nou->next=NULL;
    nou->prev=NULL;
    nou->data=elem;

    if(head==NULL)
     head=nou;
else
     {
         nou->next=head;
         head->prev=nou;
         head=nou;
     }
     return head;
}

list* adaug_final(list* head)
{
    int elem;
    printf(" [2] Ce element doresti sa adaugi la final? \n Raspuns : ");
    scanf("%d",&elem);

    list* nou=(list*)malloc(sizeof(list));
    nou->next=NULL;
    nou->prev=NULL;
    nou->data=elem;

    if(head==NULL)
     head=nou;
else
   {
    list* temp=head;
    while(temp->next)
        temp=temp->next;

    temp->next=nou;
    nou->prev=temp;
    }
    return head;
}

void afisare(list* head)
{
    list* temp=head;
    if(head==NULL)
        printf("lista e goala");
    else
        {
        while(temp!=NULL)
          {
            printf("%d ",temp->data);
            temp=temp->next;
          }
        }
}


 list* stergere_inceput(list* head)
{
    if (head==NULL)
        {printf("Lista este goala"); return head;}
else
   if (head->next==NULL)
   {
       list* temp=head;
       head=NULL;
       free(temp);
       return head;
   }
else
    {
        list* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
}

list* stergere_final(list* head)
{
    if (head==NULL)
       {printf("Lista este goala"); return head;}
else   if(head->next==NULL)
   {
       list* temp=head;
       head=NULL;
       free(temp);
       return head;
   }
else
    {
      list* temp=head;
      while(temp->next->next!=NULL)
        temp=temp->next;

    if(temp->next!=NULL)
      {
       list* sterg=temp->next;
       temp->next=NULL;
       free(sterg);
       return head;
       }

     }
}

int exercitiu(list* head)
{
     int optiune;
    do
    {
      printf("Ce doriti sa faceti?\n\n 1. Push inceput\n 2. Push final\n 3. Stergere inceput\n 4. Stergere final\n\n");
      printf("Raspuns : ");
      scanf("%d",&optiune);
      printf("\n");

      switch(optiune)
        {
      case 1:
        head=adaug_inceput(head);
        printf("\n");
        printf("Lista : ");
        afisare(head);
        printf("\n\n");
        break;

      case 2:
        head=adaug_final(head);
        printf("\n");
        printf("Lista : ");
        afisare(head);
        printf("\n\n");
        break;

      case 3:
        head=stergere_inceput(head);
        printf("\n");
        printf("Lista : ");
        afisare(head);
        printf("\n\n");
        break;

      case 4:
        head=stergere_final(head);
        printf("\n");
        printf("Lista : ");
        afisare(head);
        printf("\n\n");
        break;

      default:
        printf("Optiune invalida");
        break;
        }
    }while(optiune >=1 && optiune<=4);
}

int main()
{
    list* head=NULL;
    exercitiu(head);

    return 0;
}
