/* Suprafata circulara cu un numar n de pini (tarusi) numerotati de la 1 la n/2. Sa se determine daca o configuratie este valida ( pinii pot fi conectati cu fire metalice fara ca acestea sa se suprapuna pe suprafata circulara)
   Se vor citi numarul de pini ,iar apoi perechile in ordinea acelor de ceasornic. O pereche va fi citita cu aceeasi cifra ( ex: n=8  Legaturi : i j j i l m m l --  unde perechule sunt ii jj ll mm)
*/
#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack *next;
}stack;

struct stack* push(struct stack* root,int value)
{
  struct stack* nou=(struct stack*)malloc(sizeof(struct stack));
  nou->data=value;
  nou->next=NULL;

    if(root==NULL)
       root=nou;
    else
        nou->next=root;
    return nou;
}

struct stack* pop (struct stack* root)
{
int value;
struct stack* temp=root;
root=root->next;
value=temp->data;
free(temp);

return root;
}

bool empty(struct stack* root)
{
    if(root==NULL) return true;
    else return false;
}

int main()
{
    int i,n,k=1,a[10];
    stack* root=NULL;
    printf("Numar pomi: ");
    scanf("%d",&n);
    printf("\n");
    printf("Legaturile lor: ");
     for(i=0;i<n;i++)
         scanf("%d",&a[i]);
     for(i=0;i<n;i++)
     {
         if(root==NULL || a[i]!=root->data)
            root=push(root,a[i]);
        else
            root=pop(root);
     }
         if(empty(root)==1)
        printf("Valida");
    else
        printf("Invalida");
         printf("\n");
    return 0;

}
