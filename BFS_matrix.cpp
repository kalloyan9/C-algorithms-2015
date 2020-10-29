#include<iostream>
#include<queue>
using namespace std;
int used[1<<20], matrix[1<<10][1<<10], brs[1<<20];
int n,m;
queue<int>q;

void bfs(int x)
{
  q.push(x);
  while(!q.empty())
  {
    x=q.front();q.pop();
    for(int i=0;i<n;++i)
    {
      if(matrix[x][i]==1)
      {
        ++m;//broq brebra ++
        if(!used[i])
        {
          used[i]=used[x]+1;
          q.push(i);
        }
      }
    }
  }
}
//nakraq used[0]=0;
int main ()
{
  cin>>n;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      cin>>matrix[i][j];

  bfs(0);
  used[0]=0;

  cout<<"\n";
  return 0;
}
