#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0,tot=0;
    int n,d; cin>>n>>d;
    for(int i=0;i<n;i++){
            int a,b,c;cin>>a>>b>>c;
            if(abs(a-b)>=d||abs(b-c)>=d||abs(a-c)>=d){
                tot+=(a+b+c)/3;
                cnt++;
            }
    }
    cout<<cnt<<" "<<tot<<endl;
}
