#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> space;
void debug(){
    for(auto a:space){
        for(int i:a) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int k=0;
int dire=0;
int score=0;
int tot=0;
void turn(){
    dire=(dire+1<4) ? dire+1:0;
}
int movement[4][2]{
   { 0,1},
   { 1,0},
   { 0,-1},
   { -1,0},
};
void robot_move(int y, int x){
    while (space[y][x]!=0){
        tot++;
        score+=space[y][x];
        if(score%k==0) turn();
        space[y][x]--;
        int judx=x, judy=y;
        judx+=movement[dire][1];
        judy+=movement[dire][0];
        while(space[judy][judx]==-1){
            turn();
            judx=x; judy=y;
            judx+=movement[dire][1];
            judy+=movement[dire][0];
        }
        y=judy; x=judx;
    }
}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int m,n,r,c; cin>>m>>n>>k>>r>>c;
    space.resize(m+2,vector<int>(n+2));
    for(int i=0;i<m+2;i++){
        for(int j=0;j<n+2;j++){
            space[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int input; cin>>input;
            space[i][j]=input;
        }
    }
    int rbx,rby;
    rbx=c+1;rby=r+1;
    robot_move(rby,rbx);
    cout<<tot<<endl;
}
