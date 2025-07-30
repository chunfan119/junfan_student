#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"asd";
    int cnt=1;
    while(1){

        vector<int> bricks;
        int n; cin>>n;
        if (n==0) break;
        int tot=0;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            bricks.push_back(x);
            tot+=x;
        }
        int high=tot/n;
        int ans=0;
        for(int i=0;i<n;i++){
            if(bricks[i]>high) ans+=bricks[i]-high;
        }
        cout<<"Set #"<<cnt<<endl;
        cout<<"The minimum number of moves is "<<ans<<"."<<endl<<endl;
        cnt++;
    }
}
