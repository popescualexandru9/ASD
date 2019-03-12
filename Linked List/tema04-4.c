/*
(4 p) 4. Spunem ca o matrice X de dimensiuni n x m (n linii si m coloane) este rară daca exista “foarte multe” elemente egale cu 0.
Pentru fiecare linie i nenula vom avea o lista ce contine doar elemente nenule, in care fiecare nod are 3 campuri:

     (a) indicele coloanei, j;
     (b) valoarea elementului nenul xij ;
     (c) o legatura catre urmatorul element nenul de pe linie.

Vom avea o lista aditionala in care fiecare nod contine urmatoarele informatii:

     (a) indicele i al unei linii nenule;
     (b) o legatura catre urmatoarea linie nenula;
     (c) o legatura catre primul element nenul din lista corespunzatoare liniei i.
*/

#include <stdio.h>
#include <stdlib.h>

int n=5,m=5;
int a[5][5]={
               {1, 4, 0, 0, 0},
               {0, 3, 2, 1, 0},
               {0, 0, 0, 0, 0},
               {4, 0, 6, 2, 9},
               {7, 3, 6, 8, 5}
             };

typedef struct nod
{
int coloana;
int data;
struct nod *next;
}nod;

struct nod2
{
    int indice;
    struct nod* nextlinie;
    struct nod* nextcoloana;
};

void afisare( nod* head)
{
    nod* temp=head;

    if (head==NULL) printf("Lista este goala:(");
    else
        {
        while(temp!=NULL)
    {
        printf("|| Col %d | El %d ",temp->coloana,temp->data);
        temp=temp->next;
    }
       printf("||");
        }
}

 nod* InserareSfarsit( nod* head,int valoare,int col)
{
  nod* new_data=( nod*)malloc(sizeof( nod));
  new_data->data=valoare;
  new_data->coloana=col;
  new_data->next=NULL;

  if(head==NULL)
  {
    new_data->next=head;
    head=new_data;
   }
   else
   {
        nod* temp=head;
       while(temp->next!=NULL)
       temp=temp->next;

       new_data->next=NULL;
       temp->next=new_data;
   }
 return head;
}

/*void afisareNenule(struct nod* head)
{
    struct nod* temp=head;

    if (head==NULL) printf("Lista este goala:(");
    else
        {
        while(temp!=NULL)
    {
        printf("|| Linia nenula %d cu elementele : ",temp->data);
        afisare(lista);
        printf("\n");
        temp=temp->next;
    }
       printf("||");
        }
}
*/
struct nod2* InserareNenule(struct nod2* head,int linie)
{
  struct nod2* new_data=(struct nod2*)malloc(sizeof(struct nod2));
  new_data->indice=linie;
  new_data->nextcoloana=NULL;
  new_data->nextlinie=NULL;


  if(head==NULL)
  {

    head=new_data;
   }
   else
   {
       struct nod2* temp=head;
       while(temp->nextcoloana!=NULL)
       temp=temp->nextcoloana;

       new_data->nextcoloana=NULL;
       temp->nextcoloana=new_data;
   }
 return head;
}


int main()
{
    int i,j,ok;
    struct nod2* listaLinii=NULL;

    for(i=0;i<n;i++)
    {
    nod* lista=NULL;
    ok=0;
       for(j=0;j<n;j++)
       {
           if(a[i][j]!=0 )
              lista=InserareSfarsit(lista, a[i][j], j);
           if(a[i][j]!=0 && ok==0)
              {
                  listaLinii=InserareNenule(listaLinii,i);
                  ok=1;
              }
       }

    if(lista!=NULL)
    {printf(" Linia %d nenula : ",i);
    afisare(lista);
    printf("\n");}
    ok=0;
    }
    printf("\n");
    afisare(listaLinii);
    return 0;
}
