#include <bits/stdc++.h>

using namespace std;
int edges =0;
int dfs(vector<vector<int> > adj , int p , vector<bool> visited )
{
    int edge =1;
        if(!visited[p])
        {
            visited[p]=true;
            for(int i=0 ; i < adj[p].size() ; i++)
            {
                if(!visited[adj[p][i]]){
                    edge += dfs(adj, adj[p][i] , visited);
                }
            }
            if(edge%2 == 0 && edge >0)
            {
                edges++;
                edge = 0;
            }
            return edge;
        }
        return 0;
}
int main()
{
    int n , m;
    int u,v;
    cin >>n >>m;
    vector<vector<int> > adj(n);
    vector<bool> visited(n , false);
    for(int i=0 ;i <m ; i++)
    {
        cin >> u >>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    dfs(adj , 0 , visited);
    cout <<edges-1;
    return 0;
}
