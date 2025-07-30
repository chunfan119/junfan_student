#include <bits/stdc++.h>
using namespace std;
struct dice{
    int t=1;
    int f=4;
    int b=3;
    int l=5;
    int r=2;
    int d=6;
};
dice right(dice dc){
    dice out;
    out.b=dc.b;
    out.t=dc.l;
    out.f=dc.f;
    out.l=dc.d;
    out.r=dc.t;
    out.d=dc.r;
    return out;
}
dice award(dice dc){
    dice out;
    out.b=dc.d;
    out.t=dc.b;
    out.f=dc.t;
    out.l=dc.l;
    out.r=dc.r;
    out.d=dc.f;
    return out;
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdf";
    vector<dice> D;
    int n,m; cin>>n>>m;
    D.resize(n+1);
    for(int i=0;i<m;i++){
        int act1,act2; cin>>act1>>act2;
        if (act2>0) swap(D[act1],D[act2]);
        else if(act2==-1) D[act1]=award(D[act1]);
        else if(act2==-2) D[act1]=right(D[act1]);
    }
    for(int i=1;i<=n;i++) cout<<D[i].t<<" ";
}
