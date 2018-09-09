#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n,key=1,keyc=1;
        int m;
        long x,cost=0;
        long y;
        cin >> n >> m >> x >> y;
        vector <vector <long> >A(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                A[i].push_back(0);
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            A[city_1-1][city_2-1]=1;
            A[city_2-1][city_1-1]=1;
        }
        vector <long> C;
        if(x>y){
            vector <long> B;
            B.push_back(0);
            C.push_back(0);
            for(int i=0;i<n;i++)
            {
                for(int k=0;k<B.size();k++)
                {
                     if(B[k]==i)
                     {
                         key=0;
                         break;
                     }
                 }
                if(key==1)
                {
                    for(int k=0;k<C.size();k++)
                    {
                         if(C[k]==i)
                         {
                             keyc=0;
                             break;
                         }
                    }
                    if(keyc==1){
                        if(B.size()>1){
                            cost=cost+x+(B.size()-1)*y;
                        }
                        else{
                            cost=cost+x;
                        }
                        B.clear();
                        B.push_back(i);
                        C.push_back(i);
                    }
                    else
                        continue;
                }
                key=1;
                keyc=1;
                for(int j=0;j<n;j++)
                {
                    if(A[i][j])
                    {
                        for(int k=0;k<B.size();k++)
                        {
                            if(B[k]==j)
                            {
                                key=0;
                                break;
                            }
                        }
                        if(key==1){
                            B.push_back(j);
                            C.push_back(j);
                        }
                     }
                    key=1;
              }
          }
            if(B.size()>1)
                cost=cost+x+(B.size()-1)*y;
            else
                cost=cost+x;
            cout<<cost<<endl;
            B.clear();
            cost=0;
        }
        else
        {
            cout<<x*n<<endl;
        }
    }
    return 0;
}
