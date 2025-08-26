#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//#define   int long long


int main()
{
    #define int long long
struct players{
    int s;
    int t;
    int id;
    int lo;
};
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int n,m; cin>>n>>m;
    vector<vector<int>> input(3,vector<int>(n));
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }
    vector<players> tot(n), tmp(n);
    for(int i=0;i<n;i++){
        tmp[i].s=input[0][i];
        tmp[i].t=input[1][i];
        tmp[i].id=i+1;
    }
    for(int i=0;i<n;i++){
        tot[i]=tmp[input[2][i]-1];
    }
//        for(auto a:tot) cout<<a.s<<" "<<a.t<<" "<<a.id<<" "<<a.lo<<endl;
//        cout<<endl;
    while(tot.size()>1){
        vector<players> tmpwin, tmplose;
//        if(tot.size()<=1){
//            break;
//        }else
        {
            for(int i=0;i<tot.size()-1;i+=2){
                int a=tot[i].s; int b=tot[i].t;
                int c=tot[i+1].s; int d=tot[i+1].t;
                if(a*b>=c*d){
                    tot[i+1].lo++;
                     tot[i].s=a+c*d/(2*b);
                     tot[i].t=b+c*d/(2*a);
                     tot[i+1].s=c+c/2;
                     tot[i+1].t=d+d/2;
                     tmpwin.pb(tot[i]);
                     if (tot[i+1].lo<m) tmplose.pb(tot[i+1]);
                }else if(a*b<c*d){
                    tot[i].lo++;
                     tot[i+1].s=c+a*b/(2*d);
                     tot[i+1].t=d+a*b/(2*c);
                     tot[i].s=a+a/2;
                     tot[i].t=b+b/2;
                     tmpwin.pb(tot[i+1]);
                     if (tot[i].lo<m) tmplose.pb(tot[i]);
                }
            }

        }
        if(tot.size()%2==1&&tot.size()>=1) tmpwin.pb(tot[tot.size()-1]);
        tot=tmpwin;
        if(tmplose.size()>=1){
                for(int i=0;i<tmplose.size();i++){
                    tot.pb(tmplose[i]);
                }
        }
//        for(auto a:tmpwin) cout<<a.s<<" "<<a.t<<" "<<a.id<<" "<<a.lo<<endl;
//        cout<<endl;
//        for(auto a:tot) cout<<a.s<<" "<<a.t<<" "<<a.id<<" "<<a.lo<<endl;
//        cout<<endl;
    }
    cout<<tot[0].id<<endl;
}
