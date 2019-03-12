/* Sa se ordoneze descrescator un sir de cuvinte folosind un AVL */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 9

typedef struct arb
{
    char *data;
    struct arb* dr;
    struct arb* st;
}arb;

typedef int (*compare)(const char *, const char *);

void push(char* val, arb** root, compare cmp)
{
    int k;
    if( *root == NULL ) {
        *root = (arb*) malloc( sizeof(arb ) );
        (*root)->data = malloc( strlen (val) +1 );
        strcpy ((*root)->data, val);
        (*root)->st = NULL;
        (*root)->dr= NULL;
    }
else
    {
        k = cmp (val ,(*root)->data);
        if( k < 0)
            push( val, &(*root)->st, cmp);
else if( k > 0)
            push( val, &(*root)->dr, cmp);
    }
}

int FunctieCompara(const char *a, const char *b)
{
    return (strcmp (a, b));
}

char *input( void )
{
    static char line[MAXLEN+1];
    printf("Introduceti cuvantul : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));
}


void SRD(arb* root)
{
    if(root!=NULL)
    {
        SRD(root->st);
        printf("%s ",root->data);
        SRD(root->dr);
    }
}

int main()
{
     arb* root=NULL;
     int ok=0,n=4;
     char* cuvant;

       while(ok<n)
        {
        cuvant = input();
        push(cuvant,&root,(compare)FunctieCompara);
        ok++;
        }

     printf("\n");
     printf("Parcurgere SRD : ");
     SRD(root);
     printf("\n\n");

}
