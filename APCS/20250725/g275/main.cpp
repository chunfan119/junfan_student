#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int n=0;cin>>n;
    for(int j=0;j<n;j++){
        vector<int> a,b;
        for(int i=0;i<7;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<7;i++){
            int x;cin>>x;
            b.push_back(x);
        }
        bool jud=false;
        if(!(a[1]!=a[3]&&a[1]==a[5]//二四不同
             &&b[1]!=b[3]
             &&b[1]==b[5])) {cout<<"A";jud=true;}

        if(!(a[6]==1&&b[6]==0)) {cout<<"B";jud=true;}
        if(!(a[1]!=b[1]&&a[3]!=b[3]&&a[5]!=b[5])){cout<<"C";jud=true;}
        if (jud==false) cout<<"None";
        cout<<endl;
    }
}
