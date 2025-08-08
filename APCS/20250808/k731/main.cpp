#include <bits/stdc++.h>
using namespace std;
vector<int> tb(vector<int> der){
    swap(der[0],der[2]);
    swap(der[1],der[3]);
    return der;
}
vector<int> tl(vector<int> der){
    int tmp=der[3];
    der.erase(der.begin()+3);
    der.insert(der.begin(),tmp);
    return der;
}
vector<int> tr(vector<int> der){
    int tmp=der[0];
    der.erase(der.begin());
    der.push_back(tmp);
    return der;
}

int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> der(4);
    der[0]=1;der[1]=2;der[2]=4;der[3]=3;
    int n; cin>>n;
    int l=0,r=0,b=0;
    int x=0,y=0;
    vector<pair<int,int>> dot(n);
    for(int i=0;i<n;i++){
        cin>>dot[i].first;
        cin>>dot[i].second;
    }
    for(int i=0;i<n;i++){
            int newx=dot[i].first;
            int newy=dot[i].second;
            int act=0;
            if(newx>x){
                for(int i=0;i<4;i++){
                    if(der[i]==1) act=i;
                }
            }else  if(newx<x){
                for(int i=0;i<4;i++){
                    if(der[i]==4) act=i;
                }
            }else  if(newy>y){
                for(int i=0;i<4;i++){
                    if(der[i]==3) act=i;
                }
            }else  if(newy<y){
                for(int i=0;i<4;i++){
                    if(der[i]==2) act=i;
                }
            }
            if(act==1){r++;der=tr(der);}
            else if(act==2){b++;der=tb(der);}
            else if(act==3){l++;der=tl(der);}
            x=newx;
            y=newy;
    }


    cout<<l<<" "<<r<<" "<<b<<endl;
}
