#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"ed";
    int N=0,L=0;
    cin>>N>>L;
    vector<pair<int,int>>tree(N+2);
    vector<pair<int,int>> loc(N+2);
    for(int i=1;i<=N;i++){
        int x=0; cin>>x; tree[i].first=x;
    }
    for(int i=1;i<=N;i++){
        int x=0; cin>>x; tree[i].second=x;
    }
    tree[0].first=1;tree[0].second=0;
    tree[N+1].first=L;tree[N+1].second=0;
    for(int i=0;i<=N+1;i++){
        loc[i].first=i-1;
        loc[i].second=i+1;
    }
    int now=1;
    int biggest_tree=0;
    int cnt=0;
    while(1){
            if(tree[now].first-tree[now].second>=tree[loc[now].first].first||
               tree[now].first+tree[now].second<=tree[loc[now].second].first){
                   cnt++;
                   biggest_tree=max(biggest_tree,tree[now].second);
                   loc[loc[now].second].first=loc[now].first;
                   loc[loc[now].first].second=loc[now].second;
                   if(loc[now].first!=0) now=loc[now].first;
                   else now=loc[now].second;
               }else now=loc[now].second;
           if(now>N) break;
    }


    cout<<cnt<<endl<<biggest_tree;
}
