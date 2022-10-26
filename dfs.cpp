#include<bits/stdc++.h>
using namespace std;
// int N=10000;
vector<int>g[1000];
int depth[10000],height[10000];
void dfs(int vertex,int par=0)
{
    for(auto child:g[vertex])
    {
      
        if(child==par) continue;
          depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    for (int i = 1; i <=n; i++)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
    

    return 0;
}
