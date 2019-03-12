/* Queue */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct que
{
int data;
struct que *next;
};

struct que* push(struct que* root)
{
    int value;
  printf("Valoarea pe care doriti sa o introduceti: ");
  scanf("%d",&value);
  printf("\n");

  struct que* nou=(struct que*)malloc(sizeof(struct que));
  nou->data=value;
  nou->next=NULL;

    if(root==NULL)
       root=nou;
    else
    {
        struct que* temp=root;
        while(temp->next)
            temp=temp->next;

        temp->next=nou;
    }
    return root;
}

struct que* pop (struct que* root)
{
int value;
struct que* temp=root;
value=root->data;
root=root->next;
free(temp);
printf("Primul element al cozii este : %d", value);
printf("\n");
return root;
}

int peek (struct que* root)
{
    return root->data;
}

void afisare(struct que* root )
{
  struct que* temp = root;
  while(temp)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
}

bool empty(struct que* root)
{
    if(root==NULL) return true;
    else return false;
}

int search(struct que* root)
{
int value,cnt=0;
printf("Ce valoare doriti sa cautati? ");
scanf("%d",&value);

struct que* temp=root;

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
struct que* root=NULL;

    do
{

    printf("Ce doriti sa faceti?\n\n 1. Push\n 2. Pop\n 3. Peek\n 4. Verificati daca coada este goala\n 5. Search \n 6. Nimic\n\n");
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
            printf("Capul cozii este: %d",value);
            printf("\n------------------------------------------------------------------\n\n");
            break;

   case 5:
            afisare(root);
            printf("\n");
            value=search(root);
            printf("\n");
            if (value== (-1)) printf("Elementul nu se afla in coada");
            else printf("Elemtul se afla in coada. Pozitia : %d",value);
            printf("\n------------------------------------------------------------------\n\n");
            break;

    case 4:
            ;
            int data= empty(root);
            if(data) printf("Coada este goala");
            else printf("Coada nu este goala");
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
