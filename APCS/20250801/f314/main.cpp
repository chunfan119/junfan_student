#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int m,n; cin>>m>>n;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
            vector<int> vec(n+1),l(n+1),r(n+1);
            for(int j=1;j<=n;j++) cin>>vec[j];

            for(int j=1;j<=n;j++){
                if(j==1) l[j]=dp[i-1][j]+vec[j];
                else l[j]= max(dp[i-1][j],l[j-1])+vec[j];
            }

            for(int j=n;j>=1;j--){
                if(j==n) r[j]=dp[i-1][j]+vec[j];
                else r[j]= max(dp[i-1][j],r[j+1])+vec[j];
            }
            for(int j=1;j<=n;j++){
                dp[i][j]=max(l[j],r[j]);
            }
            //for(int j:vec) cout<<j;
    }
    bool flag=false;
    int big;
    for(auto a:dp){
        for(int i:a){
            if (flag==false) {big=i;flag=true;}
            if(i>big) big=i;
            //cout<<i;
        }
    }
    cout<<big;
}
