#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N , M , K;
    cin >> N >>M >>K;
    int j , k, a;
    vector < vector <int> > v(N);
    for(int i = 0; i < M; i++)
    {
        cin >> j;
        for(j ; j > 0 ; j--)
        {
            cin >> k;
            v[i].push_back(k);
        }
    }
    vector< vector <pair <int , int> > > Adj(N);
    for(int i=0 ; i<N ; i++)
    {
        cin >> a >> j >>k;
        Adj[a].push_back(make_pair(j,k));
    }
    //Algorithm


    return 0;
}
