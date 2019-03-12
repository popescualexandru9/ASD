/*
(2p) 2. Dat un sir w = w1w2 .... wn (n par) de caractere 'a' si 'b', să se decidă
dacă in sirul w numarul de caractere 'a' este acelasi cu numarul de caractere 'b'. Sirul
de intrare se poate parcurge doar o singura data, iar pentru a decide rezultatul se va
folosi o stiva. Nu se permite numărarea aparitiilor caracterelor 'a', 'b'.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack{
    char data;
    struct stack* next;
}stack;

stack* push(stack* root,char c)
{
    stack* nou=(stack*)malloc(sizeof(stack));
    nou->data=c;
    nou->next=NULL;

    if(root==NULL)
        root=nou;
    else
        nou->next=root;

return nou;
}

stack* pop(stack* root)
{
    stack* temp=root;
    root=root->next;
    free(temp);
    return root;
}

int peek(stack* root)
{
    return root->data;
}

void afisare(stack* root )
{

  stack* temp = root;
  while(temp)
  {
      printf("%c \n",temp->data);
      temp=temp->next;
  }
}

bool empty(stack* root)
{
    if(root==NULL) return 1;
    else return 0;
}

void exercitiu(stack* root)
{
    stack* stiva1=NULL;
    stack* stiva2=NULL;
    char litera;
    int gol1,gol2;

    while(root)
    {
        litera=peek(root);
        root=pop(root);

        if(litera=='a')
          {stiva1=push(stiva1,litera);}
        if(litera=='b')
          {stiva2=push(stiva2,litera);}
    }

    while(stiva1 && stiva2)
    {
        stiva1=pop(stiva1);
        stiva2=pop(stiva2);
    }

    gol1=empty(stiva1);
    gol2=empty(stiva2);

    if(gol1==gol2)
        printf("Numarul literelor 'a' este egal cu numarul literelor 'b' ");
else printf("Numarul literelor 'a' nu este egal cu numarul literelor 'b' ");
}

int main()
{
  stack* root=NULL;
  int i,n;
  char litera;

  printf("Cate elemente doresti sa aiba stiva? \nRaspuns : ");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Valoare pe care doriti sa o introduceti: ");
    scanf(" %c",&litera);
    root=push(root,litera);
  }
  printf("\n");
  afisare(root);
  printf("\n");
  exercitiu(root);
  printf("\n");


  return 0;
}
