/*
(1 p) Să se scrie un program pentru numărarea elementelor pare din listă şi
        pentru calcularea mediei aritmetice a celor impare.

(2 p) Să se scrie o funcţie care să modifice lista, adăugând între fiecare
        2 elemente consecutive în listă media lor aritmetică.
*/

#include <stdio.h>
#include <stdlib.h>

int a[]={4, 4, 1, 2, 3, 6, 8, 10, 2, 12};
int n = 10 ;

struct nod
{
    int data;
    struct nod* next;
};

void afisareLista( struct nod *head)
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

struct nod* creereLista(struct nod* head,int x)
{
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

int numararePare(struct nod* head)
{
  int numar=0;
  struct nod*temp=head;
  while(temp)
  {
      if(temp->data%2==0)
        numar++;
        temp=temp->next;
  }
  return numar;
}

int medieImpare(struct nod* head)
 {
  int medie=0,nr=0;
  struct nod*temp=head;
  while(temp)
  {
      if(temp->data%2==1)
        {medie+=temp->data;
        nr++;}
        temp=temp->next;
  }
  medie=medie/nr;
  return medie;
 }

int medieAritmetica(int a ,int b)
 {
     return (a+b)/2;
 }

struct nod* adaugareMedie(struct nod* head)
{
    struct nod* temp=head;

    while(temp->next!=NULL)
    {
        if(temp->next!=NULL)
        {
        struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
        new_data->data=medieAritmetica(temp->data,temp->next->data);
        new_data->next=temp->next;
        temp->next=new_data;
        }
        temp=temp->next->next;
    }
    return head;
}

int main()
{
    int x,nr,medie;
    struct nod* head=NULL;

    for(int i=0;i<n;i++)
    {
    x=a[i];
    head=creereLista(head,x);
    }

    printf("Lista ta: ");
    afisareLista(head);
    printf("\n\n");
    nr=numararePare(head);
    medie=medieImpare(head);
    printf("Numarul numerelor pare: %d\n",nr);
    printf("Media aritmetica a numerelor impare: %d",medie);
    printf("\n\n");

    printf("Sa se adauge intre fiecare 2 elemente media lor aritmetica. \n");
    printf("Lista ta: ");
    head=adaugareMedie(head);
    afisareLista(head);
    printf("\n\n");

    return 0;
}
