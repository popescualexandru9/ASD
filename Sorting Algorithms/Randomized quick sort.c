/*
(2 p) 1. Sa se implementeze algoritmul randomized quick-sort (alegerea pivotului se va face
aleator).
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int a[], int p, int r)
{
    int pivotpoz = p + rand()%(r - p + 1);  ///Alegerea unui pivot random
    int pivot;
    int i = p - 1;
    int j;
    pivot = a[pivotpoz];
    swap(&a[pivotpoz], &a[r]);
    for (j = p; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }

    }
    swap(&a[i+1], &a[r]);
    return i + 1;
}

void quick_sort(int a[], int p, int r)
{
    int j;
    if (p < r)
    {
        j = partion(a, p, r);
        quick_sort(a, p, j-1);
        quick_sort(a, j+1, r);
    }
}
int main()
{
    int i,n=10;
    int a[10]={4,2,6,1,8,19,20,3,7,13};
    n=sizeof(a)/sizeof(int);
    printf("%d \n",n);

    quick_sort(a, 0, n-1);
    for (i = 0; i < n; i++)
         printf("%d ", a[i]);
    return 0;
}
