#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>


using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,s,min=100000,max=-1,count=0,steps=0,maxi=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        vector <int> v(s);
        for(int j=0;j<s;j++)
            cin>>v[j];
        while(1)
        {
            for(int j=0;j<s;j++)
            {
                if(min>v[j])
                    min=v[j];
                if(max<v[j]){
                    max=v[j];
                    maxi=j;
                }
            }
            if(min==max)
                break;
            count=count+(max-min);
            for(int j=0;j<maxi;j++)
                v[j]=v[j]+(max-min);
            for(int j=maxi+1;j<s;j++)
                v[j]=v[j]+(max-min);
            min=100000;
        }
        steps=count/5;
        steps=steps+(count%5)/2;
        steps=steps+(count%5)%2;
        cout<<steps<<endl;
        steps=0;
        count=0;
        max=-1;
        min=1000000;
        v.clear();
    }
    return 0;
}
