/* Stack */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
int data;
struct stack *next;
};

struct stack* push(struct stack* root)
{
    int value;
  printf("Valoarea pe care doriti sa o introduceti: ");
  scanf("%d",&value);
  printf("\n");

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
printf("Element scos %d\n",value);
return root;
}

int peek (struct stack* root)
{
    return root->data;
}

void afisare(struct stack* root )
{

  struct stack* temp = root;
  while(temp)
  {
      printf("%d \n",temp->data);
      temp=temp->next;
  }
}

bool empty(struct stack* root)
{
    if(root==NULL) return true;
    else return false;
}

int search(struct stack* root)
{
int value,cnt=0;
printf("Ce valoare doriti sa cautati? ");
scanf("%d",&value);

struct stack* temp=root;

 while(temp&&temp->data!=value)
 {
     cnt++;
     temp=temp->next;
}

 if(temp==NULL)
    return -1;
 else
   return cnt;
}

int main()
{
int i,n,optiune,value;
struct stack* root=NULL;

    do
{

    printf("Ce doriti sa faceti?\n\n 1. Push\n 2. Pop\n 3. Peek\n 4. Verificati daca stiva este goala\n 5. Search \n 6. Nimic\n\n");
    printf("Optiune : ");
    scanf("%d",&optiune);
    printf("\n");


    switch(optiune)
    {
    case 1:
            root=push(root);
            printf("");
            afisare(root);
            printf("\n------------------------------------------------------------------\n\n");
            break;


    case 2:
            root=pop(root);
            printf("\n");
            afisare(root);
            printf("\n------------------------------------------------------------------\n\n");
            break;


    case 3:
            afisare(root);
            printf("\n");
            value=peek(root);
            printf("Capul stivei este: %d",value);
            printf("\n------------------------------------------------------------------\n\n");
            break;

   case 5:
            afisare(root);
            printf("\n");
            value=search(root);
            printf("\n");
            if (value== (-1)) printf("Elementul nu se afla in stiva");
            else printf("Elemtul se afla in stiva. Pozitia : %d",value);
            printf("\n------------------------------------------------------------------\n\n");
            break;

    case 4:
            ;
            int data= empty(root);
            if(data) printf("Stiva este goala");
            else printf("Stiva nu este goala");
            printf("\n------------------------------------------------------------------\n\n");
            break;

        default:
                    printf("Optiune invalida\n");
                    printf("\n------------------------------------------------------------------\n\n");
			    	break;

    }
} while (optiune>=1 && optiune<=5);


    return 0;
}
