#include <bits/stdc++.h>
using namespace std;
int act(vector<vector<int>> q, vector<int> way){
    int cost=0;
    //cout<<"k";
    vector<bool> mem(way.size(),false);
    for(int i=0;i<way.size();i++){
        if(mem[i]==true) continue;
        else{
            for(int j=i+1;j<way.size();j++){
                int now=way[i];
                if(way[j]==now){
                    mem[j]=true;
                     //cout<<i<<" "<<j<<endl;
                    for(int in=0;in<q[j].size();in++){
                        q[i][in]+=q[j][in];
                    }
                }
            }
        }
    }
//    for(auto a:q){
//        for(int i:a) cout<<i<<" ";
//        cout<<endl;
//    }
    for(int i=0;i<q.size();i++){
        if(mem[i]==true) continue;
        else {
            for(int j=0;j<q[i].size();j++){
                if(j==way[i]) cost+=q[i][j];
                else if(q[i][j]<=1000) cost+=q[i][j]*3;
                else{
                    cost=cost+3000+(q[i][j]-1000)*2;
                }
            }
        }
    }
    //cout<<"d"<<cost<<endl;
    return cost;
}

int main()
{
//    ifstream f("t.txt");
//    if (f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>vec[i][j];
    }
    int tot=0;
    //cout<<tot<<endl;
    bool flag=false;
    for(int i=0;i<k;i++){
        vector<int> way(n);
        for(int j=0;j<n;j++){
            cin>>way[j];
        }
        int now=act(vec,way);
        //cout<<now;
        if (flag==false) {tot=now;flag=true;}
        tot=(tot>now) ? now:tot;
        //cout<<tot<<endl;
    }
    cout<<tot<<endl;
}
