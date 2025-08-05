#include <bits/stdc++.h>
using namespace std;

bool can_move(vector<vector<char>> vec,int x,int y){
    if(isalpha(vec[y][x])) return true;
    else return false;
}
int main()
{
//    ifstream f("t.txt");
//    if(f)cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int m,n,k; cin>>m>>n>>k;
    cin.ignore();
    int action[6][2]={
        {0,-1},
        {1,0},
        {1,1},
        {0,1},
        {-1,0},
        {-1,-1}
    };
    vector<vector<char>> bee(m+2,vector<char>(n+2));
    int x=1,y=bee.size()-2;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            bee[i][j]='!';
        }
    }
    for(int i=1;i<=m;i++){
        string line;
        getline(cin,line);
        for(int j=0;j<=n;j++){
            bee[i][j+1]=line[j];
        }
    }
//    for(auto b:bee){
//        for(char c:b) cout<<c<<" ";
//        cout<<endl;
//    }
      vector<int> act(k);
    for(int i=0;i<k;i++){
        cin>>act[i];
    }
    unordered_map<char,int> cnt;
    //for(int i:act) cout<<i;
    for(int i:act){
        int now=i;
        //cout<<y<<" "<<x<<endl;
        if(can_move(bee,x+action[now][0],y+action[now][1])){
            //cout<<"true";
            x+=action[now][0];
            y+=action[now][1];
        }
        cnt[bee[y][x]]++;
        cout<<bee[y][x];
    }
    cout<<endl<<cnt.size()<<endl;
}
