#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("data.in");
    ofstream g("data.out");

    int n,a[100],k,ok=-1,i;
    f>>n;
    f>>k;
    for(i=0;i<n;i++)
        f>>a[i];

    for(i=0;i<n;i++)
        if(a[i]==k)
           ok=i;

    g<<ok;

    return 0;
}
