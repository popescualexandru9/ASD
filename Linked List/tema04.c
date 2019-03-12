 /*
(2+2 p) Dată o listă simplu înlăţuită A, scrieţi o functie care inversează ordinea elementelor în listă. Se vor aborda doua metode:
-prima, în care lista A nu este modificată, rezultatul afişându-se intr-o noua listă B
-a doua, in care nu se va aloca memorie suplimentara, inversarea facandu-se schimband legaturile intre nodurile listei A.
 */

#include <stdio.h>
#include <stdlib.h>

struct nod
{
int data;
struct nod *next;
};

struct nod* citire(struct nod* head)
{
    int x;
    printf("Ce valoare vrei sa introduci : ",x);
    scanf("%d",&x);

    struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
    new_data->data=x;
    new_data->next=NULL;

if (head==NULL)
    {
    new_data->next=head;
    head=new_data;
    }
else
    {
        struct nod* temp=head;
        while(temp->next)
        temp=temp->next;

        if(temp->next==NULL)
        {
        temp->next=new_data;
        new_data->next=NULL;
        }
    }
    return head;
}

void afisare(struct nod* head)
{
    struct nod *temp=head;

    if (head==NULL) printf("Lista este goala :(");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

struct nod* addInceput(struct nod* head, int x)
{
    struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
    new_data->data=x;
    new_data->next=head;
    head=new_data;
}

struct nod* reverse(struct nod* head)
 {
  struct nod* prev = NULL;
  struct nod* temp=head;
  struct nod* leg=NULL;
  while (temp!=NULL)
    {
    leg = temp->next;
    temp->next = prev;
    prev = temp;
    temp=leg;
  }
  head=prev;
}

struct nod* inverse(struct nod *lista1, struct nod *lista2)
{
    while(lista1->next!=NULL)
       {
           lista2=addInceput(lista2,lista1->data);
           lista1=lista1->next;
       }
        lista2=addInceput(lista2,lista1->data);
}

int main()
{
    int n,choice,i;

    struct nod *lista1=NULL;
    struct nod *lista2=NULL;

    printf("Numarul de elemente al listei? \nRaspuns: ");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++)
    {
        lista1=citire(lista1);
        printf("Lista ta : ");
        afisare(lista1);
        printf("\n\n");
    }

	printf("Alegeti una dintre urmatoarele operatii:\n");
	printf("[1] Inversarea listei intr-o alta lista\n");
	printf("[2] Inversarea listei prin schimbarea legaturilor dintre noduri\n");
	printf("Operatia aleasa: ");
    scanf("%d",&choice);
    printf("\n\n");

	switch(choice){
		case 1: {
             lista2=inverse(lista1,lista2);
		     printf("Lista ta: ");
		     afisare(lista2);
		     printf("\n");
		     break;
		     }
        case 2: {
		    lista1=reverse(lista1);
		    printf("Lista ta: ");
		    afisare(lista1);
		    printf("\n");
		    break;}
        default : printf("Alegere invalida.\n");
	};

    return 0;
}


