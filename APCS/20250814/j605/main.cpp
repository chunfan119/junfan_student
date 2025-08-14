#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int n;cin>>n;
    int mem1=0,mem2=0;
    int ans=0,tot=0;
    int big=0, add=0;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin>>vp[i].first>>vp[i].second;
        if(vp[i].second==-1) mem2++;
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        int a=vp[i].first,b=vp[i].second;
        big=max(big,b);
        add=(big-n-mem2*2);
        if(flag==false){
            flag=true;
            ans=a;
        }
        if(tot<add){
            ans=a;
            tot=add;
        }
    }
    cout<<tot<<" "<<ans<<endl;
}
