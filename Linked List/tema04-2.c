/*
(3 p) 2. Fie doua liste simplu inlantuite A si B, cu elementele intregi in ordine crescatoare.

 Sa se creeze o noua lista simplu inlantuita C ce contine elementele din A si din B in ordine crescatoare.
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

    if (head==NULL) printf("Lista e goala:(");
    else
        while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct nod* InserareSfarsit(struct nod* head,int valoare)
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
{int i,n,m,valoare;
struct nod* Lista1=NULL;
struct nod* Lista2=NULL;
struct nod* Lista3=NULL;

printf("Cate elemente are prima lista? \nRaspuns: ");
scanf("%d",&n);
printf("\n");
for(i=0;i<n;i++)
{
    printf("Valoarea pe care doriti sa o introduceti: ");
    scanf("%d",&valoare);
    Lista1=InserareSfarsit(Lista1,valoare);
}
printf("\n");

printf("Cate elemente are a 2-a lista? \nRaspuns: ");
scanf("%d",&m);
printf("\n");
for(i=0;i<m;i++)
{
    printf("Valoarea pe care doriti sa o introduceti: ");
    scanf("%d",&valoare);
    Lista2=InserareSfarsit(Lista2,valoare);
}
printf("\n");

while(Lista1!=NULL||Lista2!=NULL)

 {  if(Lista1!=NULL&&Lista2!=NULL)

        {
            if(Lista1->data<Lista2->data)
            {
                Lista3=InserareSfarsit(Lista3,Lista1->data);
                Lista1=Lista1->next;
            }

            else if(Lista1->data>Lista2->data)
            {
                Lista3=InserareSfarsit(Lista3,Lista2->data);
                Lista2=Lista2->next;
            }

            else if (Lista1->data==Lista2->data)
            {
                Lista3=InserareSfarsit(Lista3,Lista2->data);
                Lista2=Lista2->next;
                Lista1=Lista1->next;
            }

        }

        if(Lista1!=NULL&&Lista2==NULL)
        {
            Lista3=InserareSfarsit(Lista3,Lista1->data);
            Lista1=Lista1->next;
        }

        if(Lista1==NULL&&Lista2!=NULL)
        {
            Lista3=InserareSfarsit(Lista3,Lista2->data);
            Lista2=Lista2->next;
        }

 }

 printf("Noua lista este: ");
 afisare(Lista3);
 printf("\n");
return 0;
}
