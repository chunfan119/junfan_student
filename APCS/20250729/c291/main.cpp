#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if (f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int n; cin>>n;
    vector<int> code;
    vector<bool> mem;
    mem.resize(n,false);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        code.push_back(x);
    }
    //for(auto i:mem ) cout<<i;
    int tot=0;
    for(int i=0;i<n;i++){
        if(mem[i]==true) continue;
        int idx=i;
        while(mem[idx]!=true){
            mem[idx]=true;
            idx=code[idx];
        }
        tot++;
    }
    cout<<tot;

}

