/*
(4 p)
(a) adăugarea unui nou element la finalul listei;
(b) adăugarea unui nou element la începutul  listei;
(c) adăugarea unui nou element în interiorul listei;
(d) căutarea unui element după valoare;
(e) căutarea unui element după poziție;
(f) ştergerea unui element după valoare;
(g) ștergerea unui element după poziție;
(h) ştergerea întregii liste.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct nod* addInceput(struct nod* head)
{
    int value;
    printf("\n");
    printf("Valoare : ",value);
    scanf("%d",&value);

    struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
    new_data->data=value;
    new_data->next=head;
    head=new_data;
}

struct nod* addMijloc(struct nod* head,int k)
{
    printf("\n");
    printf("Care este pozitia k? Raspuns : ");
    scanf("%d",&k);
    int value;
    printf("\n");
    printf("Valoare : ", value);
    scanf("%d",&value);

    struct nod*temp=head;
    while(k>1)
    {
        temp=temp->next;
        k--;
    }
    struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
    new_data->data=value;
    new_data->next=temp->next;
    temp->next=new_data;
return head;

}

struct nod* addFinal(struct nod* head)
{
    int value;
    printf("\n");
    printf("Valoare : ",value);
    scanf("%d",&value);

    struct nod* new_data=(struct nod*)malloc(sizeof(struct nod));
    new_data->data=value;
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

    if(temp->next==NULL)
    {
        temp->next=new_data;
        new_data->next=NULL;
     }

  }
  return head;
}

bool verif(struct nod* head,int val)
{
    struct nod* temp=head;
    while(temp)
    {
        if(temp->data==val)
            return true;
            temp=temp->next;
    }
    return false;
}

bool verifpoz(struct nod* head,int poz)
{
    struct nod* temp=head;
    int i=0;
    while(temp!=NULL && i<poz)
    {
            temp=temp->next;
            i++;
    }
    if(i==poz)
        return true;
    else return false;
}

void stergere(struct nod* prev)
{
   struct nod* temp=prev->next;
   prev->next=prev->next->next;
   free(temp);
}

void stergereElement(struct nod* head,int val)
{
    if(head->data==val)
    {
      struct nod* temp=head;
      head=head->next;
      free(temp);
      return;
    }
    struct nod* temp=head;
    while(temp->next!=NULL && temp->next->data!=val)
        temp=temp->next;
    if(temp->next!=NULL)
    stergere(temp);
    else printf("Nu exista in lista.\n\n");
}

void stergerePozitie(struct nod* head,int poz)
{
    if(poz==0)
    {
        struct nod* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    struct nod* temp=head;
    for(int i=0;temp!=NULL && i<poz-1;i++)
            temp=temp->next;

   if(temp->next!=NULL)
    stergere(temp);
    else printf("Lista nu are atatea elemente.\n\n");
}

void stergeLista(struct nod* head)
{
    struct nod* temp=head;
    struct nod* leg;
    while(temp)
    {
     leg=temp->next;
     free(temp);
     temp=leg;
    }
    head=NULL;
}

int main()
{
 int k,i,n,loc,element,count,pozitie;
 struct nod* head=NULL;

      printf("Cate elemente doresti sa aiba lista? \nRaspuns : ");
      scanf("%d",&n);
      printf("\n");

      for(i=0;i<n;i++)
      {
         printf("Unde vrei sa adaugi elementul?  1)La inceput.  2)Dupa pozitia k.  3)La final.\nRaspuns : ");
         scanf("%d",&loc);
         if(loc==1)
         {
            head=addInceput(head);
            printf("Lista ta : ");
            afisareLista(head);
            printf("\n\n");
         }
         else if (loc==2)
         {
            head=addMijloc(head,k);
            printf("Lista ta : ");
            afisareLista(head);
            printf("\n\n");
         }
         else if(loc==3)
         {
             head=addFinal(head);
             printf("Lista ta : ");
             afisareLista(head);
             printf("\n\n");
         }
         else printf("Optiune invalida");
      }


      /// Verificare daca un element se afla in lista.
      /*
      printf("\n\n");
      count=n;
      do{
      printf("Ce element doriti sa verificati daca este in lista ?\nRaspuns: " );
      scanf("%d",&element);
      printf("\n");
      verif(head,element) ? printf("Exista in lista") : printf("Nu exista in lista");
      printf("\n\n");
      count--;
      }while(count);
     */
      /// Verificare daca un element se afla pe o pozitie in lista.
     /*
      printf("\n\n");
      count=n;
      do{
      printf("Pe ce pozitie doriti sa verificati daca se afla un element ?\nRaspuns: " );
      scanf("%d",&pozitie);
      printf("\n");
      verifpoz(head,pozitie) ? printf("Exista in lista") : printf("Nu exista in lista");
      printf("\n\n");
      count--;
      }while(count);
      */
       /// Stergere dupa element.
      /*
      printf("\n\n");
      printf("Ce element doriti sa stergeti ?\nRaspuns: " );
      scanf("%d",&element);
      printf("\n");
      stergereElement(head,element);
      printf("Lista ta : ");
      afisareLista(head);
      printf("\n\n");
      */
       /// Stergere dupa pozitie.

      printf("\n\n");
      printf("Ce pozitie doriti sa stergeti ?\nRaspuns: " );
      scanf("%d",&pozitie);
      printf("\n");
      stergerePozitie(head,pozitie);
      printf("Lista ta : ");
      afisareLista(head);
      printf("\n\n");

      ///Stergere lista.

      /*
      printf("Lista ta : ");
      stergeLista(head);
     */
}
