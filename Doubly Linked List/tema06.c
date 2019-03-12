/*
(2 p) 1. Să se implementeze o listă liniară dublu înlănţuită alocată dinamic în care se
vor reţine numere întregi. Scrieţi funcţii pentru:
a) Adăugarea unui element la început;
b) Adăugarea unui element la sfârşit;
c) Adăugarea unui element în interiorul listei;
d) Afişarea elementelor listei în ordinea introducerii lor;
e) Afişarea elementelor listei în ordine inversă;
f) Ştergerea unui element din listă ştiind numărul lui de ordine;
g) Ştergerea unui element din listă ştiind valoarea lui.
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

list* adaug_mij(list* head,int val)
{
    int elem;
    printf(" [3] Ce element doresti sa adaugi dupa valoarea %d? \n Raspuns : ",val);
    scanf("%d",&elem);

    list* nou=(list*)malloc(sizeof(list));
    nou->next=NULL;
    nou->prev=NULL;
    nou->data=elem;

    if(head==NULL)
        printf("Valoarea nu exista.\n");
else
   {
    list* temp=head;
    while(temp && temp->data!=val)
        temp=temp->next;

         if(temp==NULL)
            printf("\n Valoarea nu exista.\n");
else  if(temp->next==NULL)
    {
      nou->next=NULL;
      nou->prev=temp;
      temp->next=nou;
    }
else
    {
    nou->next=temp->next;
    nou->prev=temp;
    temp->next->prev=nou;
    temp->next=nou;
    }
}
    return head;
}

list* stergere_valoare(list* head,int val)
{
    if (head->data==val)
    {   list* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    else
    {
        list* temp=head;
        while(temp->next&&temp->next->data!=val) temp=temp->next;

  if(temp->next!=NULL)
  {
    list* sterg=temp->next;
    temp->next->next->prev=temp;
    temp->next=temp->next->next;
    free(sterg);
  }
else printf("\n Valoarea nu se afla in lista\n");
}
return head;
}

list* stergere_pozitie(list* head,int poz)
{
int i=0;

if (poz==0)
    {   list* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
    else
    {
        list* temp=head;
        while(temp->next&&i!=poz-1)
        {temp=temp->next;
        i++;}

  if(temp->next!=NULL)
  {
    list* sterg=temp->next;
    temp->next->next->prev=temp;
    temp->next=temp->next->next;
    free(sterg);
  }

else printf("\n Lista nu are atatea elemente\n");
}
return head;
}

void afisare(list* head)
{
    list* temp=head;
    if(head==NULL)
        printf("lista e goala\n");
    else
        {
        while(temp!=NULL)
          {
            printf("%d ",temp->data);
            temp=temp->next;
          }
        }
}

void reverse(list* head)
{
    list* temp=head;
    if(head==NULL)
        printf("lista e goala");
    else
        {
        while(temp->next)
            temp=temp->next;
        while(temp)
          {
           printf("%d ",temp->data);
           temp=temp->prev;
          }
        }
}

int main()
{
    int n=3,i,numar,optiune,val,poz;
    list* head=NULL;

  do
  {
    printf("Ce doresti sa faci?\n\n [1] Adaugarea unui element la inceput.\n [2] Adaugarea unui element la sfarsit.\n [3] Adaugarea unui element in interiorul listei\n [4] Afisarea elementelor listei in ordinea introducerii lor.\n [5] Afisarea elementelor listei in ordine inversa.\n [6] Stergerea unui element din lista stiind numarul lui de ordine.\n [7] Stergerea unui element din lista stiind valoarea lui.");
    printf("\n Raspuns : ");
    scanf("%d",&optiune);
    printf("\n");

    switch(optiune)
    {
          case 1:
            head=adaug_inceput(head);
            printf("\n");
            break;
          case 2:
            head=adaug_final(head);
            printf("\n");
            break;
          case 3:
            printf(" [3] Valoarea dupa care doriti sa introduceti elementul\n Raspuns : ");
            scanf("%d",&val);
            head=adaug_mij(head,val);
            printf("\n");
            break;
          case 4:
            printf(" Lista ta: ");
            afisare(head);
            printf("\n");
            printf("\n");
            break;
          case 5:
            printf(" Lista ta: ");
            reverse(head);
            printf("\n");
            printf("\n");
            break;
          case 6:
            printf(" [7] Pozitia elementului pe care doriti sa il stergeti\n Raspuns : ");
            scanf("%d",&poz);
            head=stergere_pozitie(head,poz);
            printf("\n");
            afisare(head);
            printf("\n\n");
            break;
          case 7:
            printf(" [6] Valoarea elementului pe care doriti sa il stergeti\n Raspuns : ");
            scanf("%d",&val);
            head=stergere_valoare(head,val);
            printf("\n");
            afisare(head);
            printf("\n\n");
            break;
          default:
            printf(" Optiune invalida\n");
            break;
    }

  } while(optiune>=1 && optiune <=7);


    return 0;
}
