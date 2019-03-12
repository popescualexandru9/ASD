/*
(3 p)  3. Fie lista simplu inlantuita C. Sa se distribuie elementele din C in doua liste simplu inlatuite A si B, astfel:
A contine elementele de pe pozitiile impare din C, iar B contine elementele din C de pe pozitiile pare.
*/


#include <stdio.h>
#include <stdlib.h>

struct nod
{
int data;
struct nod *next;
};

void afisare(struct nod* head)
{
    struct nod* temp=head;

    if (head==NULL)
        printf("Lista e goala :(");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

struct nod* inserareSfarsit(struct nod* head,int valoare)
{
  struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
  new_data->data=valoare;
  new_data->next=NULL;

    if(head==NULL)
    {
        new_data->next=head;
        head=new_data;
    }
    else
    {
        struct nod* temp=head;
        while(temp->next!=NULL)
        temp=temp->next;

        new_data->next=NULL;
        temp->next=new_data;
    }
    return head;
}

int main()
{
int i,n,contor=0,valoare;
struct nod* Lista=NULL;
struct nod* ListaPar=NULL;
struct nod* ListaImpar=NULL;

printf("Cate elemente are lista? \nRaspuns: ");
scanf("%d",&n);
printf("\n");
for(i=0;i<n;i++)
{
printf("Valoarea pe care doriti sa o introduceti: ");
scanf("%d",&valoare);
Lista=inserareSfarsit(Lista,valoare);
}
printf("\n");

while(Lista)
{
    if(contor%2==0) ListaPar=inserareSfarsit(ListaPar,Lista->data);
    else                ListaImpar=inserareSfarsit(ListaImpar,Lista->data);
    contor++;
    Lista=Lista->next;

}

printf("\n\n");
printf("Lista formata cu pozitiile pare: ");
afisare(ListaPar);
printf("\n\n");
printf("Lista formata cu pozitiile impare: ");
afisare(ListaImpar);
printf("\n\n");
return 0;
}
