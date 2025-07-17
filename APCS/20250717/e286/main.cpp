#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
     int win=0;
     for(int j=0;j<2;j++){
        int A=0,B=0;
        for(int i=0;i<4;i++){
            int x;
            cin>>x;
            A=A+x;
        }
        for(int i=0;i<4;i++){
            int x;
            cin>>x;
            B=B+x;
        }
    cout<<A<<":"<<B<<endl;
    if (A>B) win+=1;
    }
    if(win==2) cout<<"Win";
    else if(win==0)cout<<"Lose";
    else if(win==1)cout<<"Tie";
}
