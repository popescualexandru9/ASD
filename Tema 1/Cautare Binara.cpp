#include <iostream>
#include <fstream>
using namespace std;
int main()
{


    int n=5,k=8,i,j,st,dr,mij=-1,ok=0;
    int a[5]={1,4,6,8,13};


    st=0; dr=n-1;
    while(st<=dr)
    {
        mij=st+(dr-st)/2;
        if(a[mij]==k)
            {printf("%d " ,mij);
             ok=1;}

        if(a[mij]<k)
            st=mij+1;
        else
            dr=mij-1;
    }
    if(ok==0)
    printf("-1");
    return 0;

}

