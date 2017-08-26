#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c, vector <vector <long> > data){
    for(int i=1;i<=n;i++)
    {
        if(i%c[0]==0)
            data[0][i]=1;
    }
    for(int i=0;i<c.size();i++)
        data[i][0]=1;
    for(int i=1;i<c.size();i++)
        for(int j=1;j<=n;j++)
        {
            if(j>=c[i])
                data[i][j]=data[i-1][j]+data[i][j-c[i]];
            else
                data[i][j]=data[i-1][j];
        }
    return(data[c.size()-1][n]);
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    vector <vector <long> > data(m);
    for(int i=0;i<m;i++)
        for(int j=0;j<=n;j++)
            data[i].push_back(0);
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c , data);
    cout<<ways<<endl;
    return 0;
}
