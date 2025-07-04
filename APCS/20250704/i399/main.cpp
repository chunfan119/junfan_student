#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ans;

//    ifstream fin("t.txt");
//    if(fin) cin.rdbuf(fin.rdbuf());
    int a=0,b=0,c=0;
    cin>>a>>b>>c;
    int p=0;
    unordered_map<int,int> um;
    um[a]++;
    um[b]++;
    um[c]++;
    for(auto i:um){
        ans.push_back(i.first);
        if(i.second>p) p=i.second;
    }
    sort(ans.begin(),ans.end());
    cout<<p<<" ";
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }


}
