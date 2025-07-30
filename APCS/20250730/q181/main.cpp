#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if (f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int a,b; cin>>a>>b;
    int n; cin>>n;
    int tot=a+b;
    int ans=0;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        if (t<=tot) {
            if(t>=a) ans+=tot-t;
            else ans+=0;
        }else {
            int plu=tot-(t%tot);
            if(plu<=b) ans+=plu;
        }
    }
    cout<<ans;
}
