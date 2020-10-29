#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>susedi[1<<20];
int used[1<<20],n,m;
queue<int>q;

void bfs(int x)
{
  q.push(x);
  while(!q.empty())
  {
    x=q.front();q.pop();
    for(int i=0;i<susedi[x].size();++i)
    {
      if(!used[susedi[x][i]])
      {
        ++m;//broi rebra ++
        used[susedi[x][i]]=used[x]+1;
        q.push(susedi[x][i]);
      }
    }
  }
}
//nakraq used[0]=0;

int main ()
{
  cin>>n;
  for(int i=0;i<n;++i)
  {
    int z;
    cin>>z;
    for(int j=0;j<z;++j)
    {
      int x;
      cin>>x;
      susedi[i].push_back(x);
    }
  }

  bfs(0);
  used[0]=0;

  for(int i=0;i<n;++i) cout<<"putqt ot 0 do "<<i<<" e "<<used[i]<<"\n";

  cout<<"\n";
  return 0;
}
