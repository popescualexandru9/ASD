/*
(2 p) 1. Sa se creeze o listă ordonată folosind inserţia elementelor în listă.
(1 p) 2. coeficienţii polinomului obţinut prin înmulţirea cu un scalar a, dat de la tastatură.
(2 p) 3. P(X0) , adică evaluează polinomul P intr-un punct dat 0 x .
(2 p) 4. suma polinoamelor P și Q;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nod
{
    int data;
    struct nod* next;
};

struct polinom
{
    int grad;
    int data;
    struct polinom* next;
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

void afisarePolinom (struct polinom *head)
{
    struct polinom* temp=head;

    if (head==NULL) printf ("Polinomul nu are elemente :(");
    else
        {
            while(temp!=NULL)
            {
             if(temp->next!=NULL)
            {
                printf("%dX^%d + ",temp->data,temp->grad);
                temp=temp->next;
            }
            else
            {
                printf("%dX^%d",temp->data,temp->grad);
                temp=temp->next;
            }
            }
       }
}

struct nod* inserareOrdonata (struct nod *head)
{
    int value;
    printf("\n");
    printf("Ce valoare vrei sa introduci : ",value);
    scanf("%d",&value);

    struct nod *new_node=(struct nod*)malloc(sizeof(struct nod));
    new_node->data=value;
    new_node->next=NULL;

    if (head==NULL || head->data > new_node->data)
    {
        new_node->next=head;
        head=new_node;
    }
    else if (head->data < new_node->data)
    {
        struct  nod *temp=head;
        while(temp->next!=NULL && temp->next->data < new_node->data)
        {
            temp=temp->next;
        }

        if(temp->next==NULL)
        {
            temp->next=new_node;
            new_node->next=NULL;
        }
        else
        {
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }

    return head;
}

struct polinom* inserareElementePolionom( struct polinom * head)
{
    int gradpol,value;
    printf("Valoare: ");
    scanf("%d",&value);
    printf("Grad: ");
    scanf("%d",&gradpol);

    struct polinom* new_data=(struct polinom*)malloc(sizeof(struct polinom));
    new_data->data=value;
    new_data->grad=gradpol;
    new_data->next=NULL;

    if(head==NULL || head->grad<new_data->grad)
    {
        new_data->next=head;
        head=new_data;
    }
    else if(head->grad>new_data->grad)
    {
        struct polinom *temp=head;
        while (temp->next!=NULL && temp->next->grad>=new_data->grad)
            temp=temp->next;

        if(temp->next==NULL)
        {
            temp->next=new_data;
            new_data->next=NULL;
        }
        else
        {
            new_data->next=temp->next;
            temp->next=new_data;
        }
    }
    else if(head->grad==new_data->grad)
    {
        head->data+=new_data->data;
    }
    return head;
}

struct polinom* inmultireScalar (struct polinom* head)
{
    int scalar;
    printf("Scalar : ");
    scanf("%d",&scalar);

    struct polinom* temp=head;
    while(temp)
    {
        temp->data *= scalar;
        temp=temp->next;
    }
}

struct polinom*  Evaluare (struct polinom* head)
{
    int evaluator,suma=0;
    printf("Evaluator : ");
    scanf("%d",&evaluator);
    printf("\n");

    struct polinom *temp=head;
    while(temp)
    {
        suma+=temp->data*pow(evaluator,temp->grad);
        temp=temp->next;
    }
    printf("P(%d)=%d",evaluator,suma);
}

struct polinom* Rezultat(struct polinom* head ,int gradpol ,int value)
{
   struct polinom* new_data=(struct polinom *)malloc(sizeof(struct polinom));
   new_data->data=value;
   new_data->grad=gradpol;
   new_data->next=NULL;

   if(head==NULL) head=new_data;
   else
   {

       struct polinom *temp=head;
       while(temp->next!=NULL)
        temp=temp->next;

       temp->next=new_data;
       new_data->next=NULL;
    }
return head;
}

struct polinom* sumaPolinoame (struct polinom* Polinom1, struct polinom* Polinom2, struct polinom* head)
{
    int gradpol,value;
    struct polinom* pol1=Polinom1;
    struct polinom* pol2=Polinom2;

    while(pol1!=NULL || pol2!=NULL)
    {
        if(pol1!=NULL&&pol2!=NULL)
        {
           if(pol1->grad==pol2->grad)
             {
              value=pol1->data+pol2->data;
              gradpol=pol1->grad;
              head=Rezultat(head,gradpol,value);
              pol1=pol1->next;
              pol2=pol2->next;
             }
             else if(pol1->grad>pol2->grad)
             {
                 value=pol1->data;
                 gradpol=pol1->grad;
                 head=Rezultat(head,gradpol,value);
                 pol1=pol1->next;
             }
             else if(pol1->grad<pol2->grad)
             {
                 value=pol2->data;
                 gradpol=pol2->grad;
                 head=Rezultat(head,gradpol,value);
                 pol2=pol2->next;
             }
        }

        else if (pol1==NULL && pol2!=NULL)
        {
            value=pol2->data;
            gradpol=pol2->grad;
            head=Rezultat(head,gradpol,value);
            pol2=pol2->next;
        }

        else if(pol1!=NULL && pol2==NULL)
        {
            value=pol1->data;
            gradpol=pol1->grad;
            head=Rezultat(head,gradpol,value);
            pol1=pol1->next;
        }
    }
    return head;
}


int main()
{
    int i,n;
    struct  nod *head=NULL;
    struct polinom *Polinom=NULL;
    struct polinom *Pol1=NULL;
    struct polinom *Pol2=NULL;

    // 1. Sa se creeze o listă ordonată folosind inserţia elementelor în listă.

    printf("Cate elemente doresti sa aiba lista? \nRaspuns : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        head=inserareOrdonata(head);
        printf("Lista ta : ");
        afisareLista(head);
        printf("\n");
    }
/*
     // 2. Coeficienţii polinomului obţinut prin înmulţirea cu un scalar a, dat de la tastatură.

     printf("Cate elemente doresti sa aiba polinomul? \nRaspuns : ");
     scanf("%d",&n);

     for(i=0;i<n;i++)
        Polinom=inserareElementePolionom(Polinom);
        printf("\n\n");
        afisarePolinom(Polinom);
        printf("\n\n");
        inmultireScalar(Polinom);
        printf("\n\n");
        afisarePolinom(Polinom);
        printf("\n\n");
*/
     // 3. Evaluează polinomul P intr-un punct dat x0.
/*
      printf("Cate elemente doresti sa aiba polinomul? \nRaspuns : ");
      scanf("%d",&n);

      for(i=0;i<n;i++)
        Polinom=inserareElementePolionom(Polinom);
        printf("\n");
        afisarePolinom(Polinom);
        printf("\n\n");
        Evaluare(Polinom);
        printf("\n\n");
*/
      // 4. Suma a doua polinoame .
/*
       printf("Cate elemente doresti sa aiba primul polinom? \nRaspuns : ");
       scanf("%d",&n);

      for(i=0;i<n;i++)
        Pol1=inserareElementePolionom(Pol1);
        printf("\n");
        afisarePolinom(Pol1);
        printf("\n\n");

        printf("Cate elemente doresti sa aiba al doilea polinom? \nRaspuns : ");
        scanf("%d",&n);

      for(i=0;i<n;i++)
        Pol2=inserareElementePolionom(Pol2);
        printf("\n");
        afisarePolinom(Pol2);
        printf("\n\n");

        Polinom=sumaPolinoame(Pol1,Pol2,Polinom);
        printf("Suma polinoamelor este : ");
        afisarePolinom(Polinom);
*/

return 0;
}
