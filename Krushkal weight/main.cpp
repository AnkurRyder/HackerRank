#include <bits/stdc++.h>

using namespace std;

int n , m;
bool compair(pair <int , pair <int , int> > i1 , pair <int , pair <int , int> > i2)
{
    return((i1.first < i2.first)? 1 : ((i1.first ==i2.first)?((i1.first + i1.second.first + i1.second.second)< (i2.first + i2.second.first + i2.second.second)) : 0));
}
bool isCycleUtill(vector <vector <int> > adj , int v , vector <bool> visited , int parent)
{
     visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCycleUtill(adj , *i, visited, v))
              return true;
        }
        else if (*i != parent){
           return true;
        }
    }
    return false;
}
bool isCycle(vector <vector <int> > adj)
{
    vector <bool> visited(n , false);
    for(int i=0; i<n ; i++)
        if(!visited[i]&&adj[i].size() > 0)
            if(isCycleUtill(adj , i , visited , -1)){
                return true;
            }
    return false;
}

int main()
{
    int a,b,c ,w=0;
    cin >> n >> m;
    vector <pair <int , pair <int , int> > > Gr(m);
    vector <vector <int> > adj(n);
    for(int i=0 ; i < m ;i++)
    {
        cin >> a>> b >>c;
        Gr[i] = make_pair(c , make_pair(a,b));
    }
    vector <pair <int , pair <int , int> > > ::iterator itb = Gr.begin();
    vector <pair <int , pair <int , int> > > ::iterator ite = Gr.end();
    sort(itb, ite, compair);
    for(int i =0 ;i <Gr.size() ; i++)
    {
        adj[Gr[i].second.second-1].push_back(Gr[i].second.first-1);
        adj[Gr[i].second.first-1].push_back(Gr[i].second.second-1);
        if(!isCycle(adj) )
        {
            w+=Gr[i].first;
        }
        else
        {
            adj[Gr[i].second.second-1].pop_back();
            adj[Gr[i].second.first-1].pop_back();
        }
    }
    cout <<w;
    return 0;
}
