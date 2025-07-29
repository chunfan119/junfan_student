#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void prve(vector<vector<int>> k){
    for(auto i:k){
        bool flag=false;
        for(int j:i){
            if (flag==true) cout<<" ";
            flag=true;
            cout<<j;
        }
        cout<<endl;
    }
}
vector<vector<int>> turn(vector<vector<int>> vec){
    vector<vector<int>> out;
    while(vec.size()>0){
        vector<int> tmpp;
        for(int i=0;i<vec.size();i++){
                tmpp.pb(vec[i][vec[i].size()-1]);
                vec[i].erase(vec[i].begin()+vec[i].size()-1);
        }
        out.pb({tmpp});
        if(vec[vec.size()-1].size()<=0) break;
    }
    return out;
}
vector<vector<int>> flip(vector<vector<int>> vec){
    vector<vector<int>> out;
    while(1){
        vector<int> tmpp;
        if(vec.size()<=0) return out;
        out.pb({vec[vec.size()-1]});
        vec.erase(vec.begin()+vec.size()-1);
//        prve(out);
//        cout<<endl;
    }
}
int main()
{
//    ifstream f("t.txt");
//    if(f)cin.rdbuf(f.rdbuf());
//    else cout<<"a";
    vector<int> tmp;
    int r,c,m; cin>>r>>c>>m;
    vector<vector<int>> ans;
    stack<int> act;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x;cin>>x;
            tmp.pb(x);
        }
        ans.pb({tmp});
        tmp.clear();
    }
    for(int i=0;i<m;i++){
        int x; cin>>x;
        act.push(x);
    }
    while(!act.empty()){
        if(act.top()==0) ans=turn(ans);
        else ans=flip(ans);
        act.pop();
    }
    cout<<ans.size()<<" "<<ans[0].size()<<endl;
    prve(ans);
}
