/*
(2 p) Scrieţi un program în care se citesc două numere “mari”
(4 p) şi se construieşte o listă în care se va salva suma lor
*/
#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int data;
    struct nod* next;
};

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

void afisareLista(struct nod* head)
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

struct nod* creereLista(struct nod* head ,int x)
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

struct nod* sumaNumere(struct nod* head ,struct nod* lista1 ,struct nod* lista2)
{
    struct nod* lis1=lista1;
    struct nod* lis2=lista2;
    int value,rest=0;

    while(lis1!=NULL || lis2!=NULL)
    {
        if(lis1!=NULL&& lis2!=NULL)
        {
            value=lis1->data+lis2->data+rest;
            if(value>=10)
            {
                value=value%10;
                rest=1;
            }
            else rest=0;

            head=creereLista(head,value);
            lis1=lis1->next;
            lis2=lis2->next;
        }
else if (lis1==NULL && lis2!=NULL)
        {
            value=lis2->data+rest;
             if(value>=10)
            {
                value=value%10;
                rest=1;
            }
            else rest=0;

            head=creereLista(head,value);
            lis2=lis2->next;
        }

else if(lis1!=NULL && lis2==NULL)
        {
            value=lis1->data+rest;
             if(value>=10)
            {
                value=value%10;
                rest=1;
            }
            else rest=0;

            head=creereLista(head,value);
            lis1=lis1->next;
        }
}
        if(rest==1)
    head=creereLista(head,rest);
    return head;
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
    long int first_nr,second_nr;
    int x,y;
    struct nod* lista1=NULL;
    struct nod* lista2=NULL;
    struct nod* suma=NULL;
    struct nod* produs=NULL;

    printf("Care este primul numar mare? \nRaspuns: ");
    scanf("%d",&first_nr);
    while(first_nr)
    {
        x=first_nr%10;
        lista1=creereLista(lista1,x);
        first_nr=first_nr/10;
    }
    printf("\n");
    printf("Care este al doilea numar mare? \nRaspuns: ");
    scanf("%d",&second_nr);
    while(second_nr)
    {
        y=second_nr%10;
        lista2=creereLista(lista2,y);
        second_nr=second_nr/10;
    }

    printf(" \n");
    printf("Prima lista :  ");
    afisareLista(lista1);
    printf("\n");
    printf("A doua lista : ");
    afisareLista(lista2);
    printf("\n\n");

    suma=sumaNumere(suma,lista1,lista2);
    printf("Suma numerelor este : ");
    suma=reverse(suma);
    afisareLista(suma);


    return 0;
}
