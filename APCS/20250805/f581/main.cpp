#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> rooms(n);
    for(int i=0;i<n;i++){
        cin>>rooms[i];
    }
    vector<int> mission(m);
    for(int i=0;i<m;i++){
        cin>>mission[i];
    }
    int now=0;
    for(int i=0;i<m;i++){
        int tot=0;
        while(tot<mission[i]){
            tot+=rooms[now];
            if(now+1<n) now++;
            else now=0;
            //cout<<rooms[now]<<endl;
        }
        //cout<<rooms[now]<<endl;
    }
    cout<<now<<endl;
}
