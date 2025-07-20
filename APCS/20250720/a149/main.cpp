#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    cin.ignore();
    for(int j=0;j<n;j++){
        string line;
        getline(cin,line);
        int tot=1;
        for(char i:line){
            int k=i-'0';
            tot*=k;
        }
        cout<<tot<<endl;
    }
}
