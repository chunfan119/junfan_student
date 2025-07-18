#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"er";
    vector<int>player;
    int n; cin>>n;
    for(int i=1;i<=n;i++) player.push_back(i);
    int m;cin>>m;
    int k;cin>>k;
    int boom_index=0;
    for(int j=0;j<k;j++){
        boom_index=(boom_index+m-1)%player.size();
        player.erase(player.begin()+boom_index);
//        cout<<"bi"<<boom_index<<" ";
//        for(int k:player) cout<<k<<" ";
//        cout<<endl;
    }
    if (boom_index>=player.size()) boom_index=0;
    cout<<player[boom_index]<<endl;

}
