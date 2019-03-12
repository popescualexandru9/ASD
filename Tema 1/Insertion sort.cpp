#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("data.in");
    ofstream g("data.out");

    int a[100],n,i,j,aux;
    f>>n;
    for(i=0;i<n;i++)
        f>>a[i];

    for(i=1;i<n;i++)
    {
        aux=a[i];
        j=i-1;

        while(j>=0 && a[j]>aux)
        {
          a[j+1]=a[j];
           j=j-1;
        }
        a[j+1]=aux;
    }


    for(i=0;i<n;i++)
        g<<a[i]<<" ";

    return 0;
}
