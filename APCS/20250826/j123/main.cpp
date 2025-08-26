#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> space ;
void putitem(char item,int x,int y){
    if(item=='A'){
        space[y][x]=1;
        space[y+1][x]=1;
        space[y+2][x]=1;
        space[y+3][x]=1;
        return;
    }else if(item=='B'){
        space[y][x]=1;
        space[y][x-1]=1;
        space[y][x-2]=1;
        return;
    }else if(item=='C'){
        space[y][x]=1;
        space[y][x-1]=1;
        space[y+1][x]=1;
        space[y+1][x-1]=1;
        return;
    }else if(item=='D'){
        space[y][x]=1;
        space[y+1][x]=1;
        space[y+1][x-1]=1;
        space[y+1][x-2]=1;
        return;
    }else if(item=='E'){
        space[y][x]=1;
        space[y+1][x]=1;
        space[y+2][x]=1;
        space[y+1][x-1]=1;
        space[y+2][x-1]=1;
        return;
    }
}
bool canput(char item,int x,int y){
    if(item=='A'){
        if(space[y][x]==0&&space[y+1][x]==0&&space[y+2][x]==0&&space[y+3][x]==0){
            return true;
        }else return false;

    }else if(item=='B'){
        if(space[y][x]==0&&space[y][x-1]==0&&space[y][x-2]==0){
            return true;
        }else return false;
    }else if(item=='C'){
        if(space[y][x]==0&&space[y][x-1]==0&&space[y+1][x]==0&&space[y+1][x-1]==0){

            return true;
        }else return false;
    }else if(item=='D'){
        if(space[y][x]==0&&space[y+1][x]==0&&space[y+1][x-1]==0&&space[y+1][x-2]==0){
            return true;
        }else return false;
    }else if(item=='E'){
        if(space[y][x]==0&&space[y+1][x]==0&&space[y+2][x]==0&&space[y+1][x-1]==0&&space[y+2][x-1]==0){
            return true;
        }else return false;
    }
}
void debug(){
    for(auto a:space){
        for(int i:a) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;

}
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";

    int r,c,n; cin>>r>>c>>n;
    space.resize(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            space[i][j]=0;
        }
    }

    for(int i=0;i<r;i++){
        space[i].insert(space[i].begin(),2);
        space[i].insert(space[i].begin(),2);
    }

    int trash=0;
    for(int i=0;i<n;i++){
        //debug();
        char t; int y; cin>>t>>y;
        int ix=c+1; int iy=y;
        if(!canput(t,ix,iy)) {trash++;continue;}
        else{
            while(canput(t,ix,iy)){
                ix--;
            }
        }
        putitem(t,ix+1,iy);
    }
    int tot=0;
    for(auto a:space){
        for(int i:a){
            if(i==0) tot++;
        }
    }
    cout<<tot<<" "<<trash<<endl;
}
