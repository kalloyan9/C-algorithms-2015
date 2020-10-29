#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int>q;
vector<int>ans;
vector<int>A[1<<20];
int n,m,brfathers[1<<20];

void topological(int x)
{
  q.push(x);
  while(!q.empty())
  {
    x=q.front();q.pop();
    ans.push_back(x);
    for(int i=0;i<A[x].size();++i)
    {
      --brfathers[A[x][i]];
      if(brfathers[A[x][i]]==0) q.push(A[x][i]);
    }
  }
}//kato pri vuvejdaneto A[a].push_back(b);
//                      ++brfathers[b];

int main()
{
  cin>>n>>m;
  for(int i=0;i<m;++i)
  {
    int a,b;
    cin>>a>>b;
    A[a].push_back(b);
    ++brfathers[b];
  }
  for(int i=0;i<n;++i)
  {
    if(brfathers[i]==0)
    {
      topological(i);
      break;
    }
  }

  for(int i=0;i<ans.size();++i)
    cout<<ans[i]<<" ";

  cout<<"\n";
  return 0;
}
///!!! KAZVA6 x E PREDI y!!!
