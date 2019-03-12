#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int grad(unsigned int x,unsigned int mat[10][10], unsigned int n)
{
    unsigned int i, grad=0;
    for(i=0; i<n; i++)
        grad+=mat[x][i];
    return grad;

}

void DFS(unsigned int x, unsigned int viz[10], unsigned int mat[10][10], unsigned int n)
{
    unsigned int i;
    viz[x]=1;
    cout<<x<<" ";
    for(i=0; i<n; i++)
        if(mat[x][i]==1 && viz[i]==0)
        {
            DFS(i,viz,mat,n);
        }
}

void BFS(queue <unsigned int> q, unsigned int viz[10], unsigned int mat[10][10], unsigned int n)
{
    unsigned int i, ok;
    viz[q.front()]=1;
    cout<<q.front()<<" ";

    for(i=0; i<n; i++)
        if(mat[q.front()][i]==1 && viz[i]==0)
            {q.push(i); viz[i]=1;}

    q.pop();
    if(!q.empty())
        BFS(q,viz,mat,n);


}

int main()
{
    ifstream in("date.in");
    unsigned int n, i, j, mat[10][10], x, y, k,viz[10];

    in>>n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            in>>mat[i][j];


    cout<<"Parcurgere BF:"<<endl;
    for(i=0; i<n; i++)
        viz[i]=0;
    in>>x;

    queue <unsigned int> q;
    q.push(x);
    BFS(q, viz, mat, n);
    cout<<endl;

    cout<<"Parcurgere DF:"<<endl;
    for(i=0; i<n; i++)
        viz[i]=0;
    in>>x;
    DFS(x, viz, mat, n);
    cout<<endl;

    return 0;
}

