#include <bits/stdc++.h>
using namespace std;
int main()
{
//    ifstream f("t.txt");
//    if(f) cin.rdbuf(f.rdbuf());
//    else cout<<"as";
    int A1=0, B1=0, C1=0;
    int A2=0, B2=0, C2=0;
    int n=0;
    cin>>A1>>B1>>C1;
    cin>>A2>>B2>>C2;
    cin>>n;
    int bn=0;
    bool flag=false;
    for(int i=0;i<=n;i++){
        int k=n-i;
        int y12=(A1*i*i+B1*i+C1)+(A2*k*k+B2*k+C2);
        if (flag == false) {bn=y12; flag=true;}
        if(y12>bn ) bn=y12;
    }
    cout<<bn<<endl;
}
