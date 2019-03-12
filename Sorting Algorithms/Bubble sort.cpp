#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("data.in");
    ofstream g("data.out");

    int a[100],n,i,j;
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];

    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
        if(a[i]>a[j])
        swap(a[i],a[j]);

    for(i=1;i<=n;i++)
        g<<a[i]<<" ";

    return 0;

    }
