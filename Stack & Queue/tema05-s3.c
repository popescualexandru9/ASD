/*
(2p) 3. Dat un sir w = w1w2 ... wn de caractere '(' si ')', sa se foloseasca o stiva
pentru a decide daca acest sir este corect parantezat (i.e., pentru orice subsir w1 ...
wi, cu i de la 1 la n, avem ca numarul de caractere '(' este mai mare sau egal cu numarul
de caractere ')'). In caz ca w nu este parantezat corect, se va indica pozitia primei
paranteze ')' care nu are corespondent.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack{
    char data;
    struct stack* next;
}stack;

stack* push(stack* root, char par)
{
    stack* nou=(stack*)malloc(sizeof(stack));
    nou->data=par;
    nou->next=NULL;

    if(root==NULL)
        root=nou;
    else
    {
     stack*  temp=root;
    while(temp->next)
        temp=temp->next;

    temp->next=nou;
    }
    return root;
}

void afisare(stack* root)
{
    stack* temp=root;
    while(temp)
    {
        printf("%c ",temp->data);
        temp=temp->next;
    }
}

stack* pop(stack* root)
{
    stack* temp=root;
    root=root->next;
    free(temp);
    return root;
}

void exercitiu(stack* root)
{
    int des=0,inc=0,poz=0,ok=0;

    while(root && ok==0)
    {
        if(des>=inc)
        {
            poz++;
            if(root->data=='(')
            {
                des++;
                root=pop(root);
            }
    else if(root->data==')')
            {
                inc++;
                root=pop(root);
            }
        }
    else
         ok=poz-1;
    }

     if(ok==0)
     {
         printf("Sirul este bine parantezat");
     }
     if(ok>0)
     {
        printf("Sirul nu este bine parantezat\nPrima paranteza inchisa *)* care nu are corespondent se afla pe pozitia: %d",ok);
     }

}

int main()
{
    stack* root=NULL;
    int i,n,par;

    printf("Cate elemente va avea sirul? \nRaspuns : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
       printf("Valoarea pe care doriti sa o introduceti: ");
       scanf(" %c",&par);
       root=push(root,par);
    }

    printf("\n");
    afisare(root);
    printf("\n\n");
    exercitiu(root);
    printf("\n");
}
