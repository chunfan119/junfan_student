#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(cin>>n){
        vector<int> tot(n+1);
        tot[0]=1;tot[1]=1;
        for(int i=2;i<=n;i++){
            tot[i]=tot[i-1]+i-1;
        }
        cout<<tot[n]<<endl;
    }
}

