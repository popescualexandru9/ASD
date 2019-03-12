/*
(2 p) 1. Să se implementeze o structură de arbore binar (care să nu fie arbore binar de
căutare) cu cheile numere întregi, inserate pe niveluri. Scrieţi funcţii pentru:
(a) adăugarea unui nod frunză
(b) parcurgerea cheilor conform strategiei RSD
(c) parcurgerea cheilor conform strategiei SRD
(d) parcurgerea cheilor conform strategiei SDR
*/

#include <stdio.h>
#include <stdlib.h>

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
        arb* frunza=(arb*)malloc(sizeof(arb));
        frunza->data=val;
        frunza->st=NULL;
        frunza->dr=NULL;
        if(root->st==NULL)
            root->st=frunza;
else if(root->dr==NULL)
            root->dr=frunza;
else
     {
       arb* temp=root;
       while(temp->st!=NULL)
          temp=temp->st;
       temp->st=frunza;
     }
   }
}

void RSD(arb* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        RSD(root->st);
        RSD(root->dr);
    }
}

void SRD(arb* root,int x,int y)
{
    if(root!=NULL)
    {
        SRD(root->st,x,y);
        if(root->data>x && root->data<y)
        printf("%d ",root->data);
        SRD(root->dr,x,y);
    }
}

void SDR(arb* root)
{
    if(root!=NULL)
    {
        SDR(root->st);
        SDR(root->dr);
        printf("%d ",root->data);
    }
}

int main()
{
    int i,n,elem;
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
    printf(" Parcurgere preordine  [RSD] : ");
    RSD(root);
    printf("\n");
    printf("\n");
    printf(" Parcurgere inordine   [SRD] : ");
    SRD(root,3,7);
    printf("\n");
    printf("\n");
    printf(" Parcurgere postordine [SDR] : ");
    SDR(root);
    printf("\n");

return 0;
}
