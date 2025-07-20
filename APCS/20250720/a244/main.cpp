#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int jud;
        cin>>jud;
        long long a,b;
        cin>>a>>b;
        if(jud==1) cout<<a+b<<endl;
        else if(jud==2) cout<<a-b<<endl;
        else if(jud==3) cout<<a*b<<endl;
        else if(jud==4) cout<<a/b<<endl;
    }
}
