//count and store of connected component...............

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> g[N];
bool visted[N];

vector<vector<int>> cc;
vector<int> currcc;
void dfs(int vertex)
{
    visted[vertex]=true;
    currcc.push_back(vertex);
    for(int child : g[vertex])
    {
        if(visted[child]) continue;
        dfs(child);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
   
    for (int  i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt=0;
    for (int i = 1; i <=n; i++)
    {
        if(visted[i]) continue;
        currcc.clear();
        dfs(i);
        cc.push_back(currcc);
    }
    cout<<cc.size()<<endl;
    for(auto pr: cc)
    {
        for(auto ans :pr)
        cout<<ans<<" ";
        cout<<endl;
    }

    return 0;
}



