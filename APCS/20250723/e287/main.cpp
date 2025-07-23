#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"s";
    int n=0,m=0; cin>>n>>m;
    vector<vector<int>> tmap(n+2,vector<int>(m+2));
    vector<vector<bool>> mem(n+2,vector<bool>(m+2));
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            tmap[i][j]=-1;
            mem[i][j]=true;
        }
    }

//    cout<<"-1";
//    return 0;
    for(int i=1;i<n+1;i++){
        vector<int> tmp;
        for(int j=1;j<m+1;j++){
            int x;cin>>x;
            tmap[i][j]=x;
            mem[i][j]=false;
        }
    }
//    for(int i=0;i<=n+1;i++){
//        for(int j=0;j<=m+1;j++){
//            cout<<mem[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int small=tmap[1][1];
    int ii=1,jj=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(small>tmap[i][j]) {
                small=tmap[i][j];
                ii=i;
                jj=j ;
                //cout<<ii<<" "<<jj<<endl;
            }
        }
    }

//    cout<<small<<endl;
//    cout<<ii<<" "<<jj<<endl;
    int tot=small;
    while(1){
        mem[ii][jj]=true;
        small=1000000;
        if(mem[ii+1][jj]==true&&mem[ii][jj+1]==true&&mem[ii-1][jj]==true&&mem[ii][jj-1]==true) break;
        if(mem[ii+1][jj]==false)small=(small<tmap[ii+1][jj]) ? small:tmap[ii+1][jj] ;
        if(mem[ii-1][jj]==false)small=(small<tmap[ii-1][jj]) ? small:tmap[ii-1][jj] ;
        if(mem[ii][jj-1]==false)small=(small<tmap[ii][jj-1]) ? small:tmap[ii][jj-1] ;
        if(mem[ii][jj+1]==false)small=(small<tmap[ii][jj+1]) ? small:tmap[ii][jj+1] ;
        tot+=small;
        if(small==tmap[ii+1][jj]) ii++;
        else if(small==tmap[ii-1][jj]) ii--;
        else if(small==tmap[ii][jj+1]) jj++;
        else if(small==tmap[ii][jj-1]) jj--;
//        cout<<ii<<" "<<jj<<endl;
        //cout<<small;
//        cout<<tot;
    }

    cout<<tot;
}
