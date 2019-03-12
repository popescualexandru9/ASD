/*
(2 p) 2. Coada cu priorităţi este o coadă în care elementele au, pe lângă cheie şi o prioritate.
 Vom presupune că cea mai înaltă prioritate este 1, urmată de 2, şi aşa mai departe. Ordinea liniară este dată de regulile:
  - elementele cu aceeaşi prioritate sunt extrase (şi procesate) în ordinea intrării
   - toate elementele cu prioritate i se află înaintea celor cu prioritate i+1 (şi deci vor fi extrase înaintea lor).
 Extragerile se fac dintr-un singur capăt. Ca să se poată aplica regulile de mai sus la extragere,
inserarea unui nou element cu prioritate i se va face la sfârşitul listei ce conţine toate elementele cu prioritate i.
 Să se scrie procedurile de punere şi scoatere a unui element într-o, respectiv, dintr-o coadă cu priorităţi reprezentată cu ajutorul unei liste simplu înlănţuite.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
  int data;
  int prioritate;
  struct stack* next;
}stack;

struct stack* pop (struct stack* root)
{
  int value;
  if(root==NULL)
    {
       printf("Nu e nimeni la coada.\n\n");
       return root;
    }
  struct stack* temp=root;
  value=root->data;
  root=root->next;
  free(temp);
  return root;
}

void afisare(struct stack* root )
{
  struct stack* temp = root;
  while(temp)
  {
      printf("%d [%d] ",temp->data,temp->prioritate);
      temp=temp->next;
  }
}

stack* push(stack* root)
{
  int val,cheie;
  printf("Valoare pe care doriti sa o introduceti : ");
  scanf("%d",&val);
  printf("Prioritatea elementului : ");
  scanf("%d",&cheie);

  stack* nou=(stack*)malloc(sizeof(stack));
  nou->data=val;
  nou->prioritate=cheie;
  nou->next=NULL;

        if(root==NULL)
        root=nou;
else if(nou->prioritate<root->prioritate)
    {
        nou->next=root;
        root=nou;
    }
else
    {
     stack* temp=root;
     while(temp->next&& temp->next->prioritate<=nou->prioritate)
        temp=temp->next;
     if(temp->next)
       {
         nou->next=temp->next;
         temp->next=nou;
       }
else temp->next=nou;
    }
return root;
}

int exercitiu(stack* root)
{
    int optiune;
    do
    {
      printf("Ce doriti sa faceti?\n\n 1. Push\n 2. Pop\n\n");
      printf("Raspuns : ");
      scanf("%d",&optiune);
      printf("\n");

      switch(optiune)
        {
      case 1:
        root=push(root);
        printf("\n");
        printf("Coada : ");
        afisare(root);
        printf("\n\n");
        break;
      case 2:
        root=pop(root);
        printf("\n");
        printf("Coada : ");
        afisare(root);
        printf("\n\n");
        break;
      default:
        printf("Optiune invalida");
        break;
        }
    }while(optiune >=1 && optiune<=2);
}

int main()
{
int i,n,valoare;
stack* root=NULL;
printf("Numarul de elemente introduse in coada : ");
scanf("%d", &n);

for(i=0;i<n;i++)
root=push(root);
printf("\n");
afisare(root);
printf("\n");
exercitiu(root);

return 0;
}

