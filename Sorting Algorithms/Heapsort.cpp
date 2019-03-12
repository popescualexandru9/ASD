#include <iostream>
#include <fstream>

using namespace std;

void heap(int v[], int n, int i)
{
    int radacina = i;
    int s = 2*i + 1;
    int d = 2*i + 2;

    if (s < n && v[s] > v[radacina])
        radacina = s;
    if (d < n && v[d] > v[radacina])
        radacina = d;


    if (radacina != i)
    {
        swap(v[i], v[radacina]);

        heap(v, n, radacina);
    }
}

void heapSort(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(v, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(v[0], v[i]);

        heap(v, i, 0);
    }
}

int delet (int v[], int n)
{

    swap(v[0], v[n-1]);
    n--;
    heapSort(v,n);
    return n;
}
void printArray(int v[], int n)
{
    for (int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    ifstream f("Date.in");
    int v[100];
    int n, i;
    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];

    heapSort(v, n);
    printArray(v, n);


    while(n!=1)
    {
        n=delet(v, n);
        cout<<"\n";
        printArray(v, n);
    }

    f.close();
    return 0;
}
