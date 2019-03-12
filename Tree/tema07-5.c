/*
(3 p) 5. Să se scrie un algoritm pentru afișarea elementului de pe poziția k (în ordinea
crescătoare a elementelor dintr-un șir) folosind un arbore binar de căutare indexat. (vezi
materialul auxiliar atașat).
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct arb
{
    int data, leftsize;
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

bool leftsize(arb *root, int *nr)
{
    if (root == NULL)
       return true;

    // Recur for left and right subtrees
    bool l = leftsize(root->st, nr);
    bool r = leftsize(root->dr, nr);

    // If both left and right subtrees are in range and current node
    // is also in range, then increment count and return true
    if (l && r )
    {
       ++*nr;
       return true;
    }
    return false;
}

void SRD(arb* root)
{
    int nr;
    if(root!=NULL)
    {
        nr=0;
        leftsize(root->st, &nr);
        root->leftsize=nr;
        SRD(root->st);
        printf(" %d [%d] ;",root->data,root->leftsize);
        SRD(root->dr);
    }
}

void search(arb* root,int poz)
{
       if(poz==root->leftsize)
          {
           printf(" Elementul cautat este : %d",root->data);
           return;
          }
else if(poz<root->leftsize)
         {
             search(root->st,poz);
         }
else if(poz>root->leftsize)
        {
           search(root->dr,poz-root->leftsize-1);
        }
}

int main()
{
     int i,n=12,poz, a[12]={20,10,40,6,15,30,2,8,18,25,35,7};
    //printf(" Cate elemente vrei sa aiba arborele?\n Raspuns : ");
    //scanf("%d",&n);
    printf(" Element [LeftSize] ");
    printf("\n");
    for(i=0;i<n;i++)
    {
        push(a[i]);
    }

    printf("\n");
    SRD(root);
    printf("\n");
    printf("\n");
    printf(" Pozitia elementului pe care vrei sa-l cauti : ");
    scanf("%d",&poz);
    search(root,poz);
    printf("\n");
    return 0;
}
