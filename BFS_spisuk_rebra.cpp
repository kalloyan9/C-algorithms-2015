#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int>q;
vector<int>A[1<<20];
int used[1<<20],n,m;

void bfs(int x)
{
  q.push(x);
  while(!q.empty())
  {
    x=q.front();q.pop();
    for(int i=0;i<A[x].size();++i)
    {
      if(!used[A[x][i]])
      {
        used[A[x][i]]=used[x]+1;
        q.push(A[x][i]);
      }
    }
  }
}
// nakraq used[0]=0;
int main ()
{
  cin>>n>>m;
  for(int i=0;i<n;++i)
  {
    int a,b;
    cin>>a>>b;
    A[a].push_back(b);
    A[b].push_back(a);
  }

  bfs(0);
  used[0]=0;

  for(int i=0;i<n;++i) cout<<"putqt ot 0 do "<<i<<" e "<<used[i]<<"\n";

  cout<<"\n";
  return 0;
}
