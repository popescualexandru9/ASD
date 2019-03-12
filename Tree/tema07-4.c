/*
(2 p) 4. Dat un arbore binar de căutare și doi întregi k1 și k2, să se afișeze toate cheile x
din arbore cu proprietatea
  k1<=x<=k2
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

void SRD(arb* root,int k1,int k2)
{
    if(root!=NULL)
    {
        SRD(root->st,k1,k2);
        if(root->data>=k1 && root->data<=k2)
        printf("%d ",root->data);
        SRD(root->dr,k1,k2);
    }
}

int main()
{
     int i,n,k1,k2,elem;
    printf(" Cate elemente vrei sa aiba arborele?\n Raspuns : ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" Elementul pe care vrei sa-l adaugi : ");
        scanf("%d",&elem);
        push(elem);
    }
    printf(" Intervalul \n");
    printf("  k1: ");
    scanf("%d",&k1);
    printf("  k2: ");
    scanf("%d",&k2);
    printf("\n");
    printf(" Cheile ce se afla in interval : ");
    SRD(root,k1,k2);
    printf("\n");
    return 0;
}
