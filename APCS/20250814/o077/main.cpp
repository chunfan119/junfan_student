#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> paint;
void ppaint(){
    for(auto a:paint){
        for(int i:a) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void color(int x,int y,int dis,int col){
    int n=paint.size(); int m=paint[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int jud=abs(i-x)+abs(j-y);
            if(jud<=dis) paint[i][j]+=col;
        }
    }
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int h,w,n; cin>>h>>w>>n;
    paint.resize(h,vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            paint[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int r,c,t,x; cin>>r>>c>>t>> x;
        color(r,c,t,x);

    }
    ppaint();
}
