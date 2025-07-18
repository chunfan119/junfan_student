#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"fa";
    int n=0;
    while(cin>>n){
        vector<int> v;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            v.push_back(x);
            }
        vector<int> tmp;
        for(int i:v) {tmp.push_back(i);push_heap(tmp.begin(),tmp.end(),greater<int>());}
        //make_heap(v.begin(),v.end(),greater<int>());
        for(int i:tmp) cout<<i<<" ";
        cout<<endl;
        vector<int>tm;
        for(int i:v) {tm.push_back(i);push_heap(tm.begin(),tm.end());}
        for(int i:tm) cout<<i<<" ";
         cout<<endl;
    }
}
