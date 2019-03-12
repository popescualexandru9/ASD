#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("data.in");
    ofstream g("data.out");

    int a[100],n,i,j,minim;
    f>>n;

    for(i=0;i<n;i++)
        f>>a[i];

    for(i=0;i<n;i++)
    {
        minim=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[minim])
              minim=j;

        swap(a[i],a[minim]);

     }


    for(i=0;i<n;i++)
        g<<a[i]<<" ";

        return 0;
}
