#include <bits/stdc++.h>

using namespace std;

int main()
{
//    ifstream fin("t.txt");
//    if (fin) cin.rdbuf(fin.rdbuf());
//    else cout<<"err";

    int k=0;
    int x1=0,y1=0;
    int x2=0,y2=0;
    int d=0;
    cin>>k>>x1>>y1>>x2>>y2;

    while(k>0){
        d+=k;

        if(d%x1==0){
            k-=y1;
        }
        if(d%x2==0){
            k-=y2;
        }
    }
    cout<<d;

}
