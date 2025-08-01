#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"a";
    int m,s,n; cin>>m>>s>>n;
    vector<int> store(n);
    int used=0;
    for(int i=0;i<n;i++){
        cin>>store[i];
        used+=store[i];
    }
    int val=m-used;
    if(val>=s){cout<<0<<endl;return 0;}
    int inneed=s-val;
    int tot=used;
    vector<bool> dp(tot+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        int num=store[i];
        for(int j=tot;j>=num;j--){
            if(dp[j-num]){
                dp[j]=true;
            }
        }
    }
    //for(bool b:dp) cout<<b<<" ";
    for(int i=inneed;i<=tot;i++){
        if(dp[i]){
            cout<<i<<endl;
            return 0;
        }
    }
}
