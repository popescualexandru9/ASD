/*
(5 p) 2. Să se implementeze un arbore binar de căutare cu următoarele operații:
(a) insert (t, x) - inserează cheia x în arborele de rădăcină t;
(b) search (t, x) - întoarce 1 dacă elementul a se află în arborele de rădăcină
t și 0 în caz contrar;
(c) findMax (t) - întoarce elementul maxim din arborele de rădăcină t, fără a-l
șterge din arbore;
(d) delete (t, x) - șterge în arborele de rădăcină t nodul cu cheia x (păstrând
proprietatea de arbore binar de căutare).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arb
{
    int data;
    struct arb* dr;
    struct arb* st;
}arb;

arb* root;

void push(int val)
{
    if (root==NULL)
    {
        root=(arb*)malloc(sizeof(arb));
        root->data=val;
        root->st=NULL;
        root->dr=NULL;
    }
else
   {
        arb* temp=root;
        arb* dad;
        arb* son=(arb*)malloc(sizeof(arb));
        son->data=val;
        son->st=NULL;
        son->dr=NULL;
        while(temp!=NULL)
        {
            if(val<temp->data)
            {
                dad=temp;
                temp=temp->st;
            }
            else
            {
             dad=temp;
             temp=temp->dr;
            }
        }
        if(val<dad->data)
              dad->st=son;
        else
              dad->dr=son;
   }
}

void SRD(arb* root)
{
    if(root!=NULL)
    {
        SRD(root->st);
        printf("%d ",root->data);
        SRD(root->dr);
    }
}

void max(arb* root)
{
    if(root==NULL)
        printf(" Arborele este gol. ");
    else
     {
         arb* temp=root;
         while(temp->dr!=NULL)
            temp=temp->dr;
         printf("%d",temp->data);
     }
}

bool cautare(int val)
{
    if(root==NULL)
       printf(" Arborele este gol. ");
    else
    {
        arb* temp=root;
        while(temp)
            {
            if(temp->data==val)
                return true;
            if(val<temp->data)
                temp=temp->st;
            else
                temp=temp->dr;
           }
           return false;
   }
}

arb* minim(arb* root)
{
    arb* temp= root;
    while (temp->st != NULL)
        temp = temp->st;

    return temp;
}


arb* stergere(arb* root,int val)
{
        if(root==NULL)
          {printf(" Nu am gasit elementul.\n"); return root;}
        if(val<root->data)
          root->st=stergere(root->st,val);
else if(val>root->data)
          root->dr=stergere(root->dr,val);
else
    {
        if(root->st==NULL)
        {
            arb* temp=root->dr;
            free(root);
            return temp;
        }
else if(root->dr==NULL)
        {
            arb* temp=root->st;
            free(root);
            return temp;
        }
     arb* temp=minim(root->dr);
     root->data=temp->data;
     root->dr=stergere(root->dr,temp->data);
    }
    return root;
}

int main()
{
     int i,n,elem,optiune;
    printf(" Cate elemente vrei sa aiba arborele?\n Raspuns : ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" Elementul pe care vrei sa-l adaugi : ");
        scanf("%d",&elem);
        push(elem);
    }

     printf("\n");
     printf(" Parcurgere SRD : ");
     SRD(root);
     printf("\n\n");

     do
     {
         printf(" Ce vrei sa faci?\n 1) Insereaza in arbore\n 2) Cauta un element\n 3) Afiseaza maximul\n 4) Sterge un element\n 5) Afiseaza arborele SDR\n Raspuns : ");
         scanf("%d",&optiune);
         printf("\n");

         switch(optiune)
         {
         case 1:
            printf(" Elementul pe care vrei sa-l adaugi : ");
            scanf("%d",&elem);
            push(elem);
            printf("\n");
            break;

         case 2:
            printf(" Elementul pe care vrei sa-l cauti : ");
            scanf("%d",&elem);
            cautare(elem) ? printf(" Elementul %d se afla in arbore.\n ",elem) : printf(" Elementul %d nu se gaseste in arbore.\n ",elem);
            printf("\n");
            break;

         case 3:
            printf(" Elementul maxim este : ");
            max(root);
            printf("\n\n");
            break;

         case 4:
            printf(" Elementul pe care vrei sa-l stergi : ");
            scanf("%d",&elem);
            root=stergere(root,elem);
            printf("\n");
            break;

         case 5:
            printf(" Parcurgere SRD : ");
            SRD(root);
            printf("\n\n");
            break;

         default:
             printf("Optiune invalida.");
            break;
         }
     }while(optiune>=1 && optiune<=5);
     return 0;
}
