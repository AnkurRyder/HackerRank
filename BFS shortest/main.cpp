#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q , n , m , s ,u ,v , temp;
    cin >> q;
    for(int l= 0 ;l <q ; l++)
    {
        cin >> n >>m;
        vector <vector <int> > ADJ(n);
        vector <bool> visited(n , false);
        vector <int> Distace(n,INT_MAX);
        queue <int> st;
        for(int i=0 ; i<m; i++)
        {
            cin >> u >> v;
            ADJ[u-1].push_back(v-1);
            ADJ[v-1].push_back(u-1);
        }
        cin >> s;
        st.push(s-1);
        Distace[s-1] = 0;
        visited[s-1] = true;
        while(!st.empty())
        {
            temp = st.front();
            st.pop();
            for(int i =0 ;i <ADJ[temp].size() ; i++)
            {
                if(!visited[ADJ[temp][i]])
                {
                    visited[ADJ[temp][i]] = true;
                    st.push(ADJ[temp][i]);
                    Distace[ADJ[temp][i]] = Distace[temp] +6;
                }
            }
        }
        for(int i=0; i< n ;i++)
        {
            if(i != s-1){
                if(Distace[i] == INT_MAX)
                    cout << "-1" << " ";
                else
                    cout << Distace[i] << " ";
            }
        }
        cout <<"\n";
        ADJ.clear();
        Distace.clear();
        visited.clear();
    }
    return 0;
}
