#include <bits/stdc++.h>

using namespace std;
int l;
int minDistance(vector<int> dist, vector <bool> sptSet)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < l+2; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int dijk(vector <vector<pair <int , int> > > adj , int s  ,int e)
{
    vector<int> dist(l+2 , INT_MAX);

     vector <bool> sptSet(l+2 , false);

     dist[s] = 0;

     for (int count = 0; count < l+1; count++)
     {
       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < adj[u].size(); v++){
         if (!sptSet[v] && dist[u] != INT_MAX && dist[u]+adj[u][v].second < dist[v])
            dist[v] = dist[u] + adj[u][v].second;
       }
     }
     return dist[l+1];
}
int main()
{
    int t;
    int s , k=0, dicecount =0;
    int a ,b;
    cin >> t;
    for(int i=0 ;i< t ;i++)
    {
        cin >> l ;
        vector <pair<int , int> > ladder(l);
        vector <vector<pair <int , int> > > adj(l+2);
        for(int j=0 ; j < l ; j++)
        {
            cin >> a >>b;
            ladder[j] = make_pair(a , b);
        }
        cin >>s;
        vector <pair<int , int> > snake(s);
        for(int j=0 ; j < s ; j++)
        {
            cin >> a >>b;
            snake[j] = make_pair(a , b);
        }
        a=1;
        for(int j =0 ;j < l ; j++)
        {
            b = ladder[j].first;
            while(b > snake[k].first)
            {
                if((snake[k].first - a)%6 == 0 && snake[k].first > a)
                {
                    a = snake[k].first-1;
                    dicecount += (snake[k].first-a)/6;
                }
                k++;
            }
            k = 0;
            if(dicecount == 0)
                adj[j].push_back(make_pair(ladder[j].second,(b -a)/6));
            else
                adj[j].push_back(make_pair(ladder[j].second,dicecount));
            dicecount =0 ;
            a= ladder[j].second;
        }
        a = ladder[l-1].second;
        b = 100;
        k = 0;
        while(b > snake[k].first)
        {
            if((snake[k].first - a)%6 == 0)
            {
                a = snake[k].first-1;
                dicecount += (snake[k].first-a)/6;
            }
            k++;
        }
        k = 0;
        if(dicecount == 0)
            adj[l].push_back(make_pair( 100,(b -a)/6));
        else
            adj[l].push_back(make_pair(100,dicecount));
        dicecount =0 ;
        a = 1;
        cout <<dijk(adj , 0 , 100) << "\n";
        adj.erase(adj.begin() , adj.end());
        ladder.erase(ladder.begin() , ladder.end());
        snake.erase(snake.begin() , snake.end());
    }
    return 0;
}
