#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> area;
int jud[4]={0,0,0,0};
void debug(){
    for(auto a:area){
        for(int i: a) cout<<i<<" ";
        cout<<endl;
    }
}

int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int n,m; cin>>n>>m;
    area.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>area[i][j];
        }
    }

    int tot=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(area[i][j]==-1) continue;
            int now=area[i][j];
            //cout<<"now"<<now<<endl;
            int x=i,y=j;
            for(int ii=0;ii<4;ii++) jud[ii]=0;
            bool flag=false;
            //debug();
            do{
                x-=1;
                if(x<0)break;
                if (area[x][y]==now){
                    //cout<<"a";
                    area[i][j]=-1; area[x][y]=-1;
                    tot+=now;flag=true;
                    i=0;j=0;
                    break;
                }

            }while(area[x][y]==-1);
            x=i,y=j;
            if(flag==false)do{
                x+=1;
                if(x>=n)break;
                if (area[x][y]==now){
                        //cout<<"b";
                    area[i][j]=-1; area[x][y]=-1;
                    tot+=now;flag=true;
                    i=0;j=0;
                    break;
                }
            }while(area[x][y]==-1);
            x=i,y=j;
            if(flag==false)do{
                y-=1;
                if(y<0)break;

                if (area[x][y]==now){
                       // cout<<"c";
                    area[i][j]=-1; area[x][y]=-1;
                    tot+=now;flag=true;
                    i=0;j=0;
                    break;
                }

            }while(area[x][y]==-1);
            x=i,y=j;
            if(flag==false)do{
                y+=1;
                if(y>=m)break;

                if (area[x][y]==now){
                    //cout<<"d";
                    area[i][j]=-1; area[x][y]=-1;
                    tot+=now;flag=true;
                    i=0;j=0;
                    break;
                }

            }while(area[x][y]==-1);
        }
    }
    cout<<tot<<endl;
}
