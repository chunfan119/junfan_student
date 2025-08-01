#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++){
        unordered_map<int,int>a;
        int tot=0;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            a[x]++;
        }
        for(int j=0;j<n;j++){
            int x;cin>>x;
            if(a[x]) tot++;
        }
        cout<<tot<<endl;
    }
}
