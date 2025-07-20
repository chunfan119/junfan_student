#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int n;cin>>n;
    vector<vector<int>>people(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a;cin>>b;
        people[a].pb(b);people[b].pb(a);
    }
    int max_d=0;
    vector<int> d(n,-1); d[0]=0;
    queue<int> q; q.push(0);
    while(!q.empty()){
        int node_now=q.front(); q.pop();
        for(int j:people[node_now]){
            if (d[j]==-1) {
                    d[j]=d[node_now]+1;
                    q.push(j);
            }
        }
    }
        for(int j:d){
            if(j>max_d) max_d=j;
            //cout<<"j:"<<j<<endl;
        }
        int fame;
        for(int i=0;i<d.size();i++){
            if(d[i]==max_d) {fame=i;break;}
        }
    for(int i=0;i<d.size();i++){d[i]=-1;}
    d[fame]=0;
    q.push(fame);
    while(!q.empty()){
        int node_now=q.front(); q.pop();
        for(int j:people[node_now]){
            if (d[j]==-1) {
                    d[j]=d[node_now]+1;
                    q.push(j);
            }
        }
    }
        for(int j:d){
            if(j>max_d) max_d=j;
            //cout<<"j:"<<j<<endl;
        }
    cout<<max_d<<endl;
}
