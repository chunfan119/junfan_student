#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;cin>>a>>b>>c;

    if(a>1) a=1;
    if(b>1) b=1;
    bool flag=false;
    if((a&b)==c){cout<<"AND"<<endl;flag=true;}
    if((a|b)==c){cout<<"OR"<<endl;flag=true;}
    int jud=0;
    if((a^b)>0) jud=1;
    if (jud==c){
        cout<<"XOR"<<endl;
        flag=true;
    }
    if(flag==false){cout<<"IMPOSSIBLE"<<endl;flag=true;}

}
