#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d; cin>>n>>d;
    int tot=0,x=0,last=0;
    bool jud=false;
    for(int i=0;i<n;i++){
        int input;cin>>input;
        if(i==0) {x=input; jud=true; continue;}
        if(jud==false&&input<=last-d) {x=input; jud=true; continue;}
        if(jud==true&&input>=x+d){tot+=input-x; last=input; jud=false; continue;}
    }
    cout<<tot<<endl;
}

