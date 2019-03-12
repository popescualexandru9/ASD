/*
(1 p) 3. Să se folosească un arbore binar de căutare pentru a sorta n numere.
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
int a[100],n=0;

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
        a[n]=root->data;
        n++;
        SRD(root->dr);
    }
}

int main()
{
    int i,numere,nr;
    printf(" Cate numere vei citi? \n Raspuns : ");
    scanf("%d",&numere);
    printf("\n");
    for(i=0;i<numere;i++)
    {
        printf(" Numar : ");
        scanf("%d",&nr);
        push(nr);
    }
    printf("\n");
    SRD(root);
    printf(" Numere sortate : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
