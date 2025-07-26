#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int s,t,n,m,r; cin>>s>>t>>n>>m>>r;
    vector<vector<int>> A(s,vector<int>(t));
    vector<vector<int>> B(n,vector<int>(m));
    int Att=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            int x;cin>>x;
            A[i][j]=x;
            Att+=x;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin>>x;
            B[i][j]=x;
        }
    }
    int tot=0;
    int small=0;
    bool jud=false;
    for(int i=0;i<=n-s;i++){
        for(int j=0;j<=m-t;j++){
                int dis=0;
                int tt=0;
            for(int k=0;k<s;k++){
                for(int l=0; l<t;l++){
                    tt+=B[k+i][l+j];
                    if(B[k+i][l+j]!=A[ k][l]) dis++;
                    //if(dis>r) break;
                    //cout<<k<<" "<<l<<endl;
                }
                //if(dis>r) break;
            }
            tt=abs(Att-tt);
            if(dis<=r) {
                    //cout<<"as";
                    tot+=1;
                    if(jud==false||small>tt) {small=tt;jud=true;}
            }
        }
    }
    if(tot==0) small=-1;
    cout<<tot<<endl<<small<<endl;
}
