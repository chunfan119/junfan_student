#include <bits/stdc++.h>
using namespace std;
int n,m,k;
#define ff first
#define ss second
vector<vector<int>> bombmaze;
struct kk{
    int ri;
    int ci;
    int si;
    int ti;
    int f=0;
};
vector<kk> kings;
void debug(){
    for(auto a:bombmaze){
        for(int i:a) cout<<i<<" ";
        cout<<endl;
    }
    for(auto a:kings){
        cout<<a.ri<<" "<<a.ci<<"  alive="<<a.f<<endl;
    }
    cout<<endl;
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    bombmaze.resize(n,vector<int>(m,0));
    kings.resize(k);
    for(int i=0;i<k;i++){
        cin>>kings[i].ri>>kings[i].ci>>kings[i].si>>kings[i].ti;
    }
    int cnt=0;
    while(cnt<kings.size()){

        for(int i=0;i<kings.size();i++){
            if (kings[i].f==1) continue;
            bombmaze[kings[i].ri][kings[i].ci]=1;
            kings[i].ri+=kings[i].si;
            kings[i].ci+=kings[i].ti;
        }
        vector<pair<int,int>> tmp;
        for(int i=0;i<kings.size();i++){
            if(kings[i].f==1) continue;
            int ii=kings[i].ri, jj=kings[i].ci;
            if (ii>=n||jj>=m||ii<0||jj<0){
                kings[i].f=1; cnt++;
            }else if(bombmaze[ii][jj]>0){
                //pair<int,int> tmp;
                //tmp.ff=ii;
                //tmp.ss=jj;
               // bomb.push_back(tmp);
                pair<int,int> tmpp;
                tmpp.ff=ii; tmpp.ss=jj;
                tmp.push_back(tmpp);
                bombmaze[ii][jj]=30000; kings[i].f=1; cnt++;
//                for(int j=0;j<kings.size();j++){
//                    if(kings[j].f==1) continue;
//                    if (kings[j].ci==ii&&kings[j].ri==jj){
//                        kings[i].f=1;cnt++;
//                    }
//                }
            }
        }
        for(auto a:tmp){
            bombmaze[a.ff][a.ss]=0;
        }


        //debug();
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (bombmaze[i][j]!=0 && bombmaze[i][j]!=30000)ans++;
        }
    }
    //debug();
    cout<<ans<<endl;
}
