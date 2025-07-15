#include<bits/stdc++.h>
using namespace std;
void dp(int *city ,int R ,int C){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<*(city+i+j)<<" ";
        }
        cout<<endl;
    }
}
int main(){
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int R=0,C=0,k=0,m=0;
    cin>>R>>C>>k>>m;
    int city[R][C]={0};
int tmp[R][C]={0};
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int x=0;
            cin>>x;
            city[i][j]=x;
        }
    }
    for(int d=0;d<m;d++){
       for(int i=0;i<R;i++)
           for(int j=0;j<C;j++)
               tmp[i][j]=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                    if (city[i][j]==-1) continue;
                    int cp=city[i][j]/k;
                    if(i>0){
                        if(city[i-1][j]!=-1){
                            city[i][j]-=cp;
                            tmp[i-1][j]+=cp;
                        } //else tmp[i-1][j]=0;
                    }
                    if(j>0){
                        if(city[i][j-1]!=-1){
                            city[i][j]-=cp;
                            tmp[i][j-1]+=cp;
                        }////else tmp[i][j-1]=0;
                    }
                    if(i<R-1){
                        if(city[i+1][j]!=-1){
                            city[i][j]-=cp;
                            tmp[i+1][j]+=cp;
                        } //else tmp[i+1][j]=0;
                    }
                    if(j<C-1){
                        if(city[i][j+1]!=-1){
                            city[i][j]-=cp;
                            tmp[i][j+1]+=cp;
                        }//else tmp[i][j+1]=0;
                    }
            }
        }
        //dp(&city[0][0],R,C);
        //dp(&tmp[0][0],R,C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                    city[i][j]+=tmp[i][j];
                    tmp[i][j]=0;
            }
        }
       // dp(&city[0][0],R,C);
    }
    int big=0 ,mini=city[0][0];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
                if(city[i][j]!=-1){
                if (city[i][j]>big) big=city[i][j];
                if(city[i][j]<mini)mini=city[i][j];
        }
        }
    }
    //dp(&city[0][0],R,C);
//       for(int i=0;i<R;i++){
//        for(int j=0;j<C;j++){
//            cout<<city[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<mini<<endl<<big<<endl;
}
