#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> area;
int jud[4]={0,0,0,0};//¤W¤U¥ª¥k
void debug(){
    for(auto a:area){
        for(int i:a) cout<<i;
        cout<<endl;
    }
    cout<<endl;

}
void judf(int a,int b){
    for(int i=0;i<4;i++) jud[i]=0;
    int i=a-1,j=b;
    while(i>=0){

        if(area[i][j]==1){
            jud[0]=1;
            break;
        }

        i--;
    }
     i=a+1,j=b;
    int nn=area.size();
    while(i<nn){
        if(area[i][j]==1){
            jud[1]=1;
            break;
        }
        i++;
    }
     i=a,j=b-1;
    while(j>=0){
        if(area[i][j]==1){
            jud[2]=1;
            break;
        }
        j--;
    }
     i=a,j=b+1;
    nn=area[0].size();
    while(j<nn){
        if(area[i][j]==1){
            jud[3]=1;
            break;
        }
        j++;
    }
}
void add(int a,int b){
    area[a][b]=1;

    judf(a,b);

    if(jud[0]==1){
        int i=a-1,j=b;
        while(area[i][j]!=1){
            if(area[i][j]==0||area[i][j]==3) area[i][j]+=2;
            i--;
        }
    }
    if(jud[1]==1){
        int i=a+1,j=b;
        while(area[i][j]!=1){
            if(area[i][j]==0||area[i][j]==3) area[i][j]+=2;
            i++;
        }
    }
    if(jud[2]==1){
        int i=a,j=b-1;
        while(area[i][j]!=1){
            if(area[i][j]==0||area[i][j]==2) area[i][j]+=3;
            j--;
        }
    }
    if(jud[3]==1){
        int i=a,j=b+1;
        while(area[i][j]!=1){
            if(area[i][j]==0||area[i][j]==2) area[i][j]+=3;
            j++;
        }
    }
}
void del(int a,int b){
    area[a][b]=0;
    judf(a,b);
    if(jud[0]==1){
        int i=a-1,j=b;
        while(area[i][j]!=1){
            area[i][j]-=2;
            i--;
        }
    }
    if(jud[1]==1){
        int i=a+1,j=b;
        while(area[i][j]!=1){
            area[i][j]-=2;
            i++;
        }
    }
    if(jud[2]==1){
        int i=a,j=b-1;
        while(area[i][j]!=1){
            area[i][j]-=3;
            j--;
        }
    }
    if(jud[3]==1){
        int i=a,j=b+1;
        while(area[i][j]!=1){
            area[i][j]-=3;
            j++;
        }
    }
}
int total(){
    int out=0;
    for(int i=0;i<area.size();i++){
        for(int j=0;j<area[0].size();j++){
            if(area[i][j]>0) out++;
        }
    }
    return out;
}
int main()
{
    ifstream f("t.txt");
    if(f) cin.rdbuf(f.rdbuf());
    else cout<<"asd";
    int m,n,h; cin>>m>>n>>h;
    area.resize(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            area[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0){
            add(a,b);
        }
        if(c==1){
            del(a,b);
        }
        debug();
        ans=max(ans,total());
    }
    cout<<ans<<endl<<total();
}
