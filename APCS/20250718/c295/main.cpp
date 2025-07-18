#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asdf";
    int M=0;cin>>M;
    int n=0;cin>>n;
    vector<int> v;
    vector<int> tmp;
    int tot=0;
    for(int i=0;i<M;i++){
        int big=0;
        for(int j=0;j<n;j++){
            int x; cin>>x;
            if(big<x) big=x;
        }
        v.push_back(big);
        tot+=big;
    }
    cout<<tot<<endl;
    bool jud=false;
    for(int i:v){
        if(tot%i==0) {
                if(jud==true) cout<<" ";
                cout<<i;
                jud=true;
                }
    }
    if (jud==false) cout <<-1;
}
